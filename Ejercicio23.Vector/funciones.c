#include "vector.h"


void mostrar(int *vec, int ce)
{
    int *ptr = vec;
    for(int i=0; i< ce; i++)
    {
        printf("%d  ", *ptr);
        ptr++;
    }


    printf("\n\n");
}



void ordenar(int *vec, int ce)
{
    int aux=0;
    int *ptr= vec;

    for(int i=0; i<ce; i++)
    {
        for(int j=0; j<ce; j++)
        {
            if(*ptr> *(ptr+1))
            {
            aux= *ptr;
            *ptr = *(ptr+1);
            *(ptr+1) = aux;
            }

            ptr++;   ///incremento el puntero, o sea incrementa la direccion y apuntara a otro lugar del vect
        }
        ptr=vec;    ///esta parte la hago para el segundo for, ya que debe recorrer nuevamente el vector,
                    ///entonces lo vuelvo a inicializar desde la primera direccion
    }
}

