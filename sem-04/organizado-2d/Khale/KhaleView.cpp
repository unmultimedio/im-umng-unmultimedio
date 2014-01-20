// KhaleView.cpp: implementación de la clase CKhaleView
//

#include "stdafx.h"
#include "Khale.h"

#include "KhaleDoc.h"
#include "KhaleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKhaleView

IMPLEMENT_DYNCREATE(CKhaleView, CView)

BEGIN_MESSAGE_MAP(CKhaleView, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_LINEA_DDA, &CKhaleView::OnLineaDda)
	ON_COMMAND(ID_LINEA_BRESSENHAM, &CKhaleView::OnLineaBressenham)
	ON_COMMAND(ID_LINEA_PUNTEADA, &CKhaleView::OnLineaPunteada)
	ON_COMMAND(ID_CIRCULO_CARTESIANO, &CKhaleView::OnCirculoCartesiano)
	ON_COMMAND(ID_CIRCULO_POLAR, &CKhaleView::OnCirculoPolar)
	ON_COMMAND(ID_CIRCULO_BRESSENHAM, &CKhaleView::OnCirculoBressenham)
	ON_COMMAND(ID_ELIPSE_POLAR, &CKhaleView::OnElipsePolar)
	ON_COMMAND(ID_ELIPSE_BRESSENHAM, &CKhaleView::OnElipseBressenham)
	ON_COMMAND(ID_LINEA_MULTIPLESLINEAS, &CKhaleView::OnLineaMultipleslineas)
	ON_COMMAND(ID_POLILINEA, &CKhaleView::OnPoliLinea)
	ON_COMMAND(ID_COLORES_LINEA, &CKhaleView::OnColoresLinea)
	ON_COMMAND(ID_COLORES_RELLENO, &CKhaleView::OnColoresRelleno)
	ON_COMMAND(ID_POL32790, &CKhaleView::OnPoligonoFijo)
	ON_COMMAND(ID_POL32791, &CKhaleView::OnPoligonoPuntos)
	ON_COMMAND(ID_TRANSFORMACIONES_TRASLACI32793, &CKhaleView::OnTransformacionesTraslacion)
	ON_COMMAND(ID_TRANSFORMACIONES_ESCALAMIENTO, &CKhaleView::OnTransformacionesEscalamiento)
	ON_COMMAND(ID_TRANSFORMACIONES_ROTACION, &CKhaleView::OnTransformacionesRotacion)
	ON_COMMAND(ID_TRANSFORMACIONES_DATOS, &CKhaleView::OnTransformacionesDatos)
	ON_COMMAND(ID_RELLENO_FRONTERA, &CKhaleView::OnRellenoFrontera)
	ON_COMMAND(ID_BRAZO_CREAR, &CKhaleView::OnBrazoCrear)
	ON_COMMAND(ID_HOMBRO_ARRIBA, &CKhaleView::OnHombroArriba)
	ON_COMMAND(ID_HOMBRO_ABAJO, &CKhaleView::OnHombroAbajo)
	ON_COMMAND(ID_CODO_ARRIBA, &CKhaleView::OnCodoArriba)
	ON_COMMAND(ID_CODO_ABAJO, &CKhaleView::OnCodoAbajo)
	ON_COMMAND(ID_MU32814, &CKhaleView::OnMu32814)
	ON_COMMAND(ID_MU32815, &CKhaleView::OnMu32815)
	ON_COMMAND(ID_GRAFICAS_SENO, &CKhaleView::OnGraficasSeno)
	ON_COMMAND(ID_GRAFICAS_ESCALAS, &CKhaleView::OnGraficasEscalas)
	ON_COMMAND(ID_GRAFICAS_NUEVAVAC32819, &CKhaleView::OnGraficasNuevavac32819)
	ON_COMMAND(ID_VIEWPORT_NUEVOPUERTO, &CKhaleView::OnViewportNuevopuerto)
	ON_COMMAND(ID_HOMBRE_NUEVO, &CKhaleView::OnHombreNuevo)
	ON_COMMAND(ID_HOMBRO_ARRIBA32827, &CKhaleView::OnHombroArriba32827)
	ON_COMMAND(ID_HOMBRO_ABAJO32832, &CKhaleView::OnHombroAbajo32832)
	ON_COMMAND(ID_CODO_ARRIBA32829, &CKhaleView::OnCodoArriba32829)
	ON_COMMAND(ID_CODO_ABAJO32833, &CKhaleView::OnCodoAbajo32833)
	ON_COMMAND(ID_MU32831, &CKhaleView::OnMuArriba)
	ON_COMMAND(ID_MU32834, &CKhaleView::OnMuAbajo)
	ON_COMMAND(ID_CADERA_ARRIBA, &CKhaleView::OnCaderaArriba)
	ON_COMMAND(ID_CADERA_ABAJO, &CKhaleView::OnCaderaAbajo)
	ON_COMMAND(ID_RODILLA_ARRIBA, &CKhaleView::OnRodillaArriba)
	ON_COMMAND(ID_RODILLA_ABAJO, &CKhaleView::OnRodillaAbajo)
	ON_COMMAND(ID_TOBILLO_ARRIBA, &CKhaleView::OnTobilloArriba)
	ON_COMMAND(ID_TOBILLO_ABAJO, &CKhaleView::OnTobilloAbajo)
