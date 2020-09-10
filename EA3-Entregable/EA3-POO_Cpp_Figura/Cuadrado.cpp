/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Cuadrado.h"

Cuadrado::Cuadrado()
{
    lado = 1;   //le pongo un valor por defecto
}

Cuadrado::Cuadrado(double _lado)
{
    lado = _lado;
    if(lado<=0)
        throw FiguraInvalidaException();    //lanza la excepción, la cual es atrapada
                                            //por el bloque catch
}

double Cuadrado::area() const
{
    return lado*lado;
}

