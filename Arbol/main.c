#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

/**
          100
	50		     150
25      75	            **/        //primer lote de pruebas

/**
            100
	50		        150
25      75	   110       180       **/      //segundo lote de pruebas para probar


/**
                        100
            50		                150
    25              75	        110     180
10     30        60    80                        **/        //tercer lote de pruebas

int cmp_enteros(const void * a1, const void * a2);
unsigned leerDesdeVectorEnteros(void **d, void *vec, unsigned pos, void * params);
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params);
void imprimir(void * info, unsigned tam, unsigned n, void * params);


int main()
{
    tArbolBinBusq ar;
    crearArbol(&ar);

    //con este vecPre en preorden si puedo usar la función insertarArbolBinBusq
    //sirve para datos que están en preorden, como este vector
    //  int vecPre[] = {100, 50, 25, 10, 30, 55, 52, 81, 150, 140, 180, 190, 170, 200, 195, 230, 250};  //preorden

    int vecPre[] = {100, 50, 25, 30, 75, 60, 85, 150, 210};  //preorden

    int tamVecPre = sizeof(vecPre)/sizeof(int);

    for(int i=0; i<tamVecPre; i++)
    {
        insertarArbolBinBusq(&ar, vecPre+i, sizeof(int), cmp_enteros);
    }

    printf("Recorrido el arbol en orden:\n ");
    recorrerEnOrdenArbolBinBusq(&ar, NULL, imprimir);

    int elemento;
    mayorElemNoClaveArbol(&ar, &elemento, sizeof(int), cmp_enteros);
    printf("\nmayor: %d", elemento);
    exit(0);

    printf("\n\nRecorrido el arbol en preorden:\n ");
    recorrerPreOrdenArbolBinBusq(&ar, NULL, imprimir);

    printf("\n\nRecorrido el arbol en posorden:\n ");
    recorrerPosOrdenArbolBinBusq(&ar, NULL, imprimir);

    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");


    printf("\ncant de nodos: %d\n",contarNodos(&ar));
    printf("cant de nodos: %d\n",contarNodosV2(&ar));
    printf("cant de nodos: %d\n",cantNodosArbolBin(&ar));

    printf("\naltura del arbol: %d\n",alturaArbolBin(&ar));
    printf("altura del arbol: %d\n",alturaArbolBin2(&ar));


    esArbolBinCompleto(&ar) ?  printf("\nEs arbol completo\n")  :  printf("\nNo es arbol completo\n");

    esArbolBinBalanceado(&ar) ?  printf("\nEs arbol balanceado\n")  :  printf("\nNo es arbol balanceado\n");


    int elem= 250;
    buscarElemArbolBin(&ar, &elem, sizeof(int), cmp_enteros) ?  printf("\nEl elemento %d se encuentra en el arbol\n", elem) :
            printf("\nEl elemento %d no se encuentra en el arbol\n", elem);

    buscarMenorElemArbolBin(&ar, &elem, sizeof(int), cmp_enteros);
    printf("\nEl menor elemento del arbol es el %d\n", elem);

    buscarMayorElemArbolBin(&ar, &elem, sizeof(int), cmp_enteros);
    printf("\nEl mayor elemento del arbol es el %d\n", elem);

    buscarRaizArbolBin(&ar, &elem, sizeof(int));
    printf("\nRaiz del arbol: %d\n", elem);

    printf("Suma de nodos: %d\n", sumarElemArbolBin(&ar));


    printf("\nMostramos nodos que posean ambos hijos:\n");
    mostrarNodosConAmbosHijos(&ar, imprimir);

    printf("\nMostramos solo hijos:\n");
    mostrarHijos(&ar, imprimir);

/*
    elem= 50;
    printf("\n\nIntentamos eliminar el nodo: %d", elem);
    if(eliminarCualquierNodoMenosRaiz(&ar, &elem, sizeof(int), cmp_enteros))
        printf("\nEliminamos correctamente el nodo %d\n",elem);
    else
        printf("\nEl elemento no se encontro en el arbol\n");
*/
    eliminarRaizArbolBinBusq(&ar);

    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");

    system("pause");
    exit(0);

    elem= 100;
    printf("\n\nIntentamos eliminar el nodo hijo: %d", elem);
    if(eliminarSoloHijo(&ar, &elem, sizeof(int), cmp_enteros))
        printf("\nPudimos eliminar correctamente el nodo %d por ser hijo\n", elem);
    else
        printf("\nNo era nodo hijo por tanto el elemento no fue eliminado o no se encontro en el arbol\n");

    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");


    printf("\nPodamos arbol\n");
    podarArbol(&ar);
    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");


    printf("\nPodamos el arbol hasta convertirlo en un arbol completo\n");
    podarHastaConvertirAArbolCompleto(&ar, cmp_enteros);
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    esArbolBinCompleto(&ar) ?  printf("\nEs arbol completo\n")  :  printf("\nNo es arbol completo\n");



    printf("\nVaciamos arbol\n");
    vaciarArbol(&ar);
    recorrerEnOrdenInversoArbolBinBusq(&ar, 0, imprimir);   //solo es para probar si realmente
                                                            //se vació el árbol

    system("pause");
    return 0;
}




int cmp_enteros(const void * a1, const void * a2)
{
    const int * e1 = (const int*) a1;
    const int * e2 = (const int*) a2;
    return *e1 -*e2;
}


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
    int * dato = (int*) info;
    printf("-%d-", *dato);
}

//segun el nivel n, lo corre a la izq o derecha al nodo
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    int * dato = (int*) info;
    printf("%*s-%3d-\n", n*3, "", *dato);
}

void imprimirArch(void * info, unsigned tam, unsigned n, void * params)
{
    int * dato = (int*) info;
    fprintf((FILE*) params, "-%d-", *dato);
}


int crearArchivo(char * path, void * vec, unsigned tam, unsigned ce)
{
    FILE * pf = fopen(path, "wb");
    if(!pf)
        return 0;
    fwrite(vec, tam, ce, pf);
    fclose(pf);
    return 1;
}
