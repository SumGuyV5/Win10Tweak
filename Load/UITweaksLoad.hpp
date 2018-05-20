/////////////////////////////////////////////////////////////////////////////
// Name:        UITweaksLoad.hpp
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

class UITweaksLoad : public LoadBase
{
public:
	UITweaksLoad();
	~UITweaksLoad();

private:
	void Load();
	
	void SearchButton();
	void TaskView();
	void LargeIcons();
	void ShowTitles();
	void AllTrayIcons();
	void KnowFileExt();
	void HiddenFiles();
	void ChangeDefault();
	void ComputerShortcut();
	void DesktopIcon();
	void DocumentsIcon();
	void DownloadsIcon();
	void MusicIcon();
	void PicturesIcon();
	void VideosIcon();

	void ActionCenter();
	void LockScreen();
	void Autoplay();
	void Autorun();
	void StickyKeys();
};

