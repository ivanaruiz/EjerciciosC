#include "alumno.h"

int main()
{
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


    int i;
    printf("Ordenado por dni: \n");

    //en sizeof(t_alumno) le estoy mandando la cant de bytes de cada registro, en este caso 36
    //necesitamos ese dato ya que estamos trabajando con datos de tipo void, es decir que no sabemos qu� son
    ord_vec_x_sel(vec, cant_reg, sizeof(t_alumno), cmp_x_dni);

    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }



    printf("\nOrdenado por nombre: \n");

    ord_vec_x_sel(vec, cant_reg, sizeof(t_alumno), cmp_x_nya);


    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }

    system("pause");
    return 0;
}

