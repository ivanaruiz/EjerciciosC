#include "header.h"

void mostrar(int *vec, int ce)
{
    int *ptr = vec;
    for(int i=0; i<ce; i++)
    {
        printf("%d  ", *ptr);
        ptr++;
    }
    printf("\n");
}


int buscar(int *vec, int ce, int n)
{
    int *ptr= vec;
    int i;
    for(i=0; i<ce; i++)
    {
        if(*ptr==n)
        {
            borrar(vec, ce, n , i);
            return VERDADERO;   ///apenas encuentre la primera aparicion, retorna 1 y sale de la funcion
        }
        ptr++;
    }
    return FALSO;   ///no encontró el numero ingresado
}


void borrar(int vec[], int ce, int n, int i)
{
    printf("\nSe ha borrado el %d (primera aparicion en caso de repetirse)\n", n);

            vec[i] = vec[i+1];  ///se empiezan a pisar los numeros, a partir del borrado.

                for(int j= i++ ; j<ce-1; j++)
                {
                    vec[j] = vec[j+1];
                }
}
