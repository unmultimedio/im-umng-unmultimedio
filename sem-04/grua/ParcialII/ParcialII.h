// ParcialII.h: archivo de encabezado principal para la aplicación ParcialII
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CParcialIIApp:
// Consulte la sección ParcialII.cpp para obtener información sobre la implementación de esta clase
//

class CParcialIIApp : public CWinApp
{
public:
	CParcialIIApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CParcialIIApp theApp;