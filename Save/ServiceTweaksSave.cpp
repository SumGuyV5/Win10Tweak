/////////////////////////////////////////////////////////////////////////////
// Name:        ServiceTweaksSave.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "ServiceTweaksSave.hpp"

#include <wx/config.h>

ServiceTweaksSave::ServiceTweaksSave()
{
}


ServiceTweaksSave::~ServiceTweaksSave()
{
}


void ServiceTweaksSave::SharingMap( bool selected )
{
	if (selected == m_settings.ServiceTweaks.sharingMap)
		return;
	long value1 = 1;
	
	if (selected)
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "EnableLinkedConnections", value1);
	else
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "EnableLinkedConnections");
}


void ServiceTweaksSave::Firewall( bool selected )
{
	if (selected == m_settings.ServiceTweaks.firewall)
		return;
	wxString cmd = "netsh advfirewall set allprofiles state ";
	if (selected)
		cmd += "on";
	else
		cmd += "off";

	Execute(cmd);
}


void ServiceTweaksSave::WinDefender( bool selected )
{
	if (selected == m_settings.ServiceTweaks.winDefender)
		return;
	long value1 = 1;

	if (selected)
		KeyDelete(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows Defender", "DisableAntiSpyware");
	else
		KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows Defender", "DisableAntiSpyware", value1);
}


void ServiceTweaksSave::WinUpdateRest(bool selected )
{
	if (selected == m_settings.ServiceTweaks.winUpdateRest)
		return;
	long value1 = 1;

	if (selected)
		value1 = 0;

	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\WindowsUpdate\\UX\\Settings", "UxOption", value1);
}


void ServiceTweaksSave::Home( bool selected )
{
	if (selected == m_settings.ServiceTweaks.homeGroups)
		return;
	bool start = false;

	if (selected)
		start = true;

	Setting("HomeGroupListener", start);
	Setting("HomeGroupProvider", start);
}


void ServiceTweaksSave::RemoteAss( bool selected )
{
	if (selected == m_settings.ServiceTweaks.remoteAss)
		return;
	long value1 = 0;

	if (selected)
		value1 = 1;

	KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Remote Assistance", "fAllowToGetHelp", value1);
}


void ServiceTweaksSave::RemoteDesk( bool selected )
{
	if (selected == m_settings.ServiceTweaks.remoteDesktop)
		return;
	long value1 = 1;
	long value2 = 1;

	if (selected)
	{
		value1 = 0;
		value2 = 0;
	}

	KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Terminal Server", "fDenyTSConnections", value1);
	KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp", "UserAuthentication", value2);
}


void ServiceTweaksSave::UAC(int selected)
{
	if ((selected == 0) == m_settings.ServiceTweaks.uacRasie)
		return;
	long value1 = 0;
	long value2 = 0;

	if (selected == 0)
	{
		value1 = 5;
		value2 = 1;
	}

	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "ConsentPromptBehaviorAdmin", value1);
	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "PromptOnSecureDesktop", value2);
}