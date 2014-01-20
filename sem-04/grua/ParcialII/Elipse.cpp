#include "StdAfx.h"
#include "Elipse.h"

CElipse::CElipse(void)
{
	c.x=0; c.y=0;
	pi.x=150; pi.y=150;
	pf.x=300; pf.y=250;
	rx=0; ry=0;
	ce=RGB(0,0,0);
	PI=3.14159265;
}

CElipse::~CElipse(void)
{
}

void CElipse::Dibujar (CDC *dc)
{
	double dx=abs(pi.x-pf.x),dy=abs(pi.y-pf.y);
	double rx=dx/2,ry=dy/2;
	double theta;
	CLinea linea;
	linea.SetColor(ce);
	
	if(pf.x>pi.x)
		c.x=pi.x+rx;
	else
		c.x=pf.x+rx;
	if(pf.y>pi.y)
		c.y=pi.y+ry;
	else
		c.y=pf.y+ry;

	for(theta=0;theta<=(PI)/2;theta+=0.001)
	{
		dc->SetPixel(c.x+(rx*cos(theta)),c.y+(ry*sin(theta)),ce);
		dc->SetPixel(c.x-(rx*cos(theta)),c.y-(ry*sin(theta)),ce);		
		dc->SetPixel(c.x+(rx*cos(theta)),c.y-(ry*sin(theta)),ce);
		dc->SetPixel(c.x-(rx*cos(theta)),c.y+(ry*sin(theta)),ce);
		linea.SetPtoI(c.x,c.y+(ry*sin(theta)));
		linea.SetPtoF(c.x-(rx*cos(theta)),c.y+(ry*sin(theta)));
		linea.Dibujar(dc);
		linea.SetPtoI(c.x,c.y-(ry*sin(theta)));
		linea.SetPtoF(c.x+(rx*cos(theta)),c.y-(ry*sin(theta)));
		linea.Dibujar(dc);
	}
}