/////////////////////////////////////////////////////////////////////////////
// Name:        RemoveApplicationSave.hpp
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

class RemoveApplicationSave : public SaveBase
{
public:
	RemoveApplicationSave();
	~RemoveApplicationSave();

	void OneDrive( int selected );
	void WindowsMediaPlayer( int selected );
	void WorkFoldersClient( int selected );

private:
	void dism( wxString value, int selected );
};

