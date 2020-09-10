/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 33.329.371-RUIZ,IvanaAnahiVictoria-(06-2965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
friend ostream& operator << (ostream &, const Prisma &);

//es friend ya que para el caso de 5 * pri1;
//el obj llamador(5) no es miembro de la clase
friend Prisma operator *(int, const Prisma &);

private:
    string color;
    int alto;
    int ancho;
    int profundidad;
//   string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    //constructores
    Prisma();
    Prisma(string, int, int);
    Prisma(string, int, int, int);

    //este constructor al final no hacía falta (según la correción del profe)
    Prisma(const Prisma&);  //constructor de copia

    //sobrecarga de operadores
    Prisma operator ++(int);
    Prisma& operator --();
    //este método al final no hacía falta (según la correción del profe)
    Prisma& operator =(const Prisma &);

    Prisma& validarValores();
};

#endif // PRISMA_H_

