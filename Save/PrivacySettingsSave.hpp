/////////////////////////////////////////////////////////////////////////////
// Name:        PrivacySettingsSave.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "SaveBase.hpp"

class PrivacySettingsSave : public SaveBase
{
public:
	PrivacySettingsSave();
	~PrivacySettingsSave();

	void Telemtry( bool selected );
	void WifiSense( bool selected );
	void SmartScreen( bool selected );
	void BingSearch( bool selected );
	void LocationTracking( bool selected );
	void FeedBack( bool selected );
	void AdID( bool selected );
	void Cortana( bool selected );
	void AutoLogger( bool selected );
	void Diagnostics( bool selected );
	void WapPush( bool selected );

	void WinUpdateP2P(int selected);
};

