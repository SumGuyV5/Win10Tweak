/////////////////////////////////////////////////////////////////////////////
// Name:        SaveBase.hpp
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

#include "../LoadSaveBase.hpp"

class SaveBase : public LoadSaveBase
{
public:
	SaveBase();
	~SaveBase();

protected:
	void KillTask( wxString exe );
	void KeyValue( wxRegKey::StdKey type, wxString key, wxString value, long set );
	void KeyValue( wxRegKey::StdKey type, wxString key, wxString value = "", wxString set = "" );
	void KeyDelete( wxRegKey::StdKey type, wxString key, wxString value = "" );
	void Setting( wxString value, bool start );

private:
	void BackupDelete(wxString key);
};

