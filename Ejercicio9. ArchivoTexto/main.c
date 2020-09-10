/*Escriba un programa que genere un archivo de texto ("datos.txt") a partir del ingreso por teclado de números
enteros, de modo que en cada línea de texto haya una cantidad variable de cadenas de caracteres que representes
tales números. En el archivo debe haber como mínimo la representación de un entero y como máximo de siete.
La separación entre estas cadenas que representen números debe ser de al menos un carácter espacio(' ') o a lo
sumo cinc, de modo, que queden alineados por la derecha al leer el contenido del archivo con un procesador de
texto como notepad o el bloc de notas.
Los caracteres de saparación sólo están entre números.
En el archivo debe haber al menos una línea con un número y otra con siete.
Utilice un generador de números pseudo aleatorios para determinar cuántos números se almacenan por línea de texto*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void validar_num(int * n);

int main()
{
    srand(time(NULL));
    int n;
    int ban_uno = 0;    //dos banderas que usaré para saber cuando tenga una línea con uno, y con siete números, respectivamente
    int ban_siete = 0;

    FILE * pf= fopen("datos.txt", "wt");

    while(ban_uno==0  || ban_siete==0)  //cuando ya haya una linea con un solo numero, y otra linea con siete, que termine.
    {
        int gen= rand()%7+1;    //este generador me servira para el for, para que el ingreso vaya de 1 a 7 aleatoriamente

        if(gen==1)
            ban_uno=1;
        if(gen==7)
            ban_siete=1;

            for(int j=0; j< gen; j++)
            {
                validar_num(&n);

                fprintf(pf, "%5d ", n);

            }
            fprintf(pf, "\n");
    }

    fclose(pf);

    puts("Se ha generado un archivo de texto con numeros aleatorios");

    system("pause");
    return 0;
}

///////////////////////////////////////////
///////////////////////////////////////////


void validar_num(int * n)
{
    do
    {
        *n= rand();
        if(*n<-99999 || *n>999999)
           printf("invalido. vuelva a ingresar");

    }while(*n<-99999 || *n>999999);
}
