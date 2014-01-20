// Khale.h: archivo de encabezado principal para la aplicación Khale
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CKhaleApp:
// Consulte la sección Khale.cpp para obtener información sobre la implementación de esta clase
//

class CKhaleApp : public CWinApp
{
public:
	CKhaleApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKhaleApp theApp;