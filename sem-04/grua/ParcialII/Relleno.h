#pragma once

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

	void Rellenar (CDC *dc);
};
