#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TODO_MAL    1
#define TODO_OK     0

typedef struct
{
    int d,m,a;
}t_fecha;

typedef struct
{
    int leg;
    char nya[20];
    t_fecha fec;
}t_empleado;


int cargar_archivo(char * path);
int leer_archivo(FILE * pf, t_empleado *emp);

#endif // EMPLEADO_H_INCLUDED
