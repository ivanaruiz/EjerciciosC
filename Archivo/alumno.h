#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nya[40];
    char sexo;
    float prom;
    int notas[10];  //vector de notas, cada alumno puede tener hasta 10 notas diferentes
}t_alumno;

void guardarNotas(t_alumno *alu);

/*Crear un programa que pida por teclado que se ingresen los datos de un alumno
(dni, apellido y nombre, sexo, y notas (hasta que la nota sea 0, entonces se deja de ingresar)
por teclado y los guarde en un archivo binario.
El promedio no se pedirá al usuario. Se calculará luego.
El programa debe ir preguntando entre carga y carga si el usuario desea cargar otro alumno,
y debe ir guardando de a uno en el archivo.
Crear un programa que muestre el archivo creado en el punto anterior.
Es decir en este proyecto haremos la creacion del archivo. Luego crearemos un nuevo proyecto
(buscarlo como ArchivoContinuacion) y desde alli leeremos el archivo creado aca.*/

#endif // ALUMNO_H_INCLUDED
