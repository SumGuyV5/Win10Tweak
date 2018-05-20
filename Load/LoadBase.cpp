/////////////////////////////////////////////////////////////////////////////
// Name:        LoadBase.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "LoadBase.hpp"

#include "../win10tweakapp.hpp"

LoadBase::LoadBase()
	: m_tweak(*wxGetApp().GetWindow())
{
}


LoadBase::~LoadBase()
{
}

//////////////////////////////////////////////////////////////////////////
///Protected
//////////////////////////////////////////////////////////////////////////
long LoadBase::KeyValue(wxRegKey::StdKey type, wxString key, wxString value /*= ""*/)
{
	wxRegKey reg(type, key, wxGetApp().GetArchMode());

	long rtn = -1;

	if (reg.Exists())
	{
		if (value.IsEmpty())
			rtn = -2;
		else
		{
			if (reg.HasValue(value))
				reg.QueryValue(value, &rtn);
		}
	}

	return rtn;
}

wxString LoadBase::KeyString(wxRegKey::StdKey type, wxString key, wxString value)
{
	wxRegKey reg(type, key, wxGetApp().GetArchMode());

	wxString rtn = "";

	if (reg.Exists())
	{
		if (reg.HasValue(value))
			reg.QueryValue(value, rtn, false);

	}
	
	return rtn;
}

bool LoadBase::Query(wxString value, wxString look)
{
	bool rtn = false;
	wxArrayString output;

	if (Execute(value, output))
	{
		for (unsigned int count = 0; count < output.GetCount(); count++)
		{
			wxString tmp = output.Item(count);
			int t = tmp.Find(look);
			if (t != wxNOT_FOUND)
				rtn = true;
		}
	}
	
	return rtn;
}