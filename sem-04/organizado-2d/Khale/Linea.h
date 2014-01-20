#pragma once

class CLinea
{
	CPoint pi,pf;
	COLORREF cl;
public:
	CLinea(void);
	~CLinea(void);

	inline int GetPtoIx(){return pi.x;}
	inline int GetPtoIy(){return pi.y;}
	inline int GetPtoFx(){return pf.x;}
	inline int GetPtoFy(){return pf.y;}
	inline void SetPtoI (CPoint P){pi=P;}
	inline void SetPtoF (CPoint P){pf=P;}
	inline void SetPtoI (LONG x, LONG y){pi.x=x; pi.y=y;}
	inline void SetPtoF (LONG x, LONG y){pf.x=x; pf.y=y;}
	inline void SetColor (COLORREF c){cl=c;}

	void DDA		(CDC *dc);
	void Bressenham	(CDC *dc);
	void Punteada	(CDC *dc);
};
