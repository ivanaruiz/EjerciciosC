/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

class Figura
{
    protected:      //notar que declaro los atributos como protected
        double base;
        double altura;

    public:
        //dos constructores(sobrecarga de constructores)
        Figura();   //este constructor no lo pide el ejercicio originalmente
                    //pero lo hago para m�s eficiencia

        //hago sobrecarga de dos constructores m�s
        //el de dos par�metros lo usar� la subclase Rect�ngulo y Tri�ngulo
        Figura(double, double);
        //el de un par�metro solo lo usar� el de Cuadrado
        Figura(double);


        //al ser clase abstracta, y =0,
        //no voy a definir este m�todo aqu�, sino en las clases hijas
        virtual double area() = 0;


        //no hace falta igualar a 0 este destructor
        //con tal de que haya un m�todo igualado a 0 (el m�todo anterior)
        //ya me hace abstracta la clase
        //por otro lado, no hace falta volver a declarar este m�todo en clases hijas
        virtual ~Figura();
};




#endif // FIGURA_H_
