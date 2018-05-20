/////////////////////////////////////////////////////////////////////////////
// Name:        RemoveApplicationLoad.hpp
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

#include "../Settings/Settings.hpp"

class RemoveApplicationLoad : public LoadBase
{
public:
	RemoveApplicationLoad();
	~RemoveApplicationLoad();

private:
	void Load();

	void OneDrive();
	void WindowsMediaPlayer();
	void WorkFoldersClient();
};

