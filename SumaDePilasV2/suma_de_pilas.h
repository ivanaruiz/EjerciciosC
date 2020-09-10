#ifndef SUMA_DE_PILAS_H_INCLUDED
#define SUMA_DE_PILAS_H_INCLUDED

#define ARCHIVO_PATH "suma_de_pilas.txt"
#define TODO_BIEN 1
#define TODO_MAL 0

#include "pila_dinamica.h"

void sumar(t_pila * p1, t_pila * p2, t_pila * pRES);
int abrir_archivo(FILE **pf, char * path, char * modo_apertura);
void guardar_suma_en_txt(FILE * pf, t_pila *pRes);


#endif // SUMA_DE_PILAS_H_INCLUDED
