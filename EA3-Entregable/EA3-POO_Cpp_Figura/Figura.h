/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

//clase padre

class Figura
{
    //no defino atributos en esta clase, las definiré en las clases derivadas

    public:
    //al ser clase abstracta, no voy a definir este método aquí, sino en las clases hijas
        virtual double area() const = 0;
    //destructor
        virtual ~Figura();
};



#endif // FIGURA_H_
