#include "StdAfx.h"
#include "Linea.h"

CLinea::CLinea(void)
{
	pi.x=0; pi.y=0;
	pf.x=0; pf.y=0;
	cl=RGB(0,0,0);
}

CLinea::~CLinea(void)
{
}

void CLinea::Dibujar (CDC *dc)
{
	int i;
	float x,y,dy,dx,pasos;
	dx=pf.x-pi.x;
	dy=pf.y-pi.y;
	if(abs(dx)>abs(dy))
		pasos=abs(dx);
	else
		pasos=abs(dy);
	x=pi.x; y=pi.y;
	dy=dy/pasos; dx=dx/pasos;
	for(i=0;i<pasos;i++)
	{
		dc->SetPixel((int)(x+0.5),(int)(y+0.5),cl);
		x+=dx;
		y+=dy;
	}
}