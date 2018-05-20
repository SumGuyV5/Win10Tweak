/////////////////////////////////////////////////////////////////////////////
// Name:        UITweaksLoad.cpp
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

#include "UITweaksLoad.hpp"

#include <wx/config.h>
#include <wx/utils.h> 

UITweaksLoad::UITweaksLoad()
{
	Load();
}


UITweaksLoad::~UITweaksLoad()
{
}


//////////////////////////////////////////////////////////////////////////
///Private
//////////////////////////////////////////////////////////////////////////
void UITweaksLoad::Load()
{
	SearchButton();
	TaskView();
	LargeIcons();
	ShowTitles();
	AllTrayIcons();
	KnowFileExt();
	HiddenFiles();
	ChangeDefault();
	ComputerShortcut();
	DesktopIcon();
	DocumentsIcon();
	DownloadsIcon();
	MusicIcon();
	PicturesIcon();
	VideosIcon();

	ActionCenter();
	LockScreen();
	Autoplay();
	Autorun();
	StickyKeys();
}


void UITweaksLoad::SearchButton()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "SearchboxTaskbarMode");
	bool set = true;
	if (value1 == 0)
		set = false;

	m_tweak.mp_searchButtonCheck->SetValue(set);
	m_settings.UITweaks.searchButton = set;
}


void UITweaksLoad::TaskView()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ShowTaskViewButton");
	bool set = true;
	if (value1 == 0)
		set = false;

	m_tweak.mp_taskButtonCheck->SetValue(set);
	m_settings.UITweaks.taskView = set;
}


void UITweaksLoad::LargeIcons()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarSmallIcons");
	bool set = true;
	if (value1 == 1)
		set = false;

	m_tweak.mp_largeIconCheck->SetValue(set);
	m_settings.UITweaks.largeIcons = set;
}


void UITweaksLoad::ShowTitles()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarGlomLevel");
	bool set = true;
	if (value1 == -1)
		set = false;

	m_tweak.mp_titlesCheck->SetValue(set);
	m_settings.UITweaks.showTitles = set;
}


void UITweaksLoad::AllTrayIcons()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "EnableAutoTray");
	bool set = true;
	if (value1 == -1)
		set = false;

	m_tweak.mp_allIconsCheck->SetValue(set);
	m_settings.UITweaks.alltrayIcons = set;
}


void UITweaksLoad::KnowFileExt()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "HideFileExt");
	bool set = true;
	if (value1 == 1)
		set = false;

	m_tweak.mp_knownExtCheck->SetValue(set);
	m_settings.UITweaks.knownFileExt = set;
}


void UITweaksLoad::HiddenFiles()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "Hidden");
	bool set = true;
	if (value1 == 2)
		set = false;

	m_tweak.mp_hiddenCheck->SetValue(set);
	m_settings.UITweaks.hiddenFiles = set;
}


void UITweaksLoad::ChangeDefault()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "LaunchTo");
	bool set = true;
	if (value1 == -1)
		set = false;

	m_tweak.mp_defaultExpCheck->SetValue(set);
	m_settings.UITweaks.changeDefault = set;
}


void UITweaksLoad::ComputerShortcut()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\ClassicStartMenu", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
	long value2 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\NewStartPanel", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_computerCheck->SetValue(set);
	m_settings.UITweaks.computerShortcut = set;
}


void UITweaksLoad::DesktopIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}");
	bool set = true;
	if (value1 == -1)
		set = false;

	m_tweak.mp_deskIconCheck->SetValue(set);
	m_settings.UITweaks.desktopIcon = set;
}


void UITweaksLoad::DocumentsIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{d3162b92-9365-467a-956b-92703aca08af}");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A8CDFF1C-4878-43be-B5FD-F8091C1C60D0}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_docIconCheck->SetValue(set);
	m_settings.UITweaks.docIcon = set;
}


void UITweaksLoad::DownloadsIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{088e3905-0323-4b02-9826-5d99428e115f}");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{374DE290-123F-4565-9164-39C4925E467B}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_downIconCheck->SetValue(set);
	m_settings.UITweaks.downIcon = set;
}


void UITweaksLoad::MusicIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{1CF1260C-4DD0-4ebb-811F-33C572699FDE}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_musicIconCheck->SetValue(set);
	m_settings.UITweaks.musicIcon = set;
}


void UITweaksLoad::PicturesIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{24ad3ad4-a569-4530-98e1-ab02f9417aa8}");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3ADD1653-EB32-4cb0-BBD7-DFA0ABB5ACCA}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_pictIconCheck->SetValue(set);
	m_settings.UITweaks.picIcon = set;
}


void UITweaksLoad::VideosIcon()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}");
	long value2 = KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A0953C92-50DC-43bf-BE83-3742FED03C9C}");
	bool set = true;
	if ((value1 == -1) && (value2 == -1))
		set = false;

	m_tweak.mp_videosIconCheck->SetValue(set);
	m_settings.UITweaks.videoIcon = set;
}

void UITweaksLoad::ActionCenter()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Policies\\Microsoft\\Windows\\Explorer", "DisableNotificationCenter");
	long value2 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications", "ToastEnabled");
	bool set = true;
	if ((value1 == 1) && (value2 == 0))
		set = false;
	m_tweak.mp_actionCenterCheck->SetValue(set);
	m_settings.UITweaks.actionCenter = set;
}


void UITweaksLoad::LockScreen()
{
	long value1 = KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\Personalization", "NoLockScreen");
	bool set = true;
	if (value1 == 1)
		set = false;
	m_tweak.mp_lockScreenCheck->SetValue(set);
	m_settings.UITweaks.lockScreen = set;
}


void UITweaksLoad::Autoplay()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoplayHandlers", "DisableAutoplay");
	bool set = true;
	if (value1 == 1)
		set = false;
	m_tweak.mp_autoPlayCheck->SetValue(set);
	m_settings.UITweaks.autoPlay = set;
}


void UITweaksLoad::Autorun()
{
	long value1 = KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", "NoDriveTypeAutoRun");
	bool set = true;
	if (value1 == 255)
		set = false;
	m_tweak.mp_autorunCheck->SetValue(set);
	m_settings.UITweaks.autorun = set;
}


void UITweaksLoad::StickyKeys()
{
	wxString value1 = KeyString(wxRegKey::HKCU, "Control Panel\\Accessibility\\StickyKeys", "Flags");
	bool set = true;
	if (value1 == "506")
		set = false;
	m_tweak.mp_stickyKeysCheck->SetValue(set);
	m_settings.UITweaks.stickyKeys = set;
}
