#pragma once
#include <math.h>

class CCirculo
{
public:
	
	CPoint c,b,pi,pf;
	int r,rx,ry;
	COLORREF cc;
	double PI;
	CCirculo(void);
	~CCirculo(void);

	inline void SetCentro (CPoint C){c=C;}
	inline void SetBorde (CPoint R){b=R;}
	inline void SetRadio (int r) {SetBorde(c.x+r,c.y);}
	inline void SetCentro (LONG x, LONG y){c.x=x; c.y=y;}
	inline void SetBorde (LONG x, LONG y){b.x=x; b.y=y;}
	inline void SetColor (COLORREF c){cc=c;}

	void Cartesiano	(CDC *dc);
	void Polar		(CDC *dc);
	void Bressenham	(CDC *dc);

	int CalcRadio ();
};
