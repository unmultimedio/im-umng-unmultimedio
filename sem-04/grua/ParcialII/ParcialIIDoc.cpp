// ParcialIIDoc.cpp: implementación de la clase CParcialIIDoc
//

#include "stdafx.h"
#include "ParcialII.h"

#include "ParcialIIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CParcialIIDoc

IMPLEMENT_DYNCREATE(CParcialIIDoc, CDocument)

BEGIN_MESSAGE_MAP(CParcialIIDoc, CDocument)
END_MESSAGE_MAP()


// Construcción o destrucción de CParcialIIDoc

CParcialIIDoc::CParcialIIDoc()
{
	// TODO: agregar aquí el código de construcción único

}

CParcialIIDoc::~CParcialIIDoc()
{
}

BOOL CParcialIIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: agregar aquí código de reinicio
	// (los documentos SDI volverán a utilizar este documento)

	return TRUE;
}




// Serialización de CParcialIIDoc

void CParcialIIDoc::Serialize(CArchive& ar)
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


// Diagnósticos de CParcialIIDoc

#ifdef _DEBUG
void CParcialIIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CParcialIIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Comandos de CParcialIIDoc
