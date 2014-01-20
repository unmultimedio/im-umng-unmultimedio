#pragma once
#include "Linea.h"
#include <math.h>

class CArticulacion
{
	CPoint Lista[7],piv;
	int N;
	COLORREF ca;
public:
	CArticulacion(void);
	~CArticulacion(void);

	inline CPoint GetPiv() {return piv;}
	inline void SetPiv(CPoint p){piv=p;}
	inline void SetPiv(int x,int y){piv.x=x; piv.y=y;}
	inline void InsertarPto(int p,int x,int y){Lista[p].x=x;Lista[p].y=y;}
	inline void Cerrar(){Lista[6]=Lista[0];}

	void Parte (int p,bool d);
	void Rotacion (float theta);
	void RotacionOtroEje (CPoint piv2,float theta);
	void Dibujar (CDC *dc);
};
