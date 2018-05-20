/////////////////////////////////////////////////////////////////////////////
// Name:        
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     19/05/2017 00:18:04
// RCS-ID:      
// Copyright:   (C) 2017 Richard W. Allen
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/xrc/xmlres.h"
////@end includes

#include "app_resources.hpp"

////@begin XPM images
////@end XPM images

/*!
 * Resource functions
 */

////@begin AppResources resource functions

/*
 * Menubar creation function for ID_MENUBAR
 */

wxMenuBar* AppResources::CreateMenuMenubar()
{
    return wxXmlResource::Get()->LoadMenuBar(wxT("ID_MENUBAR"));
}

////@end AppResources resource functions

/*!
 * Get bitmap resources
 */

wxBitmap AppResources::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AppResources bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AppResources bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon AppResources::GetIconResource( const wxString& name )
{
    wxUnusedVar(name);
    // Icon retrieval
////@begin AppResources icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AppResources icon retrieval
}
