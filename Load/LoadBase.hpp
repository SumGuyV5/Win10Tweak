/////////////////////////////////////////////////////////////////////////////
// Name:        LoadBase.hpp
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

#include <wx/config.h>

#include "../win10tweak.hpp"
#include "../LoadSaveBase.hpp"

class LoadBase : public LoadSaveBase
{
public:
	LoadBase();
	~LoadBase();

protected:
	long KeyValue(wxRegKey::StdKey type, wxString key, wxString value = "");
	wxString KeyString(wxRegKey::StdKey type, wxString key, wxString value);
	bool Query(wxString value, wxString look);

	Win10Tweak& m_tweak;
};

