/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
#include <iostream>
#include <complex>


using namespace std;
class complejo
{};
void main () {
	complex<double> x(0.0,0.0),y(0.0,0.0),z,*c;
	int op;
	double re,im;
	do{
	do{
	   
	   cout<<"\n1. Ingrese del primer numero complejo\n";
	   cout<<"2. Ingrese del segundo numero complejo\n";
	   cout<<"3. Suma de numeros complejos\n";
	   cout<<"4. Resta de numeros complejos\n";
	   cout<<"5. Multiplicacion de numeros complejos\n";
	   cout<<"6. Division de numeros complejos\n";
	   cout<<"7. Salir\n";
	   cout<<"Introduce opcion: ";
	   cin>>op;
	   } while (op<1 || op>7);
	
	 switch (op)
	 {
	 
	case 1:
		 
			 cout<<"Introduce la parte real : ";cin>>re;
	        	 cout<<"Introduce la parte imaginaria: ";cin>>im;
			 c= new complex <double> (re,im);
			 x=*c;
			 delete c;
			 break;
      	case 2:
		  
			 cout<<"Introduce la parte real del segundo numero: ";cin>>re;
	         	 cout<<"Introduce la parte imaginaria: ";cin>>im;
			 c= new complex <double> (re,im);
			 y=*c;
			 delete c;
			 break;
	 case 3: 
		  
		  	z=x+y;
	          	cout<<"\nLa suma de x= "<<x<< " y de y= "<<y<<" es igual a z= "<<z<<endl;
			break;
	 case 4: 
		  
		 	 z=x-y;
	         	 cout<<"\nLa resta de x= "<<x<< " y de y= "<<y<<" es igual a z= "<<z<<endl;
			 break;
	 case 5:
		  
		 	 z=x*y;
	          	 cout<<"\nLa multiplicacion de x= "<<x<< " y de y= "<<y<<" es igual a z= "<<z<<endl;
			 break;
	 case 6:
		  
		 	 z=x/y;
	          	 cout<<"\nLa division de x= "<<x<< " y de y= "<<y<<" es igual a z= "<<z<<endl;
			 break;

	}
	 cout << z << "i";
	}while (op!=7);
	system("pause");
 }
