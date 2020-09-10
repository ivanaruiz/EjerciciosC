/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <exception>
using namespace std;

class FiguraInvalidaException: public exception
{
    public:
        FiguraInvalidaException() : exception() {}
        const char *what() throw()
        {
            return "Figura invalida";
        }
};






#endif // FIGURAINVALIDAEXCEPTION_H_
