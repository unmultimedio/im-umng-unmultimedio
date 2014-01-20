#pragma once
#include <math.h>
#include "Linea.h"

class CElipse
{
	CPoint c,pi,pf;
	int rx,ry;
	COLORREF ce;
	double PI;
public:
	CElipse(void);
	~CElipse(void);

	inline void SetPtoI (CPoint P){pi=P;}
	inline void SetPtoF (CPoint P){pf=P;}
	inline void SetPtoI (LONG x, LONG y){pi.x=x; pi.y=y;}
	inline void SetPtoF (LONG x, LONG y){pf.x=x; pf.y=y;}
	inline void SetColor (COLORREF c){ce=c;}

	void Dibujar	(CDC *dc);
};
