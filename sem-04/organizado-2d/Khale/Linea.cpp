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

void CLinea::DDA (CDC *dc)
{
	int i;
	float x,y,dy,dx,pasos;
	dx=pf.x-pi.x;
	dy=pf.y-pi.y;
	if(abs((long)dx)>abs((long)dy))
		pasos=abs((long)dx);
	else
		pasos=abs((long)dy);
	x=pi.x; y=pi.y;
	dy=dy/pasos; dx=dx/pasos;
	for(i=0;i<pasos;i++)
	{
		dc->SetPixel((int)(x+0.5),(int)(y+0.5),cl);
		x+=dx;
		y+=dy;
	}
}
void CLinea::Bressenham (CDC *dc)
{
	int dx,dy,Dx,Dy,dy2,dxy2,x,y,p=0,yend,xend,dyx2,dx2;
	Dx=pf.x-pi.x;
	Dy=pf.y-pi.y;
	dx=abs(Dx);
	dy=abs(Dy);
	dy2=2*dy;
	dyx2=2*(dy-dx);
	dx2=2*dx;
	dxy2=2*(dx-dy);
	if ((Dx>0 && Dy>0) || (Dx<0 && Dy<0))
	{
		if(abs(Dx)>abs(Dy))
		{
			p=dy2-dy;
			if (pi.x<pf.x)
			{
				x=pi.x;
				y=pi.y;
				xend=pf.x;
			}else{
				x=pf.x;
				y=pf.y;
				xend=pi.x;
			}
			dc->SetPixel(x,y,cl);
			while (x<=xend)
			{
				x++;
				if (p<0)
				p+=dy2;
				else{
					p+=dyx2;
					y++;
				}
				dc->SetPixel(x,y,cl);
			}
		}else{
			p=dx2-dy;
			if (pi.y<pf.y)
			{
				x=pi.x;
				y=pi.y;
				yend=pf.y;
			}else{
				x=pf.x;
				y=pf.y;
				yend=pi.y;
			}
			dc->SetPixel(x,y,cl);
			while (y<=yend)
			{
				y++;
				if (p<0)
					p=p+dx2;
				else{
					p=p+dxy2;
					x++;
				}
				dc->SetPixel(x,y,cl);
			}
		}
	}else{
		if(abs(Dx)>abs(Dy))
		{
			p=dy2-dy;
			if (pi.x<pf.x)
			{
				x=pi.x;
				y=pi.y;
				xend=pf.x;
			}else{
				x=pf.x;
				y=pf.y;
				xend=pi.x;
			}
			dc->SetPixel(x,y,cl);
			while (x<=xend)
			{
				x++;
				if (p<0)
					p=p+dy2;
				else{
					p=p+dyx2;
					y--;
				}
				dc->SetPixel(x,y,cl);
			}
		}else{
			p=dx2-dy;
			if (pi.y<pf.y)
			{
				x=pi.x;
				y=pi.y;
				yend=pf.y;
			}else{
				x=pf.x;
				y=pf.y;
				yend=pi.y;
			}
			dc->SetPixel(x,y,cl);
			while (y<=yend)
			{
				y++;
				if (p<0)
					p+=dx2;
				else{
					p=p+dxy2;
					x--;
				}
				dc->SetPixel(x,y,cl);
			}
		}
	}
}
void CLinea::Punteada (CDC *dc)
{
	int i,pt=0;
	float x,y,dy,dx,pasos;
	dx=pf.x-pi.x;	
	dy=pf.y-pi.y;
	if(abs((long)dx)>abs((long)dy))
		pasos=abs((long)dx);
	else
		pasos=abs((long)dy);
	x=pi.x; y=pi.y;
	dy=dy/pasos; dx=dx/pasos;
	for(i=0;i<pasos;i++)
	{
		if((pt<=5)&&(pt>=0))
		{
			dc->SetPixel((int)(x+0.5),(int)(y+0.5),cl);
			pt++;
		}else{
			if(pt==6)
				pt=-3;
			pt++;
		}
		x+=dx;
		y+=dy;
	}
}