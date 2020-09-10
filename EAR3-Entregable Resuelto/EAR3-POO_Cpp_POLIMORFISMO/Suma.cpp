/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Suma.h"

Suma::Suma()
{
}

Suma::Suma(float _operA, float _operB)
    :   Operador(_operA, _operB)
{
}

//Ac� definimos estos m�todos y as� esta clase no ser� abstracta, sino concreta
float Suma::calcular()
{
    return Operador::getOperandoA() + Operador::getOperandoB();
}

string Suma::operacion() const
{
    return "SUMA";
}

/// complete la definici�n de la class
