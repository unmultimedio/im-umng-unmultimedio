
package triqui.mundo;
public class JugadorPC
{
    private Triqui triqui;
    private String miMarca;
    public JugadorPC( Triqui juegoTriqui, String marca )
    {
        triqui = juegoTriqui;
        miMarca = marca;}
    public boolean jugar( )
    {
    	int siguienteCasilla = 0;
        boolean realizaJugada;
        if( triqui.casillaVacia( Triqui.SUPERIOR_IZQUIERDA ) )
            siguienteCasilla = Triqui.SUPERIOR_IZQUIERDA;
        else if( triqui.casillaVacia( Triqui.SUPERIOR_CENTRO ) )
            siguienteCasilla = Triqui.SUPERIOR_CENTRO;
        else if( triqui.casillaVacia( Triqui.SUPERIOR_DERECHA ) )
            siguienteCasilla = Triqui.SUPERIOR_DERECHA;
        else if( triqui.casillaVacia( Triqui.MEDIO_IZQUIERDA ) )
            siguienteCasilla = Triqui.MEDIO_IZQUIERDA;
        else if( triqui.casillaVacia( Triqui.MEDIO_CENTRO ) )
            siguienteCasilla = Triqui.MEDIO_CENTRO;
        else if( triqui.casillaVacia( Triqui.MEDIO_DERECHA ) )
            siguienteCasilla = Triqui.MEDIO_DERECHA;
        else if( triqui.casillaVacia( Triqui.INFERIOR_IZQUIERDA ) )
            siguienteCasilla = Triqui.INFERIOR_IZQUIERDA;
        else if( triqui.casillaVacia( Triqui.INFERIOR_CENTRO ) )
            siguienteCasilla = Triqui.INFERIOR_CENTRO;
        else if( triqui.casillaVacia( Triqui.INFERIOR_DERECHA ) )
            siguienteCasilla = Triqui.INFERIOR_DERECHA;
        
        if( siguienteCasilla == 0 )
        {
            realizaJugada = false;}
        else
        {
            triqui.marcarCasilla( siguienteCasilla, miMarca );
            realizaJugada = true;}
        return realizaJugada;}
}