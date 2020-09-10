#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Esta versión usa una función (la de insertar) con datos genéricos
//Por tanto también haremos un ejemplo con un vector de char para mostrar que funciona
/*
Desarrollar una función que inserte un elemento en un arreglo de enteros,
dada la posición de inserción.
*/

void insertar(void * vec, size_t ce, void * num, size_t pos, size_t tamInfo);
void mostrarVec(int * vec, int ce);
void mostrarVecChar(char * vec_char, int ce);

int main()
{
    int vec[] = {2,5,9,3,6,7};
    int tam = sizeof(vec) / sizeof(int);

    puts("VECTOR ORIGINAL DE ENTEROS: ");
    mostrarVec(vec, tam);

    int num = 1;
    int pos = 4;
    printf("\nNumero a insertar: %d.\nPosicion: %d\n", num, pos);

    insertar(vec, tam+1, &num, pos, sizeof(int));

    puts("\nVECTOR CON INSERCION: ");
    mostrarVec(vec, tam+1);

    //**************************************

    puts("\n\n*****************\nVECTOR ORIGINAL DE CHAR: ");
    char vec_char[] = {'a','b','c','d','e','f'};
    tam = sizeof(vec_char) /sizeof(char);
    mostrarVecChar(vec_char, tam);

    char car = 'p';
    pos = 4;
    printf("\nLetra a insertar: %c.\nPosicion: %d\n", car, pos);

    insertar(vec_char, tam+1, &car, pos, sizeof(char));

    puts("\nVECTOR CHAR CON INSERCION: ");
    mostrarVecChar(vec_char, tam+1);

    puts("");
    system("pause");
    return 0;
}

void mostrarVec(int * vec, int ce)
{
    for(int i=0; i<ce; i++)
        printf("%d ", vec[i]);
}

void mostrarVecChar(char * vec_char, int ce)
{
    for(int i=0; i<ce; i++)
        printf("%c ", vec_char[i]);
}


void insertar(void * vec, size_t ce, void * num, size_t pos, size_t tamInfo)
{
    void * fin = vec+ ((ce-1)*tamInfo);
    void * hasta= vec + ((pos-1)*tamInfo);

    while(fin>hasta)
    {
        memcpy(fin, fin-tamInfo, tamInfo);
        fin-=tamInfo;
    }
    memcpy(hasta, num, tamInfo);
}



