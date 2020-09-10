/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Resta.h"

Resta::Resta()
{
}

Resta::Resta(float _operA, float _operB)
    :   Operador(_operA, _operB)
{
}

float Resta::calcular()
{
    return Operador::getOperandoA() - Operador::getOperandoB();
}

string Resta::operacion() const
{
    return "RESTA";
}

/// complete la definición de la class
