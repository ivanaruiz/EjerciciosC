#include "itoa.h"

char * mi_itoa(int n, char *vec, int base)
{
    int resto=0;    //se harán divisiones sucesivas, y lo que guardo en la cadena es el resto convertido a ascii
    char *inicio=vec;
    unsigned un;  //esto es por si el usuario mete numeros negativos, pero no funciona para los decimales
    int negativo=0; //una bandera

    if(n<0 && base==10)
    {
        negativo=1;
        n*=-1;  //pasé el número a positivo
    }

    un=n;   //usaré el un ya que es unsigned

    while(un!=0)
    {
        resto= un%base;

        *vec= toAscii(resto, base);

        un=un/base;   //para volver a dividir en el siguiente ciclo, achico un, (el cociente de la division)
        vec++;
    }


    if(base==10 && negativo==1) //si fue decimal y numero negativo, entonces le ponemos una barra de neg al final
    {                           //(después voy a invertir el orden)
        *vec='-';
        vec++;
    }


    *vec='\0';  //termino de recorrer y le pongo final de cadena
    vec--;      //me posiciono en el último caracter ingresado

    invertirCadena(vec, inicio); //como me quedaron invertidos, los ordeno

    return inicio;
}


void invertirCadena(char * vec, char * inicio)
{
    char aux;

    while(inicio<vec)
    {
        aux= *inicio;
        *inicio=*vec;
        *vec= aux;

        inicio++;
        vec--;
    }
}


char toAscii(int resto, int base)
{
        return (base==16 && resto>9 ?  resto+'0'+7 : resto+'0');

        /*para las bases hexa, cuando el numero es mayor a 9,
            le sumo el ascii del 0 (que es el 48 entero) y le sumo ademas un 7 entero, al resto
        para todos los demas numeros los convierto sumandole un 48 entero al resto*/
}
