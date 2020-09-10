/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Figura.h"

class Rectangulo: public Figura
{
    private:
        double base;
        double altura;
    public:
        Rectangulo();   //tampoco este método es pedido aquí en este ejercicio,
                        //pero me resultó importante agregarlo
        Rectangulo(double, double);
        double area() const;
};






#endif // RECTANGULO_H_
