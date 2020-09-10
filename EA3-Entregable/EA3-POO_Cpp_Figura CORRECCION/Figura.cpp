/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#include "Figura.h"


//Constructores (3)
//Notar que este constructor lo inicializo solo aquí,
//y no hace falta que se vuelva a inicializar en clases hijas
Figura::Figura()
{
    this->base   = 1;
    this->altura = 1;
}


//Estos dos constructores, arrojan la excepción en caso
//de haber ingresado datos inválidos.
//En las clases hijas no hace falta que vuelva a hacer ésto,
//ya que llamarán a este constructor.
Figura::Figura(double _base, double _altura)
    :   base(_base), altura(_altura)
{
    if(base<=0 || altura<=0)
        throw FiguraInvalidaException();
}


Figura::Figura(double _base)
    :   base(_base)
{
    if(base<=0)
        throw FiguraInvalidaException();
}

//destructor virtual
Figura::~Figura()
{
}


