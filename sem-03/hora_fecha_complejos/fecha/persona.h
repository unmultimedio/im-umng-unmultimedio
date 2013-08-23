/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//  persona.h
#include <iostream.h>
#include "date.h"
class persona {

private :


char nombre[25];
long cc;
const Date fechaNac;

public:


// constructor
persona(char*, long, Date);
char* getNombre(void)
{ return nombre; }
long getcc(void)
{ return cc; }
Date getFechaNac(void)
{ return fechaNac; }

};


