/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Triangulo.h"

//tampoco es necesario este método para este ejercicio,
//pero decidí incluirlo para que esté más completo
Triangulo::Triangulo()
{
    base   = 1;
    altura = 1;
}

Triangulo::Triangulo(double _base, double _altura)
{
    base   = _base;
    altura = _altura;
    if(base<=0 || altura<=0)
        throw FiguraInvalidaException();
}

double Triangulo::area() const
{
    return (base*altura)/2;
}
