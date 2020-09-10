#ifndef ALFAJOR_H_INCLUDED
#define ALFAJOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargar_archivo(char *path);
int leer_archivo_bin(char *path);

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}t_alfajor;

/*
Este programa crea un archivo de texto desde cero,
y luego lo convierte a archivo binario.
Finalmente muestra el archivo binario por pantalla.
*/

#endif // ALFAJOR_H_INCLUDED
