#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//esta versión sí está completa si bien es distinta que la anterior
/*
Desarrollar una función que inserte un elemento en un arreglo de enteros,
dada la posición de inserción.
*/


void insertar(int * vec, int ce, int num, int pos);
void mostrarVec(int * vec, int ce);

int main()
{
    int vec[] = {2,5,9,3,6,7};
    int tam = sizeof(vec) / sizeof(int);

    puts("VECTOR ORIGINAL: ");
    mostrarVec(vec, tam);

    int num = 1;
    int pos = 4;
    printf("\nNumero a insertar: %d.\nPosicion: %d\n", num, pos);

    insertar(vec, tam+1, num, pos);

    puts("\nVECTOR CON INSERCION: ");
    mostrarVec(vec, tam+1);

    puts("");
    system("pause");
    return 0;
}



void mostrarVec(int * vec, int ce)
{
    for(int i=0; i<ce; i++)
        printf("%d ", vec[i]);
}



void insertar(int * vec, int ce, int num, int pos)
{
    int i= ce;

    while(pos-1 != i)
    {
        vec[i] = vec[i-1];
        i--;
    }
    vec[i]= num;
}
