#include "header.h"

void ingresoPos(int  *pos, int ce)
{
    do
    {
    printf("\nque posicion desea eliminar: ");
    scanf("%d", pos);
    }while(*pos<= 0 || *pos> ce);
}



void mostrar(int *vec, int ce)
{
    int *ptr= vec;

    for(int i=0; i<ce; i++)
    {
        printf("%d  ", *ptr);
        ptr++;
    }
}


void borrar(int *vec, int ce, int pos)
{
    int *ptr= vec+pos;  //el puntero comienza apuntando a la posicion del vector que nos indicó el usuario

    while(pos<ce)       //y avanzo de esa posición hasta el final, para acomodar las demás posiciones
    {
        *ptr= *(ptr+1); //con esto iran pisandose las posiciones. es decir equis posicion se pisa con la pos siguiente

        ptr++;
        pos++;
    }
}


