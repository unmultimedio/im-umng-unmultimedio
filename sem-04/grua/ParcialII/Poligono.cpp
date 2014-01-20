#include "StdAfx.h"
#include "Poligono.h"

CPoligono::CPoligono(void)
{
	N=0;
	cp=RGB(0,0,0);
}

CPoligono::~CPoligono(void)
{
}

void CPoligono::Parte(int p)
{
	CPoint pv;
	switch (p)
	{
	case 1:
		Lista[0].x=70;
		Lista[0].y=190;
		Lista[1].x=310;
		Lista[1].y=190;
		Lista[2].x=310;
		Lista[2].y=290;
		Lista[3].x=290;
		Lista[3].y=290;
		Lista[4].x=270;
		Lista[4].y=270;
		Lista[5].x=230;
		Lista[5].y=270;
		Lista[6].x=210;
		Lista[6].y=290;
		Lista[7].x=170;
		Lista[7].y=290;
		Lista[8].x=150;
		Lista[8].y=270;
		Lista[9].x=110;
		Lista[9].y=270;
		Lista[10].x=90;
		Lista[10].y=290;
		Lista[11].x=70;
		Lista[11].y=290;
		Lista[12]=Lista[0];
		N=13;
		cp=RGB(200,0,0);
		break;
	case 2:
		Lista[0].x=180;
		Lista[0].y=80;
		Lista[1].x=200;
		Lista[1].y=80;
		Lista[2].x=200;
		Lista[2].y=200;
		Lista[3].x=180;
		Lista[3].y=200;
		Lista[4]=Lista[0];
		N=5;
		pv.x=190;
		pv.y=195;
		CPoligono::SetPiv(pv);
		cp=RGB(0,200,0);
		break;
	case 3:
		Lista[0].x=150;
		Lista[0].y=50;
		Lista[1].x=160;
		Lista[1].y=60;
		Lista[2].x=220;
		Lista[2].y=60;
		Lista[3].x=230;
		Lista[3].y=50;
		Lista[4].x=230;
		Lista[4].y=110;
		Lista[5].x=150;
		Lista[5].y=110;
		Lista[6]=Lista[0];
		N=7;
		pv.x=190;
		pv.y=90;
		CPoligono::SetPiv(pv);
		cp=RGB(0,0,200);
		break;
	case 4:
		break;
	case 5:
		break;
	}
}

void CPoligono::Traslacion(int tx, int ty, CDC *dc)
{
	for(int i=0; i<N; i++)
	{
		Lista[i].x+=tx;
		Lista[i].y+=ty;
	}
	
	CPoligono::Dibujar(dc);
	dc->SetPixel(piv,cp);
	dc->SetPixel(piv.x+1,piv.y,cp);
	dc->SetPixel(piv.x+2,piv.y,cp);
	dc->SetPixel(piv.x-1,piv.y,cp);
	dc->SetPixel(piv.x-2,piv.y,cp);
	dc->SetPixel(piv.x,piv.y+1,cp);
	dc->SetPixel(piv.x,piv.y+2,cp);
	dc->SetPixel(piv.x,piv.y-1,cp);
	dc->SetPixel(piv.x,piv.y-2,cp);
}

void CPoligono::Rotacion(float theta, CDC *dc)
{
	double xp,yp;
	for(int i=0; i<N; i++)
	{
		xp=(piv.x)+((Lista[i].x-piv.x)*(cos(-theta)))-((Lista[i].y-piv.y)*(sin(-theta)));
		yp=(piv.y)+((Lista[i].x-piv.x)*(sin(-theta)))+((Lista[i].y-piv.y)*(cos(-theta)));
		Lista[i].x=xp;
		Lista[i].y=yp;
	}

	CPoligono::Dibujar(dc);
	dc->SetPixel(piv,cp);
	dc->SetPixel(piv.x+1,piv.y,cp);
	dc->SetPixel(piv.x+2,piv.y,cp);
	dc->SetPixel(piv.x-1,piv.y,cp);
	dc->SetPixel(piv.x-2,piv.y,cp);
	dc->SetPixel(piv.x,piv.y+1,cp);
	dc->SetPixel(piv.x,piv.y+2,cp);
	dc->SetPixel(piv.x,piv.y-1,cp);
	dc->SetPixel(piv.x,piv.y-2,cp);
}

void CPoligono::Rotacion2(float theta, int r, CDC *dc, bool c)
{
	CPoint pv;
	float xp,yp;
	pv.x=190;
	pv.y=195;
	CPoligono::SetPiv(pv);
	pv.y=90;
	if(c==false)
	{
		CPoligono::Rotacion(theta,dc);
		xp=(piv.x)+((pv.x-piv.x)*(cos(-theta*abs(r))))-((pv.y-piv.y)*(sin(-theta*abs(r))));
		yp=(piv.y)+((pv.x-piv.x)*(sin(-theta*abs(r))))+((pv.y-piv.y)*(cos(-theta*abs(r))));
	}else{
		CPoligono::Rotacion(theta*r,dc);
		xp=(piv.x)+((pv.x-piv.x)*(cos(-theta*r)))-((pv.y-piv.y)*(sin(-theta*r)));
		yp=(piv.y)+((pv.x-piv.x)*(sin(-theta*r)))+((pv.y-piv.y)*(cos(-theta*r)));
	}
	if((theta>0&&r>0)||(theta<0&&r<0))
	{
		xp=(piv.x)+((pv.x-piv.x)*(cos(-theta*r)))-((pv.y-piv.y)*(sin(-theta*r)));
		yp=(piv.y)+((pv.x-piv.x)*(sin(-theta*r)))+((pv.y-piv.y)*(cos(-theta*r)));
	}
	pv.x=xp;
	pv.y=yp;
	CPoligono::SetPiv(pv);
}

void CPoligono::Dibujar(CDC *dc)
{
	CLinea linea;
	linea.SetColor(cp);

	for(int i=0; i<N-1; i++)
	{
		linea.SetPtoI(Lista[i]);
		linea.SetPtoF(Lista[i+1]);
		linea.Dibujar(dc);
	}

	dc->SetPixel(piv,cp);
	dc->SetPixel(piv.x+1,piv.y,cp);
	dc->SetPixel(piv.x+2,piv.y,cp);
	dc->SetPixel(piv.x-1,piv.y,cp);
	dc->SetPixel(piv.x-2,piv.y,cp);
	dc->SetPixel(piv.x,piv.y+1,cp);
	dc->SetPixel(piv.x,piv.y+2,cp);
	dc->SetPixel(piv.x,piv.y-1,cp);
	dc->SetPixel(piv.x,piv.y-2,cp);

}