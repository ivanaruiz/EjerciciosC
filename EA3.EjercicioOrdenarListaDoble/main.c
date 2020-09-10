#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



int main()
{
    FILE   *fpPant = fopen("pantalla.txt", "wt");
    tLista  lista;
    int     cant;


    tAlumno vec[] = {
    {"pedro", 'A'},
    {"alicia", 'B'},
    {"pedro", 'B'},
    {"alicia", 'C'},
    {"damian", 'D'},
    {"pepe", 'E'},
    {"roberta", 'F'},
    {"alicia", 'G'},
    {"pepe", 'H'},
    {"alicia", 'I'},
    {"santi", 'J'},
    {"alicia", 'K'},
    {"alicia", 'M'},
    {"pepe", 'N'},
    {"damian", 'O'},
    {"bebe", 'P'},
    {"pepe", 'T'},
    };

    crear_lista(&lista);

    for(int i = 0; i<sizeof(vec)/sizeof(tAlumno); i++)
    {
        poner_ultimo_lista(&lista, &vec[i], sizeof(tAlumno));
    }


    cant = mostrarDeIzqADer_MIO(&lista, mostrarFinal_MIO, fpPant);
        fprintf(fpPant, "- Se mostraron %d calificaciones de finales.\n\n", cant);

    ordenarLista_MIO(&lista, compararFinal_MIO);

    puts("");

    printf("\nACA LA VERSION FINAL\n");
    mostrarDeIzqADer_MIO(&lista, mostrarFinal_MIO, fpPant);


    fclose(fpPant);

    system("pause");
    return 0;
}
