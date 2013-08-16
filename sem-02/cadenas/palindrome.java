/**
* DOCUMENT CREATED BY JULIAN R. FIGUEROA
* about.me/julianrfigueroa
* This work is under a Creative 
* Commons License Atribution-ShareAlike 
* 3.0 Unported. CC-BY-SA
*/
import javax.swing.JOptionPane;
class palindrome{ 
      public static void main (String [] args){ 
             int tamano;
             String palabra,entrada,a,b;          
             JOptionPane.showMessageDialog(null,"¡Hola!\n\nEste es un programa diseñado para que tu\ncompruebes si una frase o una palabra\nes palíndrome.", "Universidad Militar Nueva Granada, Programación 2",JOptionPane.INFORMATION_MESSAGE);            
             entrada=JOptionPane.showInputDialog(null,"Ingrese lo que desea comprobar (teniendo en cuenta que para comprobarla se toman en cuenta espacios).\nNO INSERTE PALABRAS CON TILDE");
             palabra = String.valueOf(entrada);  
             tamano = palabra.length(); 
             int cuenta=0;
             int j=tamano-1;
             for(int i=0;i<tamano;i++) { 
            	 a=String.valueOf(palabra.charAt(j));
            	 b=String.valueOf(palabra.charAt(i));
                   if(a.equalsIgnoreCase(b)){      
                         cuenta++;}
                  j--;} 
      if(cuenta==tamano)
    	  JOptionPane.showMessageDialog(null,"\n\t La palabra ó frase \""+palabra+"\" es Palindrome");
      else 
    	  JOptionPane.showMessageDialog(null,"\n\t La palabra ó frase \""+palabra+"\" NO es Palindrome");}
}