/***************************************************************
 * Name:      niezbednikApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "niezbednikApp.h"

//(*AppHeaders
#include "niezbednikMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(niezbednikApp);

bool niezbednikApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	niezbednikDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
