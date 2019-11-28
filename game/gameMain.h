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

//(*Headers(gameDialog)
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/dialog.h>
//*)

class gameDialog: public wxDialog {
    public:

        gameDialog(wxWindow* parent, wxWindowID id = -1);
        virtual ~gameDialog();

    private:

        //(*Handlers(gameDialog)
            void mouse_left(wxMouseEvent& event);
        //*)

        //(*Identifiers(gameDialog)
            static const long ID_STATICBITMAPMAIN;
        //*)

        //(*Declarations(gameDialog)
            wxStaticBitmap* StaticBitmapMain;
            wxBoxSizer* BoxSizer;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GAMEMAIN_H
