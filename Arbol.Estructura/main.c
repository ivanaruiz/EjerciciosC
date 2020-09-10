#include "arbol.h"
#include "producto.h"

void imprimir(void * info, unsigned tam, unsigned n, void * params);
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params);

/*Cargar un arbol desde un vector de estructuras, que ya se encuentra ordenado.*/

int main()
{
    tArbolBinBusq ar;
    crearArbol(&ar);

    tProducto vec[] =
    {
    {1, "leche"},
    {2, "harina"},
    {3, "arroz"},
    {4, "polenta"},
    {5, "yerba"},
    {6, "cafe"},
    {7, "azucar"}
    };

    int tamVec = sizeof(vec)/sizeof(tProducto);

    //como el vector está ordenado (por código), hago uso de esta función recursiva
    cargarDesdeDatosOrdenadosArbolBinBusq(&ar, vec, tamVec, sizeof(tProducto));

    printf("Recorrido el arbol en orden: (e imprimimos arbol con forma):\n");
    recorrerEnOrdenArbolBinBusq(&ar, 0, imprimir);
    puts("");
    recorrerEnOrdenArbolBinBusq(&ar, 0, imprimirConForma);

    printf("\n\nRecorrido el arbol en orden inverso (e imprimimos arbol con forma):\n");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimir);
    puts("");
    recorrerEnOrdenInversoArbolBinBusq(&ar, NULL, imprimirConForma);
    printf("\n\n");


    system("pause");
    return 0;
}


void imprimir(void * info, unsigned tam, unsigned n, void * params)
{
    tProducto * prod = (tProducto *) info;

    printf("%d%9s\n", prod->cod, prod->desc);
}


void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    tProducto * prod = (tProducto *) info;

    printf("%*s-%3d%9s-\n", n*3, "", prod->cod, prod->desc);
}
