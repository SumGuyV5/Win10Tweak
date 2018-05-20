/////////////////////////////////////////////////////////////////////////////
// Name:        Settings.hpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#pragma once
struct Settings
{
	// Privacy Settings
	struct Privacy
	{
		bool telemetry = false;
		bool wifiSense = false;
		bool smartScreen = false;
		bool bingSearch = false;
		bool locationTracking = false;
		bool feedback = false;
		bool adID = false;
		bool cortana = false;
		bool autoLogger = false;
		bool diagnostics = false;
		bool wapPush = false;

		bool winUpdateP2P = false;
	} Privacy;	

	// Service Tweaks
	struct ServiceTweaks
	{
		bool sharingMap = false;
		bool firewall = false;
		bool winDefender = false;
		bool winUpdateRest = false;
		bool homeGroups = false;
		bool remoteAss = false;
		bool remoteDesktop = false;

		bool uacRasie = false;
	} ServiceTweaks;	

	// UI Tweaks
	struct UITweaks
	{
		bool searchButton = false;
		bool taskView = false;
		bool largeIcons = false;
		bool showTitles = false;
		bool alltrayIcons = false;
		bool knownFileExt = false;
		bool hiddenFiles = false;
		bool changeDefault = false;
		bool computerShortcut = false;

		bool desktopIcon = false;
		bool docIcon = false;
		bool downIcon = false;
		bool musicIcon = false;
		bool picIcon = false;
		bool videoIcon = false;

		bool actionCenter = false;
		bool lockScreen = false;
		bool autoPlay = false;
		bool autorun = false;
		bool stickyKeys = false;
	} UITweaks;
	
	// Remove applications
	struct RemoveApp
	{
		bool onedrive = false;
		bool windowsMediaPlayer = false;
		bool workFoldersClient = false;
	} RemoveApp;
};

