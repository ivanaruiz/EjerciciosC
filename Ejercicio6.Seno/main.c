//El ejercicio funciona correctamente, pero no con números muy grandes. ej sen 50 , me da mal.
//en cambio sen 2 , me da correcto.

#include "seno.h"

int main()
{
    int n;
    float tol;

    ingresoDatos(&n,&tol);

    printf("seno (%d) = %lf \n", n, seno(n, tol));

    system("pause");
    return 0;
}


