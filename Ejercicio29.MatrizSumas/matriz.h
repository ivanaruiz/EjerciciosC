#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una funcion para que, dada una matriz cuadrada de numeros, obtenga la sumatoria
de los elementos que estan por encima de la diagonal principal(excluida esta).
Lo mismo para la diagonal secundaria.
Lo mismo incluyendo la diagonal.
Lo mismo, con los que están por debajo de la diagonal.*/

#define TAM 50  //numero por default, es como un máximo

void mostrar(int mat[][TAM], int ff, int cc);
int sumaDiagPrin(int mat[][TAM], int ff, int cc);
int sumaDiagPrinIncluyeDiag(int mat[][TAM], int ff, int cc);
int sumaDiagSecunIncluyeDiag(int mat[][TAM], int ff, int cc);
int sumaDiagSecun(int mat[][TAM], int ff, int cc);
int sumaDiagSecunInferior(int mat[][TAM], int ff, int cc);
int sumaDiagSecunInferiorIncluyeDiag(int mat[][TAM], int ff, int cc);
int sumaDiagPrinInferiorIncluyeDiag(int mat[][TAM], int ff, int cc);
int sumaDiagPrinInferior(int mat[][TAM], int ff, int cc);

#endif // MATRIZ_H_INCLUDED
