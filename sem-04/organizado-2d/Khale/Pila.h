#pragma once

class CPila
{
public:
	CPila(void);
	~CPila(void);

	CPoint Pila [1000];
	int N;
	void Apilar (CPoint p);
	void Desapilar ();
	void GetTope ();

};
