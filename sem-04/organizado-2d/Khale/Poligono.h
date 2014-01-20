#pragma once
#include <math.h>
#include "Linea.h"

class CPoligono
{
	CPoint Lista[12];
	int ancho, alto, N;
	COLORREF cp;
	bool fijo;
	
public:
	CPoint pi,pf,piv;
	double ux,uy,ut;
	CPoligono(void);
	~CPoligono(void);
	
	inline void SetT1(CPoint p){pi=p;}
	inline void SetT2(CPoint p){pf=p;}
	inline void SetTamaño(int x, int y){ancho=x; alto=y;}
	inline void SetColor(COLORREF c){cp=c;}
	inline void SetPiv(CPoint p){piv=p;}
	inline void SetPiv(int x, int y){piv.x=x; piv.y=y;}

	void Renovar ();
	void SetPiv();
	void SetFijo (bool aux);
	void SetPunto (CPoint aux);
	void Traslacion (CDC *dc);
	void Traslacion (int tx, int ty, CDC *dc);
	void Escalamiento (CDC *dc);
	void Escalamiento (double sx, double sy, CDC *dc);
	void Rotacion (CDC *dc);
	void Rotacion (float theta, CDC *dc);
	void Reflexión (bool x, bool y, CDC *dc);
	void TransLibres (double Mat[3][3], CDC *dc);
	void Dibujar (CDC *dc);
	void DibujarFijo (CDC *dc);
	void DibujarPtos (CDC *dc);
	void Crear (int parte, CDC *dc);

};
