#pragma once
#include "Linea.h"

class CPoliLinea
{
	CPoint Lista [100];
	int N;
	COLORREF cpl;

public:
	CPoliLinea(void);
	~CPoliLinea(void);

	inline void SetPunto(CPoint aux){Lista[N]=aux; N++;}
	inline void SetColor (COLORREF c){cpl=c;}
	
	void Nuevo ();
	void Dibuje (CDC *dc);
	void Cerrar (CDC *dc);
};
