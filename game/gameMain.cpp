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
#include "vec3.h"
#include <wx/wx.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

vec3_t pos = { { -10.0, -10.0, 1.0 } };
vec3_t pos2 = { { 10.0, 10.0, 1.0 } };

BEGIN_EVENT_TABLE(gameMain, wxPanel)
    EVT_MOUSE_EVENTS(gameMain::mouse_event)
    EVT_CHAR(gameMain::keyboard_event)
    EVT_PAINT(gameMain::render_self)
    EVT_ERASE_BACKGROUND(gameMain::catch_erase_background)
END_EVENT_TABLE()

void gameMain::catch_erase_background(wxEraseEvent& event) {
}

void gameMain::mouse_event(wxMouseEvent& event) {
    if (editor_mouse(event))
        this->Refresh();
}

void gameMain::keyboard_event(wxKeyEvent& event) {
    if (editor_key(event))
        this->Refresh();
}

void gameMain::render_self(wxPaintEvent& event) {
    end_frame(this);
}

gameMain::gameMain(wxWindow * parent): wxPanel(parent, 0, 0, RBUF_W, RBUF_H) {
    freopen("wxTowerProject.log", "a", stdout);
    initialize_render_buffer();
    game_render_initialize();

    vec3_t temp = { { 0.0, 0.0, 1.0 } };
    game_render_inbuffer(temp);

    Centre();
}

gameMain::~gameMain() {
    unload_all_loaded_images();
    release_render_buffer();
    exit(0);
}
