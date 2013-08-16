
package triqui.interfaz;

import java.awt.Color;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class PanelMensajes extends JPanel
{
    private JLabel mensajeJuego;
    public PanelMensajes( )
    {
        setLayout( new FlowLayout( ) );
        mensajeJuego = new JLabel( );
        mensajeJuego.setForeground( Color.BLUE);
        mensajeJuego.setHorizontalAlignment( JLabel.LEFT);
        add( mensajeJuego );
        setBackground( Color.cyan);}
    
    public void desplegarMensaje( String valor )
    {
        mensajeJuego.setText( valor );}
}
