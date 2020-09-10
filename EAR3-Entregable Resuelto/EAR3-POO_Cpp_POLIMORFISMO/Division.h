/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED

#include "Operador.h"
#include "DivisionPorCeroException.h"

//Clase hija
class Division : public Operador
{
public:
    Division();
    Division(float, float);

    float calcular();
    string operacion() const;
};

/// complete la declaración de la class


#endif // DIVISION_H_INCLUDED
