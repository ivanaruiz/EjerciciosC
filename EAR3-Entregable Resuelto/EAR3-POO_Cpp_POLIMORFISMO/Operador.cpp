/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Operador.h"

//Constructor por defecto
Operador::Operador()
{
    this->_operA = 0;   //pongo valores por default
    this->_operB = 0;
}

//Constructor parametrizado
Operador::Operador(float _operA, float _operB)
{
    this->_operA = _operA;
    this->_operB = _operB;
}

//Destructor
Operador::~Operador()
{
}

//Getters
float Operador::getOperandoA()
{
    return this->_operA;
}

float Operador::getOperandoB()
{
    return this->_operB;
}

void Operador::setOperadorB(float num)
{
    this->_operB = num;
}
/// complete la definición de la class
