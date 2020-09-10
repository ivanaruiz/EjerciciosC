#include <stdlib.h>
#include <stdio.h>
#include "ctype.h"

int main(){

    char c;

    printf("Ingrese un caracter: ");
    scanf("%c",&c);

    printf("1-VERDADERO. 0-FALSO\n");

    printf("\nEs numero:   %d ", my_isdigit(c));
    printf("\nEs letra:    %d ", my_isalpha(c));
    printf("\nEs espacio:  %d ", my_isspace(c));
    printf("\nA mayuscula: %c ", my_toupper(c));
    printf("\nA minuscula: %c ", my_tolower(c));

    system("pause");
    return 0;
}







