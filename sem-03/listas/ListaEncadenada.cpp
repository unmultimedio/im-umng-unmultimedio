/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//ListaEncadenada.cpp
///////////////////

#include "CLista.h"

void CLista :: mCrear ()
{//Comprueba si hay lista existente, la elimina y crea una nueva por defecto, con dato cero.
	if(C!=-1 && C!=0)
	{
		delete [] Lista;
		cout<<"Lista existente borrada exitosamente..."<<endl;
	}
	CNodo* p = new CNodo ();
	Lista = p;
	C=1;
	cout<<"Lista nueva creada exitosamente, Info: "<<Lista->Info<<", posiciones: "<<C<<"."<<endl;
}

void CLista :: mProbar ()
{//Comprueba si la lista ya ha sido creada, y muestra la cantidad de nodos.
	if(C==-1)
	{
		cout<<"La lista no ha sido creada aun."<<endl;
	}else{
		cout<<"Ya existe una lista creada."<<endl;
		cout<<"Cantidad de nodos: "<<C<<endl;
	}
}

void CLista :: mVer (int pPos)
{
	if(pPos<=0 || pPos > C)
	{
		cout<<"La posicion es invalida, rectifiquela."<<endl;
	}else{
		int i;
		CNodo* a = Lista;
		for (i=1; i<pPos; i++)
			a = a->Next;
		cout<<"El nodo en la posicion :"<<pPos<<" contiene: "<<a->Info<<"."<<endl;
	}
	cout<<"Recuerde que el(los) nodo(s) actual(es) es(son): "<<C<<endl;
}

void CLista :: mInsertar (int pDato, int pPos)
{
	if(C==-1 && pPos==1)
	{//Si la lista no ha sido creada, sólo crea un nodo
		CNodo* p = new CNodo (pDato, 0);
		Lista = p;
		C=1;
		cout<<"Primer y unico nodo correctamente creado."<<endl;
	}else{
		int tIn,i;
		if (pPos == 1)
		{
			tIn = 1;
		}else{
			if (pPos <= C && pPos > 1)
			{
				tIn = 2;
			}else{
				if (pPos == C+1)
					tIn = 3;
				else
					tIn = 4;
			}
		}
		CNodo *a, *p;
		switch (tIn)
		{
			case 1://caso de modificacion del primer nodo.
				p = new CNodo (pDato, Lista);
				Lista = p;
				C++;
				cout<<"Primer lugar nodo correctamente modificado."<<endl;
			break;
			case 2://caso de modificacion de nodos intermedios.
				a = Lista;
				for (i=1;i<pPos-1;i++)
					a = a->Next;
				p = new CNodo (pDato,a->Next);
				a->Next = p;
				C++;
				cout<<"Lugar "<<pPos<<" correctamente modificado."<<endl;
			break;
			case 3://caso de modificacion de nodo final.
				a = Lista;
				for (i=1;i<C;i++)
					a = a->Next;
				p = new CNodo (pDato,0);
				a->Next = p;
				C++;
				cout<<"Ultimo lugar correctamente modificado."<<endl;
			break;
			default://posicion inválida
				cout<<"La posicion es invalida, rectifiquela."<<endl;
		}
		cout<<"Dato modificado (si la posicion fue valida): "<<pDato<<", Cantidad actual de nodos: "<<C<<"."<<endl;
	}
}

void CLista :: mEliminarDatas (int pData)
{
	CNodo *p = Lista;//"p" guarda direcciones y recorre como observador. 
	int i,j,nn=0, infoDel;
	for (i=1;i<=C;i++)
	{
		if (p->Info == pData)
		{
			if(C==1)//si se pide eliminar el único nodo que quede.
			{
				infoDel = p->Info;
				delete [] p;
				C=0;
				nn++;
			}else{//con 2 o más nodos.
				CNodo* a = p;//"a" Nodo a eliminar.
				if(i==1)//Si se necesita eliminar el primer nodo.
				{
					Lista = Lista->Next;//se corre el inicio una posición
					infoDel = a->Info;//guarda la info a borrar.
					p = p->Next;//guarda dirección, sube una posición.
					a->Next = NULL;//Se da dirección nula al nodo a eliminar.
					delete [] a;//se elimina el nodo.
					C--;
					cout<<"Nodo en primera posicion, con el dato :"<<infoDel<<", correctamente eliminado."<<endl;
					nn++;
				}else{//eliminando cualquiera de los demás nodos.
					CNodo* b = Lista;//"b" da continuidad por atrás.
					for(j=1; j<i; j++)//desde el inicio hasta antes del actual "i".
						b = b->Next;//se conecta al nodo anterior a "a".
					infoDel = a->Info;//guarda la info a borrar.
					p = p->Next;//guarda dirección, sube una posición.
					b->Next = p;//conecta nodo de atrás y de adelante.
					a->Next = NULL;//Se da dirección nula al nodo a eliminar.
					delete [] a;//se elimina el nodo.
					C--;
					cout<<"Nodo en la posicion: "<<i<<", con el dato :"<<infoDel<<", correctamente eliminado."<<endl;
					nn++;
				}
			}
		}else{
			p = p->Next;//sube una posición.
		}	
	}
	cout<<"Numero de nodos encontrados y eliminados con el dato "<<pData<<": "<<nn<<"."<<endl;
}

