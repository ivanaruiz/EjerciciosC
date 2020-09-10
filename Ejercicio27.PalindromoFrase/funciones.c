#include "palindromo.h"

int es_palindromo(char *vec)
{
    char *ptrFin = sacarCaracteres(vec);   //saco comas, espacios, y otros caracteres que no sirven

    while(vec<=ptrFin)
    {
        if(*vec==*ptrFin)   //aca comparo de a dos letras(sus contenidos)
        {
            vec++;          //si hubo coincidencia, entonces se mueven los punteros de a un lugar
            ptrFin--;
        }
        else
            return FALSO;   //si pasa por aca es porque no hubo coincidencia y termina el ciclo
    }
    return VERDADERO;
}


//formateo toda la frase, le sacare comas, simbolos, dejandola compacta y todo en minusculas
char * sacarCaracteres(char *vec)
{
    char *ptr = vec;
    char *ptrFin;

    while(*vec!='\0')
    {
        if(NOESLETRA(*ptr))     //si es un caracter que no sea una letra...
        {
            while(*ptr!= '\0')  //empieza este ciclo para eliminar espacios y signos
            {
                *ptr= *(ptr+1); //se iran pisando los valores que no me sirven
                ptr++;
            }
            ptr= vec;           //luego de eliminar un caracter no valido,
                                //se restablece donde estaba el vector antes, y sigue
        }
        *ptr=tolower(*ptr);
        ptr++;
        vec++;
    }
    vec--;
    ptrFin = vec;

    return ptrFin;
}



