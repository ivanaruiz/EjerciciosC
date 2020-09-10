#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Desarrollar una función que elimine la primera aparación de un elemento determinado
de un arreglo de enteros.
*/

/*Haré una función genérica lo cual es mejor, y también lo probaré con un vector de char*/

void eliminar(void * vec, size_t ce, void * n, size_t tamInfo, int (*cmp)(const void*, const void*));
int cmp_enteros(const void * a1, const void * a2);
int cmp_char(const void * a1, const void * a2);


int main()
{
    int vec[] = {1,2,3,4,5,3,6,7};
    int ce = sizeof(vec)/sizeof(int);

    printf("VECTOR ORIGINAL DE ENTEROS:\n");
    for(int i=0; i<ce; i++)
        printf("%d ", vec[i]);

    int n = 3;
    eliminar(vec, ce, &n, sizeof(int), cmp_enteros);

    printf("\nVECTOR CON ELIMINACION DE LA PRIMERA APARICION DEL NUM %d:\n", n);
    for(int i=0; i<ce-1; i++)
        printf("%d ", vec[i]);


    printf("\n***********************\nVECTOR ORIGINAL DE CHAR:\n");
    char vec_char[] = {'a','b','b','c','d','e'};
    ce = sizeof(vec_char)/sizeof(char);

    for(int i=0; i<ce; i++)
        printf("%c ", vec_char[i]);

    char c = 'b';
    eliminar(vec_char, ce, &c, sizeof(char), cmp_char);

    printf("\nVECTOR CON ELIMINACION DE LA PRIMERA APARICION DE LETRA %c:\n", c);
    for(int i=0; i<ce-1; i++)
    printf("%c ", vec_char[i]);


    system("pause");
    return 0;
}


void eliminar(void * vec, size_t ce, void * n, size_t tamInfo, int (*cmp)(const void*, const void*))
{
    void * fin = vec + (ce-1)*tamInfo;

    while(vec<fin)
    {
        if(cmp(vec, n)==0)  //una vez que encontramos el dato, seguimos hasta el final copiando datos
        {
            while(vec<fin)
            {
            memcpy(vec, vec+tamInfo, tamInfo);
            vec+=tamInfo;
            }
        }
        vec+=tamInfo;
    }
}

int cmp_enteros(const void * a1, const void * a2)
{
    int * e1 = (int*) a1;
    int * e2 = (int*) a2;
    return *e1-*e2;
}

int cmp_char(const void * a1, const void * a2)
{
    char * e1 = (char*) a1;
    char * e2 = (char*) a2;
    return *e1-*e2;
}
