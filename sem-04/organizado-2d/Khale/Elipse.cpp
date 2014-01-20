#include "StdAfx.h"
#include "Elipse.h"

CElipse::CElipse(void)
{
	c.x=0; c.y=0;
	pi.x=0; pi.y=0;
	pf.x=0; pf.y=0;
	rx=0; ry=0;
	ce=RGB(0,0,0);
	PI=3.14159265;
}

CElipse::~CElipse(void)
{
}

void CElipse::Polar (CDC *dc)
{
	double dx=abs(pi.x-pf.x),dy=abs(pi.y-pf.y);
	double rx=dx/2,ry=dy/2;
	double theta;
	
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
	}
}
void CElipse::Bressenham (CDC *dc)
{
	double dx=abs(pi.x-pf.x),dy=abs(pi.y-pf.y);
	double rx=dx/2,ry=dy/2;
	double x,y,p;

	if(pf.x>pi.x)
		c.x=pi.x+rx;
	else
		c.x=pf.x+rx;
	if(pf.y>pi.y)
		c.y=pi.y+ry;
	else
		c.y=pf.y+ry;

	x=0; y=ry; 
	p=(2*ry)+((2*rx)*(0.25-ry));

	dc->SetPixel(c.x+x,c.y+y,ce);
	dc->SetPixel(c.x+x,c.y-y,ce);

	while(((2*rx)*(y-0.5))>=((2*ry)*(x+1)))
	{
		if(p<0)
		{
			p+=((2*ry)*((2*x)+3));
		}else{
			p+=((2*ry)*((2*x)+3))+((2*rx)*(2-(2*y)));
			y--;
		}
		x++;
		dc->SetPixel(c.x+x,c.y+y,ce);
		dc->SetPixel(c.x-x,c.y+y,ce);
		dc->SetPixel(c.x-x,c.y-y,ce);
		dc->SetPixel(c.x+x,c.y-y,ce);
	}

	p=(2*((2*ry)*(x+0.5)))+(2*((2*rx)*(y-1)))-((2*rx)*(2*ry));

	while(y>=0)
	{
		if(p<0)
		{
			p+=((2*ry)*((2*x)+2))+((2*rx)*(3-(2*y)));
			x++;
		}else{
			p+=((2*rx)*(3-(2*y)));
		}
		y--;
		dc->SetPixel(c.x+x,c.y+y,ce);
		dc->SetPixel(c.x-x,c.y+y,ce);
		dc->SetPixel(c.x-x,c.y-y,ce);
		dc->SetPixel(c.x+x,c.y-y,ce);	
	}
}