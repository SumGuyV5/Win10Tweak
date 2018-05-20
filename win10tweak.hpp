/////////////////////////////////////////////////////////////////////////////
// Name:        win10tweak.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////

#ifndef _WIN10TWEAK_H_
#define _WIN10TWEAK_H_


/*!
 * Includes
 */

////@begin includes
#include "win10tweak_symbols.h"
#include "wx/xrc/xmlres.h"
#include "wx/notebook.h"
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WIN10TWEAK 10000
#define SYMBOL_WIN10TWEAK_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WIN10TWEAK_TITLE _("Win 10 Tweak")
#define SYMBOL_WIN10TWEAK_IDNAME ID_WIN10TWEAK
#define SYMBOL_WIN10TWEAK_SIZE wxSize(400, 300)
#define SYMBOL_WIN10TWEAK_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Win10Tweak class declaration
 */

class Win10Tweak: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( Win10Tweak )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Win10Tweak();
    Win10Tweak( wxWindow* parent, wxWindowID id = SYMBOL_WIN10TWEAK_IDNAME, const wxString& caption = SYMBOL_WIN10TWEAK_TITLE, const wxPoint& pos = SYMBOL_WIN10TWEAK_POSITION, const wxSize& size = SYMBOL_WIN10TWEAK_SIZE, long style = SYMBOL_WIN10TWEAK_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WIN10TWEAK_IDNAME, const wxString& caption = SYMBOL_WIN10TWEAK_TITLE, const wxPoint& pos = SYMBOL_WIN10TWEAK_POSITION, const wxSize& size = SYMBOL_WIN10TWEAK_SIZE, long style = SYMBOL_WIN10TWEAK_STYLE );

    /// Destructor
    ~Win10Tweak();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Win10Tweak event handler declarations

    /// wxEVT_INIT_DIALOG event handler for ID_WIN10TWEAK
    void OnInitDialog( wxInitDialogEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

////@end Win10Tweak event handler declarations

////@begin Win10Tweak member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Win10Tweak member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Win10Tweak member variables
    wxCheckBox* mp_telemetryCheck;
    wxCheckBox* mp_wifiSenseCheck;
    wxCheckBox* mp_smartScreenCheck;
    wxCheckBox* mp_bingSearchCheck;
    wxCheckBox* mp_locationTrackingCheck;
    wxCheckBox* mp_feedbackCheck;
    wxCheckBox* mp_adIdCheck;
    wxCheckBox* mp_cortanaCheck;
    wxCheckBox* mp_autologgerCheck;
    wxCheckBox* mp_diagnosticsCheck;
    wxCheckBox* mp_wapPushCheck;
    wxRadioBox* mp_winUpdateP2PRadio;
    wxCheckBox* mp_sharingMapCheck;
    wxCheckBox* mp_firewallCheck;
    wxCheckBox* mp_winDefCheck;
    wxCheckBox* mp_winUpdateRestCheck;
    wxCheckBox* mp_homeCheck;
    wxCheckBox* mp_remoteAssCheck;
    wxCheckBox* mp_remoteDeskCheck;
    wxRadioBox* mp_uacLvlRadio;
    wxCheckBox* mp_searchButtonCheck;
    wxCheckBox* mp_taskButtonCheck;
    wxCheckBox* mp_largeIconCheck;
    wxCheckBox* mp_titlesCheck;
    wxCheckBox* mp_allIconsCheck;
    wxCheckBox* mp_knownExtCheck;
    wxCheckBox* mp_hiddenCheck;
    wxCheckBox* mp_defaultExpCheck;
    wxCheckBox* mp_computerCheck;
    wxCheckBox* mp_deskIconCheck;
    wxCheckBox* mp_docIconCheck;
    wxCheckBox* mp_downIconCheck;
    wxCheckBox* mp_musicIconCheck;
    wxCheckBox* mp_pictIconCheck;
    wxCheckBox* mp_videosIconCheck;
    wxCheckBox* mp_actionCenterCheck;
    wxCheckBox* mp_lockScreenCheck;
    wxCheckBox* mp_autoPlayCheck;
    wxCheckBox* mp_autorunCheck;
    wxCheckBox* mp_stickyKeysCheck;
    wxRadioBox* mp_onedriveRadio;
    wxRadioBox* mp_winMediaRadio;
    wxRadioBox* mp_workFoldersRadio;
////@end Win10Tweak member variables
};

#endif
    // _WIN10TWEAK_H_
