/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Figura.h"


class Rectangulo : public Figura
{
    public:
        Rectangulo();   //tampoco este m�todo es pedido aqu� en este ejercicio,
                        //pero me result� importante agregarlo
        Rectangulo(double, double);
        double area();


        //notar que no hace falta declarar al destructor de nuevo
        //ya lo tiene Figura
};





#endif // RECTANGULO_H_
