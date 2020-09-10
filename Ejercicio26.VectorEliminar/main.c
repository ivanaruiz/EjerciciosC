#include "header.h"
#define ce  10

int main()
{
    int vec[ce] = {3,5,3,4,5,6,3,8,3,4};
    int cant=0;    ///cantidad de veces que encuentre el mismo valor

    mostrar(vec,ce);

    int n;
    printf("Ingrese el dato que desea borrar: ");
    scanf("%d", &n);

    cant = buscar(vec, ce, n);


    if(cant>0)
        mostrar(vec,ce-cant);  ///el for lo recorrera 10-(cantidad de veces encontrado el num) veces
            else
            {
                printf("\n\nNo se encuentra el %d\n", n);
                mostrar(vec, ce);
            }


    return 0;
}
