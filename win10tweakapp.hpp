/////////////////////////////////////////////////////////////////////////////
// Name:        win10tweakapp.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:39:47
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////

#ifndef _WIN10TWEAKAPP_H_
#define _WIN10TWEAKAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/xrc/xmlres.h"
#include "wx/image.h"
#include "win10tweak.hpp"
////@end includes

#include "Settings/Settings.hpp"

#include <wx/config.h>

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * Win10TweakApp class declaration
 */

class Win10TweakApp: public wxApp
{    
    DECLARE_CLASS( Win10TweakApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    Win10TweakApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin Win10TweakApp event handler declarations

////@end Win10TweakApp event handler declarations

////@begin Win10TweakApp member function declarations

	bool Get64bit() const { return m_64bit ; }
	void Set64bit(bool value) { m_64bit = value ; }

	wxRegKey::WOW64ViewMode GetArchMode() const { return m_archMode ; }
	void SetArchMode(wxRegKey::WOW64ViewMode value) { m_archMode = value ; }

	wxString GetArchStr() const { return m_archStr ; }
	void SetArchStr(wxString value) { m_archStr = value ; }

	Win10Tweak* GetWindow() const { return mp_window ; }
	void SetWindow(Win10Tweak* value) { mp_window = value ; }

////@end Win10TweakApp member function declarations
	Settings& GetSettings() { return m_settings; }

////@begin Win10TweakApp member variables
private:
	bool m_64bit;
	wxRegKey::WOW64ViewMode m_archMode;
	wxString m_archStr;
	Win10Tweak* mp_window;
////@end Win10TweakApp member variables
	Settings m_settings;
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(Win10TweakApp)
////@end declare app

#endif
    // _WIN10TWEAKAPP_H_