END_MESSAGE_MAP()

// Construcción o destrucción de CKhaleView

CKhaleView::CKhaleView()
{
	// TODO: agregar aquí el código de construcción
	Opcion=0;
	VP=false;
	Brazo=false;
	Cuerpo=false;
	rh=rc=rm=0;
	x1=x2=y1=y2=0;
	RH=RC=RM=RI=RR=RT=0;
	LineaRec.SetColor(RGB(0,50,200));
}

CKhaleView::~CKhaleView()
{
}

BOOL CKhaleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CKhaleView

void CKhaleView::OnDraw(CDC* /*pDC*/)
{
	CKhaleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CKhaleView

BOOL CKhaleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CKhaleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CKhaleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}


// Diagnósticos de CKhaleView

#ifdef _DEBUG
void CKhaleView::AssertValid() const
{
	CView::AssertValid();
}

void CKhaleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKhaleDoc* CKhaleView::GetDocument() const // La versión de no depuración es en línea
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKhaleDoc)));
	return (CKhaleDoc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensaje de CKhaleView

void CKhaleView::OnPaint()
{
	CPaintDC dc(this); 
	CRect rect;
	CString own,c10,cr,lvp;
	own="Julián";
	c10="*Doble Click Para Cerrar";
	cr="*Click Medio Para Rellenar";
	lvp="Dibuje una línea para cortar por el puerto";
	dc.TextOutW(5,5,own);

	if(Opcion!=9)
		MultiLinea.Nuevo();
	if(Opcion!=10)
		PoliLinea.Nuevo();
	switch(Opcion)
	{
	case 1:
		Linea.DDA(&dc);
		break;
	case 2:
		Linea.Bressenham(&dc);
		break;
	case 3:
		Linea.Punteada(&dc);
		break;
	case 4:
		dc.TextOutW(5,25,cr);
		Circulo.Cartesiano(&dc);
		break;
	case 5:
		dc.TextOutW(5,25,cr);
		Circulo.Polar(&dc);
		break;
	case 6:
		dc.TextOutW(5,25,cr);
		Circulo.Bressenham(&dc);
		break;
	case 7:
		dc.TextOutW(5,25,cr);
		Elipse.Polar(&dc);
		break;
	case 8:
		dc.TextOutW(5,25,cr);
		Elipse.Bressenham(&dc);
		break;
	case 9:
		dc.TextOutW(5,25,cr);
		if(VP==true)
			Linea.DDA(&dc);
		MultiLinea.Dibuje(&dc);
		break;
	case 10:
		dc.TextOutW(5,25,cr);
		dc.TextOutW(5,45,c10);
		if(VP==true)
			Linea.DDA(&dc);
		PoliLinea.Dibuje(&dc);
		break;
	case 11:
		GetClientRect (rect);
		Poligono.SetTamaño(rect.Width(),rect.Height());
		Poligono.SetPiv();
		Poligono.Dibujar(&dc);
		break;
	case 12:
		if(VP)
			Linea.DDA(&dc);
		Poligono.SetPiv();
		Poligono.Dibujar(&dc);
		break;
	case 13:
		Poligono.SetPiv();
		Poligono.Traslacion(&dc);
		break;
	case 14:
		Poligono.SetPiv();
		Poligono.Escalamiento(&dc);
		break;
	case 15:
		Poligono.SetPiv();
		Poligono.Rotacion(&dc);
		break;
	case 16:
		Poligono.Dibujar(&dc);
		break;
	case 17:
		Brazo=true;
		Biceps.Crear(1,&dc);
		Antebrazo.Crear(2,&dc);
		Mano.Crear(3,&dc);
		Hombro.SetCentro(Biceps.piv);
		Hombro.SetBorde(Biceps.piv.x+10,Biceps.piv.y);
		Codo.SetCentro(Antebrazo.piv);
		Codo.SetBorde(Antebrazo.piv.x+10,Antebrazo.piv.y);
		Muñeca.SetCentro(Mano.piv);
		Muñeca.SetBorde(Mano.piv.x+10,Mano.piv.y);
		Hombro.Cartesiano(&dc);
		Codo.Cartesiano(&dc);
		Muñeca.Cartesiano(&dc);
		rh=rc=rm=0;
		break;
	case 18:
		Biceps.Dibujar(&dc);
		Antebrazo.Dibujar(&dc);
		Mano.Dibujar(&dc);
		Muñeca.Cartesiano(&dc);
		Codo.Cartesiano(&dc);
		Hombro.Cartesiano(&dc);
		break;
	case 19:
		GetClientRect (rect);
		Grafica.SetAncho(rect.Width());
		Grafica.SetAlto(rect.Height());
		Grafica.PintarPlano(&dc);
		break;
	case 20:
		GetClientRect (rect);
		Grafica.SetAncho(rect.Width());
		Grafica.SetAlto(rect.Height());
		Grafica.PintarPlano(&dc);
		Grafica.Seno(&dc);
		break;
	case 21:
		LineaRec.SetPtoI(LineaRec.GetPtoFx(),LineaRec.GetPtoFy());
		Puerto.Tama(0,0);
		if(VP)
		{
			GetClientRect (rect);
			Puerto.Tama(rect.Width(),rect.Height());
		}
		Puerto.DibujarVP(&dc);
		break;
	case 22:
		if(VP)
			LineaRec.DDA(&dc);
		GetClientRect (rect);
		Puerto.Tama(rect.Width(),rect.Height());
		Puerto.DibujarVP(&dc);
		if(!VP)
		{
			dc.TextOutW(5,25,lvp);
			x1=LineaRec.GetPtoIx();
			x2=LineaRec.GetPtoFx();
			y1=LineaRec.GetPtoIy();
			y2=LineaRec.GetPtoFy();
			Puerto.CalcRecorte(x1,y1,x2,y2,&dc);
		}
		break;
	case 23:
		Cuerpo=true;
		RH=RC=RM=RI=RR=RT=0;
		BicD.Parte(1,true);BicI.Parte(1,false);
		AntD.Parte(2,true);AntI.Parte(2,false);
		ManD.Parte(3,true);ManI.Parte(3,false);
		MusD.Parte(4,true);MusI.Parte(4,false);
		PanD.Parte(5,true);PanI.Parte(5,false);
		PieD.Parte(6,true);PieI.Parte(6,false);
		Opcion=24;
		Invalidate(true);
		break;
	case 24:
		Torso.Crear(4,&dc);
		Cab.SetCentro(400,160);Cab.SetRadio(20);Cab.Cartesiano(&dc);
		Hd.SetCentro(BicD.GetPiv());Hd.SetRadio(15);Hd.Cartesiano(&dc);
		Hi.SetCentro(BicI.GetPiv());Hi.SetRadio(15);Hi.Cartesiano(&dc);
		Cd.SetCentro(AntD.GetPiv());Cd.SetRadio(10);Cd.Cartesiano(&dc);
		Ci.SetCentro(AntI.GetPiv());Ci.SetRadio(10);Ci.Cartesiano(&dc);
		Md.SetCentro(ManD.GetPiv());Md.SetRadio(8);Md.Cartesiano(&dc);
		Mi.SetCentro(ManI.GetPiv());Mi.SetRadio(8);Mi.Cartesiano(&dc);
		Id.SetCentro(MusD.GetPiv());Id.SetRadio(15);Id.Cartesiano(&dc);
		Ii.SetCentro(MusI.GetPiv());Ii.SetRadio(15);Ii.Cartesiano(&dc);
		Rd.SetCentro(PanD.GetPiv());Rd.SetRadio(10);Rd.Cartesiano(&dc);
		Ri.SetCentro(PanI.GetPiv());Ri.SetRadio(10);Ri.Cartesiano(&dc);
		Td.SetCentro(PieD.GetPiv());Td.SetRadio(8);Td.Cartesiano(&dc);
		Ti.SetCentro(PieI.GetPiv());Ti.SetRadio(8);Ti.Cartesiano(&dc);
		BicD.Dibujar(&dc);
		BicI.Dibujar(&dc);
		AntD.Dibujar(&dc);
		AntI.Dibujar(&dc);
		ManD.Dibujar(&dc);
		ManI.Dibujar(&dc);
		MusD.Dibujar(&dc);
		MusI.Dibujar(&dc);
		PanD.Dibujar(&dc);
		PanI.Dibujar(&dc);
		PieD.Dibujar(&dc);
		PieI.Dibujar(&dc);
		break;
	}
	if((Opcion!=17)&&(Opcion!=18))
		Brazo=false;
	if((Opcion!=23)&&(Opcion!=24))
		Cuerpo=false;
}

void CKhaleView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if(Opcion==10)
	{
		PoliLinea.Cerrar(&dc);
		VP=false;
	}
	Invalidate(true);
	CView::OnLButtonDblClk(nFlags, point);
}

void CKhaleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	switch(Opcion)
	{
	case 1:case 2:case 3:case 9:
		Linea.SetPtoI(point);
		break;
	case 4:case 5:case 6:
		Circulo.SetCentro(point);
		break;
	case 7:case 8:
		Elipse.SetPtoI(point);
		break;
	case 10:
		Linea.SetPtoI(point);
		PoliLinea.SetPunto(point);
		break;
	case 12:
		Linea.SetPtoI(point);
		Poligono.SetPunto(point);
		break;
	case 13:
		Poligono.ux=Poligono.uy=0;
		Poligono.pf=Poligono.pi=0;
		Poligono.SetT1(point);
		break;
	case 14:
		Poligono.ux=Poligono.uy=10;
		Poligono.pf=Poligono.pi=0;
		Poligono.SetT1(point);
		break;
	case 15:
		Poligono.ut=0;
		Poligono.pf=Poligono.pi=0;
		Poligono.SetT1(point);
		break;
	case 21:
		Puerto.SetP1(point);
		break;
	case 22:
		LineaRec.SetPtoI(point);
		break;
	}
	VP=true;
	CView::OnLButtonDown(nFlags, point);
}

void CKhaleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	switch(Opcion)
	{
	case 1:case 2:case 3:
		Linea.SetPtoF(point);
		break;
	case 4:case 5:case 6:
		Circulo.SetBorde(point);
		break;
	case 7:case 8:
		Elipse.SetPtoF(point);
		break;
	case 9:
		Linea.SetPtoF(point);
		MultiLinea.Sumar(Linea);
		break;
	case 10:
		Linea.SetPtoI(point);
		PoliLinea.SetPunto(point);
		break;
	case 13:case 14:case 15:
		Poligono.SetT2(point);
		break;
	case 16:
		Relleno.SetPtoRelleno(point);
		Relleno.Frontera(&dc);
		break;
	case 21:
		Puerto.SetP2(point);
		Puerto.SetLim();
		Opcion=22;
		break;
	case 22:
		LineaRec.SetPtoF(point);
		break;
	}
	if(Opcion!=10)
		VP=false;
	if(Opcion!=16)
		Invalidate (true);
	CView::OnLButtonUp(nFlags, point);
}

