#pragma once

class CLinea
{
	CPoint pi,pf;
	COLORREF cl;
public:
	CLinea(void);
	~CLinea(void);

	inline void SetPtoI (CPoint P){pi=P;}
	inline void SetPtoF (CPoint P){pf=P;}
	inline void SetPtoI (LONG x, LONG y){pi.x=x; pi.y=y;}
	inline void SetPtoF (LONG x, LONG y){pf.x=x; pf.y=y;}
	inline void SetColor (COLORREF c){cl=c;}

	void Dibujar		(CDC *dc);
};
