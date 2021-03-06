#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 7
#define linea puts("");

void mostrarMatrizCompleta(int mat[][TAM]);
void trianguloSup(int mat[][TAM]);
void trianguloInf(int mat[][TAM]);
void trianguloIzq(int mat[][TAM]);
void trianguloDer(int mat[][TAM]);



/*
Crear funciones que hagan lo siguiente:
Mostrar por pantalla el triangulo que se forma arriba de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma abajo de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma a la izquierda de las diagonales principal y secundaria.
Mostrar por pantalla el triangulo que se forma a la derecha de las diagonales principal y secundaria.

Esta resolucion es la mas correcta pues solo recorre la matriz lo que el ejercicio exije mostrar.

*/

#endif // MATRIZ_H_INCLUDED
