#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nya[10];
}t_alumno;

int leer_arch_ord(char *path);
void intercambio(t_alumno *alu, t_alumno *men);
void buscar_menor_y_actualizar( FILE *pf, t_alumno *alu, t_alumno *men, int cv);

/*
Se crea un archivo binario con una estructura simple de alumno. pero la estructura estara con los datos desordenados.
A partir del metodo de seleccion, ordenaremos la estructura y la actualizamos en el archivo binario.
*/

#endif // ALUMNO_H_INCLUDED
