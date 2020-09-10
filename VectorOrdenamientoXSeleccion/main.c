#include <stdio.h>
#include <stdlib.h>
#define ce  13
//no usa datos genéricos
void ordenar(int *vec);
void buscar_menor(int * vec, int *fin, int * men);
void intercambio(int *men, int *vec);

int main()
{
    printf("Vector desordenado: \n");
    int vec[ce]={3,7,9,1,2,6,8,12,16,4,20,5,10};

    for(int i=0; i<ce; i++)
        printf("%d  ", vec[i]);

    printf("\nVector ordenado: \n");

    ordenar(vec);

    for(int i=0; i<ce; i++)
        printf("%d  ", vec[i]);

    printf("\n");

    system("pause");
    return 0;
}


void ordenar(int *vec)
{
    //a vec lo usaremos como puntero para hacer los recorridos buscando al menor
    int *fin= vec+ce-1;
    //el puntero men quedara apuntando siempre a la "primera" posicion de cada recorrido,
    //que la misma alojara siempre al menor encontrado
    //recordar que igual este puntero ira aumentando ya que habra sucesivas busquedas
    int *men= vec;

    while(vec<fin)
    {
        buscar_menor(vec, fin, men);

        //ambos punteros aumentan juntos de posicion
        vec++;
        men++;
    }
}

void buscar_menor(int * vec, int *fin, int * men)
{
    while(vec<=fin)
    {
        //en caso de encontrarlo, hara un intercambio
        if(*vec<*men)
            intercambio(men, vec);

        //solo vec es el que aumenta ya que es el que busca el menor
        vec++;
    }

}


void intercambio(int *men, int *vec)
{
    int aux;
    aux=*men;
    *men=*vec;
    *vec= aux;
}


