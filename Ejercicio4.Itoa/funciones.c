#include "itoa.h"

char * mi_itoa(int n, char * cad, int base)
{
    int resto=0;    //se harán divisiones sucesivas, y lo que guardo en la cadena es el resto convertido a ascii
    char * inicio = cad;    //la voy a usar para resetear

    while(n!=0)
    {
        resto= n%base;

        *cad= toAscii(resto, base);

        n=n/base;   //para volver a dividir en el siguiente ciclo, achico el n, (el cociente de la division)
        cad++;
    }
    *cad='\0';  //termino de recorrer y le pongo final de cadena
    cad--;

    invertirCadena(cad, inicio); //como me quedaron invertidos, los ordeno
    //realmente la que acomodo es cad, pues es la que voy a devolver

    return cad;
}


void invertirCadena(char * cad, char * inicio)
{
    char aux;

    while(inicio<cad)
    {
        aux = *inicio;
        *inicio=*cad;
        *cad= aux;
        inicio++;
        cad--;
    }
}


char toAscii(int resto, int base)
{
        if(base==16 && resto>9)     //para las bases hexa, cuando el numero es mayor a 9, hago esta conversion
            return resto+'0'+7;     //les sumo el ascii del 0 (que es el 48 entero) y le sumo ademas un 7 entero
        else
            return resto+'0';       //para todos los demas numeros los convierto asi, sumandole un 48 entero
}
