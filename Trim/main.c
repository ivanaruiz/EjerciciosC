#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ES_LETRA(X) (((X)>='a' &&(X)<='z') || ((X)>='A' &&(X)<='Z'))

/*
TRIM() es una función que elimina los espacios en blanco iniciales y finales de una cadena.
*/


void trim(char * cad);

int main()
{
    char cad[] = "   hola toto       ";

    //uso un strlen solo para notar que en la cadena hay muchos espacios en blanco
    printf("Cadena:%s\nCant de caracteres: %d\n\n", cad, strlen(cad));

    trim(cad);

    printf("Nueva cadena:%s\nCant de caracteres: %d\n\n", cad, strlen(cad));

    system("pause");
    return 0;
}


void trim(char * cad)
{
    char * avanzar = cad;

    while(*avanzar != '\0')
    {
        //lo que hace en la segunda condición es evaluar cuando hay un espacio entre palabra y palabra
        //en ese caso es un espacio válido, así que no debe borrarlo
        //es decir si una posicion anterior tiene una letra, y la siguiente posicion también,
        //entonces no lo descartamos
        //todos los demás espacios son borrados
        while(ES_LETRA(*avanzar) || (*avanzar==32 && ES_LETRA(*(avanzar-1)) && ES_LETRA(*(avanzar+1))))
        {
            *cad = *avanzar;
            cad++;
            avanzar++;
        }
        avanzar++;
    }

    *cad='\0';
}
