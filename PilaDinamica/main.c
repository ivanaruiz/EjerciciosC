#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

//Vamos a crear una pila de enteros y usar las primitivas de pila,
//y luego una pila de char, y lo mismo.
//Y por ultimo una pila de estructura de datos.

int main()
{
    //PRIMERO CREAMOS UNA PILA DE ENTEROS PARA VER CÓMO FUNCIONA LA PILA
    int elem;
    int i;
    t_pila pila_ent;

    crear_pila(&pila_ent);  //luego de esta funcion, vere que pila_ent = 0 ,
                            //es decir esta pila no apunta a nada por ahora

    for(i=0; i<10; i++) //10 es numero aleatorio, pero como usamos pila dinamica podriamos meter muchos mas enteros
    {
        int r;
        r=poner_en_pila(&pila_ent, &i, sizeof(i));  //le mando el tamaño del entero en este caso
        if(!r)
        {
            printf("Pila llena!");
        }
    }

    while(!pila_vacia(&pila_ent))
    {
        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
        printf("%d ", elem);
    }
    puts("");

    ////////////////////////////////////////////////////////////////////
    //AHORA CREAMOS UNA PILA DE CHAR////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    char letra;
    char vec[]= {'a', 'b', 'c', 'd', 'e' };
    int ce = sizeof(vec)/sizeof(char);
    t_pila pila_char;

    crear_pila(&pila_char);


    for(i=0; i<ce; i++)
    {
        if(!poner_en_pila(&pila_char, &vec[i], sizeof(char)))
            printf("pila llena");
    }

    while(!pila_vacia(&pila_char))
    {
        sacar_de_pila(&pila_char, &letra, sizeof(letra));
        printf("%c ", letra);
    }
    puts("");

    ////////////////////////////////////////////////////////////////////
    //AHORA CREAMOS UNA PILA DE STRUCT//////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    //creo la estructura de datos, y este struct es el que mando en poner_en_pila
    t_alumno vec_alu[] =    {
                            {"ariel", 20},
                            {"fede", 30},
                            {"maria", 25},
                            {"alicia", 28},
                            {"juan", 32}
                            };

    ce= sizeof(vec_alu)/sizeof(t_alumno);

    t_alumno alu;   //aca es donde vamos a alojar los datos con el sacar_de_pila


    t_pila pila_alu;

    crear_pila(&pila_alu);

    for(i=0; i<ce; i++)
    {
        poner_en_pila(&pila_alu, &vec_alu[i], sizeof(t_alumno));
    }

    while(!pila_vacia(&pila_alu))
    {
        sacar_de_pila(&pila_alu, &alu, sizeof(alu));
        printf("\n%-9s %d", alu.nombre, alu.edad);
    }
    puts("");



    system("pause");
    return 0;
}

