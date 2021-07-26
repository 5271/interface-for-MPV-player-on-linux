/***************************************************************
 * Name:      interface_for_MPV_playerMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-07-22
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef INTERFACE_FOR_MPV_PLAYERMAIN_H
#define INTERFACE_FOR_MPV_PLAYERMAIN_H

//(*Headers(interface_for_MPV_playerFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class interface_for_MPV_playerFrame: public wxFrame
{
    public:

        interface_for_MPV_playerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~interface_for_MPV_playerFrame();

    private:

        //(*Handlers(interface_for_MPV_playerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(interface_for_MPV_playerFrame)
        static const long ID_PLAYBUTTON;
        static const long ID_URLTEXTCTRL;
        static const long ID_NOAUDIOCHECKBOX;
        static const long ID_NOVIDEOCHECKBOX;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(interface_for_MPV_playerFrame)
        wxButton* PlayButton;
        wxCheckBox* NoAudioCheckBox;
        wxCheckBox* NoVideoCheckBox;
        wxStatusBar* StatusBar1;
        wxTextCtrl* UrlTextCtrl;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // INTERFACE_FOR_MPV_PLAYERMAIN_H
