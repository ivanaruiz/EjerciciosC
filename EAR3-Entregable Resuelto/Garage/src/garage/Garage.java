/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package garage;

import java.util.Scanner;
/**
 *
 * @author 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965)
 */
public class Garage {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String nombre, apellido, reparacion;
        int cantHoras;
        float costoMateriales;
        
        Scanner teclado = new Scanner(System.in);  
        
        System.out.print("Ingrese Nombre: ");
        nombre = teclado.nextLine();
        
        System.out.print("Ingrese Apellido: ");
        apellido = teclado.nextLine();
        
        Mecanico m1 = new Mecanico(nombre, apellido);    
        System.out.println(m1.toString());
       
        System.out.print("Ingrese nombre de la reparacion: ");
        reparacion = teclado.nextLine();
        
        System.out.print("Ingrese Cant de Horas trabajadas: ");
        cantHoras= teclado.nextInt();
        
        System.out.print("Ingrese costo de materiales gastados: ");
        costoMateriales = teclado.nextFloat();
                  
        ReparacionChapa r1 = new ReparacionChapa(reparacion, cantHoras, costoMateriales);
        System.out.println(r1.toString());
        r1.costoTrabajo(costoMateriales);
        
        teclado.nextLine();
        System.out.println("---------------------------------\n");
        
              
        System.out.print("Ingrese nombre de la reparacion: ");
        reparacion = teclado.nextLine();
        
        System.out.print("Ingrese Cant de Horas a trabajar: ");
        cantHoras= teclado.nextInt();
        
        System.out.print("Ingrese costo de materiales a gastar: ");
        costoMateriales = teclado.nextFloat();        
        
        Revision rv1 = new Revision(reparacion, cantHoras, costoMateriales);
        System.out.println(rv1.toString());       
        rv1.costoTrabajo(costoMateriales);
        
        System.out.println("La cantidad de trabajos realizados por el mecanico fue:" + Trabajo.getContadorTrabajos());
    }
}