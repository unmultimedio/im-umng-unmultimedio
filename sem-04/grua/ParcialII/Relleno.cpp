#include "StdAfx.h"
#include "Relleno.h"

CRelleno::CRelleno(void)
{
	s.x=0; s.y=0;
	cr=RGB(255,255,255);
}

CRelleno::~CRelleno(void)
{
}

void CRelleno::Rellenar(CDC *dc)
{
	CPoint a=s;
	if(dc->GetPixel(s)==RGB(255,255,255))
	{
		dc->SetPixel(s,cr);
		CRelleno::SetPtoRelleno(s.x+1,s.y);
		CRelleno::Rellenar(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x-1,s.y);
		CRelleno::Rellenar(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x,s.y+1);
		CRelleno::Rellenar(dc);
		s=a;
		CRelleno::SetPtoRelleno(s.x,s.y-1);
		CRelleno::Rellenar(dc);
	}
}