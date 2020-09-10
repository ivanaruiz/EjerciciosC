#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "pila_estatica.h"

typedef struct
{
    int dni;
    char nya[20];
}t_persona;


int crear_arch_bin(char * path, char * modo_de_escritura);
void menu();
int buscar_en_arch(t_persona * pers_leer, char * path);
int leer_arch( char* path, char * modo_de_lectura);
int grabar_desde_cero(t_pila * p, char * path);
void actualizar_arch(t_pila * p, char * path);

/*
Escriba un programa que al comenzar lea(si lo puede abrir) un archivo de binario <"datos">, y lo cargue en una
pila con implementación estática de memoria. El archivo debe ser cerrado al terminar la carga de la pila.
A continuación, y valiéndose de una función con menú, que permita cargar más información en la pila, ver la
información del tope de la pila, sacar de la pila, salir del menú. Al salir del menú, se terminará de cargar
el archivo con la información que aún quede en la pila.
Si el archivo resultara vacío, deberá ser eliminado.
*/


#endif // PERSONA_H_INCLUDED
