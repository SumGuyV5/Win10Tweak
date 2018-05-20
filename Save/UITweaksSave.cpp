/////////////////////////////////////////////////////////////////////////////
// Name:        UITweaksSave.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "UITweaksSave.hpp"

UITweaksSave::UITweaksSave()
{
}


UITweaksSave::~UITweaksSave()
{
}


void UITweaksSave::SearchButton( bool selected )
{
	if (selected == m_settings.UITweaks.searchButton)
		return;
	long value1 = 0;
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "SearchboxTaskbarMode");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "SearchboxTaskbarMode", value1);
}

void UITweaksSave::TaskView( bool selected )
{
	if (selected == m_settings.UITweaks.taskView)
		return;
	long value1 = 0;
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ShowTaskViewButton");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ShowTaskViewButton", value1);
}

void UITweaksSave::LargeIcons( bool selected )
{
	if (selected == m_settings.UITweaks.largeIcons)
		return;
	long value1 = 1;
	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarSmallIcons");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarSmallIcons", value1);
}

void UITweaksSave::ShowTitles( bool selected )
{
	if (selected == m_settings.UITweaks.showTitles)
		return;
	long value1 = 1;
	if (selected)
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarGlomLevel", value1);
	else
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarGlomLevel");
		
}

void UITweaksSave::AllTrayIcons( bool selected )
{
	if (selected == m_settings.UITweaks.alltrayIcons)
		return;
	long value1 = 0;
	if (selected)
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "EnableAutoTray", value1);
	else
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "EnableAutoTray");
		
}

void UITweaksSave::KnowFileExt( bool selected )
{
	if (selected == m_settings.UITweaks.knownFileExt)
		return;
	long value1 = 1;
	if (selected)
		value1 = 0;
	
	KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "HideFileExt", value1);
}

void UITweaksSave::HiddenFiles( bool selected )
{
	if (selected == m_settings.UITweaks.hiddenFiles)
		return;
	long value1 = 2;
	if (selected)
		value1 = 1;

	KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "Hidden", value1);
}

void UITweaksSave::ChangeDefault( bool selected )
{
	if (selected == m_settings.UITweaks.changeDefault)
		return;
	long value1 = 1;
	if (selected)
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "LaunchTo", value1);
	else
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "LaunchTo");
}

void UITweaksSave::ComputerShortcut( bool selected )
{
	if (selected == m_settings.UITweaks.computerShortcut)
		return;
	long value1 = 0;
	long value2 = 0;
	if (selected)
	{
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\ClassicStartMenu", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", value1);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\NewStartPanel", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", value2);
	}
	else
	{
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\ClassicStartMenu", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\NewStartPanel", "{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
	}	
}

void UITweaksSave::DesktopIcon( bool selected )
{
	if (selected == m_settings.UITweaks.desktopIcon)
		return;
	if (selected)
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}");
	else
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}");
}

void UITweaksSave::DocumentsIcon( bool selected )
{
	if (selected == m_settings.UITweaks.docIcon)
		return;
	if (selected)
	{
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{d3162b92-9365-467a-956b-92703aca08af}");
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A8CDFF1C-4878-43be-B5FD-F8091C1C60D0}");
	}
	else
	{
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{d3162b92-9365-467a-956b-92703aca08af}");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A8CDFF1C-4878-43be-B5FD-F8091C1C60D0}");
	}
}

void UITweaksSave::DownloadsIcon( bool selected )
{
	if (selected == m_settings.UITweaks.downIcon)
		return;
	if (selected)
	{
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{088e3905-0323-4b02-9826-5d99428e115f}");
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{374DE290-123F-4565-9164-39C4925E467B}");
	}
	else
	{
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{088e3905-0323-4b02-9826-5d99428e115f}");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{374DE290-123F-4565-9164-39C4925E467B}");
	}
}

void UITweaksSave::MusicIcon( bool selected )
{
	if (selected == m_settings.UITweaks.musicIcon)
		return;
	if (selected)
	{
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}");
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{1CF1260C-4DD0-4ebb-811F-33C572699FDE}");
	}
	else
	{
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{1CF1260C-4DD0-4ebb-811F-33C572699FDE}");
	}
}

void UITweaksSave::PicturesIcon( bool selected )
{
	if (selected == m_settings.UITweaks.picIcon)
		return;
	if (selected)
	{
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{24ad3ad4-a569-4530-98e1-ab02f9417aa8}");
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3ADD1653-EB32-4cb0-BBD7-DFA0ABB5ACCA}");
	}
	else
	{
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{24ad3ad4-a569-4530-98e1-ab02f9417aa8}");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3ADD1653-EB32-4cb0-BBD7-DFA0ABB5ACCA}");
	}
}

void UITweaksSave::VideosIcon( bool selected )
{
	if (selected == m_settings.UITweaks.videoIcon)
		return;
	if (selected)
	{
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}");
		KeyValue(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A0953C92-50DC-43bf-BE83-3742FED03C9C}");
	}
	else
	{
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}");
		KeyDelete(wxRegKey::HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A0953C92-50DC-43bf-BE83-3742FED03C9C}");
	}
}


void UITweaksSave::ActionCenter( bool selected )
{
	if (selected == m_settings.UITweaks.actionCenter)
		return;
	long value1 = 1;
	long value2 = 0;

	if (selected)
	{
		KeyDelete(wxRegKey::HKCU, "Software\\Policies\\Microsoft\\Windows\\Explorer", "DisableNotificationCenter");
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications", "ToastEnabled");
	}
	else
	{
		KeyValue(wxRegKey::HKCU, "Software\\Policies\\Microsoft\\Windows\\Explorer", "DisableNotificationCenter", value1);
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications", "ToastEnabled", value2);
	}
}

void UITweaksSave::LockScreen( bool selected )
{
	if (selected == m_settings.UITweaks.lockScreen)
		return;
	long value1 = 1;

	if (selected)
		KeyDelete(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\Personalization", "NoLockScreen");
	else
		KeyValue(wxRegKey::HKLM, "Software\\Policies\\Microsoft\\Windows\\Personalization", "NoLockScreen", value1);
}

void UITweaksSave::Autoplay( bool selected )
{
	if (selected == m_settings.UITweaks.autoPlay)
		return;
	long value1 = 1;

	if (selected)
		value1 = 0;

	KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoplayHandlers", "DisableAutoplay", value1);

}

void UITweaksSave::Autorun( bool selected )
{
	if (selected == m_settings.UITweaks.autorun)
		return;
	long value1 = 255;

	if (selected)
		KeyDelete(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", "NoDriveTypeAutoRun");
	else
		KeyValue(wxRegKey::HKCU, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", "NoDriveTypeAutoRun", value1);

}

void UITweaksSave::StickyKeys( bool selected )
{
	if (selected == m_settings.UITweaks.stickyKeys)
		return;
	wxString value1 = "506";

	if (selected)
		value1 = "510";

	KeyValue(wxRegKey::HKCU, "Control Panel\\Accessibility\\StickyKeys", "Flags", value1);
}
