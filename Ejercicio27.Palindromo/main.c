#define ce  20  //por default haremos una palabra de max 20 caracteres
#include "header.h"

/*
Desarrollar una función que determine si una palabra ingresada es un palíndromo*/

int main()
{
    char vec[ce];

    printf("Ingrese palabra: \n");
    fflush(stdin);
    gets(vec);

    if(frase(vec))
        printf("Es palindromo\n");
    else
        printf("No es palindromo\n");

    system("pause");
    return 0;
}


