/////////////////////////////////////////////////////////////////////////////
// Name:        win10tweakapp.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:39:47
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
#include "wx/fs_zip.h"
////@end includes

#include "win10tweakapp.hpp"

extern void InitXmlResource();

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( Win10TweakApp )
////@end implement app


/*
 * Win10TweakApp type definition
 */

IMPLEMENT_CLASS( Win10TweakApp, wxApp )


/*
 * Win10TweakApp event table definition
 */

BEGIN_EVENT_TABLE( Win10TweakApp, wxApp )

////@begin Win10TweakApp event table entries
////@end Win10TweakApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for Win10TweakApp
 */

Win10TweakApp::Win10TweakApp()
{
    Init();
}


/*
 * Member initialisation
 */

void Win10TweakApp::Init()
{
////@begin Win10TweakApp member initialisation
	m_64bit = true;
	m_archMode = wxRegKey::WOW64ViewMode_64;
	m_archStr = "64";
	mp_window = nullptr;
////@end Win10TweakApp member initialisation
	wxPlatformInfo plat;
	if (plat.GetArchitecture() == wxArchitecture::wxARCH_32)
	{
		m_archMode = wxRegKey::WOW64ViewMode_Default;
		m_archStr = "32";
        m_64bit = false;
	}
}

/*
 * Initialisation for Win10TweakApp
 */

bool Win10TweakApp::OnInit()
{    
	wxXmlResource::Get()->InitAllHandlers();
	InitXmlResource();

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	Win10Tweak* mainWindow = new Win10Tweak(NULL);
	/* int returnValue = */ mainWindow->ShowModal();

	mainWindow->Destroy();
	// A modal dialog application should return false to terminate the app.
	return false;
}


/*
 * Cleanup for Win10TweakApp
 */

int Win10TweakApp::OnExit()
{    
////@begin Win10TweakApp cleanup
	return wxApp::OnExit();
////@end Win10TweakApp cleanup
}

