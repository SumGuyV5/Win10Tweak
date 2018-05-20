/////////////////////////////////////////////////////////////////////////////
// Name:        SaveBase.cpp
// Purpose:     
// Author:      Richard W. Allen
// Modified by: 
// Created:     11/04/2017 17:45:05
// RCS-ID:      
// Copyright:   Richard W. Allen 2017
// Licence:     GPL 2
/////////////////////////////////////////////////////////////////////////////
#include "SaveBase.hpp"

#include "../win10tweakapp.hpp"

#include <wx/regex.h>

SaveBase::SaveBase()
{
}


SaveBase::~SaveBase()
{
}


//////////////////////////////////////////////////////////////////////////
///Protected
//////////////////////////////////////////////////////////////////////////
void SaveBase::KillTask(wxString exe)
{
	wxArrayString output;
	wxString str;
	str.Printf("TASKLIST /FI \"imagename eq %S \"", exe);
	if (Execute(str, output))
	{
		for (unsigned int count = 0; count < output.GetCount(); count++)
		{
			wxString tmp = output.Item(count);
			int t = tmp.Find(exe);
			if (t > -1)
			{
				wxRegEx rePID(wxString("[ 0-9 ]+"));
				bool val = rePID.IsValid();
				bool mach = rePID.Matches(tmp);
				long t = rePID.GetMatchCount();
				if (mach)
				{
					wxString PID = rePID.GetMatch(tmp, 0);
					long kill = 0;
					PID.ToLong(&kill);
					wxKill(kill);
				}
			}
		}
	}
}

void SaveBase::KeyValue( wxRegKey::StdKey type, wxString key, wxString value, long set )
{
	wxRegKey reg(type, key, wxGetApp().GetArchMode());
	if (!reg.Exists())
		reg.Create();

	reg.SetValue(value, set);
}

void SaveBase::KeyValue( wxRegKey::StdKey type, wxString key, wxString value /*= ""*/, wxString set /*= ""*/ )
{
	wxRegKey reg(type, key, wxGetApp().GetArchMode());
	if (!reg.Exists())
		reg.Create();
	if (!value.IsEmpty())
		reg.SetValue(value, set);
}

void SaveBase::KeyDelete( wxRegKey::StdKey type, wxString key, wxString value /*= ""*/ )
{
	wxRegKey reg(type, key, wxGetApp().GetArchMode());
	if (reg.Exists())
	{
		if (value.IsEmpty())
		{
			reg.DeleteSelf();
			if (reg.Exists())
				BackupDelete(reg.GetName());
		}
		else
			reg.DeleteValue(value);
	}
}

void SaveBase::Setting( wxString value, bool start )
{
	wxString disableStr = "sc config " + value + " start=";
	wxString serviceStr = "sc ";

	if (start)
	{
		disableStr += "auto";
		serviceStr += " start " + value;
	}
	else
	{
		disableStr += "disable";
		serviceStr += " stop " + value;
	}
	
	Execute(disableStr);
	Execute(serviceStr);
}

//////////////////////////////////////////////////////////////////////////
///Private
//////////////////////////////////////////////////////////////////////////
void SaveBase::BackupDelete( wxString key )
{
	Execute("REG DELETE " + key + " /f /reg:" + wxGetApp().GetArchStr());
}