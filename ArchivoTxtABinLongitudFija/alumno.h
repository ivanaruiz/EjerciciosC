#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


int crear_arch_texto(char *path);
int leer_arch_bin(char *path);

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

/*
Este programa crea un archivo de texto desde cero. Y luego lo convierte a archivo binario de LONGITUD FIJA.
*/

#endif // ALUMNO_H_INCLUDED
