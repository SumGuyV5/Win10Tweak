/////////////////////////////////////////////////////////////////////////////
// Name:        RemoveApplicationSave.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "RemoveApplicationSave.hpp"

#include "../win10tweakapp.hpp"

RemoveApplicationSave::RemoveApplicationSave()
{
}


RemoveApplicationSave::~RemoveApplicationSave()
{
}


void RemoveApplicationSave::OneDrive( int selected )
{
	if ((selected == 0) == m_settings.RemoveApp.onedrive)
		return;
	wxString envSYSTEMROOT = wxGetenv("SYSTEMROOT");
	if (wxGetApp().Get64bit())
		envSYSTEMROOT += "\\SysWOW64\\OneDriveSetup.exe";
	else
		envSYSTEMROOT += "\\System32\\OneDriveSetup.exe";
	long value1 = 1;
	if (selected == 0)
	{
		KeyDelete(wxRegKey::HKLM, "SOFTWARE\\Policies\\Microsoft\\Windows\\OneDrive", "DisableFileSyncNGSC");
		envSYSTEMROOT += " -NoNewWindow";
		Execute(envSYSTEMROOT);
	}
	else
	{
		PowerShell("Stop-Process -Name OneDrive -ErrorAction SilentlyContinue");
		wxSleep(3);
		KeyValue(wxRegKey::HKLM, "SOFTWARE\\Policies\\Microsoft\\Windows\\OneDrive", "DisableFileSyncNGSC", value1);
		envSYSTEMROOT += " /uninstall";
		Execute(envSYSTEMROOT);
		wxSleep(3);
		PowerShell("Stop-Process -Name explorer -ErrorAction SilentlyContinue");
		wxSleep(3);

		wxString dir = wxGetenv("USERPROFILE");
		RemoveDir(dir + "\\OneDrive");

		dir = wxGetenv("LOCALAPPDATA");
		RemoveDir(dir + "\\Microsoft\\OneDrive");

		dir = wxGetenv("PROGRAMDATA");
		RemoveDir(dir + "\\Microsoft OneDrive");

		dir = wxGetenv("SYSTEMDRIVE");
		RemoveDir(dir + "\\OneDriveTemp");

		KeyDelete(wxRegKey::HKCR, "CLSID\\{018D5C66-4533-4307-9B53-224DE2ED1FE6}");
		KeyDelete(wxRegKey::HKCR, "Wow6432Node\\CLSID\\{018D5C66-4533-4307-9B53-224DE2ED1FE6}");
	}
}


void RemoveApplicationSave::WindowsMediaPlayer( int selected )
{
	if ((selected == 0) == m_settings.RemoveApp.windowsMediaPlayer)
		return;
	dism("MediaPlayback", selected);
}


void RemoveApplicationSave::WorkFoldersClient( int selected )
{
	if ((selected == 0) == m_settings.RemoveApp.workFoldersClient)
		return;
	dism("WorkFolders-Client", selected);
}


//////////////////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////////////////
void RemoveApplicationSave::dism( wxString value, int selected )
{
	wxString exe;
	wxString enable = "Disable";
	if (selected == 0)
		enable = "Enable";
	exe.Printf("dism /online /%s-Feature /FeatureName:%s /Quiet /NoRestart", enable, value);
	Execute(exe);	
}
