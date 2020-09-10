#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,m,a;
}t_fecha;

typedef struct
{
    int dni;
    char nya[30];
    t_fecha fec;
    float prom;
}t_alumno;

int crear_arch_bin(char *path);
int leer_arch_bin(char *path, t_alumno *alu);


/*Programa que crea un archivo binario de cero y luego lo convierte en archivo de texto
en formato variable
*/


#endif // ALUMNO_H_INCLUDED
