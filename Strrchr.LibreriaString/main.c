#include <stdio.h>
#include <stdlib.h>

/*Localiza la última aparición de c (letra en mi caso) en la cadena apuntada por s (cad en mi caso).
La función retorna un puntero a partir del carácter encontrado.
Si no se ha encontrado el caracter c, entonces retorna un puntero nulo.*/

char * mi_strrchr(char * cad, int ce, char letra);

int main()
{
    char cad[] = "hola totito";
    int ce = sizeof(cad) / sizeof(char);
    char letra = 't';

    printf("Cadena: %s\nLetra: %c\n\n", cad, letra);

    mi_strrchr(cad, ce-1, letra);

    printf("Cadena final: %s\n", cad);

    system("pause");
    return 0;
}


char * mi_strrchr(char * cad, int ce, char letra)
{
    char * fin = cad + ce -1;

    while(fin>cad)          //empiezo por el final y retrocedo hasta encontrar la letra
    {
        if(*fin == letra)   //una vez que encuentro la letra, avanzo con cad y fin, y voy copiando
        {
            while(*fin!= '\0')
            {
                *cad = *fin;
                fin++;
                cad++;
            }
            *cad='\0';
            return cad;     //ya puedo devolver cad
        }
        fin--;
    }

    return NULL;            //si no encontré la letra, entonces devuelvo puntero a null
}
