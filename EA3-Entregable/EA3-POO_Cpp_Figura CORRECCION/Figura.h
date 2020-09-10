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
                    //pero lo hago para más eficiencia

        //hago sobrecarga de dos constructores más
        //el de dos parámetros lo usará la subclase Rectángulo y Triángulo
        Figura(double, double);
        //el de un parámetro solo lo usará el de Cuadrado
        Figura(double);


        //al ser clase abstracta, y =0,
        //no voy a definir este método aquí, sino en las clases hijas
        virtual double area() = 0;


        //no hace falta igualar a 0 este destructor
        //con tal de que haya un método igualado a 0 (el método anterior)
        //ya me hace abstracta la clase
        //por otro lado, no hace falta volver a declarar este método en clases hijas
        virtual ~Figura();
};




#endif // FIGURA_H_
