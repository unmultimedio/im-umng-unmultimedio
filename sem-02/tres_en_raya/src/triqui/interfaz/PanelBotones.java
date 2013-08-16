
package triqui.interfaz;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;

public class PanelBotones extends JPanel implements ActionListener
{
    
    private static final String JUEGO_NUEVO = "JUEGO_NUEVO";
    private JButton botonNuevoJuego;
    private InterfazTriqui principal;
    
    public PanelBotones( InterfazTriqui ventana )
    {
        principal = ventana;
        botonNuevoJuego = new JButton( );
        inicializarBoton( botonNuevoJuego, "Juego nuevo", PanelBotones.JUEGO_NUEVO, Color.BLACK );
        add( botonNuevoJuego );}
    private void inicializarBoton( JButton boton, String etiqueta, String comando, Color colorTexto )
    {
        boton.setText( etiqueta );
        boton.setFocusable( false );
        boton.setActionCommand( comando );
        boton.addActionListener( this );
        boton.setForeground( colorTexto );}
    
    public void actionPerformed( ActionEvent evento )
    {
        String actionCommand = evento.getActionCommand( );
        if( actionCommand.equals( PanelBotones.JUEGO_NUEVO ) )
        {
            principal.nuevoJuego( );}
    }
}
