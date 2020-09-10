
#include "pila.h"

/*Ordeno un vector ayudándome de dos pilas dinámicas.*/

void muestro_vec(int * vec, int ce);



int main()
{
    t_pila p;
    t_pila p_aux;

    crear_pila(&p);         //acá me quedarán los datos ordenados
    crear_pila(&p_aux);     //esta pila auxiliar me ayudará a ordenar

    int vec[]= {2,1,7,5,4,6,3,8};
    muestro_vec(vec, sizeof(vec)/sizeof(int));


    printf("\nOrdeno con dos pilas:\n");


    int elem;
    int aux;

    //al primer elemento lo mando por default a la pila
    poner_en_pila(&p, &vec[0], sizeof(int));


    for(int i=1; i<sizeof(vec)/sizeof(int); i++)
    {
        ver_tope(&p, &elem, sizeof(int));   //siempre compararé con el tope de p

        if(vec[i]<=elem)    //si entra por acá es porque viene en orden
        {
            poner_en_pila(&p, &vec[i], sizeof(int));
        }

        else if(vec[i]>elem)    //sino empiezo a ordenar ayudándome de p_aux
        {
            while(vec[i]>elem && !pila_vacia(&p))
            {
                sacar_de_pila(&p, &aux, sizeof(int));
                poner_en_pila(&p_aux, &aux, sizeof(int));

                ver_tope(&p, &elem, sizeof(int));
            }

            //finalmente meto el dato que venía desordenado
            poner_en_pila(&p, &vec[i], sizeof(int));

            //y ahora meto los que me quedaron en p_aux (a pila p)
            while(!pila_vacia(&p_aux))
            {
                sacar_de_pila(&p_aux, &aux, sizeof(int));
                poner_en_pila(&p, &aux, sizeof(int));
            }
        }
    }


    //acá ya está ordenado, entonces procedo a desempilar p y mostrar
    while(!pila_vacia(&p))
    {
        sacar_de_pila(&p, &elem, sizeof(int));
        printf("%d ", elem);
    }

    puts("");
    system("pause");
    return 0;
}



void muestro_vec(int * vec, int ce)
{
    printf("Muestro vector desordenado:\n");

    for(unsigned i = 0; i<ce; i++)
    {
        printf("%d ", vec[i]);
    }
    puts("");
}
