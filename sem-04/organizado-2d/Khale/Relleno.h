#pragma once
#include "Linea.h"
#include "Pila.h"

class CRelleno
{
public:
	CPoint s;
	COLORREF cr;

public:
	CRelleno(void);
	~CRelleno(void);

	inline void SetColorRelleno (COLORREF R){cr=R;}
	inline void SetPtoRelleno (CPoint S){s=S;}
	inline void SetPtoRelleno (LONG x, LONG y){s.x=x; s.y=y;}

	void Vecindad4 (CDC *dc);
	void Frontera (CDC *dc);
	int XLim(CPoint p, CDC *dc, int c);
};
