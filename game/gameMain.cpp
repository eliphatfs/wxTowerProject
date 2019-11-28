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
#include <iostream>
using namespace std;

const long gameDialog::ID_STATICBITMAPMAIN = wxNewId();
wxStaticBitmap * mainStaticBitmap;

long image_id;
vec3_t pos = { { -10.0, -10.0, 1.0 } };
vec3_t pos2 = { { 10.0, 10.0, 1.0 } };
void game_render();

void gameDialog::mouse_left(wxMouseEvent& event) {
    vec3_t npos = { { event.GetX(), event.GetY(), 1.0 } };
    pos = npos;
    cout << 1 << endl;
    game_render();
}

BEGIN_EVENT_TABLE(gameDialog, wxDialog)
    EVT_LEFT_UP(gameDialog::mouse_left)
END_EVENT_TABLE()

void game_render() {
    begin_frame(true);
    draw_bitmap(get_image_by_id(image_id), pos);
    draw_bitmap(get_image_by_id(image_id), pos2);
    end_frame();

    mainStaticBitmap->SetBitmap(get_render_buffer());
}

gameDialog::gameDialog(wxWindow * parent, wxWindowID id) {
    freopen("wxTowerProject.log", "a", stdout);
    //(*Initialize(gameDialog)
    initialize_render_buffer();


    Create(parent, wxID_ANY, _("WX Tower Project"), wxPoint(150, 120), wxDefaultSize, wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxBORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(800, 600));
    BoxSizer = new wxBoxSizer(wxHORIZONTAL);

    image_id = load_png_image("res/9.png");
    mainStaticBitmap = StaticBitmapMain = new wxStaticBitmap(this, ID_STATICBITMAPMAIN, get_render_buffer(), wxDefaultPosition, wxSize(RBUF_W, RBUF_H), 0, _T("ID_STATICBITMAPMAIN"));
    StaticBitmapMain->Connect(wxID_ANY, wxEVT_LEFT_UP, wxMouseEventHandler(gameDialog::mouse_left), NULL, this);

    game_render();

    BoxSizer->Add(StaticBitmapMain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer);
    BoxSizer->SetSizeHints(this);

    Centre();
    //*)
}

gameDialog::~gameDialog() {
    unload_all_loaded_images();
    release_render_buffer();
}
