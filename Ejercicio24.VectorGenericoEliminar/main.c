#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Desarrollar una función que elimine el elemento que ocupa una determinada posición de
un arreglo de enteros.
*/

/*Esta versión trabaja con datos genéricos, por lo tanto es mucho mejor.
Usaremos de ejemplo un vector de enteros, pero también uno de char.
*/

void eliminar(void * vec, size_t ce, size_t pos, size_t tamInfo);
void mostrarVec(int * vec, int ce, int pos);
void mostrarVec_char(char * vec, int ce, int pos);

int main()
{
    int vec_ent[] = {1,2,3,4,5,6};
    int ce= sizeof(vec_ent)/sizeof(int);

    int pos = 4;

    puts("VECTOR DE ENTEROS:");
    mostrarVec(vec_ent, ce, pos);

    eliminar(vec_ent, ce, pos, sizeof(int));

    printf("\nVECTOR CON ELEMENTO ELIMINADO EN POSICION %d:\n", pos);
    mostrarVec(vec_ent, ce-1, pos);

    //*************************//

    char vec_char[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    ce = sizeof(vec_char) /sizeof(char);

    puts("\n\nVECTOR DE CHAR:");
    mostrarVec_char(vec_char, ce, pos);

    eliminar(vec_char, ce, pos, sizeof(char));

    printf("\nVECTOR CON ELEMENTO ELIMINADO EN POSICION %d:\n", pos);
    mostrarVec_char(vec_char, ce-1, pos);

    puts("");
    system("pause");
    return 0;
}

//las funciones de mostrar no pueden ser genéricas
void mostrarVec(int * vec, int ce, int pos)
{
    for(int i = 0; i<ce; i++)
    {
        printf("%d ", vec[i]);
    }
}

void mostrarVec_char(char * vec, int ce, int pos)
{
    for(int i = 0; i<ce; i++)
    {
        printf("%c ", vec[i]);
    }
}

//función genérica
void eliminar(void * vec, size_t ce, size_t pos, size_t tamInfo)
{
    void * ini= vec+ (pos-1)*tamInfo;
    void * fin= vec+ (ce-1)*tamInfo;

    while(ini<fin)
    {
        memcpy(ini, (ini+tamInfo), tamInfo);
        ini+=tamInfo;
    }
}
