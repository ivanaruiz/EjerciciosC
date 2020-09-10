/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef RESTA_H_INCLUDED
#define RESTA_H_INCLUDED

#include "Operador.h"

//Clase hija
class Resta : public Operador
{
public:
    Resta();    //recordar que este constructor no era necesario, pero lo aplico para mayor eficiencia
    Resta(float, float);

    float calcular();
    string operacion() const;
};

/// complete la declaración de la class


#endif // RESTA_H_INCLUDED
