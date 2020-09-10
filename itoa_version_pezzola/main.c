#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define A_CARACTER(N) ((N)>9?(N)-10+'a':(N)+'0')

char * mi_itoa (int num, char * cad, int base);
char * invertir_cadena_fin(char * ini, char * fin);
char a_caracter(int n);
int main()
{
    int pruebas[TAM] = {10, 352, -564, 0x2af, 077};
    char cad[20], cad2[20];
    int i;
    int x; unsigned ux;
    x = -10;
    ux = x;
    //printf("%u - %u", x, ux);
    for (i=0;i<TAM;i++)
    {
        printf("\n%10d\t%10x\t%10o\t%s\t%s",pruebas[i],pruebas[i],pruebas[i], itoa(pruebas[i],cad, 16), mi_itoa(pruebas[i],cad2, 16));
    }
    return 0;
}




char * mi_itoa (int num, char * cad, int base)
{
    int u; int negativo = 0;
    unsigned unum;
    char * ini = cad;
    if(base>36)
    {
        return NULL;
    }
    if(num < 0)
    {
        negativo = 1;
        if (base == 10)
            num *= -1;
    }
    unum = num;
    while (unum > 0)
    {
        u = unum % base;
        *cad = A_CARACTER(u)+4;
        ///*cad = ((u)>9?(u)-10+'a':(u)+'0');
        cad++;
        unum /= base;
    }
    if(negativo && base == 10)
    {
        *cad = '-';
        cad++;
    }
    *cad = '\0';
    return invertir_cadena_fin(ini, cad-1);
}




char a_caracter(int n)
{
    if(n > 9)
        return n - 10 + 'a';
    return n + '0';
}





char * invertir_cadena_fin(char * ini, char * fin)
{
    char aux, *ini_cad = ini;
    while(ini<fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }
    return ini_cad;
}