void CKhaleView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(VP==true)
	{
		switch(Opcion)
		{
		case 1:case 2:case 3:case 9:case 10:case 12:
			Linea.SetPtoF(point);
			break;
		case 4:case 5:case 6:
			Circulo.SetBorde(point);
			break;
		case 7:case 8:
			Elipse.SetPtoF(point);
			break;
		case 13:case 14:case 15:
			Poligono.SetT2(point);
			break;
		case 21:
			Puerto.SetP2(point);
			break;
		case 22:
			LineaRec.SetPtoF(point);
			break;
		}
		Invalidate (true);
	}
	CView::OnMouseMove(nFlags, point);
}

void CKhaleView::OnMButtonUp(UINT nFlags, CPoint point)
{
	if ((Opcion>3)&&(Opcion<11)&&(Relleno.cr!=RGB(255,255,255)))
	{
		CClientDC dc(this);
		Relleno.SetPtoRelleno(point);
		Relleno.Vecindad4(&dc);
	}
	Invalidate (false);
	CView::OnMButtonUp(nFlags, point);
}

void CKhaleView::OnLineaDda(){Opcion=1;}
void CKhaleView::OnLineaBressenham(){Opcion=2;}
void CKhaleView::OnLineaPunteada(){Opcion=3;}
void CKhaleView::OnCirculoCartesiano(){Opcion=4;}
void CKhaleView::OnCirculoPolar(){Opcion=5;}
void CKhaleView::OnCirculoBressenham(){Opcion=6;}
void CKhaleView::OnElipsePolar(){Opcion=7;}
void CKhaleView::OnElipseBressenham(){Opcion=8;}
void CKhaleView::OnLineaMultipleslineas(){Opcion=9;}
void CKhaleView::OnPoliLinea(){Opcion=10;}
void CKhaleView::OnPoligonoFijo(){Opcion=11; Poligono.SetFijo(true);}
void CKhaleView::OnPoligonoPuntos(){Opcion=12; Poligono.SetFijo(false);}
void CKhaleView::OnTransformacionesTraslacion(){Opcion=13;}
void CKhaleView::OnTransformacionesEscalamiento(){Opcion=14;}
void CKhaleView::OnTransformacionesRotacion(){Opcion=15;}
void CKhaleView::OnRellenoFrontera(){Opcion=16;}
void CKhaleView::OnBrazoCrear(){Opcion=17;Invalidate(true);}
void CKhaleView::OnGraficasEscalas()
{
	if((Opcion==19)||(Opcion==20))
	{
		float x,y;
		DatGr.DoModal();
		x=DatGr.sx;
		y=DatGr.sy;
		Grafica.SetEsc(x,y);
	}
	Invalidate(true);
}
void CKhaleView::OnGraficasSeno(){Opcion=20;Invalidate(true);}
void CKhaleView::OnViewportNuevopuerto()
{
	Puerto.Nuevo();
	Opcion=21;
	Invalidate(true);
}
void CKhaleView::OnTransformacionesDatos()
{
	CClientDC dc(this);
	float tx,ty,theta;
	double sx,sy,Mat[3][3];
	bool rx,ry;
	DatosDlg.DoModal();
	tx=DatosDlg.Tx;
	ty=-DatosDlg.Ty;
	sx=DatosDlg.Sx;
	sy=DatosDlg.Sy;
	rx=DatosDlg.Rx;
	ry=DatosDlg.Ry;
	Mat[0][0]=DatosDlg.p11;
	Mat[0][1]=DatosDlg.p21;
	Mat[0][2]=DatosDlg.p31;
	Mat[1][0]=DatosDlg.p12;
	Mat[1][1]=DatosDlg.p22;
	Mat[1][2]=DatosDlg.p32;
	Mat[2][0]=DatosDlg.p13;
	Mat[2][1]=DatosDlg.p23;
	Mat[2][2]=DatosDlg.p33;
	theta=DatosDlg.Theta;
	Poligono.Traslacion(tx,ty,&dc);
	Poligono.Escalamiento(sx,sy,&dc);
	Poligono.Rotacion(theta,&dc);
	Poligono.Reflexión(rx,ry,&dc);
	Poligono.TransLibres(Mat,&dc);
	Invalidate(false);
}
void CKhaleView::OnColoresLinea()
{	
	CColorDialog Color;
	Color.DoModal();
	switch(Opcion)
	{
	case 1:case 2:case 3:
		Linea.SetColor(Color.GetColor());
		break;
	case 4:case 5:case 6:
		Circulo.SetColor(Color.GetColor());
		break;
	case 7:case 8:
		Elipse.SetColor(Color.GetColor());
		break;
	case 9:
		Linea.SetColor(Color.GetColor());
		MultiLinea.SetColor(Color.GetColor());
		break;
	case 10:
		Linea.SetColor(Color.GetColor());
		PoliLinea.SetColor(Color.GetColor());
		break;
	case 11:case 12:
		Poligono.SetColor(Color.GetColor());
		break;
	}
}

