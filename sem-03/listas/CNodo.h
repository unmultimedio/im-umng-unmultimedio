/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//CNodo.h
/////////

#include <iostream>
#include <stdlib.h>
using namespace std;

class CNodo //ClaseNodo
{//no se declara en parte privada por comodidad de uso en set_ y get_
public:
	int Info;//el tipo de dato que guarda el nodo
	CNodo* Next;//el apuntador que debe apuntar a otro nodo, "Clase autoreferenciada"
//Contador de nodos

	CNodo ()//por defecto
	{
		Info = 0;
		Next = NULL;

	}
	CNodo (int pInfo, CNodo* pNext)//sobrecargado
	{//si viene con informacion, se inicializa con ésa informacion, si no, se inicializa
	 // como un por defecto.
		Info = pInfo;
		Next = pNext;

	}
};
//Una lista enlazada es una secuencia de nodos.
//No se puede comparar quien es mayor ni menor, salvo con la información.
//Se pueden agregar más datos sin necesidad de declarar de nuevo la lista.