/////////////////////////////////////////////////////////////////////////////
// Name:        UITweaksSave.hpp
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
class UITweaksSave : public SaveBase
{
public:
	UITweaksSave();
	~UITweaksSave();
	
	void SearchButton( bool selected );
	void TaskView( bool selected );
	void LargeIcons( bool selected );
	void ShowTitles( bool selected );
	void AllTrayIcons( bool selected );
	void KnowFileExt( bool selected );
	void HiddenFiles( bool selected );
	void ChangeDefault( bool selected );
	void ComputerShortcut( bool selected );
	void DesktopIcon( bool selected );
	void DocumentsIcon( bool selected );
	void DownloadsIcon( bool selected );
	void MusicIcon( bool selected );
	void PicturesIcon( bool selected );
	void VideosIcon( bool selected );

	void ActionCenter( bool selected );
	void LockScreen( bool selected );
	void Autoplay( bool selected );
	void Autorun( bool selected );
	void StickyKeys( bool selected );
};

