#pragma once
#include "Linea.h"

class CMultiLinea
{
	CLinea Lista [100];
	int N;
	COLORREF cml;

public:
	CMultiLinea(void);
	~CMultiLinea(void);

	inline void Sumar (CLinea aux){Lista[N]=aux; Lista[N].SetColor(cml); N++;}
	inline void SetColor (COLORREF c){cml=c;}

	void Nuevo ();
	void Dibuje (CDC *dc);
};
