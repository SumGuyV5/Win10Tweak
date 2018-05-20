/////////////////////////////////////////////////////////////////////////////
// Name:        PrivacySettingsLoad.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "LoadBase.hpp"

class PrivacySettingsLoad : public LoadBase
{
public:
	PrivacySettingsLoad();
	~PrivacySettingsLoad();
	
private:
	void Load();

	void Telemetry();
	void WifiSense();
	void SmartScreen();
	void BingSearch();
	void LocationTracking();
	void FeedBack();
	void AdID();
	void Cortana();
	void AutoLogger();
	void Diagnostics();
	void WapPush();

	void WinUpdateP2P();
};

