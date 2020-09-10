/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef CUADRADO_H_
#define CUADRADO_H_
#include "Figura.h"

//clase hija, que hereda de Figura
//para que esta clase no sea abstracta, sobreescribo método área
//entonces esta clase será clase concreta (no abstracta)
//lo mismo sucederá con las otras clases hijas Rectángulo y Triángulo
class Cuadrado : public Figura
{
    public:
        Cuadrado(); //este método no lo pide el ejercicio(según el main),
                    //pero lo hago para más eficiencia
        Cuadrado(double);
        double area();
};





#endif // CUADRADO_H_
