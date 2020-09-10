#include "palindromo.h"

int main()
{
    char vec[ce];
    int respuesta;

    printf("Ingrese frase: \n");
    fflush(stdin);
    gets(vec);

    respuesta= es_palindromo(vec);

     if(respuesta==VERDADERO)
        printf("\nEs palindromo\n\n");
    else
        printf("\nNo es palindromo\n\n");

    system("pause");
    return 0;
}
