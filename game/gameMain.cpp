/***************************************************************
 * Name:      gameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-11-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "gameMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(gameDialog)
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/mstream.h>
//*)

//(*IdInit(gameDialog)
const long gameDialog::ID_STATICBITMAPMAIN = wxNewId();
//*)

BEGIN_EVENT_TABLE(gameDialog,wxDialog)
    //(*EventTable(gameDialog)
    //*)
END_EVENT_TABLE()

gameDialog::gameDialog(wxWindow* parent, wxWindowID id) {
    //(*Initialize(gameDialog)
    Create(parent, wxID_ANY, _("WX Tower Project"), wxPoint(150, 120), wxDefaultSize, wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxBORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(800, 600));
    BoxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxImage* image = new wxImage();
    image->LoadFile(wxString::FromUTF8("res/9.png"), wxBITMAP_TYPE_PNG, -1);
    StaticBitmapMain = new wxStaticBitmap(this, ID_STATICBITMAPMAIN, wxBitmap(*image), wxDefaultPosition, wxSize(800, 600), 0, _T("ID_STATICBITMAPMAIN"));
    BoxSizer->Add(StaticBitmapMain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer);
    BoxSizer->SetSizeHints(this);
    //*)
}

gameDialog::~gameDialog() {
    //(*Destroy(gameDialog)
    //*)
}
