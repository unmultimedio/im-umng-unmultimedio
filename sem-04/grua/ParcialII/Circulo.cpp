#include "StdAfx.h"
#include "Circulo.h"

CCirculo::CCirculo(void)
{
	c.x=0; c.y=0;
	r=0;
	cc=RGB(0,0,0);
	PI=3.14159265;
}

CCirculo::~CCirculo(void)
{
}

void CCirculo::Dibujar (CDC *dc)
{
	double x,y,s;
	r=CCirculo::CalcRadio();
	for(x=c.x-r;x<=c.x+r;x++)
	{
		s=sqrt(pow((double)r,2)-pow((x-c.x),2));
		y=c.y+s;
		dc->SetPixel(x,y,cc);
		y=c.y-s;
		dc->SetPixel(x,y,cc);
	}
	
	for(y=c.y-r;y<=c.y+r;y++)
	{
		s=sqrt(pow((double)r,2)-pow(y-c.y,2));
		x=c.x+s;
		dc->SetPixel(x,y,cc);
		x=c.x-s;
		dc->SetPixel(x,y,cc);
	}
}
int CCirculo::CalcRadio ()
{
	int rad;
	rad=sqrt((pow((double)(c.x-b.x),2))+(pow((double)(c.y-b.y),2)));
	return rad;
}
