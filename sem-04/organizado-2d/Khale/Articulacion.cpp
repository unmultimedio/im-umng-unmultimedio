#include "StdAfx.h"
#include "Articulacion.h"

CArticulacion::CArticulacion(void)
{
	N=7;
	ca=RGB(0,0,0);
}

CArticulacion::~CArticulacion(void)
{
}

void CArticulacion::Dibujar(CDC *dc)
{
	CLinea linea;
	linea.SetColor(ca);

	for(int i=0; i<N; i++)
	{
		linea.SetPtoI(Lista[i]);
		linea.SetPtoF(Lista[i+1]);
		linea.DDA(dc);
	}

	dc->SetPixel(piv,ca);
	dc->SetPixel(piv.x+1,piv.y,ca);
	dc->SetPixel(piv.x+2,piv.y,ca);
	dc->SetPixel(piv.x-1,piv.y,ca);
	dc->SetPixel(piv.x-2,piv.y,ca);
	dc->SetPixel(piv.x,piv.y+1,ca);
	dc->SetPixel(piv.x,piv.y+2,ca);
	dc->SetPixel(piv.x,piv.y-1,ca);
	dc->SetPixel(piv.x,piv.y-2,ca);
}

void CArticulacion::Rotacion(float theta)
{
	double xp,yp;
	for(int i=0; i<N; i++)
	{
		xp=(piv.x)+((Lista[i].x-piv.x)*(cos(-theta)))-((Lista[i].y-piv.y)*(sin(-theta)));
		yp=(piv.y)+((Lista[i].x-piv.x)*(sin(-theta)))+((Lista[i].y-piv.y)*(cos(-theta)));
		Lista[i].x=xp;
		Lista[i].y=yp;
	}
}

void CArticulacion::RotacionOtroEje(CPoint piv2,float theta)
{
	double xp,yp;
	xp=(piv2.x)+((piv.x-piv2.x)*(cos(-theta)))-((piv.y-piv2.y)*(sin(-theta)));
	yp=(piv2.y)+((piv.x-piv2.x)*(sin(-theta)))+((piv.y-piv2.y)*(cos(-theta)));
	SetPiv(piv2);
	Rotacion(theta);
	SetPiv(xp,yp);
}

void CArticulacion::Parte(int p, bool d)
{//p->parte		di->derecha
	switch(p)
	{
	case 1://Biceps
		if(d)
		{
			SetPiv(460,220);
			InsertarPto(0,460,220);
			InsertarPto(1,475,235);
			InsertarPto(2,470,270);
			InsertarPto(3,460,280);
			InsertarPto(4,450,270);
			InsertarPto(5,445,235);
			Cerrar();
		}
		else
		{
			SetPiv(340,220);
			InsertarPto(0,340,220);
			InsertarPto(1,355,235);
			InsertarPto(2,350,270);
			InsertarPto(3,340,280);
			InsertarPto(4,330,270);
			InsertarPto(5,325,235);
			Cerrar();
		}
		break;
	case 2://Antebrazo
		if(d)
		{
			SetPiv(460,280);
			InsertarPto(0,460,280);
			InsertarPto(1,470,290);
			InsertarPto(2,470,310);
			InsertarPto(3,460,320);
			InsertarPto(4,450,310);
			InsertarPto(5,450,290);
			Cerrar();
		}
		else
		{
			SetPiv(340,280);
			InsertarPto(0,340,280);
			InsertarPto(1,350,290);
			InsertarPto(2,350,310);
			InsertarPto(3,340,320);
			InsertarPto(4,330,310);
			InsertarPto(5,330,290);
			Cerrar();
		}
		break;
	case 3://Mano
		if(d)
		{
			SetPiv(460,320);
			InsertarPto(0,460,320);
			InsertarPto(1,475,335);
			InsertarPto(2,470,335);
			InsertarPto(3,470,345);
			InsertarPto(4,450,345);
			InsertarPto(5,450,330);
			Cerrar();
		}
		else
		{
			SetPiv(340,320);
			InsertarPto(0,340,320);
			InsertarPto(1,325,335);
			InsertarPto(2,330,335);
			InsertarPto(3,330,345);
			InsertarPto(4,350,345);
			InsertarPto(5,350,330);
			Cerrar();
		}
		break;
	case 4://Muslo
		if(d)
		{
			SetPiv(420,320);
			InsertarPto(0,420,320);
			InsertarPto(1,435,335);
			InsertarPto(2,430,370);
			InsertarPto(3,420,380);
			InsertarPto(4,410,370);
			InsertarPto(5,405,335);
			Cerrar();
		}
		else
		{
			SetPiv(380,320);
			InsertarPto(0,380,320);
			InsertarPto(1,395,335);
			InsertarPto(2,390,370);
			InsertarPto(3,380,380);
			InsertarPto(4,370,370);
			InsertarPto(5,365,335);
			Cerrar();
		}
		break;
	case 5://Pantorrila
		if(d)
		{
			SetPiv(420,380);
			InsertarPto(0,420,380);
			InsertarPto(1,430,390);
			InsertarPto(2,430,430);
			InsertarPto(3,420,440);
			InsertarPto(4,410,430);
			InsertarPto(5,410,390);
			Cerrar();
		}
		else
		{
			SetPiv(380,380);
			InsertarPto(0,380,380);
			InsertarPto(1,390,390);
			InsertarPto(2,390,430);
			InsertarPto(3,380,440);
			InsertarPto(4,370,430);
			InsertarPto(5,370,390);
			Cerrar();
		}
		break;
	case 6://Pie
		if(d)
		{
			SetPiv(420,440);
			InsertarPto(0,420,440);
			InsertarPto(1,440,445);
			InsertarPto(2,440,460);
			InsertarPto(3,420,455);
			InsertarPto(4,400,460);
			InsertarPto(5,400,445);
			Cerrar();
		}
		else
		{
			SetPiv(380,440);
			InsertarPto(0,380,440);
			InsertarPto(1,400,445);
			InsertarPto(2,400,460);
			InsertarPto(3,380,455);
			InsertarPto(4,360,460);
			InsertarPto(5,360,445);
			Cerrar();
		}
		break;
	}
}
