/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef SUMA_H_INCLUDED
#define SUMA_H_INCLUDED

#include <string>
#include "Operador.h"

//Clase hija (y además es clase concreta)

class Suma : public Operador
{
public:
    //Constructores
    Suma();
    Suma(float, float);

    //En esta clase sí implementaremos estos métodos
    float calcular();
    string operacion() const;
};

/// complete la declaración de la class


#endif // SUMA_H_INCLUDED
