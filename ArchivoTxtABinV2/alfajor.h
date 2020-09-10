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

/*Programa que crea desde cero un archivo de texto y luego lo convierte a archivo binario*/
/*Uso fgets y sscanf*/

#endif // ALFAJOR_H_INCLUDED
