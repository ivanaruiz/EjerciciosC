#include <stdio.h>
#include <stdlib.h>
#define VERDADERO   1
#define FALSO       0

/*El programa nos dice si una fecha es valida o no. Tiene en cuenta años bisiestos.
Y los años validos consideramos entre 1600 y 2050, por poner un rango. */

typedef struct
{
    int d,m,a;
}t_fecha;


int es_fecha_valida(t_fecha *fec);
int cant_dias_mes(int m, int a);
int es_bisiesto(int a);

int main()
{
    t_fecha fec = {29, 2, 2020};

    printf("%02d/%02d/%4d:\n", fec.d, fec.m, fec.a);
    printf(es_fecha_valida(&fec) ? "Es fecha valida\n" : "No es fecha valida\n");

    system("pause");
    return 0;
}

////////////////////////////////////////////////

int es_fecha_valida(t_fecha *fec)
{
    if(fec->a >1600 && fec->a < 2050)
       if(fec->m >=1 && fec->m <=12)
            if(fec->d >=1 && fec->d <= cant_dias_mes(fec->m, fec->a))
                return VERDADERO;

    return FALSO;
}

////////////////////////////////////////////////


int cant_dias_mes(int m, int a)
{
    //el static agiliza el programa. lo que hace es que declara la variable UNA SOLA VEZ.
    //es decir. al usar funciones y tener variables declaradas en ellas,
    //se crean cada vez que se usan dichas funciones.
    //en cambio en este caso lo crea una vez (al usar esta funcion) y no mas.
    //sirve aqui porque este vector no cambia nunca.

    static const int vec[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    if(m==2 && es_bisiesto(a)==VERDADERO)
        return 29;

    return vec[m-1];
}

////////////////////////////////////////////////

int es_bisiesto(int a)
{
    if( a%4==0 && (a%400==0 || a%100!=0) )
        return VERDADERO;   //o sea que sería bisiesto si viene por aqui

    return FALSO;
}
