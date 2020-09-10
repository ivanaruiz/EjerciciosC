#include "alumno.h"

int main()
{
    int ordenar_0dni_1nya = 0;

    t_alumno vec[] =
                    {
                    {14,"m"},
                    {12,"a"},
                    {5,"g"},
                    {4,"d"},
                    {1,"f"},
                    {3,"c"},
                    {6,"e"},
                    {8,"b"},
                    {15,"n"},
                    {2,"h"},
                    {7,"o"},
                    {9,"i"},
                    {13,"l"},
                    {10,"j"},
                    {11,"k"}
                    };

    int cant_reg= sizeof(vec)/ sizeof(t_alumno);

    printf("Ordenado por dni: \n");
    ord_struct_x_sel(vec, cant_reg, ordenar_0dni_1nya);

    int i;
    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }

    printf("\nOrdenado por nombre: \n");
    ordenar_0dni_1nya = 1;
    ord_struct_x_sel(vec, cant_reg, ordenar_0dni_1nya);

    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }

    system("pause");
    return 0;
}
