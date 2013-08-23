/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

// Hora

class Hora {

public:
   Hora(); // constructor
   void estableceHora( int h, int m, int s ); 
   void imprimeColombia();          
   void imprimeArgentina();          

private:
   int hora;     
   int minuto;   
   int segundo;  
}; 

// constructor Hora 

Hora::Hora()
 { 
	hora = minuto = segundo = 0; 
}


void Hora::estableceHora( int h, int m, int s )

{
   hora = ( h >= 0 && h < 24 )  ;h : 0;
   minuto = ( m >= 0 && m < 60 )  ;m : 0;
   segundo = ( s >= 0 && s < 60 )  ;s : 0;
} 

// Hora Colombia
void Hora::imprimeColombia()
{
   cout << ( hora < 10 ? "0" : "" ) << hora << ":"
        << ( minuto < 10 ? "0" : "" ) << minuto;
} 

// Hora Argentina
void Hora::imprimeArgentina()
{
   cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12+2 )<< ":" << ( minuto < 10 ? "0" : "" ) << minuto<< ":" << ( segundo < 10 ? "0" : "" ) << segundo<< ( hora < 12 ? " AM" : " PM" );
} 


int main()
{
   Hora h;  
	cout << "La hora inicial es ";
	h.imprimeColombia();

   
   h.estableceHora(1, 35,30 );
   
   cout << "\n\nLa hora en Colombia despues de estableceHora es ";
   
   h.imprimeColombia();
   
   cout << "\nLa hora en Argentina despues de estableceHora es ";
   
   h.imprimeArgentina();

   
 
   return 0;
} 