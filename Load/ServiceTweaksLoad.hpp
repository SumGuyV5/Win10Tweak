/////////////////////////////////////////////////////////////////////////////
// Name:        ServiceTweaksLoad.hpp
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

class ServiceTweaksLoad : public LoadBase
{
public:
	ServiceTweaksLoad();
	~ServiceTweaksLoad();

private:
	void Load();

	void SharingMap();
	void Firewall();
	void WinDefender();
	void WinUpdateRest();
	void HomeGroup();
	void RemoteAssistance();
	void RemoteDesktop();

	void UAC();
};

