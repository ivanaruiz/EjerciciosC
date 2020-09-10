#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
/**
                 100
        50		          150
    10	   60	     110      175
      25     75	       125	     200	 **/
int cmp_enteros(const void * a1, const void * a2);
unsigned leerDesdeVectorEnteros(void **d, void *vec, unsigned pos, void * params);
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params);
void imprimir(void * info, unsigned tam, unsigned n, void * params);
void imprimirArch(void * info, unsigned tam, unsigned n, void * params);



int main()
{
    tArbolBinBusq ar;
    crearArbol(&ar);

    //notar que con este vec ordenado, no me sirve la funcion insertarArbolBinBusq
    //entonces uso las otras funciones de cargarDesdeDatosOrdenados
    int vec[] = {10, 25, 50, 60, 75, 100, 110, 125, 150, 175, 200};
//    int vec[] = {100, 50, 25, 10, 30, 75, 60, 90, 150, 125, 110, 130, 175, 160, 200};
//    int vec[] = {100, 50, 25, 75, 150, 125, 175};
//    int vec[] = {25, 50, 75, 100, 125, 150, 175};

    //con esta funcion puedo cargar los datos ordenados
    cargarDesdeDatosOrdenadosArbolBinBusq(&ar, vec, sizeof(vec)/sizeof(int), leerDesdeVectorEnteros, NULL);


    printf("Recorrido el arbol en orden:\n ");
    recorrerEnOrdenArbolBinBusq(&ar, NULL, imprimir);

    printf("\n\nRecorrido el arbol en preorden:\n ");
    recorrerPreOrdenArbolBinBusq(&ar, NULL, imprimir);

    printf("\n\nRecorrido el arbol en posorden:\n ");
    recorrerPosOrdenArbolBinBusq(&ar, NULL, imprimir);

    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");

    system("pause");
    return 0;
}




int cmp_enteros(const void * a1, const void * a2)
{
    const int * e1 = (const int*) a1;
    const int * e2 = (const int*) a2;
    return *e1 -*e2;
}

//en el parametro mando &(*p)->info
unsigned leerDesdeVectorEnteros(void **d, void *vec, unsigned pos, void * params)
{
    *d = malloc(sizeof(int));
    if(!*d)
        return 0;
    memcpy(*d, vec+(sizeof(int)*pos), sizeof(int));
    return sizeof(int);
}

//n es el nivels
void imprimir(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int*) info;
    printf("-%d-", *i);
}

//segun el nivel n, lo corre a la izq o derecha al nodo
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int*) info;
    printf("%*s-%3d-\n", n*3, "", *i);
}

void imprimirArch(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int*) info;
    fprintf((FILE*) params, "-%d-", *i);
}