void CLista :: mEliminarPos (int pPos)
{
	if (pPos<=0 || pPos > C)
	{
		cout<<"La posicion es invalida, rectifiquela."<<endl;
	}else{
		CNodo* p = Lista;
		int i,infoDel;
		if(C==1)//si se pide eliminar el único nodo que quede.
		{
			infoDel = p->Info;
			delete [] p;
			C=0;
		}else{//con 2 o más nodos.
			for (i=1;i<pPos-1;i++)
				p = p->Next;
			CNodo* a = p->Next;//"a" Nodo a eliminar
			p->Next = a->Next;//guarda la dirección del siguiente nodo.
			infoDel = a->Info;//guarda Info a eliminar.
			a->Next = NULL;//dirección nula al nodo a eliminar.
			delete [] a;//elimina el nodo.
			C--;
		}
		cout<<"Nodo en la posicion: "<<pPos<<", con el dato :"<<infoDel<<", correctamente eliminado."<<endl;
	}
}

void CLista :: mEliminarBoth (int pPos, int pData)
{
	if (pPos<=0 || pPos>C)
	{
		cout<<"La posicion es invalida, rectifiquela."<<endl;
	}else{
		int i, infoDel;
		CNodo* p = Lista;
		for (i=1;i<pPos-1;i++)
			p = p->Next;
		
		if(C==1)//si se pide eliminar el único nodo que quede.
		{
			if(Lista->Info == pData)
			{
				infoDel = Lista->Info;
				delete [] p;
				C=0;
				cout<<"El nodo en la unica posicion, con el dato: "<<infoDel<<", se ha borrado correctamente."<<endl;
			}else{
				cout<<"El nodo en la primera posicion, con el dato : "<<Lista->Info<<", no concuerda con el dato: "<<pData<<"; No se ha eliminado."<<endl;
			}
		}else{//con 2 o más nodos.
			CNodo* a = p->Next;//"a" Nodo a eliminar
			if (a->Info == pData)//comprueba concoordancia entre la Info en la posicion, y la Info pedida.
			{
				infoDel = a->Info;//guarda la info a eliminar.
				p->Next = a->Next;//guarda la dirección del siguiente nodo.
				a->Next = NULL;//dirección nula al nodo a eliminar.
				delete [] a;//elimina el nodo.
				C--;
				cout<<"Nodo en la posicion: "<<pPos<<", con el dato :"<<infoDel<<", correctamente eliminado."<<endl;
			}else{
				cout<<"El nodo en la posicion: "<<pPos<<", con el dato :"<<a->Info<<", no concuerda con el dato: "<<pData<<"; No se ha eliminado."<<endl;
			}
		}
	}
}

void CLista :: mDestruir ()
{
	CNodo* p = Lista;
	if(C!=0)
	{
		int i;
		for (i=1; i<=C; i++)//lleva a "p" a la última posición.
		{
			CNodo* a = p;//"a" Nodo a eliminar.
			p = p->Next;//"p" aumenta una posición.
			a->Next = NULL;//nulidad.
			delete [] a;//elimina a.
		}
		delete [] p;
	}
	C=-1;
	Lista = NULL;
}

void CLista :: imprimir ()
{
	if(C==-1 || C==0)
	{
		cout<<"No hay Lista aun, o fue creada pero no tiene nodos."<<endl;
	}else{
		int i;
		CNodo* a = Lista;
		for (i=1; i<=C; i++)//lleva hasta la última posición.
		{
			cout<<"Nodo #"<<i<<": "<<a->Info<<endl;
			a = a->Next;
		}
	}
	
}

//se implementan las operaciones del CLista.h