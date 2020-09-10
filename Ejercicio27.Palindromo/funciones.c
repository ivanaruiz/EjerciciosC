#include "header.h"
#define ce  20

int frase(char *vec)
{
    char *ptr= vec;
    char *ptrFin = vec; //le asigno cuaquier cosa total en la siguiente funci�n �sto se modificar�

    ptrFin = cortarPalabra(ptr, ptrFin);    ///en este puntero quedara la ubicacion de la ultima letra

    int aviso=1;    //si se mantiene en 1(TRUE), hay coincidencia de letras(posible pal�ndromo)

    while(ptr<=ptrFin)
    {
        if(*ptr==*ptrFin)   //aca comparo de a dos letras(sus contenidos)
        {
            ptr++;          //si hubo coincidencia, entonces se mueven los punteros de a un lugar
            ptrFin--;
        }
        else
        {
            aviso=0;        //si pasa por aca es porque alguna letra no tuvo coincidencia
            return aviso;   //asi que se pone en 0, y cortamos la funci�n
        }
    }
    return aviso;   //si llegamos ac� es porque hubo efectivamente un pal�ndromo
}


//hago esta funci�n para usar la cantidad de caracteres de la palabra ingresada
//y no los 20 que ten�a asignado al principio

char * cortarPalabra(char *ptr, char *ptrFin)    //devolver� una direcci�n de puntero
{
    for(int i=0; i<ce ; i++)//con este for corto la palabra ingresada y qued� asignado el puntero ptr
        {                   //a la primera letra, y el puntero ptrFin a la ultima letra
            if(*ptr == '\0')
            {
                ptr--;      //al encontrar un fin de cadena '\0', debe retroceder un lugar asi obtiene la ult letra
                ptrFin= ptr;    //finalmente se lo asigno a ptrFin

                break;
            }
            ptr++;
        }

      return ptrFin;   ///devuelve una direccion
}
