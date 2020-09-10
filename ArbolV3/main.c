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
int crearArchivo(char * path, void * vec, unsigned tam, unsigned ce);

/*Primero guardamos un vector en un archivo binarios.
Después cargamos el archivo binario y pasamos los datos al árbol. */


int main()
{
    tArbolBinBusq ar;
    crearArbol(&ar);

    //notar que con este vec ordenado, no me sirve la funcion insertarArbolBinBusq
    //entonces uso las otras funciones de cargarDesdeDatosOrdenados
    int vec[] = {10, 25, 50, 60, 75, 100, 110, 125, 150, 175, 200};

    int cant_reg = sizeof(vec)/sizeof(int);

    crearArchivo("ordenado.dat", vec, sizeof(int), cant_reg);

    cargarArchivoBinOrdenadoArbolBinBusq(&ar, "ordenado.dat", sizeof(int));

    //voy a crear el archivo de texto y al recorrer y leer el arbol, copio los datos
    FILE * pf = fopen("arbol.txt", "wt");
    if(!pf)
        return 1;

    recorrerEnOrdenArbolBinBusq(&ar, pf, imprimirArch);
    fclose(pf);


    printf("Recorrido el arbol en orden:\n ");
    recorrerEnOrdenArbolBinBusq(&ar, NULL, imprimir);


    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n ");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");

    system("pause");
    return 0;
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
    fprintf((FILE*) params, "-%d-", *dato); //notar que casteo (FILE*)params,
                                            //ya que en params recibi pf
}


//tam es el tamaño de cada dato del vector (o sea, int en este caso)
//voy a crear un archivo binario
int crearArchivo(char * path, void * vec, unsigned tam, unsigned ce)
{
    FILE * pf = fopen(path, "wb");
    if(!pf)
        return 0;
    fwrite(vec, tam, ce, pf);
    fclose(pf);
    return 1;
}
