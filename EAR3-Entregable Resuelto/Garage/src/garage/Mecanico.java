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
public class Mecanico {
    
    //Atributos
    final private String nombre;
    final private String apellido;
    
    //Constructor parametrizado
    Mecanico(String nombre, String apellido)
    {
        this.nombre   = nombre;
        this.apellido = apellido;
    }
    
    //Sobrecarga del método toString
    @Override
    public String toString()
    {   
        return "Mecanico(nombre= " + nombre + ", apellido=" + apellido + ")";
    }
}
