#include "lista_doble.h"

int cmp_enteros(const void * a1, const void * a2);
void mostrar_movimiento(void * d);
//ACLARACIÓN IMPORTANTE
//DENTRO DE CADA FUNCION, ES MENESTER AL FINAL HACER QUE PL INDIQUE A ALGÚN LUGAR VÁLIDO
//NO PUEDE QUEDAR APUNTANDO A NULL
//POR LO GENERAL DEJAMOS QUE APUNTE AL ÚLTIMO LUGAR DONDE OPERÓ

//ACLARACIÓN IMPORTANTE:
//LA NOTABLE DIFERENCIA ENTRE LISTA SIMPLEMENTE ENLAZADA Y LISTA DOBLEMENTE ENLAZADA ES QUE LA PRIMERA,
//AL INGRESAR A CUALQUIER FUNCIÓN (PRIMITIVA) PL SIEMPRE APUNTA AL PRIMERO DE LA LISTA.
//EN CAMBIO EN LAS LISTAS DOBLES PUEDE ESTAR APUNTANDO A CUALQUIER LADO DE LA LISTA.
//LO CORRECTO ES SABER CÓMO MANEJARSE DE IZQUIERDA A DERECHA, Y VICEVERSA, EN UNA LISTA DOBLE.

int main()
{
    tLista pl;
    crear_lista(&pl);
    int elem;
    int vec[] = {3,3,5,1,8,6,2,8,9,7,1,9,2,9,9,4};


    printf("--poner ordenado en lista (sin duplicados)--\n");
    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_orden_lista(&pl, &vec[i], sizeof(int), cmp_enteros);
    }

    printf("--ver lista--\n");
    int cant_reg =  mostrar_lista(&pl);
    puts("");

    printf("\nHay %d elementos en la lista\n", cant_reg);

    int elemento_nuevo = 10;
    insertarAlFinal(&pl, &elemento_nuevo, sizeof(int));
    printf("\nINSERTO AL FINAL UN %d\n", elemento_nuevo);
    mostrar_lista(&pl);

    elemento_nuevo = 0;
    insertarAlComienzo(&pl, &elemento_nuevo, sizeof(int));
    printf("\nINSERTO AL COMIENZO UN %d\n", elemento_nuevo);
    mostrar_lista(&pl);

    puts("");
//    cant_reg = mostrarDeIzqADer(&pl, mostrar_movimiento);
//    printf("\n%d\n", cant_reg);

    elem = 5;
    eliminarPorClave(&pl, &elem, sizeof(int), cmp_enteros);
    puts("");
//    cant_reg = mostrarDeIzqADer(&pl, mostrar_movimiento);
//    printf("\n%d\n", cant_reg);



    if(ver_primer_elem_lista(&pl, &elem, sizeof(int)))
        printf("\nPrimer elemento de la lista: %d \n", elem);

    if(ver_ultimo_elem_lista(&pl, &elem, sizeof(int)))
        printf("\nUltimo elemento de la lista: %d \n", elem);


    printf("\n--Sacar un elemento de lista ord--\n");
    printf("Que elemento desea sacar? : ");
    scanf("%d", &elem);

    if(!sacar_elem_ord(&pl, &elem, sizeof(int), cmp_enteros))
        printf("\nno se encontro el elemento en la lista\n");



    printf("\n--sacamos de lista ordenada--\n");
    while(!lista_vacia(&pl))
    {
        sacar_orden_lista(&pl, &elem, sizeof(elem));
        printf("%d ", elem);
    }

    puts("\n\n--Ahora insertamos en orden con duplicados--");

    for(int i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        insertarAlComienzo(&pl, &vec[i], sizeof(int));
        //poner_orden_lista_duplicados(&pl, &vec[i], sizeof(int), cmp_enteros);
    }


    printf("--ver lista--\n");
    cant_reg = mostrar_lista(&pl);
    puts("");

    printf("hay %d elementos en la lista\n", cant_reg);


    printf("\n--Eliminar duplicados--");
    eliminar_duplicados(&pl, cmp_enteros);

    printf("\n--sacamos de lista ordenada--\n");
    while(!lista_vacia(&pl))
    {
        sacar_orden_lista(&pl, &elem, sizeof(elem));
        printf("%d ", elem);
    }




    puts("");
    mostrar_lista(&pl);

    printf("\n\n--Ponemos en lista ordenada del 1 al 7--\n");
    int vec2[] = {1,5,7,4,3,6,2};
    for(int i=0; i<sizeof(vec2)/sizeof(int); i++)
    {
        poner_orden_lista(&pl, &vec2[i], sizeof(int), cmp_enteros);
    }

    printf("\n--ver lista--\n");
    mostrar_lista(&pl);
    puts("");


    printf("\n--Sacar un elemento de lista ord--\n");
    printf("Que elemento desea sacar? : ");
    scanf("%d", &elem);

    if(!sacar_elem_ord(&pl, &elem, sizeof(int), cmp_enteros))
        printf("\nno se encontro el elemento en la lista\n");

    printf("\n--ver lista--\n");
    mostrar_lista(&pl);
    puts("");


    printf("\n--vaciamos lista--\n");
    cant_reg = vaciar_lista(&pl);
    printf("\nVaciamos %d elementos\n", cant_reg);



    puts("");

    mostrar_lista(&pl);


    system("pause");
    return 0;
}


int cmp_enteros(const void * a1, const void * a2)
{
    int * e1 = (int*) a1;
    int * e2 = (int*) a2;
    return *e1 - *e2;
}

