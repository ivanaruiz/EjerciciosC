#include <stdio.h>
#include <stdlib.h>

/*Programa que simula la función strcpy de la librería string.h*/
/*Se le copia una cadena de caracteres a otra*/

/*Copia la cadena apuntada por s2(incluyendo el caracter nulo) a la cadena apuntada por s1.
La función retorna el valor de s1.
char * strcpy(char * s1, const char * s2);
*/

char * mi_strcpy(char *, const char *);

int main()
{
    char t1[40] = "hola";
    char t2[  ] = "toto";

    printf("t1: %s\n", t1);

    printf("t2: %s\n", t2);

    mi_strcpy(t1,t2);

    puts("Copio t2 a t1:");
    printf("t1: %s\n", t1);

    system("pause");
    return 0;
}


char * mi_strcpy(char * t1, const char * t2)
{
    while(*t2!='\0')
    {
        *t1=*t2;
        t1++;
        t2++;
    }
    *t1='\0';
    return t1;
}
