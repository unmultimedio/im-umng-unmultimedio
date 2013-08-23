/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//Vector.cpp
//
/////////////
#include "Vector.h"//si lanza errores, intente con <>
CVector :: CVector ()//por defecto
{
 //Se inicializa sin memoria y sin valores.
 aTama = 0;
 aVec = NULL;
}
CVector :: CVector (int *paVec, int paTama)//sobrecargado

{
 paVec=NULL;
 //Se le da memoria dinámica
 aTama = paVec.set_aTama(paTama);
 aVec = new int [aTama];
 paVec = aVec;
}
CVector :: CVector (CVector & Copia)//copia
{
 aTama = Copia.get_aTama();
 aVec = new int [aTama];
 aVec = Copia.get_aVec();                                                                                                        
}
CVector :: ~CVector ()//destructor
{
 if(aVec!=NULL)
  delete [] aVec;
}
void CVector :: set_aTama (int paTama)//darle tamaño
{
 
 if(paTama >= 0)
 {
  aTama = paTama;
  cout<<"El vector ahora es de "<<paTama<<" posiciones."<<endl;
 }
 else
 {
  aTama = 0;
  cout<<"El vector no puede ser de "<<paTama<<" posiciones, se le ha dado el valor de cero."<<endl;
 }
 aVec = new int [aTama];
}
void CVector :: set_aVec (int *paVec)//llenar posiciones
{
 int i;
 aVec = paVec;
 for (i=0; i<get_aTama(); i++)
 {
  cout<<"¿Posicion #"<<i+1<<" del vector?"<<endl;
  cin>> aVec[i];
  //Llena todas las posiciones del vector.
 }
 paVec = aVec;
}
//operacionalidad:
int CVector :: sumarDatos (int *paVec, int paTama)
{
 int escalar=0,i;
 
 for (i=0; i<paTama; i++)
  escalar += paVec[i];
 return escalar;
}
void CVector :: ordenarVector (int *paVec, int paTama)
{
 int i,j,k;
 for(i=0; i<paTama; i++)
 {
  for(j=i+1; j<paTama; j++)
  {
   if(paVec[i]>paVec[j])
   {
    k=paVec[i];
    paVec[i]=paVec[j];
    paVec[j]=k;
   }
  }
 }
 aVec = paVec;
}
int CVector :: encontrarDato (int *paVec, int paTama, int pDato)
{
 int i=0,pos=0;
 aVec = paVec;
 
 while (i<paTama && pos==0)
 {
  if (aVec[i]==pDato)
  {
   pos=i+1;
  }else{}
  i++;
 }
 return pos;
}
void CVector :: llenarPosicion (int *paVec, int pDato, int pPos)
{
 aVec = paVec;
 
 if (pPos<get_aTama()){
  aVec[pPos+1] = pDato;
  cout<<"Dato correctamente sobre-escrito."<<endl;
 }else{
	 cout<<"La posicion ingresada es invalida."<<endl;}
}
int CVector :: Imprimir (int *paVec)
{
 int i;
 paVec = aVec;
 for (i=0; i<get_aTama(); i++)
 {
  cout<<"Posicion #"<<i+1<<": "<<paVec[i]<<endl;
 }
}