/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"


class Triangulo: public Figura
{
    public:
        Triangulo();
        Triangulo(double, double);
        double area();

        //notar que no hace falta declarar al destructor de nuevo
        //ya lo tiene Figura
};






#endif // TRIANGULO_H_
