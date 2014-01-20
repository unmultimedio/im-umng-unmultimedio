#include "StdAfx.h"
#include "Pila.h"

CPila::CPila(void)
{
	N=-1;
}

CPila::~CPila(void)
{
}

void CPila::Apilar(CPoint p)
{
	if(N<999)
	{
		N++;
		Pila[N]=p;
	}
}

void CPila::Desapilar()
{
	N--;
}