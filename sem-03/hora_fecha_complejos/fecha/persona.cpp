/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//  persona.cpp
#include "persona.h"
#include <string.h>

// 
persona::persona(char* name = "", long cc = 0, Date birth=(0,0,0) )


// inicializadores
: cc(cc), fechaNac(birth)

{

strcpy(nombre, name);

}
