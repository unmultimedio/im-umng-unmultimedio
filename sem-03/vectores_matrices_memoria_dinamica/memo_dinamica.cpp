/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/

#include <iostream.h>
#include <stdlib.h>

void crearmatrices (int);
void crearvectores (int);
void borrar ();

void llenarmatrices ();
void llenarunamatriz ();
void llenarvectores ();
void llenarunvector ();

void ppunto ();
void pescvector ();
void ordenarvector ();

void pmatrices ();
void pescalarmat ();
void traspuesta ();

void vervectores ();
void vermatrices ();

int i,j,k,operacion,opcion,vectorr,matrizr,tamano,escalar,esc;
char limpiar,salir;
int **m1, **m2, **mr, *v1, *v2, *vr;

void main() {

i=j=k=0;
do{
        do{

        cout<<"¡Hola!, Este es un programa diseñado para"<<endl;
        cout<<"trabajar arreglos de una y dos dimensiones."<<endl;
        cout<<"Por favor escoge la opcion mas conveniente:"<<endl<<endl;
        cout<<"1.Vector\n2.Matriz"<<endl;
        cin>>opcion;

        if(opcion<1 || opcion>2)
        cout<<"Por favor marque una opcion posible"<<endl;
        }while(opcion<1 || opcion>2);

        cout<<"Por favor ingresa el tamano con el que desees trabajar:"<<endl;
        cout<<"(para matrices se trabajaran en cuadrados)"<<endl;
        cin>>tamano;

		if (opcion==1)
		{
			crearvectores (tamano);
		}else{
			crearmatrices (tamano);
		}

        do{

			if (opcion==1)
			{
				cout<<endl<<"Que operacion desea realizar con los vectores?"<<endl;
				cout<<"1.Producto Punto entre dos vectores.\n2.Producto de un vector y un escalar.\n3.Ordenar un vector."<<endl;
				cin>>operacion;
			}else{
				cout<<endl<<"Que operacion desea realizar con las matrices?"<<endl;
				cout<<"1.Producto entre dos matrices.\n2.Producto de una matriz y un escalar.\n3.Obtener la matriz traspuesta de una matriz inicial."<<endl;
				cin>>operacion;
			}

			if(operacion<1 || operacion>3)
			{
                cout<<"Por favor marque una opcion posible"<<endl;
			}

        }while(operacion<1 || operacion>3);


	switch (operacion){

		case 1:

			if (opcion==1)
			{
				llenarvectores ();
				ppunto ();
				vervectores ();
			}else{
				llenarmatrices ();
				pmatrices ();
				vermatrices ();
			}
                       
		break;

		case 2:

			if (opcion==1)
			{
				llenarunvector ();
				pescvector ();
				vervectores ();
			}else{
				llenarunamatriz ();
				pescalarmat ();
				vermatrices ();
			}

                break;

                case 3:

			if (opcion==1)
			{
				llenarunvector ();
				ordenarvector ();
				vervectores ();
			}else{
				llenarunamatriz ();
				traspuesta ();
			}
        break;
	}

cout<<endl<<"Desea Limpiar Pantalla?(S/N)"<<endl;
cin>>limpiar;

if(limpiar=='s' || limpiar=='S')
{
	system("cls");
}

cout<<endl<<"Desea Salir del Programa?(S/N)"<<endl;
cin>>salir;


}while (salir!='s' && salir!='S');

borrar ();

}

void crearvectores (int tam)
{
	v1 = new int [tam];
	v2 = new int [tam];
	vr = new int [tam];
}

void crearmatrices (int tam)
{
	m1 = new int *[tam];
	for (i=0; i<tam; i++)
	{
		m1[i] = new int [tam];
	}

	m2 = new int *[tam];
	for (i=0; i<tam; i++)
	{
		m2[i] = new int [tam];
	}

	mr = new int *[tam];
	for (i=0; i<tam; i++)
	{
		mr[i] = new int [tam];
	}
}

void llenarvectores ()
{
	for(i=0; i<tamano; i++)
	{
		cout<<endl<<"Ingrese el valor numero "<<i+1<<" del vector #1 de "<<tamano<<" posiciones a operar."<<endl;
		cin>>v1 [i];
	}

	for(i=0; i<tamano; i++)
	{
		cout<<endl<<"Ingrese el valor numero "<<i+1<<" del vector #2 de "<<tamano<<" posiciones a operar."<<endl;
		cin>>v2 [i];
	}
}

void llenarunvector ()
{
	for(i=0; i<tamano; i++)
	{
		cout<<endl<<"Ingrese el valor numero "<<i+1<<" del vector de "<<tamano<<" posiciones a operar."<<endl;
		cin>>vr [i];
	}
}



void vervectores ()
{
	if(v1!=NULL)
	{
		cout<<"Los Vectores son:"<<endl<<endl;
		for(i=0; i<tamano; i++)
		{
			cout<<v1 [i]<<"  ";
		}
	}else{
		cout<<"No hay vector uno por mostrar"<<endl;
	}

	if(v2!=NULL)
	{
		cout<<endl<<", y"<<endl;
		for(i=0; i<tamano; i++)
		{
			cout<<v2 [i]<<"  ";
		}
	}else{
		cout<<"No hay vector dos por mostrar"<<endl;
	}
	
	if(vr!=NULL)
	{
		cout<<endl<<", y el resultado es:"<<endl;
		for(i=0; i<tamano; i++)
		{
			cout<<vr [i]<<"  ";
		}
	}else{
		cout<<"No hay vector resultado por mostrar"<<endl;
	}

	if(vectorr!=NULL)
	{
		cout<<endl<<"El escalar resultado del producto punto es:"<<endl<<vectorr<<".";
	}else{
		cout<<"No hay escalar resultado por mostrar"<<endl;
	}
}


