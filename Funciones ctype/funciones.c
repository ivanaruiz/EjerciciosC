#include "ctype.h"

int my_isdigit(char c)
{
   return (ES_NUMERO(c) ? VERDADERO : FALSO);
}

int my_isalpha(char c)
{
    return ( ES_LETRA(c) ? VERDADERO : FALSO);
}

int my_isspace(char c)
{
    return( ES_ESPACIO(c)  ? VERDADERO: FALSO);
}

char my_toupper(char c)
{
    if(c>=97 && c<=122)
        return c-32;
    return c;
}

char my_tolower(char c)
{
    if(c>=65 && c<=90)
        return c+32;
    return c;
}
