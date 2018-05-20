/////////////////////////////////////////////////////////////////////////////
// Name:        win10tweak.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/mstream.h"
#include "wx/imaglist.h"
////@end includes

#include "win10tweak.hpp"

#include "win10tweakapp.hpp"

#include "Load/PrivacySettingsLoad.hpp"
#include "Save/PrivacySettingsSave.hpp"

#include "Load/ServiceTweaksLoad.hpp"
#include "Save/ServiceTweaksSave.hpp"

#include "Load/UITweaksLoad.hpp"
#include "Save/UITweaksSave.hpp"

#include "Load/RemoveApplicationLoad.hpp"
#include "Save/RemoveApplicationSave.hpp"

////@begin XPM images
////@end XPM images


/*
 * Win10Tweak type definition
 */

IMPLEMENT_DYNAMIC_CLASS( Win10Tweak, wxDialog )


/*
 * Win10Tweak event table definition
 */

BEGIN_EVENT_TABLE( Win10Tweak, wxDialog )

////@begin Win10Tweak event table entries
    EVT_INIT_DIALOG( Win10Tweak::OnInitDialog )
    EVT_BUTTON( wxID_OK, Win10Tweak::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, Win10Tweak::OnCancelClick )
////@end Win10Tweak event table entries

END_EVENT_TABLE()


/*
 * Win10Tweak constructors
 */

Win10Tweak::Win10Tweak()
{
    Init();
}

Win10Tweak::Win10Tweak( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * Win10Tweak creator
 */

bool Win10Tweak::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Win10Tweak creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    SetParent(parent);
    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end Win10Tweak creation
    return true;
}


/*
 * Win10Tweak destructor
 */

Win10Tweak::~Win10Tweak()
{
////@begin Win10Tweak destruction
////@end Win10Tweak destruction
}


/*
 * Member initialisation
 */

void Win10Tweak::Init()
{
////@begin Win10Tweak member initialisation
    mp_telemetryCheck = NULL;
    mp_wifiSenseCheck = NULL;
    mp_smartScreenCheck = NULL;
    mp_bingSearchCheck = NULL;
    mp_locationTrackingCheck = NULL;
    mp_feedbackCheck = NULL;
    mp_adIdCheck = NULL;
    mp_cortanaCheck = NULL;
    mp_autologgerCheck = NULL;
    mp_diagnosticsCheck = NULL;
    mp_wapPushCheck = NULL;
    mp_winUpdateP2PRadio = NULL;
    mp_sharingMapCheck = NULL;
    mp_firewallCheck = NULL;
    mp_winDefCheck = NULL;
    mp_winUpdateRestCheck = NULL;
    mp_homeCheck = NULL;
    mp_remoteAssCheck = NULL;
    mp_remoteDeskCheck = NULL;
    mp_uacLvlRadio = NULL;
    mp_searchButtonCheck = NULL;
    mp_taskButtonCheck = NULL;
    mp_largeIconCheck = NULL;
    mp_titlesCheck = NULL;
    mp_allIconsCheck = NULL;
    mp_knownExtCheck = NULL;
    mp_hiddenCheck = NULL;
    mp_defaultExpCheck = NULL;
    mp_computerCheck = NULL;
    mp_deskIconCheck = NULL;
    mp_docIconCheck = NULL;
    mp_downIconCheck = NULL;
    mp_musicIconCheck = NULL;
    mp_pictIconCheck = NULL;
    mp_videosIconCheck = NULL;
    mp_actionCenterCheck = NULL;
    mp_lockScreenCheck = NULL;
    mp_autoPlayCheck = NULL;
    mp_autorunCheck = NULL;
    mp_stickyKeysCheck = NULL;
    mp_onedriveRadio = NULL;
    mp_winMediaRadio = NULL;
    mp_workFoldersRadio = NULL;
////@end Win10Tweak member initialisation
	wxGetApp().SetWindow(this);
}


/*
 * Control creation for Win10Tweak
 */

