/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Division.h"

Division::Division()
{
    /**para que no me tome el 0 por defecto del constructor de Operador, le mando un 1
    (al divisor)**/
    Operador::setOperadorB(1);
}

Division::Division(float _operA, float _operB)
    :   Operador(_operA, _operB)
{
    if(Operador::getOperandoB()==0)
        throw DivisionPorCeroException();   //lanza la excepción, la cual es atrapada
}                                           //por el bloque catch

float Division::calcular()
{
    return Operador::getOperandoA() / Operador::getOperandoB();
}

string Division::operacion() const
{
    return "DIVISION";
}

/// complete la definición de la class
