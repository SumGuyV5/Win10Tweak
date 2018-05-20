/////////////////////////////////////////////////////////////////////////////
// Name:        PrivacySettingsLoad.cpp
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

#include "PrivacySettingsLoad.hpp"
#include "../win10tweakapp.hpp"

#include <wx/config.h>
#include <wx/utils.h> 


PrivacySettingsLoad::PrivacySettingsLoad()
{
	Load();
}


PrivacySettingsLoad::~PrivacySettingsLoad()
{
}

//////////////////////////////////////////////////////////////////////////
///Private
//////////////////////////////////////////////////////////////////////////
void PrivacySettingsLoad::Load()
{
	Telemetry();
	WifiSense();
	SmartScreen();
	BingSearch();
	LocationTracking();
	FeedBack();
	AdID();
	Cortana();
	AutoLogger();
	Diagnostics();
	WapPush();

	WinUpdateP2P();
}


void PrivacySettingsLoad::Telemetry()
{
	long value = KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\DataCollection", "AllowTelemetry");
	bool set = true;
	if (value == 0)
		set = false;
	m_tweak.mp_telemetryCheck->SetValue(set);
	m_settings.Privacy.telemetry = set;
}


void PrivacySettingsLoad::WifiSense()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\PolicyManager\\default\\WiFi\\AllowWiFiHotSpotReporting", "Value");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\PolicyManager\\default\\WiFi\\AllowAutoConnectToWifiSenseHotspots", "Value");
	bool set = true;
	if ((value1 == 0) && (value2 == 0))
		set = false;
	m_tweak.mp_wifiSenseCheck->SetValue(set);
	m_settings.Privacy.wifiSense = set;
}


void PrivacySettingsLoad::SmartScreen()
{	
	wxString value1 = KeyString(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "SmartScreenEnabled");
	long value2 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AppHost", "EnableWebContentEvaluation");
	bool set = true;
	if ((value1 == "Off") && (value2 == 0))
		set = false;
	m_tweak.mp_smartScreenCheck->SetValue(set);
	m_settings.Privacy.smartScreen = set;
}


void PrivacySettingsLoad::BingSearch()
{
	long value = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "BingSearchEnabled");
	bool set = true;
	if (value == 0)
		set = false;
	m_tweak.mp_bingSearchCheck->SetValue(set);
	m_settings.Privacy.bingSearch = set;
}


void PrivacySettingsLoad::LocationTracking()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Sensor\\Overrides\\{BFA794E4-F964-4FDB-90F6-51056BFE4B44}", "SensorPermissionState");
	long value2 = KeyValue(wxRegKey::HKLM, "System\\CurrentControlSet\\Services\\lfsvc\\Service\\Configuration", "Status");
	bool set = true;
	if ((value1 == 0) && (value2 == 0))
		set = false;
	m_tweak.mp_locationTrackingCheck->SetValue(set);
	m_settings.Privacy.locationTracking = set;
}


void PrivacySettingsLoad::FeedBack()
{
	long value = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Siuf\\Rules", "NumberOfSIUFInPeriod");
	bool set = true;
	if (value == 0)
		set = false;
	m_tweak.mp_feedbackCheck->SetValue(set);
	m_settings.Privacy.feedback = set;
}


void PrivacySettingsLoad::AdID()
{
	long value = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo", "Enabled");
	bool set = true;
	if (value == 0)
		set = false;
	m_tweak.mp_adIdCheck->SetValue(set);
	m_settings.Privacy.adID = set;
}


void PrivacySettingsLoad::Cortana()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Personalization\\Settings", "AcceptedPrivacyPolicy");
	long value2 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitTextCollection");
	long value3 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization", "RestrictImplicitInkCollection");
	long value4 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\InputPersonalization\\TrainedDataStore", "HarvestContacts");
	bool set = true;
	if ((value1 == 0) && (value2 == 1) && (value3 == 1) && (value4 == 0))
		set = false;
	m_tweak.mp_cortanaCheck->SetValue(set);
	m_settings.Privacy.cortana = set;
}


void PrivacySettingsLoad::AutoLogger()
{
	bool rtn = false;
	bool set = true;
	wxArrayString output;
	wxString exe;
	exe.Printf("icacls %s\\Microsoft\\Diagnosis\\ETLLogs\\AutoLogger", wxGetenv("PROGRAMDATA"));
	
	Execute(exe, output);
	for (unsigned int count = 0; count < output.GetCount(); count++)
	{
		wxString tmp = output.Item(count);
		int t = tmp.Find("NT AUTHORITY\\SYSTEM:\(OI\)\(CI\)\(N\)");
		if (t != wxNOT_FOUND)
			rtn = true;
	}
	if (rtn == true)
		set = false;
	m_tweak.mp_autologgerCheck->SetValue(set);
	m_settings.Privacy.autoLogger = set;
}


void PrivacySettingsLoad::Diagnostics()
{	
	bool set = true;
	if (Query("sc query DiagTrack", "RUNNING") == false)
		set = false;
	m_tweak.mp_diagnosticsCheck->SetValue(set);
	m_settings.Privacy.diagnostics = set;
}


void PrivacySettingsLoad::WapPush()
{
	bool set = true;
	if (Query("sc query dmwappushservice", "RUNNING") == false)
		set = false;
	m_tweak.mp_wapPushCheck->SetValue(set);
	m_settings.Privacy.wapPush = set;
}


void PrivacySettingsLoad::WinUpdateP2P()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization", "SystemSettingsDownloadMode");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Config", "DODownloadMode");
	long set = 1;
	if ((value1 == 3) || (value2 == 1))
		set = 0;

	m_tweak.mp_winUpdateP2PRadio->SetSelection(set);
	m_settings.Privacy.winUpdateP2P = (set == 0);
}
