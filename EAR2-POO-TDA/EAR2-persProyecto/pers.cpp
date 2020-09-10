/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/

#include <string.h>
#include <stdio.h>
#include "pers.h"
/// DESARROLLE ACÁ LOS MÉTODOS (y FUNCIONES MIEMBRO) DE LA CLASS


Pers::Pers()
{
    this->dni = 0L;
    this->sexo= 'X';
    this->edad= 0;
    this->apyn= "NN";         //en caso de usar string

    //en caso de usar char
    //this->apyn= new char[3];
    //strcpy(this->apyn, "NN");
}

//si uso string, uso este siguiente constructor
Pers::Pers(long _dni, char _sexo, string _apyn, int _edad)
    :   dni(_dni), sexo(_sexo), apyn(_apyn), edad(_edad)
{
}


//si uso char *, uso el siguiente constructor
/*Pers::Pers(long _dni, char _sexo, char * _apyn, int _edad)
{
    this->dni = _dni;
    this->sexo= _sexo;
    this->edad= _edad;

    if(!_apyn)     //lo mismo, si el usuario mandó nada, le asigno un '\0'
    {
        this->apyn= new char[3];
        strcpy(this->apyn, "NN");
        return;
    }

    this->apyn = new char[strlen(_apyn) +1];
    strcpy(this->apyn, _apyn);
}
*/


/*en caso de usar char uso este destructor
Pers::~Pers()
{
    delete[]this->apyn;
}
*/


ostream& operator << (ostream &salida, const Pers &p)
{
    salida << p.dni << "-"<<p.sexo<<"-"<<p.edad<<"-"<<p.apyn;
    return salida;
}


/*
istream& operator >>(istream &entrada, Pers &p)
{
    char guion= '-';
    entrada>>p.dni >>guion;
    entrada>>p.sexo>>guion;
    entrada>>p.edad>>guion;
    entrada>>p.apyn;

    return entrada;
}
*/


istream &operator >>(istream &entrada, Pers &p)
{
    entrada >> p.dni;
    entrada.ignore(1,'\0');     //ignoro el guión
    entrada >> p.sexo;
    p.sexo = toupper(p.sexo);
    entrada.ignore(1, '\0');
    entrada >> p.edad;
    entrada.ignore(1,'\0');

    getline(entrada, p.apyn);   //getline para poder atrapar toda la cadena incluso espacios
                                //solo sirve para string
    return entrada;
}



Pers Pers::operator++(int num)
{
    Pers aux(*this);
    this->edad+=1;
    return aux;
}
