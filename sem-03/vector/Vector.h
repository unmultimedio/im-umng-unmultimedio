/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
// Vector.h
//
////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
class CVector // ClaseVector
{
 private:
 
  int aTama;  // AtributoTamaño del vector
  int *aVec;  // AtributoVector puntero
 public:
  CVector ();     //constructor por defecto
  CVector (int *paVec, int paTama);  //constructor sobrecargado
  CVector (CVector & Copia);   //contructor copia
  ~CVector ();    //destructor
 inline int get_aTama ()
 {
  return aTama;
 }
 inline int get_aVec ()
 {
  return *aVec;
 }
 void set_aTama (int paTama);
 void set_aVec (int *paVec);
 //Métodos de operacionalidad: 
 int sumarDatos (int *paVec, int paTama);
 void ordenarVector (int *paVec, int paTama);
 int encontrarDato (int *paVec, int paTama, int pDato);
 void llenarPosicion (int *paVec, int pDato, int pPos);
 
 int Imprimir (int *paVec);
}