/*Crearemos un vector de estructura y luego lo ordenamos con el metodo de burbujeo. El cual consiste en tomar de a dos
elementos y compararlos. De ser el primero menor, se queda tal cual esta. Caso contrario se invierten. Y luego avanzo
una posicion y sigo comparando de a pares. En la primera pasada, quedara el mayor ordenado en la ultima posicion, por
lo que se vuelva a empezar desde el inicio. Por lo tanto se hacen reiteradas pasadas. Ejemplo: 4 8 2 1 5
Primera pasada: 4 2 1 5 8. Segunda: 2 1 4 5 8. Tercera: 1 2 4 5 8.
Por otro lado usaremos una funcion del tipo generica, porque lo que dica funcion no solo resuelve un vector de enteros,
como en el ejemplo, sino que puede resolver de cualquier tipo. Ej char. */

#include "ordenarstruct.h"

int main()
{
    t_producto vec_prod[] = {
                            {4, "leche", 50},
                            {3, "harina", 40},
                            {5, "arroz", 30},
                            {1, "polenta",35},
                            {2, "arvejas",25},
                            };

    int ce= sizeof(vec_prod)/sizeof(t_producto);

    ///////////////////////////////////////////////////////


    ordenar(vec_prod, ce, sizeof(t_producto), cmp_ent);

    printf("Ordenado por codigo: \n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-14s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }

    ///////////////////////////////////////////////////////

    ordenar(vec_prod, ce, sizeof(t_producto), cmp_char);

    printf("Ordenado por nombre: \n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-14s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }

    ///////////////////////////////////////////////////////

    ordenar(vec_prod, ce, sizeof(t_producto), cmp_float);

    printf("Ordenado por precio:\n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-14s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }

    printf("\n");

    system("pause");
    return 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

