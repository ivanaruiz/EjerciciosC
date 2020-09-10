/*Strrchr es una función de librería string.h . Localiza la ultima aparacion de un char que deseamos
en una cadena apuntada. Por ejemplo. Frase original "hola pepe" y como char seleccionamos la 'p'.
Entonces busca la ultima p y muestra el texto a partir de ella. Resultado: "pe". */

/*================================================================= */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mi_strrchr(char *vec, int ce, char let);

/*================================================================= */

int main()
{
    char vec[]= "hola pepe";
    int ce=  sizeof(vec)/sizeof(char);  //tambien me cuenta el caracter fin de cadena, ej ce=10 para este caso
    char let='p';

    printf("frase original: %s\n", vec);
    printf("strrchr: %s", strrchr(vec,let));    //pruebo cómo funciona strrchr

    printf("\nmi strrchr: %s\n\n", mi_strrchr(vec, ce, let));

    system("pause");
    return 0;
}

/*================================================================= */

char * mi_strrchr(char *vec, int ce, char let)
{
    char *ini = vec;
    char *fin = vec+ce-1;

    while(fin>=ini)
    {
        if(*fin==let)
        {
            ini=fin;
            return ini;
        }

        fin--;
    }

    //no se encontró letra asi que devuelvo null
    return NULL;
}

/*================================================================= */
