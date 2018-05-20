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

#ifndef _APP_RESOURCES_H_
#define _APP_RESOURCES_H_

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

class AppResources
{
public:
    AppResources() {}

/*!
 * Resource functions
 */

////@begin AppResources resource functions
    /// Menubar creation function for ID_MENUBAR
    static wxMenuBar* CreateMenuMenubar();

    /// Retrieves bitmap resources
    static wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    static wxIcon GetIconResource( const wxString& name );
////@end AppResources resource functions

};

#endif
    // _APP_RESOURCES_H_
