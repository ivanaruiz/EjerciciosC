#include "lista.h"

int cmp_enteros(const void * a1, const void * a2);

/*pl apunta siempre al primero de la lista*/

int main()
{
    t_lista pl;
    crear_lista(&pl);
    int elem;

    ///////////////////////
    printf("poner_primero_lista  y  sacar_primero_lista:\n");
    for(int i=0; i<10; i++)
    {
        poner_primero_lista(&pl, &i, sizeof(i));
    }

    while(!lista_vacia(&pl))
    {
        sacar_primero_lista(&pl, &elem, sizeof(elem));  //notar que funciona como una pila
        printf("%d ",elem);
    }
    puts("");


    ///////////////////////
    printf("poner_ultimo_lista  y  sacar_primero_lista:\n");
    for(int i=0; i<10; i++)
    {
        poner_ultimo_lista(&pl, &i, sizeof(i));
    }

    while(!lista_vacia(&pl))
    {
        sacar_primero_lista(&pl, &elem, sizeof(elem));  //notar que funciona como una pila
        printf("%d ",elem);
    }
    puts("");

    ///////////////////////
    printf("poner_primero_lista  y  sacar_ultimo_lista:\n");
    for(int i=0; i<10; i++)
    {
        poner_primero_lista(&pl, &i, sizeof(i));
    }

    while(!lista_vacia(&pl))
    {
        sacar_ultimo_lista(&pl, &elem, sizeof(elem));
        printf("%d ",elem);
    }
    puts("");

    ///////////////////////
    printf("poner_primero_lista,  ver_primero_lista  y  ver_ultimo_lista:\n");
    for(int i=0; i<10; i++)
    {
        poner_primero_lista(&pl, &i, sizeof(i));
    }
    if(ver_primero_lista(&pl, &elem, sizeof(elem)))
        printf("primero de lista: %d\n", elem);

    if(ver_ultimo_lista(&pl, &elem, sizeof(elem)))
        printf("ultimo de lista: %d\n", elem);
    puts("");

    ///////////////////////
    printf("vaciar_lista,  ver_primero_lista  y  ver_ultimo_lista:\n");
    vaciar_lista(&pl);
    if(ver_primero_lista(&pl, &elem, sizeof(elem)))
        printf("primero de lista: %d\n", elem);

    if(ver_ultimo_lista(&pl, &elem, sizeof(elem)))
        printf("ultimo de lista: %d\n", elem);
    puts("");
    ///////////////////////
    printf("poner_ultimo_lista (del 1 al 3),  poner_ultimo_lista (el 5),\n"
           "poner_pos_lista(el 4 en pos 4)  y  luego sacar_primero_lista:\n");
    for(int i=1; i<4; i++)
    {
        poner_ultimo_lista(&pl, &i, sizeof(i));
    }
    int num= 5;
    poner_ultimo_lista(&pl, &num, sizeof(num));

    num=4;
    poner_pos_lista(&pl, &num, sizeof(num), 4);

    while(!lista_vacia(&pl))
    {
        sacar_primero_lista(&pl, &elem, sizeof(elem));
        printf("%d ",elem);
    }

    puts("");
    ///////////////////////
    int pos= 10;
    printf("\nponer_ultimo_lista (del 0 al 9)  y  sacar_pos_lista(el de pos %d):\n", pos);
    for(int i=0; i<10; i++)
    {
        poner_ultimo_lista(&pl, &i, sizeof(i));
    }

    if(sacar_pos_lista(&pl, &elem, sizeof(elem), pos))
        printf("saque de posicion %d el numero: %d\n", pos, elem);
                printf("hay un total de %d elementos en la lista\n", contar_elem_lista(&pl));

    printf("hago sacar_primero_lista  asi verifico que el de pos %d se fue correctamente\n", pos);
    while(!lista_vacia(&pl))
    {
        sacar_primero_lista(&pl, &elem, sizeof(elem));
        printf("%d ",elem);
    }


    puts("");
    ///////////////////////
    printf("\nponer_ultimo_lista (del 0 al 9),  mostrar_lista  y  contar_elem_lista:\n");
    for(int i=0; i<10; i++)
    {
        poner_ultimo_lista(&pl, &i, sizeof(i));
    }

    mostrar_lista(&pl);
    printf("hay un total de %d elementos en la lista\n", contar_elem_lista(&pl));

    printf("ingrese posicion que desea modificar: ");
    scanf("%d", &pos);
    printf("ingrese nuevo valor que desea ingresarle: ");
    scanf("%d", &elem);

    modificar_nodo(&pl, &elem, sizeof(elem), pos);

    printf("mostrar_lista:\n");
    mostrar_lista(&pl);
    printf("\nsacar_primero_lista:\n");
    while(!lista_vacia(&pl))
    {
        sacar_primero_lista(&pl, &elem, sizeof(elem));
        printf("%d ",elem);
    }

    puts("");
    ///////////////////////
    int vec[] = {2, 4, 8, 8, 1, 8, 3, 3, 3, 6, 5, 8, 7, 9, 5, 8, 9, 9};

//  int vec[] = {1,2,3,3,2,4,9,5,1,4,2,2,6,6,7,8,2,4,1,2,4,8};
//  int vec[] = {2,2,2,4,4,3,6,7,8,5,2,4,1,9};
//  int vec[] = {1,2,3,3};
//  int vec[] = {1,2,3,3,3};
//  int vec[] = {1,2,3,4};

    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_ultimo_lista(&pl, vec+i, sizeof(int));
    }
    mostrar_lista(&pl);


    printf("que elemento desea cambiar?: ");
    scanf("%d", &elem);
    int nuevo;
    printf("nuevo dato que quiere ponerle: ");
    scanf("%d", &nuevo);

    printf("--\nmodificar el primero encontrado--\n");
    modificar_elem_unidad(&pl, &elem, sizeof(elem), &nuevo, sizeof(nuevo), cmp_enteros);
    puts("");
    mostrar_lista(&pl);


    printf("que elemento desea cambiar?: ");
    scanf("%d", &elem);

    printf("nuevo dato que quiere ponerle: ");
    scanf("%d", &nuevo);

    printf("--\nmodificar todos los elementos encontrados igual al ingresado--\n");
    modificar_elem_todos(&pl, &elem, sizeof(elem), &nuevo, sizeof(nuevo), cmp_enteros);
    puts("");
    mostrar_lista(&pl);

    printf("que elemento desea sacar?: ");
    scanf("%d", &elem);

    printf("--\neliminar elemento (el primero encontrado)--\n");
    eliminar_elem_unidad(&pl, &elem, sizeof(elem), cmp_enteros);

    mostrar_lista(&pl);

    printf("que elemento desea sacar?: ");
    scanf("%d", &elem);

    printf("--\neliminar todos los elementos iguales al ingresado--\n");
    eliminar_elem_todos(&pl, &elem, sizeof(elem), cmp_enteros);

    mostrar_lista(&pl);

    printf("--\neliminar elementos pares\n--");
    eliminar_elem_pares(&pl);

    puts("");
    mostrar_lista(&pl);

    printf("--\neliminar duplicados\n--");
    eliminar_duplicados(&pl, cmp_enteros);

    puts("");
    mostrar_lista(&pl);

    system("pause");
    return 0;
}


int cmp_enteros(const void * a1, const void * a2)
{
    int* e1 = (int*) a1;
    int* e2 = (int*) a2;

    return *e1-*e2;
}

