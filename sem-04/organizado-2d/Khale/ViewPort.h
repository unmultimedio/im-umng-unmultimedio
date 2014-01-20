#pragma once
#include "Linea.h"

class CViewPort
{
	int Xmax,Xmin,Ymax,Ymin;
	int ancho,alto;
public:
	CViewPort(void);
	~CViewPort(void);

	inline void Tama (int an,int al){ancho=an;alto=al;}
	inline void SetP1 (CPoint p){Xmin=p.x; Ymin=p.y;}
	inline void SetP2 (CPoint p){Xmax=p.x; Ymax=p.y;}
	inline void Nuevo (){Xmax=Xmin=Ymax=Ymin=0;}

	void SetLim ();
	void DibujarVP (CDC *dc);
	int CalcCodPto (int x,int y);
	void CalcRecorte (int xi,int yi,int xf,int yf, CDC *dc);
};
