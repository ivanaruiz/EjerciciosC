/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Rectangulo.h"

//Notar que no hace falta que inicialice nuevamente base= 1, altura=1
//puesto que ya lo hace Figura
Rectangulo::Rectangulo()
{
}

Rectangulo::Rectangulo(double _base, double _altura)
    :   Figura(_base, _altura)
{
}


double Rectangulo::area()
{
    return base*altura;
}
