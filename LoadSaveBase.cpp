/////////////////////////////////////////////////////////////////////////////
// Name:        LoadSaveBase.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "LoadSaveBase.hpp"

#include "win10tweakapp.hpp"


LoadSaveBase::LoadSaveBase()
	: m_settings(wxGetApp().GetSettings())
{
}


LoadSaveBase::~LoadSaveBase()
{
}


//////////////////////////////////////////////////////////////////////////
// Protected
//////////////////////////////////////////////////////////////////////////
bool LoadSaveBase::Execute( wxString exe )
{
	wxArrayString output;
	return Execute(exe, output);
}

bool LoadSaveBase::Execute( wxString exe, wxArrayString& output )
{
	bool rtn = true;
	wxArrayString errors;
	wxExecute(exe, output, errors);

	if (errors.GetCount() > 0)
	{
		rtn = false;
		wxMessageOutputDebug().Printf(exe);
		for (unsigned int count = 0; count < errors.GetCount(); count++)
			wxMessageOutputDebug().Printf(errors.Item(count));
	}
	return rtn;
}

void LoadSaveBase::RemoveDir( wxString dir )
{
	if (wxFileExists(dir))
		wxRemoveFile(dir);
}

bool LoadSaveBase::PowerShell(wxString ps)
{
	wxString exe = "powershell.exe -ExecutionPolicy Bypass -NoLogo -NonInteractive -NoProfile -WindowStyle Hidden -Command \'" + ps + "\'";
	return Execute(exe);
}