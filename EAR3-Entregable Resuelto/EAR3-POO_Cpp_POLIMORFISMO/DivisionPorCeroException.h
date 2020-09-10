/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef DIVISIONPORCEROEXCEPTION_H_INCLUDED
#define DIVISIONPORCEROEXCEPTION_H_INCLUDED

#include <exception>

using namespace std;

class DivisionPorCeroException : public exception
{
    public:
        DivisionPorCeroException() : exception() {}
        const char *what() throw()
        {
            return "Division por cero";
        }
};

/// complete la declaración de la class


#endif // DIVISIONPORCEROEXCEPTION_H_INCLUDED
