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


    printf("Ordenado por dni: \n");
    //como primero quiero ordenar por dni, le paso por parametro esa funcion
    //es decir le paso el puntero a la funcion que quiero que ejecute
    //no le pongo los parentesis a cmp_x_dni porque sino el compilador esperara los parametros
    //y los parametros aun no los tengo(los manejo en otra subfuncion), en la de buscar menor
    //el nombre de la funcion indica un puntero a esa funcion
    //entonces si lo paso sin parentesis, esta funcion NO se va a ejecutar ya, sino que va a ser pasado como puntero
    ord_struct_x_sel(vec, cant_reg, cmp_x_dni);

    int i;
    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }



    printf("\nOrdenado por nombre: \n");
    //ahora le mando por parametro la otra funcion, que ordena por nya
    //aca lo mismo. no se va a ejecutar la funcion cmp_x_nya. sino que estoy pasando como puntero
    //es decir le digo a la funcion ord_struct.. que cuando compare, USE esa funcion
    ord_struct_x_sel(vec, cant_reg, cmp_x_nya);


    for(i=0; i<cant_reg; i++)
    {
        printf("%2d %2s\n", vec[i].dni , vec[i].nya);
    }

    system("pause");
    return 0;
}


