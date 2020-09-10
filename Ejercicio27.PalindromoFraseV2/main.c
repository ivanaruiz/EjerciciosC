#include <stdio.h>
#include <stdlib.h>

#define VERDADERO   1
#define FALSO       0

/*Desarrollar una funci�n para determinar si una cadena de caracteres es palindromo*/
/*Esta versi�n es m�s corta que la otra, sin embargo no tiene en cuenta si hubiera caracteres
raros m�s alla del espacio, o si hubiera mas de un espacio seguido. tampoco las mayusculas*/

int palindromo(char * vec, int ce);


int main()
{
    char vec[] = "amo la pacifica paloma";
    int ce = sizeof(vec)/sizeof(char);
    printf("Frase: %s\n", vec);

    if(palindromo(vec, ce-1))
        printf("Es palindromo.\n");
    else printf("No es palindromo.\n");

    system("pause");
    return 0;
}


int palindromo(char * vec, int ce)
{
    char * fin = vec + ce -1;

    while(vec<fin)
    {
        if(*vec==32)    //si hay un espacio, salto a la siguiente posici�n
            vec++;
        if(*fin==32)    //lo mismo aqu�, retrocedo otra posici�n
            fin--;

        if(*vec==*fin)  //el resto del c�digo es igual que antes
        {
            vec++;
            fin--;
        }
        else
            return FALSO;
    }
    return VERDADERO;
}
