// KhaleView.h: interfaz de la clase CKhaleView
//


#pragma once
#include "Linea.h"
#include "PoliLinea.h"
#include "MultiLinea.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Relleno.h"
#include "Poligono.h"
#include "Datos.h"
#include "DatGrafica.h"
#include "Grafica.h"
#include "ViewPort.h"
#include "Articulacion.h"

class CKhaleView : public CView
{
protected: // Crear sólo a partir de serialización
	CKhaleView();
	DECLARE_DYNCREATE(CKhaleView)

// Atributos
public:
	CKhaleDoc* GetDocument() const;

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
	virtual ~CKhaleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool VP,Brazo,Cuerpo;
	int Opcion,rh,rc,rm,x1,x2,y1,y2,RH,RC,RM,RI,RR,RT;
	CRelleno Relleno;
	CLinea Linea,LineaRec;
	CMultiLinea MultiLinea;
	CPoliLinea PoliLinea;
	CCirculo Circulo;
	CElipse Elipse;
	CPoligono Poligono;
	CDatos DatosDlg;
	CDatGrafica DatGr;
	CPoligono Biceps,Antebrazo,Mano,Torso;
	CCirculo Hombro,Codo,Muñeca,Hd,Hi,Cd,Ci,Md,Mi,Id,Ii,Rd,Ri,Td,Ti,Cab;
	CGrafica Grafica;
	CViewPort Puerto;
	CArticulacion BicD,BicI,AntD,AntI,ManD,ManI,MusD,MusI,PanD,PanI,PieD,PieI;

public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLineaDda();
	afx_msg void OnLineaBressenham();
	afx_msg void OnLineaPunteada();
	afx_msg void OnCirculoCartesiano();
	afx_msg void OnCirculoPolar();
	afx_msg void OnCirculoBressenham();
	afx_msg void OnElipsePolar();
	afx_msg void OnElipseBressenham();
	afx_msg void OnLineaMultipleslineas();
	afx_msg void OnPoliLinea();
	afx_msg void OnColoresLinea();
	afx_msg void OnColoresRelleno();
	afx_msg void OnPoligonoFijo();
	afx_msg void OnPoligonoPuntos();
	afx_msg void OnTransformacionesTraslacion();
	afx_msg void OnTransformacionesEscalamiento();
	afx_msg void OnTransformacionesRotacion();
	afx_msg void OnTransformacionesDatos();
	afx_msg void OnRellenoFrontera();
	afx_msg void OnBrazoCrear();
	afx_msg void OnHombroArriba();
	afx_msg void OnHombroAbajo();
	afx_msg void OnCodoArriba();
	afx_msg void OnCodoAbajo();
	afx_msg void OnMu32814();
	afx_msg void OnMu32815();
	afx_msg void OnGraficasSeno();
	afx_msg void OnGraficasEscalas();
	afx_msg void OnGraficasNuevavac32819();
	afx_msg void OnViewportNuevopuerto();
	afx_msg void OnHombreNuevo();
	afx_msg void OnHombroArriba32827();
	afx_msg void OnHombroAbajo32832();
	afx_msg void OnCodoArriba32829();
	afx_msg void OnCodoAbajo32833();
	afx_msg void OnMuArriba();
	afx_msg void OnMuAbajo();
	afx_msg void OnCaderaArriba();
	afx_msg void OnCaderaAbajo();
	afx_msg void OnRodillaArriba();
	afx_msg void OnRodillaAbajo();
	afx_msg void OnTobilloArriba();
	afx_msg void OnTobilloAbajo();
};

#ifndef _DEBUG  // Versión de depuración en KhaleView.cpp
inline CKhaleDoc* CKhaleView::GetDocument() const
   { return reinterpret_cast<CKhaleDoc*>(m_pDocument); }
#endif

