#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "lista.h"

typedef struct
{
    int dni;
    char apyn[20];
    char sexo;
}t_persona;

int cmp_dni(const void * e1, const void * e2);


#endif // PERSONA_H_INCLUDED
