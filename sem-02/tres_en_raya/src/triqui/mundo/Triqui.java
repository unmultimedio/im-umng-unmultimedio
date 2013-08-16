
package triqui.mundo;
public class Triqui
{
    final public static int SUPERIOR_IZQUIERDA = 1;
    final public static int SUPERIOR_CENTRO = 2;
    final public static int SUPERIOR_DERECHA = 3;
    final public static int MEDIO_IZQUIERDA = 4;
    final public static int MEDIO_CENTRO = 5;
    final public static int MEDIO_DERECHA = 6;
    final public static int INFERIOR_IZQUIERDA = 7;
    final public static int INFERIOR_CENTRO = 8;
    final public static int INFERIOR_DERECHA = 9;
    private Casilla casilla1;
    private Casilla casilla2;
    private Casilla casilla3;
    private Casilla casilla4;
    private Casilla casilla5;
    private Casilla casilla6;
    private Casilla casilla7;
    private Casilla casilla8;
    private Casilla casilla9;
    
    public Triqui( )
    {
        casilla1 = new Casilla( );
        casilla2 = new Casilla( );
        casilla3 = new Casilla( );
        casilla4 = new Casilla( );
        casilla5 = new Casilla( );
        casilla6 = new Casilla( );
        casilla7 = new Casilla( );
        casilla8 = new Casilla( );
        casilla9 = new Casilla( );}
    
    public void marcarCasilla( int casilla, String marca )
    {
        switch( casilla )
        {
            case SUPERIOR_IZQUIERDA:
                casilla1.asignarMarca( marca );
                break;
            case SUPERIOR_CENTRO:
                casilla2.asignarMarca( marca );
                break;
            case SUPERIOR_DERECHA:
                casilla3.asignarMarca( marca );
                break;
            case MEDIO_IZQUIERDA:
                casilla4.asignarMarca( marca );
                break;
            case MEDIO_CENTRO:
                casilla5.asignarMarca( marca );
                break;
            case MEDIO_DERECHA:
                casilla6.asignarMarca( marca );
                break;
            case INFERIOR_IZQUIERDA:
                casilla7.asignarMarca( marca );
                break;
            case INFERIOR_CENTRO:
                casilla8.asignarMarca( marca );
                break;
            case INFERIOR_DERECHA:
                casilla9.asignarMarca( marca );}
    }
    
    public String obtenerMarcaCasilla( int casilla )
    {
        switch( casilla )
        {
            case SUPERIOR_IZQUIERDA:
                return casilla1.obtenerMarca( );
            case SUPERIOR_CENTRO:
                return casilla2.obtenerMarca( );
            case SUPERIOR_DERECHA:
                return casilla3.obtenerMarca( );
            case MEDIO_IZQUIERDA:
                return casilla4.obtenerMarca( );
            case MEDIO_CENTRO:
                return casilla5.obtenerMarca( );
            case MEDIO_DERECHA:
                return casilla6.obtenerMarca( );
            case INFERIOR_IZQUIERDA:
                return casilla7.obtenerMarca( );
            case INFERIOR_CENTRO:
                return casilla8.obtenerMarca( );
            case INFERIOR_DERECHA:
                return casilla9.obtenerMarca( );
            default:
                return Casilla.CASILLA_VACIA;}
    }
    
    public boolean diagonalPrincipalLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla1.contieneMarca( marcaJugador ) && casilla5.contieneMarca( marcaJugador ) && casilla9.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}
    
    public boolean diagonalSecundariaLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla3.contieneMarca( marcaJugador ) && casilla5.contieneMarca( marcaJugador ) && casilla7.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}
    
    public boolean filaSuperiorLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla1.contieneMarca( marcaJugador ) && casilla2.contieneMarca( marcaJugador ) && casilla3.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}
    
    public boolean filaMediaLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla4.contieneMarca( marcaJugador ) && casilla5.contieneMarca( marcaJugador ) && casilla6.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}

    public boolean filaInferiorLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla7.contieneMarca( marcaJugador ) && casilla8.contieneMarca( marcaJugador ) && casilla9.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}

    public boolean columnaIzquierdaLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla1.contieneMarca( marcaJugador ) && casilla4.contieneMarca( marcaJugador ) && casilla7.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}

    public boolean columnaCentralLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla2.contieneMarca( marcaJugador ) && casilla5.contieneMarca( marcaJugador ) && casilla8.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}

    public boolean columnaDerechaLlena( String marcaJugador )
    {
        boolean contiene = false;
        if( casilla3.contieneMarca( marcaJugador ) && casilla6.contieneMarca( marcaJugador ) && casilla9.contieneMarca( marcaJugador ) )
            contiene = true;
        return contiene;}

    public boolean casillaVacia( int casilla )
    {
        switch( casilla )
        {
            case SUPERIOR_IZQUIERDA:
                return casilla1.estaVacia( );
            case SUPERIOR_CENTRO:
                return casilla2.estaVacia( );
            case SUPERIOR_DERECHA:
                return casilla3.estaVacia( );
            case MEDIO_IZQUIERDA:
                return casilla4.estaVacia( );
            case MEDIO_CENTRO:
                return casilla5.estaVacia( );
            case MEDIO_DERECHA:
                return casilla6.estaVacia( );
            case INFERIOR_IZQUIERDA:
                return casilla7.estaVacia( );
            case INFERIOR_CENTRO:
                return casilla8.estaVacia( );
            case INFERIOR_DERECHA:
                return casilla9.estaVacia( );
            default:
                return false;}
    }
    public boolean tableroLleno( )
    {
        boolean estaLleno = ! ( casilla1.estaVacia( ) || casilla2.estaVacia( ) || casilla3.estaVacia( ) || casilla4.estaVacia( ) || casilla5.estaVacia( ) || casilla6.estaVacia( ) || casilla7.estaVacia( ) || casilla8.estaVacia( ) || casilla9.estaVacia( ) );
        return estaLleno;}
    
    public boolean ganoJuego( String marca )
    {
        boolean gano = ( diagonalPrincipalLlena( marca ) || diagonalSecundariaLlena( marca ) || filaSuperiorLlena( marca ) || filaMediaLlena( marca ) || filaInferiorLlena( marca ) || columnaIzquierdaLlena( marca ) || columnaCentralLlena( marca ) || columnaDerechaLlena( marca ) );
        return gano;}
    
    public void limpiarTablero( )
    {
        casilla1.limpiar( );
        casilla2.limpiar( );
        casilla3.limpiar( );
        casilla4.limpiar( );
        casilla5.limpiar( );
        casilla6.limpiar( );
        casilla7.limpiar( );
        casilla8.limpiar( );
        casilla9.limpiar( );}
}