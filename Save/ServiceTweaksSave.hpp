/////////////////////////////////////////////////////////////////////////////
// Name:        SarviceTweaksSave.hpp
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

class ServiceTweaksSave : public SaveBase
{
public:
	ServiceTweaksSave();
	~ServiceTweaksSave();

	void SharingMap( bool selected );
	void Firewall( bool selected );
	void WinDefender( bool selected );
	void WinUpdateRest( bool selected );
	void Home( bool selected );
	void RemoteAss( bool selected );
	void RemoteDesk( bool selected );

	void UAC(int selected);
};

