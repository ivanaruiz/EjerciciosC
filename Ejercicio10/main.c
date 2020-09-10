/*Escriba una función que determine si una cadena de caracteres que representa a un número, es decir compuesta
por los caracteres que representan dígitos:
-es capicúa
-es múltiplo de 5 (el último dígito es 0 o 5)
-es múltiplo de 6 (es par, termina en '0', '2', '4', '6', '8', y la suma de sus dígitos es múltiplo de 3)
-es múltiplo de 11(a la suma de los dígitos de posiciones pares, le resto la suma de los dígitos de posiciones
impares. Si es resultado es 0, es múltiplo de 11).
-es mayor a 100*/

#include <stdio.h>
#include <stdlib.h>
#define VERDADERO   1
#define FALSO       0

void resolver(char * vec, int ce);
int multiplo_de_cinco(char * fin);
int multiplo_de_tres(char * vec, char * fin);
int es_capicua(char * vec, char * fin, int ce);
int multiplo_de_once(char * vec, int ce);
int es_mayor_a_100(char * vec, int ce);
int compuesta_por_solo_tres_digitos(char * vec, int ce);
int compuesta_por_mas_de_tres_digitos(char * vec, int ce);

int main()
{
    char vec[] = "00110";     //me falta evaular el caso en que sea 100
    int ce= sizeof(vec)/sizeof(char);    //recordar que tambien cuenta el '\0'

    resolver(vec, ce-1);

    system("pause");
    return 0;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

void resolver(char * vec, int ce)
{
    char * fin = vec+ce-1;

    if(multiplo_de_cinco(fin))
        printf("Es multiplo de 5\n");

    if(es_capicua(vec, fin, ce))
        printf("Es capicua\n");

    if(multiplo_de_tres(vec, fin))
        printf("Es multiplo de 3\n");

    if(multiplo_de_once(vec, ce))
        printf("Es multiplo de 11\n");

    if(es_mayor_a_100(vec,ce))          //podria resolverse con atoi sencillamente, convirtiendo el char en entero
        printf("es mayor a 100\n");     //if(atoi(vec)>100) printf("es mayor a 100");
                                        //pero vamos a complejizarlo y resolverlo en char tal como está

}

//////////////////////////////////////////////
//////////////////////////////////////////////

int multiplo_de_cinco(char * fin)
{
    return *(fin)=='0' || *(fin)=='5' ;
}

//////////////////////////////////////////////
//////////////////////////////////////////////


int multiplo_de_tres(char * vec, char * fin)
{
    int suma=0;

    if(*fin=='0' || *fin=='2' || *fin=='4' || *fin=='6' || *fin=='8')
    {
        while(*vec!= '\0')
        {
            suma+= (*vec)-48;
            vec++;
        }

        if(suma%3==0)
            return VERDADERO;
    }

    return FALSO;
}

//////////////////////////////////////////////
//////////////////////////////////////////////


int es_capicua(char * vec, char * fin, int ce)
{
    int cont=0;
    while(vec<fin && *vec == *fin)
    {
            vec++;
            fin--;

            cont++;
    }

    return cont >= ce/2;
}

//////////////////////////////////////////////
//////////////////////////////////////////////


int multiplo_de_once(char * vec, int ce)
{
    int sumpar=0;
    int sumimp=0;

    for(int i=0; i<ce; i++)
    {
        if(i%2==0)
            sumpar+= vec[i]-48;
        else
            sumimp+= vec[i]-48;
    }

    return (sumpar - sumimp==0)?   VERDADERO   :   FALSO;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

int es_mayor_a_100(char * vec, int ce)
{

    if(ce==3)
    {
        return compuesta_por_solo_tres_digitos(vec, ce);
    }


    if(ce>3)
    {
        return compuesta_por_mas_de_tres_digitos(vec, ce);
    }


    return FALSO;   //ejemplo 99
}

//////////////////////////////////////////////
//////////////////////////////////////////////

int compuesta_por_solo_tres_digitos(char * vec, int ce)
{
    if(*vec!= '0')
    {
        vec++;
        if(*vec=='0')
            {
            vec++;
            if(*vec=='0')   //para el caso de 100
                return FALSO;
            else
                return VERDADERO;
            }
        else
            return  VERDADERO;
    }
    else
        return FALSO;   //ej 045 o 004
}

//////////////////////////////////////////////
//////////////////////////////////////////////

int compuesta_por_mas_de_tres_digitos(char * vec, int ce)
{
int cont_ceros = 0;

    while(*vec == '0')
    {
        cont_ceros++;
        vec++;
    }

    if(ce - cont_ceros> 3)  //ejemplo 0034565
    {
        return VERDADERO;
    }
    if( ce- cont_ceros==3)  //ejemplo 00453
    {
        if(*vec=='1')
            vec++;
                if(*vec=='0')
                    vec++;
                        if(*vec=='0')       //para el caso de 000100
                            return FALSO;
                        else
                            return VERDADERO;   //ejemplo 00000105

    }

return FALSO;               //ejemplo 00045
}
