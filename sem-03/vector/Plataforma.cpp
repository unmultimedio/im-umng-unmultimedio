/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//Plataforma.cpp
//
/////////////////
#include "Vector.h"//si lanza errores, intente con <>

void main ()
{
 int Tama,Dato,*pVec,op,Pos;
 CVector Vec1;//Crea un Vector como parámetro del atributo aVec.
 cout<<"¡Hola!, Este es un programa diseñado para"<<endl;
 cout<<"trabajar arreglos de una dimension."<<endl;
 cout<<"Ingrese el numero de posiciones del vector:"<<endl;
 cin>>Tama;
 Vec1.set_aTama (Tama);//Le da memoria dinámica
 pVec = new int [Tama];//Memoria dinámica al apuntador
 cout<<"Ahora ingrese los datos del vector:"<<endl;
 Vec1.set_aVec (pVec);//Llena Vec1, y pVec.
do{
 cout<<"¿Que desea hacer?"<<endl;
 cout<<"1. Ver la suma de los datos del vector."<<endl;
 cout<<"2. Ver el vector ordendo."<<endl;
 cout<<"3. Encontrar un dato en el vector."<<endl;
 cout<<"4. Sobre-escribir en una posicion del vector."<<endl;
 cout<<"5. Salir de la aplicacion."<<endl;
 cin>>op;
 switch (op)
 {
  case 1:
   cout<<"La suma de los datos del vector son:"<<endl;
   Vec1.sumarDatos (pVec, Tama);
  break;
  case 2:
   cout<<"El mismo vector ordenado es: (Se modificara el original)"<<endl;
   Vec1.ordenarVector (pVec, Tama);
   Vec1.Imprimir (pVec);
  break;
  case 3:
   cout<<"¿Que dato quiere buscar?"<<endl;
   cin>>Dato;
   cout<<"El dato se encuentra en la posicion: "<<Vec1.encontrarDato (pVec, Tama, Dato)<<" del vector."<<endl;
   cout<<"(Si el dato devuelto es cero, el dato no se encuentra en el vector)"<<endl;
  break;
  case 4:
   cout<<"¿Que dato quiere sobre-escribir?"<<endl;
   cin>>Dato;
   cout<<"¿En que posicion?"<<endl;
   cin>>Pos;
   Vec1.llenarPosicion (pVec, Dato, Pos);
  break;
  default:
   cout<<"Ingrese una opcion posible."<<endl;
  break;
 }
 
}while (op != 5);
 cout<<"El resultado final fue: "<<endl;
 Vec1.Imprimir (pVec); 
 
 //~CVector Vec1;//No estoy seguro de llamar al destructor acá o si V1 se auto-destruye.
 //Los Constructores sobrecargado y copia se usan en aplicaciones con más de un vector.
}