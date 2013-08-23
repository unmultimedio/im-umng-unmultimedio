/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//Plataforma.cpp
////////////////

//principal... el que se corre.
#include "CLista.h"
void main ()
{
	int op, posCon, posIn, datoIn, opDel, datoDel, posDel, perm=0;
	char confDest, limPan, yaCre=0;
	CLista L;
	
	do{
		do{

		cout<<"----Menu Principal---"<<endl;
		cout<<"Bienvenido a Listas.Programacion III.UMNG"<<endl;
		cout<<"Por favor escoja una opcion:"<<endl;
		cout<<"1. Crear una Lista por defecto. (se borrara la Lista actual, si la hay)"<<endl;
		cout<<"2. Probar la existencia y cantidad de una una Lista."<<endl;
		cout<<"3. Ver un nodo en la Lista."<<endl;
		cout<<"4. Insertar un nodo en la Lista."<<endl;
		cout<<"5. Eliminar un nodo de la lista."<<endl;
		cout<<"6. Destruir una Lista actual."<<endl;
		cout<<"7. Salir de la aplicacion."<<endl;
		cin>>op;

			if(op==3 || op==5 || op==6)
			{
				if(yaCre==0)
				{
					system("cls");
					cout<<"Porfavor, hay que crear primero la Lista!"<<endl<<endl;
					perm=0;//autorizacion para ejecutar acciones 3, 5 y 6 en la lista.
				}else{
					perm=1;
				}
			}else{
				perm=2;
			}
		}while(perm==0);


		switch(op)
		{
		case 1:
			L.mCrear();
			yaCre=1;
		break;

		case 2:
			L.mProbar();
		break;

		case 3:
			cout<<"Que posicion desea consultar?"<<endl;
			cout<<"Nodo # ";
			cin>> posCon;

			L.mVer (posCon);
		break;

		case 4:
			cout<<"En que posicion desea insertar?"<<endl;
			cout<<"Nodo # ";
			cin>> posIn;

			cout<<"Que dato desea ingresar en el nodo # "<<posIn<<"?"<<endl;
			cout<<"Dato : ";
			cin>> datoIn;

			L.mInsertar(datoIn,posIn);
			yaCre=1;
		break;

		case 5:
			cout<<"¿De que forma desea eliminar?"<<endl;
			cout<<"1. Todos los datos que concidan con un dato ingresado."<<endl;
			cout<<"2. Un Nodo especifico."<<endl;
			cout<<"3. Un Nodo y un Dato cooncordantes especificos."<<endl;
			cin>>opDel;

			switch (opDel)
			{
			case 1:
				cout<<"Cual es el dato que desea borrar?"<<endl;
				cin>>datoDel;

				L.mEliminarDatas (datoDel);
			break;

			case 2:
				cout<<"Que posicion desea borrar?"<<endl;
				cout<<"Nodo # ";
				cin>> posDel;

				L.mEliminarPos (posDel);
			break;

			case 3:
				cout<<"Que posicion desea borrar?"<<endl;
				cout<<"Nodo # ";
				cin>> posDel;

				cout<<"Que dato se encuentra en el nodo # "<<posDel<<"?"<<endl;
				cout<<"Dato : ";
				cin>> datoDel;

				L.mEliminarBoth (posDel, datoDel);
			break;

			default:
				cout<<"Opcion Invalida, rectifique."<<endl;
			}
		break;

		case 6:
			cout<<"Esta seguro que desea destruir la Lista actual? (S/N)"<<endl;
			cin>>confDest;

			if(confDest=='S' || confDest=='s')
			{
				L.mDestruir();
				cout<<"Lista correctamente destruida"<<endl;
				yaCre=0;
			}else{
				cout<<"Lista Salvada"<<endl;
			}
		break;

		case 7:
			cout<<"Saliendo de la aplicacion..."<<endl;
			system("pause");
		break;

		default:
			cout<<"Opcion Invalida, rectifique."<<endl;
		}

		if(op!=7)
		{
			cout<<"Desea Limpiar pantalla? (S/N)"<<endl;
			cin>>limPan;

			if(limPan=='S' || limPan=='s')
				system("cls");
		}

		if(yaCre==1 && op!=7)
		{
			cout<<"La lista actual es: "<<endl;
			L.imprimir();
			cout<<endl;
		}

	}while (op!=7);
	
	cout<<"Gracias por confiar en nuestros servicios!."<<endl;

	system ("pause");
	//menu, opciones... bla bla bla.
}