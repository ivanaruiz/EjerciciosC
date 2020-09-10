#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 7
#define linea puts("");

void mostrarMatrizCompleta(int mat[][TAM]);
void trianguloArriba(int mat[][TAM]);
void trianguloAbajo(int mat[][TAM]);
void trianguloIzquierda(int mat[][TAM]);
void trianguloDerecha(int mat[][TAM]);

void triangulo(int mat[][TAM]);

/*
Crear funciones que hagan lo siguiente:
Mostrar por pantalla el triangulo que se forma a arriba de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma abajo de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma a la izquierda de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma a la derecha de las diagonales principal y secundaria.

El problema de esta resolucion es que la matriz la recorre entera.
Buscaremos hacerlo de otra manera mas pero que no recorra la matriz entera, sino solo los datos que nos pide mostrar.

*/

#endif // MATRICES_H_INCLUDED
