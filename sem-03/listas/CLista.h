/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//CLista.h
//////////

#include "CNodo.h"
//agregaremos los métodos de los nodos, los seis básicos.

class CLista
{
private:
	CNodo* Lista;
	int C;

public:
	
	CLista ()//por defecto
	{
		CNodo* p = new CNodo (0,0);
		Lista = p;
		C=-1;
	}

	~CLista ()//destructor
	{
		delete [] Lista;
	}

	void mCrear ();
	
	void mProbar ();

	void mVer (int pPos);

	void mInsertar (int pDato, int pPos);

	void mEliminarDatas (int pData);

	void mEliminarPos (int pPos);

	void mEliminarBoth (int pPos, int pData);

	void mDestruir ();

	void imprimir ();
	
	//métodos constructores, destructores, set y get.
	//1.crear 2.probar 3.ver 4.insertar 5.eliminar 6.destruir
};
