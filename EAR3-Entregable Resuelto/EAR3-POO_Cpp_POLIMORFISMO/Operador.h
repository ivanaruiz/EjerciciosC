/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED

#include <string>

using namespace std;

//Clase padre
//Tambi�n es clase abstracta, al ser abstracta no puedo instanciar objetos de la misma
class Operador
{
private:
    //Atributos
    float _operA;
    float _operB;

public:
    //Constructor parametrizado
    Operador(float, float);

    //Destructor
    virtual ~Operador();

    //M�todos
    float getOperandoA();
    float getOperandoB();

    /**Al ser Operador una clase abstracta, estos siguientes m�todos virtuales puros
    no los definiremos en esta clase, sino que lo haremos en las clases derivadas**/
    virtual float calcular() = 0;
    virtual string operacion() const = 0;

    /**Aclaraci�n: el siguiente constructor no se pide seg�n el main de este ejercicio,
    pero lo dejo para que est� m�s completo y eficiente.
    Lo mismo aplica a las clases hijas con respecto a este constructor por defecto.**/
    Operador();

    /**El siguiente m�todo tampoco se pide, pero lo hago para poder modificar
    los valores por defecto en una divisi�n (para que no quede divisor 0)**/
    void setOperadorB(float);
};

/// complete la declaraci�n de la class


#endif // OPERADOR_H_INCLUDED
