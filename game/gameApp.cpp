/***************************************************************
 * Name:      gameApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-11-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "gameApp.h"

//(*AppHeaders
#include "gameMain.h"
#include <wx/wx.h>
//*)

IMPLEMENT_APP(gameApp);

bool gameApp::OnInit() {
    wxInitAllImageHandlers();
    wxDialog Dlg(NULL, wxID_ANY, _("WX Tower Project"), wxPoint(150, 120), wxDefaultSize, wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN, _T("wxID_ANY"));
    Dlg.SetClientSize(wxSize(800, 600));

    wxIcon iconLoader;
    iconLoader.LoadFile(wxString::FromAscii("res/icon.ico"), wxBITMAP_TYPE_ICO);
    Dlg.SetIcon(iconLoader);

    gameMain mainPanel(&Dlg);

    SetTopWindow(&Dlg);
    Dlg.Centre();
    Dlg.ShowModal();
    return true;
}
