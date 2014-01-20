#include "StdAfx.h"
#include "ViewPort.h"

CViewPort::CViewPort(void)
{
	ancho=alto=0;
	Xmax=Xmin=Ymax=Ymin=0;
}

CViewPort::~CViewPort(void)
{
}

void CViewPort::DibujarVP(CDC*dc)
{
	CLinea linea;
	linea.SetColor(RGB(240,0,0));
	linea.SetPtoI(0,Ymin);
	linea.SetPtoF(ancho,Ymin);
	linea.Punteada(dc);
	linea.SetPtoI(0,Ymax);
	linea.SetPtoF(ancho,Ymax);
	linea.Punteada(dc);
	linea.SetPtoI(Xmin,0);
	linea.SetPtoF(Xmin,alto);
	linea.Punteada(dc);
	linea.SetPtoI(Xmax,0);
	linea.SetPtoF(Xmax,alto);
	linea.Punteada(dc);
	linea.SetColor(RGB(20,20,20));
	linea.SetPtoI(Xmin+1,Ymin+1);
	linea.SetPtoF(Xmax-1,Ymin+1);
	linea.DDA(dc);
	linea.SetPtoI(Xmin-1,Ymin-1);
	linea.SetPtoF(Xmax+1,Ymin-1);
	linea.DDA(dc);
	linea.SetPtoI(Xmin+1,Ymax-1);
	linea.SetPtoF(Xmax-1,Ymax-1);
	linea.DDA(dc);
	linea.SetPtoI(Xmin-1,Ymax+1);
	linea.SetPtoF(Xmax+1,Ymax+1);
	linea.DDA(dc);
	linea.SetPtoI(Xmin+1,Ymin+1);
	linea.SetPtoF(Xmin+1,Ymax-1);
	linea.DDA(dc);
	linea.SetPtoI(Xmin-1,Ymin-1);
	linea.SetPtoF(Xmin-1,Ymax+1);
	linea.DDA(dc);
	linea.SetPtoI(Xmax-1,Ymin+1);
	linea.SetPtoF(Xmax-1,Ymax-1);
	linea.DDA(dc);
	linea.SetPtoI(Xmax+1,Ymin-1);
	linea.SetPtoF(Xmax+1,Ymax+1);
	linea.DDA(dc);
}

void CViewPort::SetLim()
{
	int x,y;
	if (Xmax<Xmin)
	{
		x=Xmin;
		Xmin=Xmax;
		Xmax=x;
	}
	if (Ymax<Ymin)
	{
		y=Ymin;
		Ymin=Ymax;
		Ymax=y;
	}
}

int CViewPort::CalcCodPto(int x, int y)
{
	int b=0;
	if(x<Xmin)
		b++;
	else
		if(x>Xmax)
			b|=2;
	if(y<Ymin)
		b|=4;
	else
		if(y>Ymax)
			b|=8;
	return b;
}

void CViewPort::CalcRecorte(int xi,int yi,int xf,int yf, CDC *dc)
{
	CLinea linea;
	bool dibuje,listo;
	int cod1,cod2,codt,x,y;
	cod1=CalcCodPto(xi,yi);
	cod2=CalcCodPto(xf,yf);
	dibuje=listo=false;
	do{
		if((cod1==0)&&(cod2==0))//'&&'->lógico.
			dibuje=listo=true;
		else
			if((cod1&cod2)!=0)//'&'->binario.
				listo=true;
			else
			{
				if(cod1==0)
					codt=cod2;
				else
					codt=cod1;
				if((codt==10)||(codt==8)||(codt==9))
				{
					if(yf!=yi)
						x=xi+(xf-xi)*(Ymax-yi)/(yf-yi);
					else
						x=xi;
					y=Ymax;
				}else{
					if((codt==5)||(codt==4)||(codt==6))
					{
						if(yf!=yi)
							x=xi+(xf-xi)*(Ymin-yi)/(yf-yi);
						else
							x=xi;
						y=Ymin;
					}

				}
				if((codt==10)||(codt==2)||(codt==6))
				{
					if(xf!=xi)
						y=yi+(yf-yi)*(Xmax-xi)/(xf-xi);
					else
						y=yi;
					x=Xmax;
				}else{
					if((codt==1)||(codt==5)||(codt==9))
					{
						if(xf!=xi)
							y=yi+(yf-yi)*(Xmin-xi)/(xf-xi);
						else
							y=yi;
						x=Xmin;
					}

				}
				if(codt==cod1)
				{
					xi=x;yi=y;
					cod1=CalcCodPto(xi,yi);
				}
				else
				{
					xf=x;yf=y;
					cod2=CalcCodPto(xf,yf);
				}
			}

	}while(listo==false);
	
	if(dibuje)
	{
		linea.SetColor(RGB(55,155,0));
		linea.SetPtoI(xi,yi);
		linea.SetPtoF(xf,yf);
		linea.DDA(dc);
	}
}