/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ESTE ARCHIVO NO DEBE SER ENVIADO                           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include <iostream>

#include "Figura.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Triangulo.h"

using namespace std;

/*Desarrollar clase Figura, y subclases Cuadrado, Rectángulo y Triángulo.
Deben responder al siguiente main.
Por otro lado yo había optado que en Figura no tuviera atributos, sino que cada subclase
tenga sus atributos. Puesto que si, por ejemplo, tuviera la subclase Circulo,
no usaría base y alturo, sino que usaría radio (como atributo) y PI (como constante).
Sin embargo mi ejercicio fue corregido como incorrecto, y que la clase Figura debería
tener los atributos de base y altura.
Por tanto acá corregí eso.*/

void funcionMostrar(Figura *p);

int main()
{
    Triangulo t1;
    funcionMostrar(&t1);
    Cuadrado c1;
    funcionMostrar(&c1);
    Rectangulo r1;
    funcionMostrar(&r1);
    cout<<endl;
    //La parte de arriba no estaba incluida en el ejercicio
    //La agregué yo.


    cout << "Esperado: El area de la figura es: 9" << endl << "--------: ";
    Cuadrado *c = new Cuadrado(3);
    funcionMostrar(c);

    cout << endl << "Esperado: El area de la figura es: 20" << endl << "--------: ";
    Figura *r = new Rectangulo(4, 5);
    funcionMostrar(r);

    cout << endl << "Esperado: El area de la figura es: 6" << endl << "--------: ";
    Triangulo t(3, 4);
    funcionMostrar(&t);

    // La siguiente linea no deberìa compilar
    //Figura f();

    cout << endl << "Esperado: Excepcion: Figura invalida" << endl << "--------: ";
    try
    {
        Cuadrado malC(0);
        funcionMostrar(&malC);
        Triangulo *malT = new Triangulo (-1, -5);
        funcionMostrar(malT);
    }
    catch(FiguraInvalidaException &efi)
    {
        cout << "Excepcion: " << efi.what() << endl;
    }

    delete c;
    delete r;

    return 0;
}

void funcionMostrar(Figura *p)
{
    cout << "El area de la figura es: " << p->area() << endl;
}
