#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Programa que simula la función strchr de la librería string.
La función retorna un puntero a partir del carácter encontrado.
Si no ha encontrado el caracter, entonces retorna un puntero NULL.*/


char * miStrchr( char *cad, char letra);


int main()
{
    char cad[50];
    puts("Ingrese cadena: ");
    fflush(stdin);
    gets(cad);

    printf("Cadena: %s\n",cad);

    char letra;
    puts("\nIngrese letra: ");
    fflush(stdin);
    scanf("%c", &letra);

    miStrchr(cad, letra);

    printf("Cadena reformada: %s\n",cad);

    system("pause");
    return 0;
}



char * miStrchr( char *cad, char letra)
{
    char *avanzar= cad;


    while(*avanzar !='\0')
    {
        if( *avanzar== letra)   //no puedo usar el strcmp porque espera dos punteros, y char de caracter unico no es puntero
                                //recordar que las cadenas de caracteres sí son punteros , pero no el char solito
            {
                while(*avanzar !='\0')
                {
                    *cad= *avanzar;
                    avanzar++;
                    cad++;
                }
                *cad='\0';
                return cad;     //terminé de copiar, así qe mando devuelvo el puntero cadena
            }

        avanzar++;
    }

    //si llegamos acá es porque no encontró el caracter, entonces devuelvo puntero a null
    return NULL;
}
