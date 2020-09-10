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
public class ReparacionChapa extends Reparacion  {
    
    ReparacionChapa(String descripcion, int cantHoras, float costoReparacion)
    {
        super(descripcion, cantHoras, costoReparacion);
    }
    
    
    public void costoTrabajo(float costoReparacion)
    {
        System.out.println("El costo total a cobrar es: $" + (super.costoTrabajo() + costoReparacion*2));
    }
    
    
    @Override
    public String toString()
    {   
        return super.toString();
    }
    
}
