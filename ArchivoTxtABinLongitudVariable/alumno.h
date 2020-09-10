#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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


int crear_arch_texto(char *path);
void separar_campos(char *texto, t_alumno *alu);
int leer_arch_bin(char *path);

/*Programa que crea un archivo de texto desde cero,
y luego lo convierte a binario en longitud variable.
Este formato tiene el problema que al tener pipes
(o cualquier otro simbolo que use para separar), el archivo
binario no me lo lee. Asi que debo eliminarlos*/


#endif // ALUMNO_H_INCLUDED
