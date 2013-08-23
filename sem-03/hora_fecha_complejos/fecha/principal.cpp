/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//  principal.cpp

#include <iostream.h>
#include "persona.h"

int ContarYears(const Date& hoy, const Date& birth);


void main(void)
{


persona* m = new persona("Pepito Perez", 1234567890, Date(12, 05, 1976));

persona i("Rosita Rosales", 0987654321, Date(03, 11, 1992));

Date hoy(8,9,2008);

cout << m->getNombre() << " tiene " <<

ContarYears(hoy, m->getFechaNac()) <<" de edad" << endl;

cout << i.getNombre() << " tiene " <<

ContarYears(hoy, i.getFechaNac()) <<" de edad" << endl;

cout << "Estos son sus codigos, y edades actuales" << endl;

}



int ContarYears(const Date& hoy, const Date& birth)

{

int years = hoy.year - birth.year;
if ((birth.mes <= hoy.mes) && (birth.dia <= hoy.dia))
return years;
else
return (years-1);

}


