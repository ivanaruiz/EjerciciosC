/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Triangulo.h"

//Notar que no hace falta que inicialice nuevamente base= 1, altura=1
//puesto que ya lo hace Figura
Triangulo::Triangulo()
{
}


Triangulo::Triangulo(double _base, double _altura)
    :   Figura(_base, _altura)
{
}


double Triangulo::area()
{
    return (this->base * this->altura)/2;
}
