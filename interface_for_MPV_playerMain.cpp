/***************************************************************
 * Name:      interface_for_MPV_playerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-07-22
 * Copyright:  ()
 * License:
 **************************************************************/

#include "interface_for_MPV_playerMain.h"
#include <wx/msgdlg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//(*InternalHeaders(interface_for_MPV_playerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

bool noVideoAproved = false;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(interface_for_MPV_playerFrame)
const long interface_for_MPV_playerFrame::ID_PLAYBUTTON = wxNewId();
const long interface_for_MPV_playerFrame::ID_URLTEXTCTRL = wxNewId();
const long interface_for_MPV_playerFrame::ID_NOAUDIOCHECKBOX = wxNewId();
const long interface_for_MPV_playerFrame::ID_NOVIDEOCHECKBOX = wxNewId();
const long interface_for_MPV_playerFrame::idMenuQuit = wxNewId();
const long interface_for_MPV_playerFrame::idMenuAbout = wxNewId();
const long interface_for_MPV_playerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(interface_for_MPV_playerFrame,wxFrame)
    //(*EventTable(interface_for_MPV_playerFrame)
    //*)
END_EVENT_TABLE()

interface_for_MPV_playerFrame::interface_for_MPV_playerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(interface_for_MPV_playerFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,150));
    SetMinSize(wxSize(500,150));
    SetMaxSize(wxSize(500,150));
    PlayButton = new wxButton(this, ID_PLAYBUTTON, _("Play the video"), wxPoint(24,64), wxSize(104,26), 0, wxDefaultValidator, _T("ID_PLAYBUTTON"));
    UrlTextCtrl = new wxTextCtrl(this, ID_URLTEXTCTRL, _("Enter video URL here"), wxPoint(24,24), wxSize(352,27), 0, wxDefaultValidator, _T("ID_URLTEXTCTRL"));
    NoAudioCheckBox = new wxCheckBox(this, ID_NOAUDIOCHECKBOX, _("No audio"), wxPoint(392,28), wxDefaultSize, 0, wxDefaultValidator, _T("ID_NOAUDIOCHECKBOX"));
    NoAudioCheckBox->SetValue(false);
    NoVideoCheckBox = new wxCheckBox(this, ID_NOVIDEOCHECKBOX, _("No video"), wxPoint(392,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_NOVIDEOCHECKBOX"));
    NoVideoCheckBox->SetValue(false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Manual\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_PLAYBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interface_for_MPV_playerFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&interface_for_MPV_playerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&interface_for_MPV_playerFrame::OnAbout);
    //*)
}

interface_for_MPV_playerFrame::~interface_for_MPV_playerFrame()
{
    //(*Destroy(interface_for_MPV_playerFrame)
    //*)
}

void interface_for_MPV_playerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void interface_for_MPV_playerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxString("To play a video you just have to enter a proper video URL from eg. youtube or reddit and then click the \"Play the video\" button. The video should start playing in few seconds. \n\nNo sound option makes the video play without any sound. Duh \n\nNo video option makes the video play without any image. Be cautious about this option because when it's on there will be no window of the video and in order to stop it from playing you will have to turn it off through the process manager of your linux distro.");
    wxMessageBox(msg, _("Program manual"));
}

void interface_for_MPV_playerFrame::OnButton1Click(wxCommandEvent& event)
{
    bool isAudioOff = NoAudioCheckBox -> GetValue();
    bool isVideoOff = NoVideoCheckBox -> GetValue();

    wxString video = UrlTextCtrl -> GetValue();
    if (isAudioOff)
    {
        video += wxString(" --no-audio");
    }
    if (isVideoOff)
    {
        video += wxString(" --no-video");
        if (!noVideoAproved)
        {
            wxMessageBox(wxT("Warning! \nThere will be no window of the video because you checked the \"No Video\" check box. In order to stop the video from playing you will have to close it through the process manager of your linux distro."));
            noVideoAproved = true;
        }
    }
    system(wxString("mpv ") + video + wxString(" &"));
}
