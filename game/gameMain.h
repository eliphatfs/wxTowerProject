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

        void mouse_left(wxMouseEvent& event);
        void render_self(wxPaintEvent& evt);
        void catch_erase_background(wxEraseEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif // GAMEMAIN_H
