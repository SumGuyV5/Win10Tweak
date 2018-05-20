/////////////////////////////////////////////////////////////////////////////
// Name:        PrivacySettingsSave.cpp
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

#include "PrivacySettingsSave.hpp"
#include "../win10tweakapp.hpp"

#include <wx/config.h>
#include <wx/filename.h>

PrivacySettingsSave::PrivacySettingsSave()
{
	m_settings = wxGetApp().GetSettings();
}


PrivacySettingsSave::~PrivacySettingsSave()
{
}

void PrivacySettingsSave::Telemtry( bool selected )
{
	if (selected == m_settings.Privacy.telemetry)
		return;
	long value1 = 0;
	
	if (selected)
		KeyDelete(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\DataCollection", "AllowTelemetry");
	else
		KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\DataCollection", "AllowTelemetry", value1);
}


void PrivacySettingsSave::WifiSense( bool selected )
{
	if (selected == m_settings.Privacy.wifiSense)
		return;
	long value1 = 0;
	long value2 = 0;

	if (selected)
	{
		value1 = 1;
		value2 = 1;
	}
	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\PolicyManager\\default\\WiFi\\AllowWiFiHotSpotReporting", "Value", value1);
	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\PolicyManager\\default\\WiFi\\AllowAutoConnectToWifiSenseHotspots", "Value", value2);
}

void PrivacySettingsSave::SmartScreen( bool selected )
{
	if (selected == m_settings.Privacy.smartScreen)
		return;
	wxString value1 = "Off";
	long value2 = 0;

	if (selected)
	{
		value1 = "RequireAdmin";
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AppHost", "EnableWebContentEvaluation");
	}
	else
	{
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AppHost", "EnableWebContentEvaluation", value2);
	}
	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "SmartScreenEnabled", value1);	
}


void PrivacySettingsSave::BingSearch( bool selected )
{
	if (selected == m_settings.Privacy.bingSearch)
		return;
	long value1 = 0;
	
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "BingSearchEnabled");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "BingSearchEnabled", value1);
}


void PrivacySettingsSave::LocationTracking( bool selected )
{
	if (selected == m_settings.Privacy.locationTracking)
		return;
	long value1 = 0;
	long value2 = 0;

	if (selected)
	{
		value1 = 1;
		value2 = 1;
	}

	KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Sensor\\Overrides\\{BFA794E4-F964-4FDB-90F6-51056BFE4B44}", "SensorPermissionState", value1);
	KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Services\\lfsvc\\Service\\Configuration", "Status", value2);
}


void PrivacySettingsSave::FeedBack( bool selected )
{
	if (selected == m_settings.Privacy.feedback)
		return;
	long value1 = 0;
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Siuf\\Rules", "NumberOfSIUFInPeriod");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Siuf\\Rules", "NumberOfSIUFInPeriod", value1);
}


void PrivacySettingsSave::AdID( bool selected )
{
	if (selected == m_settings.Privacy.adID)
		return;
	long value1 = 0;
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo", "Enabled");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo", "Enabled", value1);
}


void PrivacySettingsSave::Cortana( bool selected )
{
	if (selected == m_settings.Privacy.cortana)
		return;
	long value1 = 0;
	long value2 = 0;
	long value3 = 0;
	long value4 = 0;
	wxRegKey key(wxRegKey::HKCU, "Software\\Microsoft\\Personalization\\Settings", wxRegKey::WOW64ViewMode_64);
	wxRegKey key2(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", wxRegKey::WOW64ViewMode_64);
	wxRegKey key3(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization\\TrainedDataStore", wxRegKey::WOW64ViewMode_64);

	if (selected)
	{
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Personalization\\Settings", "AcceptedPrivacyPolicy");
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitTextCollection", value2);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitInkCollection", value3);
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization\\TrainedDataStore", "HarvestContacts");
	}
	else
	{
		value2 = 1;
		value3 = 1;
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Personalization\\Settings", "AcceptedPrivacyPolicy", value1);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitTextCollection", value2);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitInkCollection", value3);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization\\TrainedDataStore", "HarvestContacts", value4);
	}
}


void PrivacySettingsSave::AutoLogger( bool selected )
{
	if (selected == m_settings.Privacy.autoLogger)
		return;
	wxString env = wxGetenv("PROGRAMDATA");
	env += "\\Microsoft\\Diagnosis\\ETLLogs\\AutoLogger";
	
	wxString exe = "icacls " + env;	

	if (selected)
		exe += " /grant:r SYSTEM:\(OI\)\(CI\)F";
	else
	{
		exe += " /deny SYSTEM:\(OI\)\(CI\)F";
		RemoveDir(env + "\\AutoLogger-Diagtrack-Listener.etl");
	}
	
	Execute(exe);
}


void PrivacySettingsSave::Diagnostics( bool selected )
{
	if (selected == m_settings.Privacy.diagnostics)
		return;
	bool start = false;
	if (selected)
		start = true;

	Setting("DiagTrack", start);
}


void PrivacySettingsSave::WapPush( bool selected )
{
	if (selected == m_settings.Privacy.wapPush)
		return;
	bool start = false;
	if (selected)
		start = true;

	Setting("dmwappushservice", start);
}


void PrivacySettingsSave::WinUpdateP2P(int selected)
{
	if ((selected == 0) == m_settings.Privacy.winUpdateP2P)
		return;
	long value1 = 3;
	long value2 = 1;

	if (selected == 0)
	{
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization", "SystemSettingsDownloadMode", value1);
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Config", "DODownloadMode", value2);
	}
	else
	{
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization", "SystemSettingsDownloadMode");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Config", "DODownloadMode");
	}
}