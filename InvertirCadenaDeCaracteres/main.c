#include "invertircadena.h"


int main()
{
    char cad[] = "Hola Totito!";
    int ce = sizeof(cad)/sizeof(char);
    printf("Cadena original: \n%s \n\n", cad);

    invertirCadena(cad, ce-1);


    printf("Cadena invertida: \n%s \n\n\n", cad);

    system("pause");
    return 0;
}


char * invertirCadena(char * cad, int ce)
{
    char * fin = cad + ce - 1;

    while(cad < fin)
    {
        intercambio(cad, fin);
        cad++;
        fin--;
    }

    return cad;
}

void intercambio(char * cad, char * fin)
{
    char aux;

    aux  = *cad;
    *cad = *fin;
    *fin = aux;
}
