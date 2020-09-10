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
public class Revision extends Trabajo{
    
    final private float costoRevision;
    
    //Constructor parametrizado
    Revision(String descripcion, int cantHoras, float costoRevision)
    {
        super(descripcion, cantHoras);
        this.costoRevision = costoRevision;
    }
    
    //Método costoTrabajo
    public void costoTrabajo(float costoRevision)
    {
        float costoFinal;
        costoFinal= this.costoRevision * 1.5f + super.costoTrabajo();
        System.out.println("El presupuesto es: $" + costoFinal);
    }
    
    @Override
    public String toString()
    {
        return super.toString() + "Revision(costo Revision=" + costoRevision + ")";
    }
}
