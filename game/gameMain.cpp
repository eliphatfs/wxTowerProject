/***************************************************************
 * Name:      gameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-11-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "gameMain.h"
#include "resource_loader.h"
#include "game_map_editor.h"
#include "game_render.h"
#include "renderer.h"
#include "player.h"
#include "game_io.h"
#include "game_play.h"
#include "vec3.h"
#include <wx/wx.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool editor_mode;

BEGIN_EVENT_TABLE(gameMain, wxPanel)
    EVT_MOUSE_EVENTS(gameMain::mouse_event)
    EVT_CHAR(gameMain::keyboard_event)
    EVT_PAINT(gameMain::render_self)
    EVT_ERASE_BACKGROUND(gameMain::catch_erase_background)
    EVT_IDLE(gameMain::on_idle)
END_EVENT_TABLE()

void gameMain::catch_erase_background(wxEraseEvent& event) {
}

void gameMain::mouse_event(wxMouseEvent& event) {
    if (editor_mode)
        if (editor_mouse(event))
            this->Refresh();
    if (!editor_mode)
        if (play_mouse(event))
            this->Refresh();
}

void gameMain::on_idle(wxIdleEvent& evt) {
    if (play_anim()) {
        this->Refresh();
        wxMilliSleep(20);
    }
}

void gameMain::keyboard_event(wxKeyEvent& event) {
    player_t& plr = get_player();
    if (event.GetKeyCode() == 'p') {
        if (editor_mode)
            dump_state("res/map_data.bin");
        editor_mode = false;
        load_state("res/map_data.bin");
        plr.attack = 1;
        plr.defence = 0;
        plr.hp = 100;
        plr.keynumber = 0;
        plr.frame = 0;
        vec3_t centerInit = { { plr.x * 36.0, plr.y * 36.0, 1.0 } };
        game_render_inbuffer(centerInit, false);
        this->Refresh();
    }
    if (editor_mode)
        if (editor_key(event))
            this->Refresh();
    if (!editor_mode)
        if (play_key(event))
            this->Refresh();
}

void gameMain::render_self(wxPaintEvent& event) {
    end_frame(this);
}

gameMain::gameMain(wxWindow * parent): wxPanel(parent, 0, 0, RBUF_W, RBUF_H) {
    freopen("wxTowerProject.log", "a", stdout);
    load_config("res/config.txt");
    load_state("res/map_data.bin");
    editor_mode = true;
    initialize_render_buffer();
    game_render_initialize();

    vec3_t temp = { { 0.0, 0.0, 1.0 } };
    game_render_inbuffer(temp, true);

    Centre();
}

gameMain::~gameMain() {
    unload_all_loaded_images();
    release_render_buffer();
    if (editor_mode)
        dump_state("res/map_data.bin");
    exit(0);
}
