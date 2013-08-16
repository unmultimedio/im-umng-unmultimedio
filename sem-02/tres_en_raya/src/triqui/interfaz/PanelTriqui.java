
package triqui.interfaz;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
public class PanelTriqui extends JPanel implements ActionListener
{
    private JButton botonCasilla;
    private InterfazTriqui principal;
    public PanelTriqui( InterfazTriqui ventanaP )
    {
        principal = ventanaP;
        setLayout( new GridLayout( 3, 3, 3, 3 ) );
        setBackground( Color.black );
        inicializarTriqui( );}
    private void inicializarTriqui( )
    {
        for( int i = 1; i <= 9; i++ )
        {
            botonCasilla = new JButton( );
            botonCasilla.setFocusable( false );
            botonCasilla.setRolloverEnabled( false );
            botonCasilla.setBorderPainted( true );
            botonCasilla.setFont( botonCasilla.getFont( ).deriveFont( ( float )50.0 ) );
            botonCasilla.setPreferredSize( new Dimension( 15, 15 ) );
            botonCasilla.setName( String.valueOf( i ) );
            botonCasilla.addActionListener( this );
            botonCasilla.setActionCommand( String.valueOf( i ) );
            add( botonCasilla );}
    }
    
    public void actionPerformed( ActionEvent evento )
    {
        String actionCommand = evento.getActionCommand( );
        principal.procesaJugada( actionCommand );
        principal.repintarTriqui( );}
}
