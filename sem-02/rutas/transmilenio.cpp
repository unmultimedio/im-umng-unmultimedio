/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/

/**
* En el momento de creaci๓n de ้ste archivo
* los buses de TM y los horarios eran recientes
* ahora mismo los horarios y rutas han cambiado
*/
#include <iostream.h>
#include <stdlib.h>
#include <math.h>

int B1[22]={1}; // 500-2300
int F1[22]={1}; // 500-2300
//servicios expresos todos los dias.

int B70[22]={0,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,0}; // 430-900
int B14[22]={1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1}; // 500-2130
int B13[22]={1,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0}; // 500-2200
int B73[22]={1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0}; // 500-2300
int B52[22]={1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0}; // 530-830
int B53[22]={1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0}; // 530-830
int B71[22]={1,1,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0}; // 530-900
int B72[22]={1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0}; // 530-900
int B74[22]={1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0}; // 700-2200
int B61[22]={1,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1}; // 1630-1930
//servicios que van hacia el norte, lunes a sabado.

int F14[22]={1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1}; // 530-2200
int F61[22]={1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0}; // 1700-2000

int H70[22]={0,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,0}; // 500-900
int H74[22]={1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0}; // 500-2200
int H73[22]={0,1,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1}; // 530-900 y 1630-2000 
int H13[22]={1,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0}; // 530-2200
int H51[22]={1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0}; // 600-900
int H52[22]={1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; // 600-900
int H60[22]={1,1,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0}; // 1630-2000
int H61[22]={1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0}; // 1630-2000

int J70[22]={1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}; // 530-900
int J72[22]={1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0}; // 630-2130
//servicios que van hacia el sur, lunes a sabado. 

int B92[22]={1,1,0,0,0,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1}; // 600-2200
int B93[22]={1,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0}; // 600-2000
int H92[22]={1,1,0,0,0,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1}; // 600-2200
int H93[22]={1,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0}; // 700-2100
//servicios exclusivos de los domingos.

int ppartida, pllegada,hora, dia, i, j;
char apellidos[30], nombre [30];


void main ()
{

	cout<<"*** SISTEMA DE TRANSPORTE MASIVO TRANSMILENIO ***"<<endl;
	cout<<"Bogota D.C."<<endl<<endl;
	cout<<"El presente programa te mostrara las opciones de viaje en nuestro sistema"<<endl<<"desde el Portal del Norte, hasta la calle 45,"<<endl<<"imprimiendo tu tarjeta virtual electronica de viajero preferencial transmilenio.";

	cout<<"Ingresa tus apellidos: ";
	cin>>apellidos;

	cout<<"Ingresa tu nombre: ";
	cin>>nombre;

	do{
	cout<<"Cuentanos en que estacion te encuentras?"<<endl<<endl;
	cout<<"1. Portal del norte"<<endl<<"2. Toberin"<<endl<<"3. Cardio Infantil"<<endl<<"4. Mazuren"<<endl<<"5. Calle 146"<<endl<<"6. Calle 142"<<endl<<"7. Alcala"<<endl<<"8. Prado"<<endl<<"9. Calle 127"<<endl<<"10. Pepe Sierra"<<endl<<"11. Calle 106"<<endl<<"12. Calle 100"<<endl<<"13. Virrey"<<endl<<"14. Calle 85"<<endl<<"15. Heroes"<<endl<<"16. Calle 76"<<endl<<"17. Calle 72"<<endl<<"18. Flores"<<endl<<"19. Calle 63"<<endl<<"20. Calle 57"<<endl<<"21. Marly"<<endl<<"22. Calle 45"<<endl;
	cout<<"Digite el numero de la estacion: ";
	cin>>ppartida;
	i=ppartida;

	cout<<"Cuentenos a que estacion quiere llegar?"<<endl<<endl;
	cout<<"1. Portal del norte"<<endl<<"2. Toberin"<<endl<<"3. Cardio Infantil"<<endl<<"4. Mazuren"<<endl<<"5. Calle 146"<<endl<<"6. Calle 142"<<endl<<"7. Alcala"<<endl<<"8. Prado"<<endl<<"9. Calle 127"<<endl<<"10. Pepe Sierra"<<endl<<"11. Calle 106"<<endl<<"12. Calle 100"<<endl<<"13. Virrey"<<endl<<"14. Calle 85"<<endl<<"15. Heroes"<<endl<<"16. Calle 76"<<endl<<"17. Calle 72"<<endl<<"18. Flores"<<endl<<"19. Calle 63"<<endl<<"20. Calle 57"<<endl<<"21. Marly"<<endl<<"22. Calle 45"<<endl;
	cout<<"Digite la opcion: ";
	cin>>pllegada;
	j=pllegada;

	if (i<1 || i>22 || j<1 || j>22)
	{
		cout<<"Por favor verifica las estaciones, y marca las opciones bien"<<endl<<endl;
	}
	else {}
	}while (i<1 || i>22 || j<1 || j>22);

	cout<<"En que dia deseas viajar?"<<endl;
	cout<<"1. Domingo"<<endl<<"2. Lunes"<<endl<<"3. Martes"<<endl<<"4. Miercoles"<<endl<<"5. Jueves"<<endl<<"6. Viernes"<<endl<<"7. Sabado"<<endl;
	cin>>dia;

	switch (dia)
	{

	case 1:
	
		cout<<"A que horas deseas viajar?"<<"(favor ingresa datos sin simbolos, de 0600 a 2200)"<<endl;
		cin>>hora;
		
		do{	
		if (hora<600 || hora>2200)
		{	
			cout<<"Recuerda que el servicio de Transmilenio los Domingos funciona de 6:00 a.m. hasta las 10:00 p.m."<<endl;
		}
		else{}
		}while (hora<600 || hora>2200);
	
			if (hora>=600 && hora <700)
			{
				if (i<j)
				{
			 		if(F1[i]==1 && F1[j]==1)					จจ
					{
						cout<<"El bus F1 te sirve"<<endl;
					}
					else{}	
					if(H92[i]==1 && H92[j]==1)					จจ
					{
						cout<<"El bus H92 te sirve"<<endl;
					}
					else{}
				}
				else 
				{
					if (i>j)
					{
						if(B1[i]==1 && B1[j]==1)					จจ
						{
							cout<<"El bus B1 te sirve"<<endl;
						}
						else{}
						if(B92[i]==1 && B92[j]==1)					จจ
						{
							cout<<"El bus B92 te sirve"<<endl;
						}
						else{}
						if(B93[i]==1 && B93[j]==1)					จจ
						{
							cout<<"El bus B93 te sirve"<<endl;
						}
						else{}
					}
					else
					{
						cout<<"Las estaciones de partida y de llegada son las mismas, no te burles de mi, ya estas en tu destino."<<endl;
					}
				}
			}
			else
			{
				if (hora>=700 && hora <2000)
				{
	
					if (i<j)
					{
				 		if(F1[i]==1 && F1[j]==1)					จจ
						{
							cout<<"El bus F1 te sirve"<<endl;
						}
						else{}	
						if(H92[i]==1 && H92[j]==1)					จจ
						{
							cout<<"El bus H92 te sirve"<<endl;
						}
						else{}
						if(H93[i]==1 && H93[j]==1)					จจ
						{
							cout<<"El bus H93 te sirve"<<endl;
						}
						else{}
					}	
					else 	
					{
						if (i>j)
						{
							if(B1[i]==1 && B1[j]==1)					จจ
							{
								cout<<"El bus B1 te sirve"<<endl;
							}
							else{}
							if(B92[i]==1 && B92[j]==1)					จจ
							{
								cout<<"El bus B92 te sirve"<<endl;
							}
							else{}
							if(B93[i]==1 && B93[j]==1)					จจ
							{
							cout<<"El bus B93 te sirve"<<endl;
							}
							else{}
						}
						else
						{
							cout<<"Las estaciones de partida y de llegada son las mismas, no te burles de mi, ya estas en tu destino."<<endl;
						}
					}
				}
				else
				{

					if (hora>=2000 && hora <2100)
	
					{
						if (i<j)
						{
				 			if(F1[i]==1 && F1[j]==1)					จจ
							{
								cout<<"El bus F1 te sirve"<<endl;
							}
							else{}	
							if(H92[i]==1 && H92[j]==1)					จจ
							{
								cout<<"El bus H92 te sirve"<<endl;
							}
							else{}
							if(H93[i]==1 && H93[j]==1)					จจ
							{
								cout<<"El bus H93 te sirve"<<endl;
							}
							else{}
						}
						else 	
						{
							if (i>j)
							{
								if(B1[i]==1 && B1[j]==1)					จจ
								{
									cout<<"El bus B1 te sirve"<<endl;
								}
								else{}
								if(B92[i]==1 && B92[j]==1)					จจ
								{
									cout<<"El bus B92 te sirve"<<endl;
								}
								else{}
							}
							else
							{
								cout<<"Las estaciones de partida y de llegada son las mismas, no te burles de mi, ya estas en tu destino."<<endl;
							}
						}
					}
					else
					{
						if (hora>=2100 && hora <2200)
						{
							if (i<j)
							{
				 				if(F1[i]==1 && F1[j]==1)					จจ
								{
									cout<<"El bus F1 te sirve"<<endl;
								}
								else{}	
								if(H92[i]==1 && H92[j]==1)					จจ
								{
									cout<<"El bus H92 te sirve"<<endl;
								}
								else{}
							}
							else 	
							{
								if (i>j)
								{
									if(B1[i]==1 && B1[j]==1)					จจ
									{
										cout<<"El bus B1 te sirve"<<endl;
									}
									else{}
									if(B92[i]==1 && B92[j]==1)					จจ
									{
										cout<<"El bus B92 te sirve"<<endl;
									}
									else{}
								}
								else
								{
									cout<<"Las estaciones de partida y de llegada son las mismas, no te burles de mi, ya estas en tu destino."<<endl;
								}
							}
						}
						else {}
					}
				}
	
	break;

	case 2 : case 3 : case 4 : case 5 : case 6 : case 7:

		cout<<"A que horas deseas viajar?"<<"(favor ingresa datos sin simbolos, de 0430 a 2300)"<<endl;
		cin>>hora;

		do{	
		if (hora<430 || hora>2300)
		{	
			cout<<"Recuerda que el servicio de Transmilenio de Lunes a Sabado funciona de 4:30 a.m. hasta las 11:00 p.m."<<endl;
		}
		else {}
		}while (hora<430 || hora>2300);

	break;

	default:

		cout<<"Por favor ingrese bien el dia del viaje"<<endl;
	}
	
}
}