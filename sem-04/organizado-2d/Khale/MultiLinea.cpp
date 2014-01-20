#include "StdAfx.h"
#include "MultiLinea.h"

CMultiLinea::CMultiLinea(void)
{
	N=0;
	cml=RGB(0,0,0);
}

CMultiLinea::~CMultiLinea(void)
{
}

void CMultiLinea::Dibuje(CDC *dc)
{
	int i;
	for(i=0;i<=N;i++)
		Lista[i].DDA(dc);
}
void CMultiLinea::Nuevo()
{
	for (int i=0;i<=N;i++)
	{
		Lista[i].SetPtoI(0,0);
		Lista[i].SetPtoF(0,0);
	}
	N=0;
}