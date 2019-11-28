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
#include "renderer.h"
#include "vec3.h"
#include <wx/wx.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

long image_id, bg_tile, walk_0;
vec3_t pos = { { -10.0, -10.0, 1.0 } };
vec3_t pos2 = { { 10.0, 10.0, 1.0 } };

BEGIN_EVENT_TABLE(gameMain, wxPanel)
    EVT_LEFT_UP(gameMain::mouse_left)
    EVT_PAINT(gameMain::render_self)
    EVT_ERASE_BACKGROUND(gameMain::catch_erase_background)
END_EVENT_TABLE()

void game_render_inbuffer();

void gameMain::catch_erase_background(wxEraseEvent& event) {
}

void gameMain::mouse_left(wxMouseEvent& event) {
    vec3_t npos = { { event.GetX(), event.GetY(), 1.0 } };
    pos = npos;
    game_render_inbuffer();
    this->Refresh();
}

void gameMain::render_self(wxPaintEvent& event) {
    end_frame(this);
}

gameMain::gameMain(wxWindow * parent): wxPanel(parent, 0, 0, RBUF_W, RBUF_H) {
    freopen("wxTowerProject.log", "a", stdout);
    initialize_render_buffer();

    image_id = load_png_image("res/9.png");
    bg_tile = load_png_image("res/bg_0.png");
    walk_0 = load_png_image("res/walks/flandre_000.png");

    game_render_inbuffer();

    Centre();
}

gameMain::~gameMain() {
    unload_all_loaded_images();
    release_render_buffer();
    exit(0);
}

void game_render_inbuffer() {
    begin_frame(true);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 20; j++) {
            vec3_t s = { { i * 36 - 26, j * 36 - 26, 1.0 } };
            draw_bitmap(get_image_by_id(bg_tile), s);
            if (i == 16 && j == 10) draw_bitmap(get_image_by_id(walk_0), s);
        }
    }
    // draw_bitmap(get_image_by_id(image_id), pos);
    // draw_bitmap(get_image_by_id(image_id), pos2);
}
