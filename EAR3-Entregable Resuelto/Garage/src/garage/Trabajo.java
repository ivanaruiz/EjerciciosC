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
public class Trabajo {
    
    //atributo estático asociado a la clase (pertenece a la clase, y no a los objetos)
    private static int contadorTrabajos;    
    //atributos asociados a los objetos
    private int idTrabajo;
    private String descripcion;
    private int cantHoras;
    
    private static final int PRECIO_POR_HORA = 800;
    
    //Constructor por defecto
    Trabajo()
    {
        contadorTrabajos++;
        this.idTrabajo = contadorTrabajos;
    }
    
    //Constructor parametrizado
    Trabajo(String descripcion, int cantHoras)
    {   
        //Llamo al constructor por defecto
        this();
        this.descripcion = descripcion;
        this.cantHoras   = cantHoras;
    }
    
    //Método costoTrabajo
    public float costoTrabajo()
    {
        float costo = this.cantHoras * PRECIO_POR_HORA;
        return costo;
    }
    
    //Getter. Solo hago el getter que considero necesario y usaré
     public static int getContadorTrabajos(){
        return contadorTrabajos;
    }
    
    @Override
    public String toString()
    {   
        return "Trabajo(idTrabajo=" + idTrabajo + ", descripcion=" + descripcion + ", cantHoras=" + cantHoras + ")";
    }
}
