#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d;
    int m;
    int a;
}t_fecha_ing;


typedef struct
{
    int dni;
    char nya[40];
    char sexo;
    float prom;
    int notas[10];
    t_fecha_ing fecha;
    char estado;
}t_alumno;


int cargarArchivo(char * path, char * modoApertura);
int leerArchivo(char * path, char * modoApertura);

/*
Crearemos un archivo binario con una estructura con varios alumnos.
Luego procedemos a leer el archivo.
Y luego haremos una actualizacion del mismo.
Los que tengan fecha de ingreso menor al año 2000, se cambiara el estado
de ACTIVO(A) a INACTIVO(I).
Por ultimo leemos el archivo ya actualizado.
*/

#endif // ALUMNO_H_INCLUDED
