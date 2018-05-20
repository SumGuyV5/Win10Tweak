/////////////////////////////////////////////////////////////////////////////
// Name:        RemoveApplicationLoad.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "RemoveApplicationLoad.hpp"

RemoveApplicationLoad::RemoveApplicationLoad()
{
	Load();
}


RemoveApplicationLoad::~RemoveApplicationLoad()
{
}


void RemoveApplicationLoad::Load()
{
	OneDrive();
	WindowsMediaPlayer();
	WorkFoldersClient();
}

void RemoveApplicationLoad::OneDrive()
{
	long value1 = KeyValue(wxRegKey::HKCR, "CLSID\\{018D5C66-4533-4307-9B53-224DE2ED1FE6}");
	long value2 = KeyValue(wxRegKey::HKCR, "Wow6432Node\\CLSID\\{018D5C66-4533-4307-9B53-224DE2ED1FE6}");
	int set = 1;
	if ((value1 == -2) && (value2 == -2))
		set = 0;
	m_tweak.mp_onedriveRadio->SetSelection(set);
	m_settings.RemoveApp.onedrive = (set == 0);
}


void RemoveApplicationLoad::WindowsMediaPlayer()
{
	wxString exe = "dism /online /Get-FeatureInfo /FeatureName:MediaPlayback";
	int set = 0;
	if (!Query(exe, "Enabled"))
		set = 1;
	m_tweak.mp_winMediaRadio->SetSelection(set);
	m_settings.RemoveApp.windowsMediaPlayer = (set == 0);
}


void RemoveApplicationLoad::WorkFoldersClient()
{
	wxString exe = "dism /online /Get-FeatureInfo /FeatureName:WorkFolders-Client";
	int set = 0;
	if (!Query(exe, "Enabled"))
		set = 1;
	m_tweak.mp_workFoldersRadio->SetSelection(set);
	m_settings.RemoveApp.workFoldersClient = (set == 0);
}