void Win10Tweak::CreateControls()
{    
////@begin Win10Tweak content construction
    if (!wxXmlResource::Get()->LoadDialog(this, GetParent(), wxT("ID_WIN10TWEAK")))
        wxLogError(wxT("Missing wxXmlResource::Get()->Load() in OnInit()?"));
    mp_telemetryCheck = XRCCTRL(*this, "ID_CHECKBOX15", wxCheckBox);
    mp_wifiSenseCheck = XRCCTRL(*this, "ID_CHECKBOX16", wxCheckBox);
    mp_smartScreenCheck = XRCCTRL(*this, "ID_CHECKBOX17", wxCheckBox);
    mp_bingSearchCheck = XRCCTRL(*this, "ID_CHECKBOX18", wxCheckBox);
    mp_locationTrackingCheck = XRCCTRL(*this, "ID_CHECKBOX19", wxCheckBox);
    mp_feedbackCheck = XRCCTRL(*this, "ID_CHECKBOX20", wxCheckBox);
    mp_adIdCheck = XRCCTRL(*this, "ID_CHECKBOX21", wxCheckBox);
    mp_cortanaCheck = XRCCTRL(*this, "ID_CHECKBOX22", wxCheckBox);
    mp_autologgerCheck = XRCCTRL(*this, "ID_CHECKBOX23", wxCheckBox);
    mp_diagnosticsCheck = XRCCTRL(*this, "ID_CHECKBOX24", wxCheckBox);
    mp_wapPushCheck = XRCCTRL(*this, "ID_CHECKBOX25", wxCheckBox);
    mp_winUpdateP2PRadio = XRCCTRL(*this, "ID_RADIOBOX9", wxRadioBox);
    mp_sharingMapCheck = XRCCTRL(*this, "ID_CHECKBOX26", wxCheckBox);
    mp_firewallCheck = XRCCTRL(*this, "ID_CHECKBOX27", wxCheckBox);
    mp_winDefCheck = XRCCTRL(*this, "ID_CHECKBOX28", wxCheckBox);
    mp_winUpdateRestCheck = XRCCTRL(*this, "ID_CHECKBOX29", wxCheckBox);
    mp_homeCheck = XRCCTRL(*this, "ID_CHECKBOX30", wxCheckBox);
    mp_remoteAssCheck = XRCCTRL(*this, "ID_CHECKBOX31", wxCheckBox);
    mp_remoteDeskCheck = XRCCTRL(*this, "ID_CHECKBOX32", wxCheckBox);
    mp_uacLvlRadio = XRCCTRL(*this, "ID_RADIOBOX27", wxRadioBox);
    mp_searchButtonCheck = XRCCTRL(*this, "ID_CHECKBOX", wxCheckBox);
    mp_taskButtonCheck = XRCCTRL(*this, "ID_CHECKBOX1", wxCheckBox);
    mp_largeIconCheck = XRCCTRL(*this, "ID_CHECKBOX2", wxCheckBox);
    mp_titlesCheck = XRCCTRL(*this, "ID_CHECKBOX3", wxCheckBox);
    mp_allIconsCheck = XRCCTRL(*this, "ID_CHECKBOX4", wxCheckBox);
    mp_knownExtCheck = XRCCTRL(*this, "ID_CHECKBOX5", wxCheckBox);
    mp_hiddenCheck = XRCCTRL(*this, "ID_CHECKBOX6", wxCheckBox);
    mp_defaultExpCheck = XRCCTRL(*this, "ID_CHECKBOX7", wxCheckBox);
    mp_computerCheck = XRCCTRL(*this, "ID_CHECKBOX8", wxCheckBox);
    mp_deskIconCheck = XRCCTRL(*this, "ID_CHECKBOX9", wxCheckBox);
    mp_docIconCheck = XRCCTRL(*this, "ID_CHECKBOX10", wxCheckBox);
    mp_downIconCheck = XRCCTRL(*this, "ID_CHECKBOX11", wxCheckBox);
    mp_musicIconCheck = XRCCTRL(*this, "ID_CHECKBOX12", wxCheckBox);
    mp_pictIconCheck = XRCCTRL(*this, "ID_CHECKBOX13", wxCheckBox);
    mp_videosIconCheck = XRCCTRL(*this, "ID_CHECKBOX14", wxCheckBox);
    mp_actionCenterCheck = XRCCTRL(*this, "ID_CHECKBOX33", wxCheckBox);
    mp_lockScreenCheck = XRCCTRL(*this, "ID_CHECKBOX34", wxCheckBox);
    mp_autoPlayCheck = XRCCTRL(*this, "ID_CHECKBOX35", wxCheckBox);
    mp_autorunCheck = XRCCTRL(*this, "ID_CHECKBOX36", wxCheckBox);
    mp_stickyKeysCheck = XRCCTRL(*this, "ID_CHECKBOX37", wxCheckBox);
    mp_onedriveRadio = XRCCTRL(*this, "ID_RADIOBOX21", wxRadioBox);
    mp_winMediaRadio = XRCCTRL(*this, "ID_RADIOBOX1", wxRadioBox);
    mp_workFoldersRadio = XRCCTRL(*this, "ID_RADIOBOX", wxRadioBox);
////@end Win10Tweak content construction
}


