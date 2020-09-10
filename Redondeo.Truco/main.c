#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 7;
    int b = 5;
    int c = 5;

    //creo dos variables de promedio, una de tipo float, y la otra de tipo int
    //es para ver las diferencias de una con otra a la hora de redondear
    float promedio = ( (float)a + (float)b + (float)c) / 3;
    int prom = (a+b+c)/3;

    //notaremos que con float promediamos para arriba (se ve en la segunda línea de código)
    printf("Promedio : %f \n", promedio);
    printf("Promedio : %2.0f\n", promedio);


    //en cambio con int, promediamos para abajo, (se ve en la segunda línea de código)
    printf("Promedio : %d\n", prom);
    printf("Promedio : %2.0f\n", (float)prom);

    system("pause");
    return 0;
}
