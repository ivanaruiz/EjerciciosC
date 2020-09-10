/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef CUADRADO_H_
#define CUADRADO_H_
#include "Figura.h"

//clase hija, que hereda de Figura
//para que esta clase no sea abstracta, sobreescribo m�todo �rea
//entonces esta clase ser� clase concreta (no abstracta)
//lo mismo suceder� con las otras clases hijas Rect�ngulo y Tri�ngulo
class Cuadrado : public Figura
{
    public:
        Cuadrado(); //este m�todo no lo pide el ejercicio(seg�n el main),
                    //pero lo hago para m�s eficiencia
        Cuadrado(double);
        double area();
};





#endif // CUADRADO_H_
