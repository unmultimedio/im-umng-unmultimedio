#include "StdAfx.h"
#include "Poligono.h"

CPoligono::CPoligono(void)
{
	N=0;
	cp=RGB(0,0,0);
	ancho=0;
	alto=0;
	pi=pf=0;
	ux=uy=0;
}

CPoligono::~CPoligono(void)
{
}

void CPoligono::SetPunto(CPoint aux)
{
	if(N==10)
	{
		Lista[0]=Lista[9];
		N=1;
	}
	if(Lista[N-1]!=aux)
	{
		Lista[N]=aux; 
		N++;
	}
}

void CPoligono::DibujarFijo(CDC *dc)
{
	CPoint p1,p2;
	CLinea linea;
	linea.SetColor(cp);

	for(int i=0; i<N-1; i++)
	{
		p1.x=Lista[i].x;
		p1.y=Lista[i].y;
		p2.x=Lista[i+1].x;
		p2.y=Lista[i+1].y;
		linea.SetPtoI(p1);
		linea.SetPtoF(p2);
		linea.DDA(dc);
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

void CPoligono::DibujarPtos(CDC *dc)
{
	CLinea linea;
	linea.SetColor(cp);

	for(int i=0; i<N-1; i++)
	{
		linea.SetPtoI(Lista[i]);
		linea.SetPtoF(Lista[i+1]);
		linea.DDA(dc);
	}
	if(N>2)
	{
		linea.SetPtoI(Lista[0]);
		linea.SetPtoF(Lista[N-1]);
		linea.DDA(dc);
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

void CPoligono::Traslacion(CDC *dc)
{
	int dx,dy;
	dx=(pf.x-pi.x);
	dy=(pf.y-pi.y);

	for(int i=0; i<N; i++)
	{
		Lista[i].x+=(dx-ux);
		Lista[i].y+=(dy-uy);
	}
	ux=dx; uy=dy;
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

void CPoligono::Escalamiento(CDC *dc)
{
	double sx,sy,px,py;
	sx=10+(pf.x-pi.x);
	sy=10-(pf.y-pi.y);

	if(sx<=0)
		sx=1;
	if(sy<=0)
		sy=1;

	for(int i=0; i<N; i++)
	{
		px=((sx/ux)*Lista[i].x)+((piv.x)*(1-(sx/ux)));
		py=((sy/uy)*Lista[i].y)+((piv.y)*(1-(sy/uy)));
		Lista[i].x=px;
		Lista[i].y=py;
	}
	ux=sx; uy=sy;
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

void CPoligono::Escalamiento(double sx, double sy, CDC *dc)
{
	double px,py;

	for(int i=0; i<N; i++)
	{
		px=(sx*Lista[i].x)+((piv.x)*(1-sx));
		py=(sy*Lista[i].y)+((piv.y)*(1-sy));
		Lista[i].x=px;
		Lista[i].y=py;
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

void CPoligono::Rotacion(CDC *dc)
{
	int dx,dy;
	dx=(pf.x-pi.x);
	dy=(pi.y-pf.y);
	double tg,xp,yp;
	if(dy!=0)
		tg=dx/dy;
	else
		tg=0;
	double t;
	t=atan(tg);

	for(int i=0; i<N; i++)
	{
		xp=(piv.x)+((Lista[i].x-piv.x)*(cos(ut-t)))-((Lista[i].y-piv.y)*(sin(ut-t)));
		yp=(piv.y)+((Lista[i].x-piv.x)*(sin(ut-t)))+((Lista[i].y-piv.y)*(cos(ut-t)));
		Lista[i].x=xp;
		Lista[i].y=yp;
	}
	ut=t;
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

void CPoligono::Dibujar(CDC *dc)
{
	if (fijo==true)
		CPoligono::DibujarFijo(dc);
	else
		CPoligono::DibujarPtos(dc);
}

void CPoligono::SetFijo(bool aux)
{
	CPoligono::Renovar();
	fijo=aux;
	if(aux==true)
	{
		Lista[0].x=(ancho/2)+50;
		Lista[0].y=Lista[1].y=(alto/2)-50;
		Lista[1].x=(ancho/2)+150;
		Lista[2].x=(ancho/2)+100;
		Lista[2].y=(alto/2)-100;
		Lista[3]=Lista[0];
		N=4;
	}
}

void CPoligono::Renovar()
{
	N=0;
	for(int i=0; i<10; i++)
	{
		Lista[i].x=0;
		Lista[i].y=0;
	}
}
void CPoligono::SetPiv()
{
	int xmax=0, xmin, ymax=0, ymin;
	for(int i=0; i<N; i++)
	{
		if(Lista[i].x>xmax)
			xmax=Lista[i].x;
		if(Lista[i].y>ymax)
			ymax=Lista[i].y;
		if(i==0)
		{
			xmin=xmax;
			ymin=ymax;
		}else{
			if(Lista[i].x<xmin)
				xmin=Lista[i].x;
			if(Lista[i].y<ymin)
				ymin=Lista[i].y;
		}
	}
	if(N==0)
		xmax=xmin=ymax=ymin=0;
	piv.x=(abs(xmax-xmin)/2)+xmin;
	piv.y=(abs(ymax-ymin)/2)+ymin;
}

void CPoligono::Reflexión(bool x, bool y, CDC *dc)
{
	int d;
	if(x==true)
	{
		for(int i=0; i<N; i++)
		{
			d=piv.x-Lista[i].x;
			if(d>=0)
				Lista[i].x+=2*d;
			else
				Lista[i].x-=2*d;
		}
	}
	if(y==true)
	{
		for(int i=0; i<N; i++)
		{
			d=piv.y-Lista[i].y;
			if(d>0)
				Lista[i].y+=2*d;
			else
				Lista[i].y-=2*d;
		}
	}
	CPoligono::Dibujar(dc);
}

void CPoligono::TransLibres (double Mat[3][3], CDC *dc)
{
	double px,py;
	for(int i=0; i<N; i++)
	{
		px=Mat[0][0]*Lista[i].x + Mat[0][1]*Lista[i].y + Mat[0][2];
		py=Mat[1][0]*Lista[i].x + Mat[1][1]*Lista[i].y - Mat[1][2];
		Lista[i].x=px;
		Lista[i].y=py;
	}
	CPoligono::Dibujar(dc);
}

void CPoligono::Crear(int parte, CDC *dc)
{
	switch(parte)
	{
	case 1:
		Lista[0].x=100;
		Lista[0].y=120;
		Lista[1].x=160;
		Lista[1].y=120;
		Lista[2].x=160;
		Lista[2].y=140;
		Lista[3].x=100;
		Lista[3].y=140;
		Lista[4]=Lista[0];
		cp=RGB(200,20,20);
		SetPiv(90,130);
		N=5;
		break;
	case 2:
		Lista[0].x=180;
		Lista[0].y=120;
		Lista[1].x=240;
		Lista[1].y=120;
		Lista[2].x=240;
		Lista[2].y=140;
		Lista[3].x=180;
		Lista[3].y=140;
		Lista[4]=Lista[0];
		cp=RGB(20,200,20);
		SetPiv(170,130);
		N=5;
		break;
	case 3:
		Lista[0].x=260;
		Lista[0].y=120;
		Lista[1].x=270;
		Lista[1].y=115;
		Lista[2].x=270;
		Lista[2].y=120;
		Lista[3].x=280;
		Lista[3].y=120;
		Lista[4].x=280;
		Lista[4].y=140;
		Lista[5].x=260;
		Lista[5].y=140;
		Lista[6]=Lista[0];
		cp=RGB(20,20,200);
		SetPiv(250,130);
		N=7;
		break;
	case 4:
		Lista[0].x=390;
		Lista[0].y=180;
		Lista[1].x=410;
		Lista[1].y=180;
		Lista[2].x=420;
		Lista[2].y=190;
		Lista[3].x=460;
		Lista[3].y=200;
		Lista[4].x=420;
		Lista[4].y=280;
		Lista[5].x=430;
		Lista[5].y=300;
		Lista[6].x=400;
		Lista[6].y=310;
		Lista[7].x=370;
		Lista[7].y=300;
		Lista[8].x=380;
		Lista[8].y=280;
		Lista[9].x=340;
		Lista[9].y=200;
		Lista[10].x=380;
		Lista[10].y=190;
		Lista[11]=Lista[0];
		SetPiv(400,220);
		N=12;
		break;
	}
	CPoligono::DibujarPtos(dc);
}