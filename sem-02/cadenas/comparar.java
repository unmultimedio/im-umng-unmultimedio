/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
import javax.swing.JOptionPane;
public class comparar {
	public static void main(String[] args) {
		String vector[],tamano,acum,acum2;
		int i,j,cantidad,iguales=0;
		acum=acum2="";
	    tamano=JOptionPane.showInputDialog(null,"¡Hola!\n\nEste es un programa diseñado para que \ntu compruebes cuántas veces se repite\nuna palabra en un vector de i posiciones.\n\nDeseas ingresar ¿? posiciones (palabras):","Universidad Militar Nueva Granada, Programación 2",JOptionPane.INFORMATION_MESSAGE);            
	    cantidad=Integer.parseInt(tamano);
	    vector=new String [cantidad];
	    for(i=0;i<cantidad;i++){
	    	vector[i]=JOptionPane.showInputDialog(null,"Ingresa la palabra número "+(i+1)+":","Ingreso de datos #"+(i+1),JOptionPane.INFORMATION_MESSAGE);}
	    for(i=0;i<cantidad;i++){
	    	for(j=i+1;j<cantidad;j++){
	    		if(vector[i].equals(vector[j])){
	    			iguales++;
	    			acum=acum+"posición "+(i+1)+" con la posición "+(j+1)+"\n";}
	    	}
	    }
	    for(i=0;i<cantidad;i++){
		    acum2=acum2+String.valueOf(vector[i])+", ";
	    }
	    JOptionPane.showMessageDialog(null,"La cantidad de palabras iguales en el vector de\n"+cantidad+" posiciones\ny con las palabras:\n"+acum2+"\nes de:\n"+iguales+" palabras iguales\ncon coordenadas:\n"+acum,"RESULTADOS FINALES",JOptionPane.INFORMATION_MESSAGE);}
}