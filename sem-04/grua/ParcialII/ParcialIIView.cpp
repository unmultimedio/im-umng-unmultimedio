// ParcialIIView.cpp: implementación de la clase CParcialIIView
//

#include "stdafx.h"
#include "ParcialII.h"

#include "ParcialIIDoc.h"
#include "ParcialIIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CParcialIIView

IMPLEMENT_DYNCREATE(CParcialIIView, CView)

BEGIN_MESSAGE_MAP(CParcialIIView, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_COMMAND(ID_GRUA_DIBUJAR, &CParcialIIView::OnGruaDibujar)
	ON_COMMAND(ID_ROTARSOPORTE_DERECHA, &CParcialIIView::OnRotarsoporteDerecha)
	ON_COMMAND(ID_ROTARSOPORTE_IZQUIERDA, &CParcialIIView::OnRotarsoporteIzquierda)
	ON_COMMAND(ID_ROTARCANASTA_DERECHA, &CParcialIIView::OnRotarcanastaDerecha)
	ON_COMMAND(ID_ROTARCANASTA_IZQUIERDA, &CParcialIIView::OnRotarcanastaIzquierda)
	ON_COMMAND(ID_ELIPSE_DIBUJAR, &CParcialIIView::OnElipseDibujar)
	ON_COMMAND(ID_ELIPSE_CAMBIARCOLOR, &CParcialIIView::OnElipseCambiarcolor)
	ON_COMMAND(ID_FILE_NEW, &CParcialIIView::OnFileNew)
END_MESSAGE_MAP()

// Construcción o destrucción de CParcialIIView

CParcialIIView::CParcialIIView()
{
	opcion=0;
	rs=rc=0;
}

CParcialIIView::~CParcialIIView()
{
}

BOOL CParcialIIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CParcialIIView

void CParcialIIView::OnDraw(CDC* /*pDC*/)
{
	CParcialIIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CParcialIIView

BOOL CParcialIIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CParcialIIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CParcialIIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}


// Diagnósticos de CParcialIIView

#ifdef _DEBUG
void CParcialIIView::AssertValid() const
{
	CView::AssertValid();
}

void CParcialIIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParcialIIDoc* CParcialIIView::GetDocument() const // La versión de no depuración es en línea
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParcialIIDoc)));
	return (CParcialIIDoc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensaje de CParcialIIView

void CParcialIIView::OnPaint()
{
	CPaintDC dc(this); 
	CString own,nuevo;
	own="Julián Rodrigo Figueroa Pedreros - 1200792";
	nuevo="Cree Una Grúa ó una Elipse...";
	dc.TextOutW(5,5,own);

	switch (opcion)
	{
	case 0:
		dc.TextOutW(50,50,nuevo);
		G=false;
		break;
	case 1:
		rs=0;
		Grua.Parte(1);
		Grua.Dibujar(&dc);
		Soporte.Parte(2);
		Soporte.Dibujar(&dc);
		Canasta.Parte(3);
		Canasta.Dibujar(&dc);
		R1.SetCentro(130,310);
		R1.SetBorde(110,310);
		R1.Dibujar(&dc);
		R2.SetCentro(250,310);
		R2.SetBorde(230,310);
		R2.Dibujar(&dc);
		break;
	case 2:
		Soporte.Rotacion(-0.2,&dc);
		Grua.Dibujar(&dc);
		R1.Dibujar(&dc);
		R2.Dibujar(&dc);
		Canasta.Rotacion2(-0.2,rs,&dc,0);
		Canasta.Dibujar(&dc);
		Soporte.Dibujar(&dc);
		break;
	case 3:
		Soporte.Rotacion(0.2,&dc);
		Grua.Dibujar(&dc);
		R1.Dibujar(&dc);
		R2.Dibujar(&dc);
		Canasta.Rotacion2(0.2,rs,&dc,0);
		Canasta.Dibujar(&dc);
		Soporte.Dibujar(&dc);
		break;
	case 4:
		Canasta.Rotacion(-0.2,&dc);
		Grua.Dibujar(&dc);
		R1.Dibujar(&dc);
		R2.Dibujar(&dc);
		Canasta.Dibujar(&dc);
		Soporte.Dibujar(&dc);
		break;
	case 5:
		Canasta.Rotacion(0.2,&dc);
		Grua.Dibujar(&dc);
		R1.Dibujar(&dc);
		R2.Dibujar(&dc);
		Canasta.Dibujar(&dc);
		Soporte.Dibujar(&dc);
		break;
	case 6:
		Canasta.Parte(3);
		if(rs>0)
			Canasta.Rotacion2(-0.2,rs,&dc,1);
		else
			Canasta.Rotacion2(-0.2,rs,&dc,1);
		
		Grua.Dibujar(&dc);
		R1.Dibujar(&dc);
		R2.Dibujar(&dc);
		Canasta.Dibujar(&dc);
		Soporte.Dibujar(&dc);
		break;
	case 7:
		Elipse.Dibujar(&dc);
		G=false;
		break;
	}

}

void CParcialIIView::OnGruaDibujar() 
{
	opcion=1; 
	G=true; 
	Invalidate (true);
}

void CParcialIIView::OnRotarsoporteDerecha() 
{
	if(G)
	{
		rs++;
		if(rs<5&&rs!=-1)
			opcion=2; 
		else{
			rs=0;
			opcion=1;}
		Invalidate (true);
	}
}

void CParcialIIView::OnRotarsoporteIzquierda() 
{
	if(G)
	{
		rs--;
		if(rs>-5&&rs!=1)
			opcion=3; 
		else{
			rs=0;
			opcion=1;}
		Invalidate (true);
	}
}


void CParcialIIView::OnRotarcanastaDerecha()
{
	if(G)
	{
		rc++;
		if(rc==1)
			opcion=6;
		else
		{
			if(rc<7&&rc!=-1)
				opcion=4; 
			else{
				rc=0;
				opcion=6;}
			Invalidate (true);
		}
	}
}

void CParcialIIView::OnRotarcanastaIzquierda()
{
	if(G)
	{
		rc--;
		if(rc==-1)
			opcion=6;
		else
		{
			if(rc>-7&&rc!=1)
				opcion=5; 
			else{
				rc=0;
				opcion=6;}
		}
		Invalidate (true);
	}
}

void CParcialIIView::OnElipseDibujar()
{
	opcion=7;
	Invalidate (true);
}

void CParcialIIView::OnElipseCambiarcolor()
{
	CColorDialog Color;
	Color.DoModal();
	Elipse.SetColor(Color.GetColor());
	opcion=7;
	Invalidate(true);
}

void CParcialIIView::OnFileNew()
{
	opcion=0;
	Invalidate (true);
}
