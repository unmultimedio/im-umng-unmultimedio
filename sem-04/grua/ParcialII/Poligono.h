#pragma once
#include <math.h>
#include "Linea.h"

class CPoligono
{
	CPoint Lista[13];
	int N;
	COLORREF cp;
	
public:
	CPoint piv;
	double ux,uy,ut;
	CPoligono(void);
	~CPoligono(void);

	inline void SetPiv(CPoint p) {piv=p;}
	inline void SetColor(COLORREF c){cp=c;}

	void Parte (int p);
	void SetPiv();
	void Traslacion (int tx, int ty, CDC *dc);
	void Rotacion (float theta, CDC *dc);
	void Rotacion2 (float theta, int r, CDC *dc, bool c);
	void Dibujar (CDC *dc);
};
