/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
    base   = 1;     //valores por defecto
    altura = 1;
}

Rectangulo::Rectangulo(double _base, double _altura)
{
    base   = _base;
    altura = _altura;
    if(base<=0 || altura <=0)
        throw FiguraInvalidaException();
}

double Rectangulo::area() const
{
    return base*altura;
}
