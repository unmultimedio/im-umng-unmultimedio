
#pragma once
#include "Linea.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Relleno.h"
#include "Poligono.h"

class CParcialIIView : public CView
{
protected: // Crear sólo a partir de serialización
	CParcialIIView();
	DECLARE_DYNCREATE(CParcialIIView)

// Atributos
public:
	CParcialIIDoc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementación
public:
	virtual ~CParcialIIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
	int opcion;
	bool G;
	int rs,rc;
	CPoligono Grua;
	CPoligono Soporte;
	CPoligono Canasta;
	CCirculo R1,R2;
	CElipse Elipse;

public:
	afx_msg void OnPaint();
	afx_msg void OnGruaDibujar();
	afx_msg void OnRotarsoporteDerecha();
	afx_msg void OnRotarsoporteIzquierda();
	afx_msg void OnRotarcanastaDerecha();
	afx_msg void OnRotarcanastaIzquierda();
	afx_msg void OnElipseDibujar();
	afx_msg void OnElipseCambiarcolor();
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // Versión de depuración en ParcialIIView.cpp
inline CParcialIIDoc* CParcialIIView::GetDocument() const
   { return reinterpret_cast<CParcialIIDoc*>(m_pDocument); }
#endif

