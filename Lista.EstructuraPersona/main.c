#include "lista.h"
#include "persona.h"


int main()
{
    t_persona vec[] =   {
                        {2, "Persona 1", 'X'},
                        {8, "Persona 2", 'X'},
                        {4, "Persona 3", 'X'},
                        {6, "Persona 4", 'X'},
                        {5, "Persona 5", 'X'},
                        {9, "Persona 6", 'X'},
                        {7, "Persona 7", 'X'},
                        {4, "Persona 8", 'X'},
                        {1, "Persona 9", 'X'},
                        {3, "Persona 10", 'X'},
                        };

    t_lista lista_pers;

    crear_lista(&lista_pers);


    printf("colocamos elementos en una lista ordenada:\n");
    for(int i=0; i<sizeof(vec)/sizeof(t_persona); i++)
    {
        poner_orden_lista(&lista_pers, &vec[i], sizeof(t_persona), cmp_dni);
        printf("\n");
        mostrar_lista(&lista_pers);
    }

    printf("\n\nsacamos elementos de lista");
    t_persona pers;
    for(int i=0; i<sizeof(vec)/sizeof(t_persona); i++)
    {
        pers.dni = vec[i].dni;
        strcpy(pers.apyn, "xxxxxxxx");

        sacar_elem_orden_lista(&lista_pers, &pers, sizeof(t_persona), cmp_dni);
        printf("\n");

        printf("  -%d %s", pers.dni, pers.apyn);
        //mostrar_lista(&lista_pers);
    }

    puts("");
    system("pause");
    return 0;
}



int cmp_dni(const void * e1, const void * e2)
{
    t_persona * p1 = (t_persona *) e1;
    t_persona * p2 = (t_persona *) e2;
    return p1->dni - p2 ->dni;
}

