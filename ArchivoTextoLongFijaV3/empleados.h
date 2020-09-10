#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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

#endif // EMPLEADOS_H_INCLUDED
