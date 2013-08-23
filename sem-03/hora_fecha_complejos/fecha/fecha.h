/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
//  fecha.h

class Date {

private:


int dia;
int mes;
int year;

public:



Date(int dia=1, int mes=1, int anio=0) :
dia(dia), mes(mes), year(anio) {}
int getDia() const { return dia; }
int getMes() const { return mes; }
int getYear() const { return year; }

friend int ContarYears(const Date&, const Date&);

void setDia(int dia) { dia=dia; }
void setMes(int mes) { mes=mes; }
void setYear(int anio) { year=anio; }

};