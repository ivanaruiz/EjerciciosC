/*Escriba un programa que genere un archivo de texto ("datos.txt") a partir del ingreso por teclado de n�meros
enteros, de modo que en cada l�nea de texto haya una cantidad variable de cadenas de caracteres que representes
tales n�meros. En el archivo debe haber como m�nimo la representaci�n de un entero y como m�ximo de siete.
La separaci�n entre estas cadenas que representen n�meros debe ser de al menos un car�cter espacio(' ') o a lo
sumo cinc, de modo, que queden alineados por la derecha al leer el contenido del archivo con un procesador de
texto como notepad o el bloc de notas.
Los caracteres de saparaci�n s�lo est�n entre n�meros.
En el archivo debe haber al menos una l�nea con un n�mero y otra con siete.
Utilice un generador de n�meros pseudo aleatorios para determinar cu�ntos n�meros se almacenan por l�nea de texto*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void validar_num(int * n);

int main()
{
    srand(time(NULL));
    int n;
    int ban_uno = 0;    //dos banderas que usar� para saber cuando tenga una l�nea con uno, y con siete n�meros, respectivamente
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
