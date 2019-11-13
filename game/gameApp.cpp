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
#include <wx/image.h>
//*)

IMPLEMENT_APP(gameApp);

bool gameApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gameDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
