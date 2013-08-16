
package triqui.interfaz;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import triqui.mundo.JugadorPC;
import triqui.mundo.Triqui;

public class InterfazTriqui extends JFrame
{
    private final static String MARCA_JUGADOR = "X";
    private final static String MARCA_PC = "O";
    private PanelTriqui triquiPanel;
    private PanelBotones botonesPanel;
    private PanelMensajes mensajesPanel;
    private Triqui juegoTriqui;
    private JugadorPC jugadorPC;
    public InterfazTriqui( String titulo )
    {
        triquiPanel = new PanelTriqui( this );
        botonesPanel = new PanelBotones( this );
        mensajesPanel = new PanelMensajes( );
        setPreferredSize( new Dimension( 300, 300 ) );
        add( mensajesPanel, BorderLayout.PAGE_END);
        add( triquiPanel, BorderLayout.CENTER );
        add( botonesPanel, BorderLayout.NORTH );
        setTitle( titulo );
        pack( );
        setResizable( false );
        setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        mensajesPanel.desplegarMensaje( "Universidad Militar Nueva Granada" );
        juegoTriqui = new Triqui( );
        jugadorPC = new JugadorPC( juegoTriqui, MARCA_PC );}
    
    public void nuevoJuego( )
    {
    	juegoTriqui.limpiarTablero( );
        JButton botonReiniciar;
        for( int i = 1; i <= 9; i++ )
        {
            botonReiniciar = ( JButton )triquiPanel.getComponent( i - 1 );
            botonReiniciar.setEnabled( true );
            botonReiniciar.setText( "" );}
    }
    
    public void procesaJugada( String casillaJugada )
    {
    	int casilla;
        casilla = Integer.valueOf( casillaJugada ).intValue( );
        juegoTriqui.marcarCasilla( casilla, MARCA_JUGADOR );
        if( juegoTriqui.ganoJuego( MARCA_JUGADOR ) )
        {
            mensajesPanel.desplegarMensaje( "Vale!!! Ganaste... xD" );
            JButton botonReiniciar;
            for( int i = 1; i <= 9; i++ )
            {
                botonReiniciar = ( JButton )triquiPanel.getComponent( i - 1 );
                botonReiniciar.setEnabled( false );}
        }
        else
        {
            mensajesPanel.desplegarMensaje( "...Mi turno..." );
            if( jugadorPC.jugar( ) )
            {
                if( juegoTriqui.ganoJuego( MARCA_PC ) )
                {
                    mensajesPanel.desplegarMensaje( "Qué paso?... y eso que jugué fácil!" );
                    JButton botonReiniciar;
                    for( int i = 1; i <= 9; i++ )
                    {
                        botonReiniciar = ( JButton )triquiPanel.getComponent( i - 1 );
                        botonReiniciar.setEnabled( false );}
                }
                else
                    mensajesPanel.desplegarMensaje( "...Tu turno..." );}
            else
            {
                mensajesPanel.desplegarMensaje( "Buen empate :D" );}
        }
    }
    
    public void repintarTriqui( )
    {
        String marca;
        JButton botonReiniciar;
        for( int i = 1; i <= 9; i++ )
        {
            botonReiniciar = ( JButton )triquiPanel.getComponent( i - 1 );
            if( !juegoTriqui.casillaVacia( i ) )
            {
                marca = juegoTriqui.obtenerMarcaCasilla( i );
                botonReiniciar.setText( marca );
                botonReiniciar.setEnabled( false );}
        }
    }
    
    public static void main( String[] args )
    {
        InterfazTriqui gui = new InterfazTriqui( "Triqui-fácil" );
        gui.setVisible( true );}
}