/*
 * Should we show tooltips?
 */

bool Win10Tweak::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Win10Tweak::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Win10Tweak bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Win10Tweak bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Win10Tweak::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Win10Tweak icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end Win10Tweak icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void Win10Tweak::OnOkClick( wxCommandEvent& event )
{
	PrivacySettingsSave priSettings;
	priSettings.Telemtry(mp_telemetryCheck->GetValue());
	priSettings.WifiSense(mp_wifiSenseCheck->GetValue());
	priSettings.SmartScreen(mp_smartScreenCheck->GetValue());
	priSettings.BingSearch(mp_bingSearchCheck->GetValue());
	priSettings.LocationTracking(mp_locationTrackingCheck->GetValue());
	priSettings.FeedBack(mp_feedbackCheck->GetValue());
	priSettings.AdID(mp_adIdCheck->GetValue());
	priSettings.Cortana(mp_cortanaCheck->GetValue());
	priSettings.AutoLogger(mp_autologgerCheck->GetValue());
	priSettings.Diagnostics(mp_diagnosticsCheck->GetValue());
	priSettings.WapPush(mp_wapPushCheck->GetValue());

	priSettings.WinUpdateP2P(mp_winUpdateP2PRadio->GetSelection());

	ServiceTweaksSave serTweak;
	serTweak.SharingMap(mp_sharingMapCheck->GetValue());
	serTweak.Firewall(mp_firewallCheck->GetValue());
	serTweak.WinDefender(mp_winDefCheck->GetValue());
	serTweak.WinUpdateRest(mp_winUpdateRestCheck->GetValue());
	serTweak.Home(mp_homeCheck->GetValue());
	serTweak.RemoteAss(mp_remoteAssCheck->GetValue());
	serTweak.RemoteDesk(mp_remoteDeskCheck->GetValue());

	serTweak.UAC(mp_uacLvlRadio->GetSelection());

	UITweaksSave uiTweak;
	uiTweak.SearchButton(mp_searchButtonCheck->GetValue());
	uiTweak.TaskView(mp_taskButtonCheck->GetValue());
	uiTweak.LargeIcons(mp_largeIconCheck->GetValue());
	uiTweak.ShowTitles(mp_titlesCheck->GetValue());
	uiTweak.AllTrayIcons(mp_allIconsCheck->GetValue());
	uiTweak.KnowFileExt(mp_knownExtCheck->GetValue());
	uiTweak.HiddenFiles(mp_hiddenCheck->GetValue());
	uiTweak.ChangeDefault(mp_defaultExpCheck->GetValue());
	uiTweak.ComputerShortcut(mp_computerCheck->GetValue());
	uiTweak.DesktopIcon(mp_deskIconCheck->GetValue());
	uiTweak.DocumentsIcon(mp_docIconCheck->GetValue());
	uiTweak.DownloadsIcon(mp_downIconCheck->GetValue());
	uiTweak.MusicIcon(mp_musicIconCheck->GetValue());
	uiTweak.PicturesIcon(mp_pictIconCheck->GetValue());
	uiTweak.VideosIcon(mp_videosIconCheck->GetValue());

	uiTweak.ActionCenter(mp_actionCenterCheck->GetValue());
	uiTweak.LockScreen(mp_lockScreenCheck->GetValue());
	uiTweak.Autoplay(mp_autoPlayCheck->GetValue());
	uiTweak.Autorun(mp_autorunCheck->GetValue());
	uiTweak.StickyKeys(mp_stickyKeysCheck->GetValue());

	RemoveApplicationSave rmApp;
	rmApp.OneDrive(mp_onedriveRadio->GetSelection());
	rmApp.WindowsMediaPlayer(mp_winMediaRadio->GetSelection());
	rmApp.WorkFoldersClient(mp_workFoldersRadio->GetSelection());

    event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void Win10Tweak::OnCancelClick( wxCommandEvent& event )
{
	this->Close();
    event.Skip();
}

/*
 * wxEVT_INIT_DIALOG event handler for ID_WIN10TWEAK
 */

void Win10Tweak::OnInitDialog( wxInitDialogEvent& event )
{
	PrivacySettingsLoad psl;
	ServiceTweaksLoad stl;
	UITweaksLoad uit;
	RemoveApplicationLoad rmLoad;
		
	event.Skip();
}

