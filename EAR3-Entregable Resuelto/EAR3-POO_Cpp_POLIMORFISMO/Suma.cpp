/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Suma.h"

Suma::Suma()
{
}

Suma::Suma(float _operA, float _operB)
    :   Operador(_operA, _operB)
{
}

//Acá definimos estos métodos y así esta clase no será abstracta, sino concreta
float Suma::calcular()
{
    return Operador::getOperandoA() + Operador::getOperandoB();
}

string Suma::operacion() const
{
    return "SUMA";
}

/// complete la definición de la class
