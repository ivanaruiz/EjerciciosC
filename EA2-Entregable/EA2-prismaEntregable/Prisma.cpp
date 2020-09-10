/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

Prisma::Prisma()
{
    this->color = "Incoloro";
    this->alto  = 1;
    this->ancho = 1;
    this->profundidad = 1;
}

Prisma::Prisma(string _color, int _alto, int _ancho)
    :   color(_color) , alto(_alto) , ancho(_ancho) , profundidad(1)
{
    if(color=="" || alto<=0 || ancho<=0)
        validarValores();
}

Prisma::Prisma(string _color, int _alto, int _ancho, int _profundidad)
    :   color(_color) , alto(_alto) , ancho(_ancho) , profundidad(_profundidad)
{
    if(color=="" || alto<=0 || ancho<=0 || profundidad<=0)
        validarValores();
}

//constructor de copia // Prisma pri3(pri0);
//este constructor al final no hacía falta (según la correción del profe)
Prisma::Prisma(const Prisma &p)
{
    this->color = p.color;
    this->alto  = p.alto;
    this->ancho = p.ancho;
    this->profundidad = p.profundidad;
}

//sobrecarga del operador de asignación =
//este método al final no es necesario (según la correción del profe)
Prisma& Prisma::operator =(const Prisma &p)
{
    this->color = p.color;
    this->alto  = p.alto;
    this->ancho = p.ancho;
    this->profundidad = p.profundidad;

    return * this;
}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    alto +=1;
    ancho+=1;
    profundidad+=1;

    return aux;
}

Prisma& Prisma::operator--()
{
    this->alto -=1;
    this->ancho-=1;
    this->profundidad-=1;

    if(alto<=0 || ancho<=0 || profundidad<=0)
        validarValores();

    return * this;
}

Prisma& Prisma::validarValores()
{
    /**Si alguno de los valores fuera negativo o cero, decidí que el programa los cambie
    automáticamente.
    Así mismo si el color fuera vacío, que lo setee a "Incoloro".
    Esto no me lo pide en el ejercicio, pero opté por hacerlo así cuestión que no me quede
    un prisma con datos inconsistentes**/

    alto   < 0 ? alto *= (-1)  :  (alto ==0 ? alto  = 1 : alto  );
    ancho  < 0 ? ancho*= (-1)  :  (ancho==0 ? ancho = 1 : ancho );
    profundidad  < 0 ? profundidad*= (-1)  :  (profundidad==0 ? profundidad = 1 : profundidad);
    color == "" ? color = "Incoloro" : color;

    cout <<"Algunos valores fueron cambiados por haber ingresado valores invalidos"<<endl;

    return * this;
}

ostream& operator << (ostream & salida, const Prisma & p)
{
    salida << p.alto << "x" << p.ancho << "x" << p.profundidad << "-" << p.color;
    return salida;
}

Prisma operator *(int num, const Prisma &p)
{
    //También modifico al número que multiplica si este resultara negativo o cero
    num < 0 ? num*= -1 : (num==0 ? num = 1 : num);
    Prisma aux(p.color, p.alto * num , p.ancho * num , p.profundidad * num);
    return aux;
}
