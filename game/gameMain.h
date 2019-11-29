/***************************************************************
 * Name:      gameMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-11-13
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include <wx/wx.h>

class gameMain: public wxPanel {
    public:

        gameMain(wxWindow* parent);
        virtual ~gameMain();

    private:

        void mouse_event(wxMouseEvent& event);
        void keyboard_event(wxKeyEvent& event);
        void render_self(wxPaintEvent& evt);
        void catch_erase_background(wxEraseEvent& event);
        void on_idle(wxIdleEvent& evt);

        DECLARE_EVENT_TABLE()
};

#endif // GAMEMAIN_H
