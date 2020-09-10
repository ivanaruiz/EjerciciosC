/**//* NO DEBE MANDAR ESTE ARCHIVO   -   SI TODOS LOS DEMÁS  *//**/

#include <iostream>

#include "Suma.h"
#include "Resta.h"
#include "Division.h"
#include "DivisionPorCeroException.h"

using namespace std;

void mostrarOperacion(Operador *p);

int main()
{
    cout << endl << "Esperado: 12 resultado de SUMA de 5 y 7" << endl <<
                    "--------: ";
    Suma s(5, 7);
    mostrarOperacion(&s);

    cout << endl << "Esperado: 3 resultado de RESTA de 10 y 7" << endl <<
                    "--------: ";
    Resta *r = new Resta(10, 7);
    mostrarOperacion(r);

    cout << endl << "Esperado: -4 resultado de DIVISION de 20 y -5" << endl <<
                    "--------: ";
    Operador *d = new Division(20, -5);
    mostrarOperacion(d);

    // La siguiente linea no deberìa compilar
    //Operador o;

    cout << endl << "Esperado: Excepcion: Division por cero" << endl <<
                    "--------: ";
    try
    {
        Operador *malD = new Division (1, 0);
        mostrarOperacion(malD);
        delete malD;
    }
    catch(DivisionPorCeroException &dpc)
    {
        cout << "Excepcion: " << dpc.what() << endl;
    }

    delete r;
    delete d;

    return 0;
}



void mostrarOperacion(Operador *p)
{
    float r = p->calcular();
    cout << r << " resultado de "
         << p->operacion() << " de "
         << p->getOperandoA() << " y "
         << p->getOperandoB() << endl;
}

