#include "StdAfx.h"
#include "PoliLinea.h"

CPoliLinea::CPoliLinea(void)
{
	N=0;
	cpl=RGB(0,0,0);
}

CPoliLinea::~CPoliLinea(void)
{
}

void CPoliLinea::Dibuje(CDC *dc)
{
	CLinea linea;
	for (int i=0;i<N-1;i++)
	{
		linea.SetPtoI(Lista[i]);
		linea.SetPtoF(Lista[i+1]);
		linea.SetColor(cpl);
		linea.DDA(dc);
	}
}

void CPoliLinea::Cerrar(CDC *dc)
{
	Lista[N]=Lista[0];
	N++;
	CPoliLinea::Dibuje(dc);
}

void CPoliLinea::Nuevo()
{
	for (int i=0;i<=N;i++)
		Lista[i]=0;
	N=0;
}