/////////////////////////////////////////////////////////////////////////////
// Name:        LoadSaveBase.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "Settings/Settings.hpp"

class LoadSaveBase
{
public:
	LoadSaveBase();
	~LoadSaveBase();

protected:
	bool Execute( wxString exe );
	bool Execute( wxString exe, wxArrayString& output );

	void RemoveDir( wxString dir );

	bool PowerShell( wxString ps );

	Settings& m_settings;
};

