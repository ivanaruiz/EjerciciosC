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


//sobreescribo este m�todo, y as� pierde la condici�n de clase abstracta
double Cuadrado::area()
{
    return this->base* this->base;
}

