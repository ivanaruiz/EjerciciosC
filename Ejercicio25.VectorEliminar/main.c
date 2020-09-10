#include "header.h"
#define ce  8   ///ce= cantidad de elementos

int main()
{
    int vec[ce] = {1,2,3,4,5,6,3,8};

    mostrar(vec,ce);

    int n;
    printf("Ingrese el dato que desea borrar: ");
    scanf("%d", &n);

    if(buscar(vec, ce, n)==VERDADERO)    ///si entra al if es porque borró el numero ingresado
        mostrar(vec,ce-1);               ///es ce-1 porque se borró un numero
            else
            {
                printf("\n\nNo se encuentra el %d\n", n);
                mostrar(vec, ce);   ///puedo volver a mostrar el vector ya que nada se ha borrado
            }

    return 0;
}