void CKhaleView::OnColoresRelleno()
{
	CColorDialog R;
	COLORREF Rel;
	R.DoModal();
	Rel=R.GetColor();
	Relleno.SetColorRelleno(Rel);
}


void CKhaleView::OnHombroArriba()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp,xxp,yyp;
	CPoint ptc,ptm;
	Err="Por Favor Cree Primero El Brazo.";
	if(Brazo==true)
	{
		rh--;
		if(rh==-9)
			rh=0;
		if(rh!=0)
		{
			xp=(Biceps.piv.x)+((170-Biceps.piv.x)*(cos(0.2*rh)))-((130-Biceps.piv.y)*(sin(0.2*rh)));
			yp=(Biceps.piv.y)+((170-Biceps.piv.x)*(sin(0.2*rh)))+((130-Biceps.piv.y)*(cos(0.2*rh)));
			ptc.x=xp; ptc.y=yp;
			Codo.SetCentro(ptc);
			Codo.SetBorde(ptc.x+10,ptc.y);
			xp=(Biceps.piv.x)+((250-Biceps.piv.x)*(cos(0.2*rh)))-((130-Biceps.piv.y)*(sin(0.2*rh)));
			yp=(Biceps.piv.y)+((250-Biceps.piv.x)*(sin(0.2*rh)))+((130-Biceps.piv.y)*(cos(0.2*rh)));
			xxp=(Antebrazo.piv.x)+((xp-Antebrazo.piv.x)*(cos(0.2*rc)))-((yp-Antebrazo.piv.y)*(sin(0.2*rc)));
			yyp=(Antebrazo.piv.y)+((xp-Antebrazo.piv.x)*(sin(0.2*rc)))+((yp-Antebrazo.piv.y)*(cos(0.2*rc)));
			ptm.x=xxp; ptm.y=yyp;
			Muñeca.SetCentro(ptm);
			Muñeca.SetBorde(ptm.x+10,ptm.y);
			Mano.piv=Antebrazo.piv=Biceps.piv;
			Biceps.Rotacion(0.2,&dc);
			Antebrazo.Rotacion(0.2,&dc);
			Mano.Rotacion(0.2,&dc);
			Antebrazo.SetPiv(ptc);
			Mano.SetPiv(ptm);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnHombroAbajo()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp,xxp,yyp;
	CPoint ptc,ptm;
	Err="Por Favor Cree Primero El Brazo.";	
	if(Brazo==true)
	{
		rh++;
		if(rh==9)
			rh=0;
		if(rh!=0)
		{
			xp=(Biceps.piv.x)+((170-Biceps.piv.x)*(cos(0.2*rh)))-((130-Biceps.piv.y)*(sin(0.2*rh)));
			yp=(Biceps.piv.y)+((170-Biceps.piv.x)*(sin(0.2*rh)))+((130-Biceps.piv.y)*(cos(0.2*rh)));
			ptc.x=xp; ptc.y=yp;
			Codo.SetCentro(ptc);
			Codo.SetBorde(ptc.x+10,ptc.y);
			xp=(Biceps.piv.x)+((250-Biceps.piv.x)*(cos(0.2*rh)))-((130-Biceps.piv.y)*(sin(0.2*rh)));
			yp=(Biceps.piv.y)+((250-Biceps.piv.x)*(sin(0.2*rh)))+((130-Biceps.piv.y)*(cos(0.2*rh)));
			xxp=(Antebrazo.piv.x)+((xp-Antebrazo.piv.x)*(cos(0.2*rc)))-((yp-Antebrazo.piv.y)*(sin(0.2*rc)));
			yyp=(Antebrazo.piv.y)+((xp-Antebrazo.piv.x)*(sin(0.2*rc)))+((yp-Antebrazo.piv.y)*(cos(0.2*rc)));
			ptm.x=xxp; ptm.y=yyp;
			Muñeca.SetCentro(ptm);
			Muñeca.SetBorde(ptm.x+10,ptm.y);
			Mano.piv=Antebrazo.piv=Biceps.piv;
			Biceps.Rotacion(-0.2,&dc);
			Antebrazo.Rotacion(-0.2,&dc);
			Mano.Rotacion(-0.2,&dc);
			Antebrazo.SetPiv(ptc);
			Mano.SetPiv(ptm);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCodoArriba()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp;
	CPoint ptc,ptm;
	Err="Por Favor Cree Primero El Brazo.";	
	if(Brazo==true)
	{
		rc--;
		if(rc==-9)
			rc=0;
		if(rc!=0)
		{
			xp=(Antebrazo.piv.x)+((Muñeca.c.x-Antebrazo.piv.x)*(cos(-0.2)))-((Muñeca.c.y-Antebrazo.piv.y)*(sin(-0.2)));
			yp=(Antebrazo.piv.y)+((Muñeca.c.x-Antebrazo.piv.x)*(sin(-0.2)))+((Muñeca.c.y-Antebrazo.piv.y)*(cos(-0.2)));
			ptm.x=xp; ptm.y=yp;
			Muñeca.SetCentro(ptm);
			Muñeca.SetBorde(ptm.x+10,ptm.y);
			Mano.piv=Antebrazo.piv;
			Antebrazo.Rotacion(0.2,&dc);
			Mano.Rotacion(0.2,&dc);
			Mano.SetPiv(ptm);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCodoAbajo()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp;
	CPoint ptc,ptm;
	Err="Por Favor Cree Primero El Brazo.";	
	if(Brazo==true)
	{
		rc++;
		if(rc==9)
			rc=0;
		if(rc!=0)
		{
			xp=(Antebrazo.piv.x)+((Muñeca.c.x-Antebrazo.piv.x)*(cos(0.2)))-((Muñeca.c.y-Antebrazo.piv.y)*(sin(0.2)));
			yp=(Antebrazo.piv.y)+((Muñeca.c.x-Antebrazo.piv.x)*(sin(0.2)))+((Muñeca.c.y-Antebrazo.piv.y)*(cos(0.2)));
			ptm.x=xp; ptm.y=yp;
			Muñeca.SetCentro(ptm);
			Muñeca.SetBorde(ptm.x+10,ptm.y);
			Mano.piv=Antebrazo.piv;
			Antebrazo.Rotacion(-0.2,&dc);
			Mano.Rotacion(-0.2,&dc);
			Mano.SetPiv(ptm);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnMu32814()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp;
	Err="Por Favor Cree Primero El Brazo.";	
	if(Brazo==true)
	{
		rm--;
		if(rm==-9)
			rm=0;
		if(rm!=0)
		{
			Mano.Rotacion(0.2,&dc);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnMu32815()
{
	CClientDC dc (this);
	CString Err;
	int xp,yp;
	Err="Por Favor Cree Primero El Brazo.";	
	if(Brazo==true)
	{
		rm++;
		if(rm==9)
			rm=0;
		if(rm!=0)
		{
			Mano.Rotacion(-0.2,&dc);
			Opcion=18;
		}else{
			Opcion=17;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}



void CKhaleView::OnGraficasNuevavac32819()
{
	CClientDC dc(this);
	Grafica.Nuevo();
	Opcion=19;
	Invalidate(true);
}



void CKhaleView::OnHombreNuevo(){Opcion=23;Invalidate(true);}
void CKhaleView::OnHombroArriba32827()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RH++;
		if(RH<20)
		{
			ManD.RotacionOtroEje(BicD.GetPiv(),0.1);
			AntD.RotacionOtroEje(BicD.GetPiv(),0.1);
			BicD.Rotacion(0.1);
			ManI.RotacionOtroEje(BicI.GetPiv(),-0.1);
			AntI.RotacionOtroEje(BicI.GetPiv(),-0.1);
			BicI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnHombroAbajo32832()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RH--;
		if(RH>0)
		{
			ManD.RotacionOtroEje(BicD.GetPiv(),-0.1);
			AntD.RotacionOtroEje(BicD.GetPiv(),-0.1);
			BicD.Rotacion(-0.1);
			ManI.RotacionOtroEje(BicI.GetPiv(),0.1);
			AntI.RotacionOtroEje(BicI.GetPiv(),0.1);
			BicI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCodoArriba32829()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RC++;
		if(RC<15)
		{
			ManD.RotacionOtroEje(AntD.GetPiv(),0.1);
			AntD.Rotacion(0.1);
			ManI.RotacionOtroEje(AntI.GetPiv(),-0.1);
			AntI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCodoAbajo32833()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RC--;
		if(RC>0)
		{
			ManD.RotacionOtroEje(AntD.GetPiv(),-0.1);
			AntD.Rotacion(-0.1);
			ManI.RotacionOtroEje(AntI.GetPiv(),0.1);
			AntI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnMuArriba()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RM++;
		if(RM<8)
		{
			ManD.Rotacion(0.1);
			ManI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnMuAbajo()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RM--;
		if(RM>-8)
		{
			ManD.Rotacion(-0.1);
			ManI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCaderaArriba()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RI++;
		if(RI<15)
		{
			PieD.RotacionOtroEje(MusD.GetPiv(),0.1);
			PanD.RotacionOtroEje(MusD.GetPiv(),0.1);
			MusD.Rotacion(0.1);
			PieI.RotacionOtroEje(MusI.GetPiv(),-0.1);
			PanI.RotacionOtroEje(MusI.GetPiv(),-0.1);
			MusI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnCaderaAbajo()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RI--;
		if(RI>0)
		{
			PieD.RotacionOtroEje(MusD.GetPiv(),-0.1);
			PanD.RotacionOtroEje(MusD.GetPiv(),-0.1);
			MusD.Rotacion(-0.1);
			PieI.RotacionOtroEje(MusI.GetPiv(),0.1);
			PanI.RotacionOtroEje(MusI.GetPiv(),0.1);
			MusI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnRodillaArriba()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RR++;
		if(RR<5)
		{
			PieD.RotacionOtroEje(PanD.GetPiv(),0.1);
			PanD.Rotacion(0.1);
			PieI.RotacionOtroEje(PanI.GetPiv(),-0.1);
			PanI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnRodillaAbajo()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RR--;
		if(RR>0)
		{
			PieD.RotacionOtroEje(PanD.GetPiv(),-0.1);
			PanD.Rotacion(-0.1);
			PieI.RotacionOtroEje(PanI.GetPiv(),0.1);
			PanI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnTobilloArriba()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";	if(Cuerpo)
	{
		RT++;
		if(RT<8)
		{
			PieD.Rotacion(0.1);
			PieI.Rotacion(-0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}

void CKhaleView::OnTobilloAbajo()
{
	CClientDC dc (this);
	CString Err;
	Err="Por favor cree primero el cuerpo";
	if(Cuerpo)
	{
		RT--;
		if(RT>-8)
		{
			PieD.Rotacion(-0.1);
			PieI.Rotacion(0.1);
		}else{
			Opcion=23;
		}
		Invalidate (true);
	}
	else
	{
		Opcion=0;
		dc.TextOutW(80,50,Err);
	}
}
