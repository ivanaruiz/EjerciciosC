/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package garage;

/**
 *
 * @author 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965)
 */
public class Reparacion extends Trabajo{
    
    final private float costoReparacion;
    
    //Constructor parametrizado
    Reparacion(String descripcion, int cantHoras, float costoReparacion)
    {
        super(descripcion, cantHoras);
        this.costoReparacion = costoReparacion;
    }
    
    //Método costoTrabajo
    @Override
    public float costoTrabajo()
    {
        return super.costoTrabajo();
    }
    
    @Override
    public String toString()
    {   
        return super.toString() + "Reparacion(costo Reparacion=" + costoReparacion + ")";
    }
}
