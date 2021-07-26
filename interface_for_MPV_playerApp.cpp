/***************************************************************
 * Name:      interface_for_MPV_playerApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-07-22
 * Copyright:  ()
 * License:
 **************************************************************/

#include "interface_for_MPV_playerApp.h"

//(*AppHeaders
#include "interface_for_MPV_playerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(interface_for_MPV_playerApp);

bool interface_for_MPV_playerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	interface_for_MPV_playerFrame* Frame = new interface_for_MPV_playerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