void llenarmatrices ()
{
	for(i=0; i<tamano; i++)
	{
    	for(j=0;j<tamano;j++)
		{
			cout<<endl<<"Ingresa el valor de la columna #"<<i+1<<" y de la fila #"<<j+1<<" de la matriz #1 a operar."<<endl;
			cin>>m1[i][j];
		}
	}
	for(i=0; i<tamano; i++)
	{
		for(j=0;j<tamano;j++)
		{
			cout<<endl<<"Ingresa el valor de la columna #"<<i+1<<" y de la fila #"<<j+1<<" de la matriz #2 a operar."<<endl;
			cin>>m2 [i][j];
		}
	}
}

void llenarunamatriz ()
{
	for(i=0; i<tamano; i++)
	{
    	for(j=0;j<tamano;j++)
		{
			cout<<endl<<"Ingresa el valor de la columna #"<<i+1<<" y de la fila #"<<j+1<<" de la matriz a operar."<<endl;
			cin>>mr[i][j];
		}
	}
}

void vermatrices ()
{
	if(m1!=NULL)
	{
		cout<<"Las matrices son:"<<endl<<endl;
		for(i=0; i<tamano; i++)
		{
			for(j=0;j<tamano;j++)
			{
				cout<<m1 [i][j]<<"  ";
			}
			cout<<endl;
		}
	}else{
		cout<<"No hay matriz uno por mostrar"<<endl;
	}

	if(m2!=NULL)
	{
		cout<<endl<<", y"<<endl;
		for(i=0; i<tamano; i++)
		{
			for(j=0;j<tamano;j++)
			{
				cout<<m2 [i][j]<<"  ";
			}
		cout<<endl;
		}
	}else{
		cout<<"No hay matriz dos por mostrar"<<endl;
	}

	if(mr!=NULL)
	{
		cout<<endl<<", y el resultado es:"<<endl;
		for(i=0; i<tamano; i++)
		{
			for(j=0;j<tamano;j++)
			{
				cout<<mr [i][j]<<"  ";
			}
			cout<<endl;
		}
	}else{
		cout<<"No hay matriz resultado por mostrar"<<endl;
	}	
}

void ppunto ()
{
	
	vectorr=0;
	for(i=0; i<tamano; i++)
	{
		vectorr = vectorr + (v1[i]*v2[i]);
	}
}

void pescvector ()
{
	cout<<"Ingrese el escalar por el cual quiere multiplicar el vector:"<<endl;
	cin>>esc;

	for(i=0; i<tamano; i++)
	{
		vr[i] = (vr[i]*esc);
	}
}

void ordenarvector ()
{
	
	
	for(i=0; i<tamano; i++)
	{
		for(j=i+1; j<tamano; j++)
		{
			if(vr[i]>vr[j])
			{
				k=vr[i];
				vr[i]=vr[j];
				vr[j]=k;
			}
		}
	}
}

void pmatrices ()
{
	
	for(i=0; i<tamano; i++)
	{
        for(j=0; j<tamano; j++)
		{
        	matrizr = 0;
        	for(k=0; k<tamano; k++)
			{
        			matrizr = matrizr + (m1[i][k]*m2[k][i]);
			}
            mr[i][j] = matrizr;
		}
	}
}

void pescalarmat ()
{
	
	cout<<"Ingrese el escalar por el cual quiere multiplicar la matriz:"<<endl;
	cin>>escalar;

	for(i=0; i<tamano; i++)
	{
		for(j=0; j<tamano; j++)
		{
			mr[i][j] = (mr[i][j]*escalar);
		}
	}
}

void traspuesta ()
{
	
	cout<<"La matriz original:"<<endl<<endl;
	for(i=0; i<tamano; i++)
	{
		for(j=0;j<tamano;j++)
		{
			cout<<mr [i][j]<<"  ";
		}
		cout<<endl;
	}

	cout<<endl<<"Y la matriz traspuesta de ésa original es:"<<endl<<endl;
	for(i=0; i<tamano; i++)
	{
		for(j=0;j<tamano;j++)
		{
			cout<<mr [j][i]<<"  ";
		}
		cout<<endl;
	}
	
}

void borrar ()
{
	if(v1!=NULL)
	{
		delete []v1;
	}

	if(v2!=NULL)
	{
		delete []v2;
	}

	if(vr!=NULL)
	{
		delete []vr;
	}

	if(m1!=NULL)
	{
		for(i=0; i<tamano; i++)
		{
			delete []m1[i];
		}
		delete []m1;
	}
	
	if(m2!=NULL)
	{
		for(i=0; i<tamano; i++)
		{
			delete []m2[i];
		}
		delete []m2;
	}

	if(mr!=NULL)
	{
		for(i=0; i<tamano; i++)
		{
			delete []mr[i];
		}
		delete []mr;
	}
}