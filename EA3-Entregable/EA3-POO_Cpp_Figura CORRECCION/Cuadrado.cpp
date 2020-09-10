/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Cuadrado.h"

//Notar que no hace falta que inicialice nuevamente base= 1, altura=1
//puesto que ya lo hace Figura
Cuadrado::Cuadrado()
{
}


Cuadrado::Cuadrado(double _base)
    :   Figura(_base)
{
//    if(this->base <=0)
//        throw FiguraInvalidaException();
}


//sobreescribo este método, y así pierde la condición de clase abstracta
double Cuadrado::area()
{
    return this->base* this->base;
}

