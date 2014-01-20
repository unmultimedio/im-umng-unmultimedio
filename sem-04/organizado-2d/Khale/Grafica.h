#pragma once
#include "Linea.h"
#include <math.h>

class CGrafica
{
	CLinea EjeY,EjeX;
	int Ancho,Alto;
	double EscX,EscY;
	COLORREF cg;

public:
	CGrafica(void);
	~CGrafica(void);

	inline void SetAncho (int ancho){Ancho=ancho;}
	inline void SetAlto (int alto){Alto=alto;}
	inline void Nuevo (){EscX=EscY=1;}
	inline void SetEsc(double ex,double ey){EscX=ex;EscY=ey;}

	void PintarPlano (CDC *dc);
	void Seno (CDC *dc);
};
