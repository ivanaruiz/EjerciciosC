#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

/*
Desarrollar una funcion para que, dada una matriz cuadrada de enteros, obtenga la traza de la misma
(sumatoria de los elementos de la diagonal principal).
Lo mismo, pero con la diagonal secundaria.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 50

void mostrarMatriz(int mat[][TAM], int ff, int cc);
int trazaDiagPrincipal(int mat[][TAM], int ff, int cc);
int trazaDiagSecundaria(int mat[][TAM], int ff, int cc);

#endif // MATRIZ_H_INCLUDED
