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

    ord_struct_x_sel(vec, cant_reg);

    int i;
    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }

    ord_struct_x_sel(vec, cant_reg);

    system("pause");
    return 0;
}


