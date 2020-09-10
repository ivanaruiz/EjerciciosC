#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0

/*Determina si una fecha es válida o no*/

typedef struct
{
    int d;
    int m;
    int a;
}tFecha;

int es_fecha_valida(tFecha * f);
int es_mes_valido(tFecha * f);
int es_dia_valido(tFecha * f);
int es_bisiesto(int a);

int main()
{
    tFecha fec = {29,2,2020};

    if(es_fecha_valida(&fec))
        printf("Es fecha valida\n");
    else
        printf("No es fecha valida\n");

    system("pause");
    return 0;
}

int es_fecha_valida(tFecha * f)
{
    if(f->a > 1700 && f->a<2050)
        return es_mes_valido(f);

    return FALSE;
}

int es_mes_valido(tFecha * f)
{
    if(f->m >= 1 && f->m <=12)
        return es_dia_valido(f);

    return FALSE;
}


int es_dia_valido(tFecha * f)
{
    int vec_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(f->d>= 1 && f->d<= vec_mes[f->m-1] + es_bisiesto(f->a))
        return TRUE;

    return FALSE;
}

int es_bisiesto(int a)
{
    if( a%4==0 && (a%100!=0 || a%400==0 ))
        return TRUE;

    return FALSE;
}
