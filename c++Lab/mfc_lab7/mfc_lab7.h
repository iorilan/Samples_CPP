// mfc_lab7.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmfc_lab7App:
// See mfc_lab7.cpp for the implementation of this class
//

class Cmfc_lab7App : public CWinApp
{
public:
	Cmfc_lab7App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_lab7App theApp;