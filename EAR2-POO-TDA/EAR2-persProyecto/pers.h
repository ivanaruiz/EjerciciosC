/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/

#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <iostream>
#include <string>

#include "stdio.h"
#include "stdlib.h"

#include <cstdio>


using namespace std;


class Pers
{
    friend istream& operator >>(istream &, Pers &);  // ingresa por teclado un objeto
    friend ostream& operator <<(ostream &, const Pers &);  // muestra por pantalla un objeto

    private:

        long    dni;
        char    sexo;
        string  apyn;       // Apellido/s y nombre/s
//      char   *apyn;       en su defecto usar:  char   *apyn;
        int     edad;

    public :
        Pers();             // defecto
        Pers(long, char, string, int);          //si uso string
        //Pers(long, char, char *, int);        //si uso char
        Pers operator++(int);                   // incrementa edad
        //~Pers();                              //en el caso de que use char, uso destructor
};
#endif

