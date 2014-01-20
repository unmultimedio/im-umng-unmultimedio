#include "StdAfx.h"
#include "Relleno.h"

CRelleno::CRelleno(void)
{
	s.x=0; s.y=0;
	cr=RGB(20,200,20);
}

CRelleno::~CRelleno(void)
{
}

void CRelleno::Vecindad4(CDC *dc)
{
	CPoint a=s;
	if(dc->GetPixel(s)==RGB(255,255,255))
	{
		dc->SetPixel(s,cr);
		CRelleno::SetPtoRelleno(s.x+1,s.y);
		CRelleno::Vecindad4(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x-1,s.y);
		CRelleno::Vecindad4(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x,s.y+1);
		CRelleno::Vecindad4(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x,s.y-1);
		CRelleno::Vecindad4(dc);
	}
}

void CRelleno::Frontera(CDC *dc)
{
	CPila pila;
	CLinea linea;
	CPoint p;
	linea.SetColor(cr);
	COLORREF actual,fondo;
	fondo=RGB(255,255,255);
	actual=dc->GetPixel(s);
	int xde,xiz,pos;

	if((actual==fondo)&&(actual!=cr))
		pila.Apilar(s);

	while(pila.N>=0)
	{
		p=pila.Pila[pila.N];
		pila.Desapilar();
		xde=XLim(p,dc,1);
		xiz=XLim(p,dc,2);
		if(xde-xiz>1)
		{
		linea.SetPtoI(xiz,p.y);
		linea.SetPtoF(xde,p.y);
		linea.DDA(dc);
		p.x=xde;
		p.y--;
		actual=dc->GetPixel(p);
		if((actual==fondo)&&(actual!=cr))
			pila.Apilar(p);
		p.y+=2;
		actual=dc->GetPixel(p);
		if((actual==fondo)&&(actual!=cr))
			pila.Apilar(p);
		p.x=xiz;
		p.y-=2;
		actual=dc->GetPixel(p);
		if((actual==fondo)&&(actual!=cr))
			pila.Apilar(p);
		p.y+=2;
		actual=dc->GetPixel(p);
		if((actual==fondo)&&(actual!=cr))
			pila.Apilar(p);
		}
	}
}

int CRelleno::XLim(CPoint p, CDC *dc, int c)
{
	COLORREF actual,fondo;
	fondo=RGB(255,255,255);
	actual=dc->GetPixel(p);
	if(c==1)
	{
		while((actual==fondo)&&(actual!=cr))
		{
			p.x++;
			actual=dc->GetPixel(p);
		}
		p.x-=3;
	}else{
		while((actual==fondo)&&(actual!=cr))
		{
			p.x--;
			actual=dc->GetPixel(p);
		}
		p.x+=3;
	}
	return p.x;
}