
package triqui.mundo;
public class Casilla
{
    final public static String CASILLA_VACIA = "";
    private String marca;
    public Casilla( )
    {
        marca = CASILLA_VACIA;}
    public void asignarMarca( String unaMarca )
    {
        marca = unaMarca;}
    public String obtenerMarca( )
    {
        return marca;}
    public boolean estaVacia( )
    {
        boolean esta = false;
        if( marca.equals( CASILLA_VACIA ) )
            esta = true;
        return esta;}
    public void limpiar( )
    {
        marca = CASILLA_VACIA;}
    public boolean contieneMarca( String unaMarca )
    {
        boolean esta = marca.equals( unaMarca );
        return esta;}
}