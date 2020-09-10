#include "vector.h"
#define ce  6

int main()
{

    int vec[ce] = {4,8,1,2,9,7};

    printf("Muestro el vector no ordenado:\n");
    mostrar(vec, ce);

    ordenar(vec, ce);

    printf("Muestro el vector ordenado:\n");
    mostrar(vec, ce);

    int n;
    printf("\nIngresar numero: ");
    scanf("%d", &n);
    vec[ce] = n;
    printf("\n");

    printf("Muestro el vector con el ultimo dato ingresado en el ultimo lugar:\n");
    mostrar(vec, ce+1);

    ordenar(vec, ce+1);

    printf("Muestro el vector totalmente ordenado:\n");
    mostrar(vec, ce+1);


    return 0;
}



