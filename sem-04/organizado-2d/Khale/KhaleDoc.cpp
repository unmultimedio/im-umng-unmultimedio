// KhaleDoc.cpp: implementación de la clase CKhaleDoc
//

#include "stdafx.h"
#include "Khale.h"

#include "KhaleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKhaleDoc

IMPLEMENT_DYNCREATE(CKhaleDoc, CDocument)

BEGIN_MESSAGE_MAP(CKhaleDoc, CDocument)
END_MESSAGE_MAP()


// Construcción o destrucción de CKhaleDoc

CKhaleDoc::CKhaleDoc()
{
	// TODO: agregar aquí el código de construcción único

}

CKhaleDoc::~CKhaleDoc()
{
}

BOOL CKhaleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: agregar aquí código de reinicio
	// (los documentos SDI volverán a utilizar este documento)

	return TRUE;
}




// Serialización de CKhaleDoc

void CKhaleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: agregar aquí el código de almacenamiento
	}
	else
	{
		// TODO: agregar aquí el código de carga
	}
}


// Diagnósticos de CKhaleDoc

#ifdef _DEBUG
void CKhaleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKhaleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Comandos de CKhaleDoc
