/////////////////////////////////////////////////////////////////////////////
// Name:        ServiceTweaksLoad.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
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

#include "ServiceTweaksLoad.hpp"

#include <wx/config.h>

ServiceTweaksLoad::ServiceTweaksLoad()
{
	Load();
}


ServiceTweaksLoad::~ServiceTweaksLoad()
{
}


//////////////////////////////////////////////////////////////////////////
///Private
//////////////////////////////////////////////////////////////////////////
void ServiceTweaksLoad::Load()
{
	SharingMap();
	Firewall();
	WinDefender();
	WinUpdateRest();
	HomeGroup();
	RemoteAssistance();
	RemoteDesktop();

	UAC();
}


void ServiceTweaksLoad::SharingMap()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "EnableLinkedConnections");
	bool set = true;
	if (value1 == -1)
		set = false;
	m_tweak.mp_sharingMapCheck->SetValue(set);
	m_settings.ServiceTweaks.sharingMap = set;
}


void ServiceTweaksLoad::Firewall()
{
	bool set = true;
	if (!Query("netsh advfirewall show allprofiles", "ON"))
		set = false;
	m_tweak.mp_firewallCheck->SetValue(set);
	m_settings.ServiceTweaks.firewall = set;
}


void ServiceTweaksLoad::WinDefender()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows Defender", "DisableAntiSpyware");
	bool set = true;
	if (value1 == 1)
		set = false;
	m_tweak.mp_winDefCheck->SetValue(set);
	m_settings.ServiceTweaks.winDefender = set;
}


void ServiceTweaksLoad::WinUpdateRest()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\WindowsUpdate\\UX\\Settings", "UxOption");
	bool set = true;
	if (value1 == 1)
		set = false;
	m_tweak.mp_winUpdateRestCheck->SetValue(set);
	m_settings.ServiceTweaks.winUpdateRest = set;
}


void ServiceTweaksLoad::HomeGroup()
{
	bool set = true;
	if (!Query("sc query HomeGroupListener", "RUNNING"))
		set = false;
	m_tweak.mp_homeCheck->SetValue(set);
	m_settings.ServiceTweaks.homeGroups = set;
}


void ServiceTweaksLoad::RemoteAssistance()
{
	long value1 = KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Remote Assistance", "fAllowToGetHelp");
	bool set = true;
	if (value1 == 0)
		set = false;
	m_tweak.mp_remoteAssCheck->SetValue(set);
	m_settings.ServiceTweaks.remoteAss = set;
}


void ServiceTweaksLoad::RemoteDesktop()
{
	long value1 = KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Terminal Server", "fDenyTSConnections");
	long value2 = KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp", "UserAuthentication");
	bool set = true;
	if ((value1 == 1) && (value2 == 1))
		set = false;
	m_tweak.mp_remoteDeskCheck->SetValue(set);
	m_settings.ServiceTweaks.remoteDesktop = set;
}


void ServiceTweaksLoad::UAC()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "ConsentPromptBehaviorAdmin");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "PromptOnSecureDesktop");
	long set = 1;

	if ((value1 == 5) && (value2 == 1))
		set = 0;
	m_tweak.mp_uacLvlRadio->SetSelection(set);
	m_settings.ServiceTweaks.uacRasie = set;
}