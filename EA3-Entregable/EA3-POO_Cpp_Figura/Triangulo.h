/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo: public Figura
{
    private:
        double base;
        double altura;
    public:
        Triangulo();
        Triangulo(double, double);
        double area() const;
};






#endif // TRIANGULO_H_
