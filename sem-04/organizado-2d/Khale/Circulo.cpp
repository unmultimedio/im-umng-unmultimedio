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

void CCirculo::Cartesiano (CDC *dc)
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
	dc->SetPixel(c,cc);
}
void CCirculo::Polar (CDC *dc)
{
	double x,y,theta;
	r=CCirculo::CalcRadio();
	for(theta=0;theta<=2*(PI);theta+=0.001)
	{
		x=c.x+r*cos(theta);
		y=c.y+r*sin(theta);
		dc->SetPixel(x,y,cc);
	}
}
void CCirculo::Bressenham (CDC *dc)
{
	int x,y;
	double p;
	y=r=CCirculo::CalcRadio();
	p=(5/4)-r;
	for(x=0;x<=y;x++)
	{
		dc->SetPixel(c.x+x,c.y-y,cc);
		dc->SetPixel(c.x-x,c.y+y,cc);
		dc->SetPixel(c.x-x,c.y-y,cc);
		dc->SetPixel(c.x+x,c.y+y,cc);
		dc->SetPixel(c.x+y,c.y+x,cc);
		dc->SetPixel(c.x-y,c.y-x,cc);
		dc->SetPixel(c.x-y,c.y+x,cc);
		dc->SetPixel(c.x+y,c.y-x,cc);
		if(p<0)
		{
			p+=(2*x)+3;
		}else{
			p+=(2*x)-(2*y)+5;
			y--;
		}
	}
}

int CCirculo::CalcRadio ()
{
	int rad;
	rad=sqrt((pow((double)(c.x-b.x),2))+(pow((double)(c.y-b.y),2)));
	return rad;
}