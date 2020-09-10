#include "lista.h"


void crear_lista(t_lista * pl)
{
    *pl = NULL;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int cargar_lista(t_lista * pl)
{
    t_alumno vec[] =    {
                        {33333333, "Rodriguez, Pedro", "Programacion", "P1", 7},
                        {38888888, "Perez, Juan", "Matematica", "P2", 6},
                        {29999999, "Diaz, Bruno", "Historia", "P1", 5},
                        {26111111, "Coronel, Luis", "Programacion", "P2", 2},
                        {35555555, "De La Vega, Diego", "Matematica", "P2", 7},
                        {34444444, "Garcia, Demetrio", "Programacion", "P2", 9},
                        {35555555, "De La Vega, Diego", "Programacion", "P1", 8},
                        {27777777, "Benitez, Aurelio", "Historia", "P2", 4},
                        {39999999, "Pereira, Francisco", "Matematica", "P2", 2},
                        {30000000, "Nigma, Eduardo", "Matematica", "P1", 0},
                        {26111111, "Coronel, Luis", "Programacion", "P1", 6},
                        {35555555, "De La Vega, Diego", "Matematica", "P1", 8},
                        {36666666, "Saravia, Gustavo", "Historia", "P2", 10},
                        {34444444, "Garcia, Demetrio", "Programacion", "P1", 7},
                        {33333333, "Rodriguez, Pedro", "Programacion", "P2", 9},
                        {38888888, "Perez, Juan", "Matematica", "P1", 4},
                        {35555555, "De La Vega, Diego", "Programacion", "P2", 4},
                        {39999999, "Pereira, Francisco", "Matematica", "P2", 10},
                        {36666666, "Saravia, Gustavo", "Historia", "P1", 9},
                        {28777777, "Kent, Clark", "Programacion", "P2", 4},
                        {27777777, "Benitez, Aurelio", "Historia", "P1", 5},
                        {28777777, "Kent, Clark", "Programacion", "P1", 2},
                        {29999999, "Diaz, Bruno", "Historia", "P2", 5},
                        {30000000, "Nigma, Eduardo", "Matematica", "P1", 0},
                        {35555555, "De La Vega, Diego", "Lengua", "P1", 7},
                        {35555555, "De La Vega, Diego", "Lengua", "P2", 7},
                        };


    for(int i=0; i<sizeof(vec)/sizeof(t_alumno); i++)
    {
        poner_ultimo_lista(pl, &vec[i], sizeof(t_alumno));
    }

    return sizeof(vec)/sizeof(t_alumno);
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int lista_vacia(const t_lista *pl)
{
    return *pl==NULL;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


//vamos a tener que recorrer la lista hasta el ultimo elemento (nodo) para poder insertar allí
//es decir ponemos al final de la lista
int poner_ultimo_lista(t_lista * pl, const void * d, unsigned tam_dato)
{
    //creo el nodo
    t_nodo * nue = (t_nodo *) malloc (sizeof(t_nodo));

    if(!nue)
    {
        printf("lista llena\n");
        return 0;
    }

    //creo la memoria para la informacion y valido que esa memoria haya sido creada
    nue->info = malloc(tam_dato);

    if(!nue->info)
    {
        printf("lista llena\n");
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, tam_dato);
    nue->tam_info = tam_dato;
    nue->sig = NULL;

    while(*pl)  //recorro hasta que *p1==NULL, que sería hasta el último nodo que tenía antes
    {
        pl = &(*pl)->sig;
    }

    *pl = nue;

    return 1;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int mostrar_lista(t_lista * pl)
{
    if(!*pl)
        return 0;

    int cont_nodos= 0;

    while(*pl)
    {
        cont_nodos++;

        t_alumno * alu = (t_alumno *)((*pl)->info);

        printf("%d %-29s %-19s %-4s %d\n", alu->dni, alu->apyn, alu->materia, alu->codigo_nota, alu->nota);

        pl= &(*pl)->sig;
    }

    return cont_nodos;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int actualizar_lista(t_lista * pl, int (*cmp_dni)(const void *, const void *),
                                    int (*cmp_mat)(const void * a1, const void * a2))
{
    if(!*pl)
        return 0;

    int cont_nodos = 0;

    while(*pl)
    {
        cont_nodos++;

        buscar_repetido(pl, cmp_dni, cmp_mat);

        if(*pl)
            pl = &(*pl)->sig;
    }

    return cont_nodos;
}

//acá lo que hacemos es buscar el P2 de cada alumno
void buscar_repetido(t_lista * pl, int (*cmp_dni)(const void *, const void *),
                                    int (*cmp_mat)(const void * a1, const void * a2))
{
    //en aux apuntará al alumno con su P1
    t_nodo * aux = *pl;

    pl = &(*pl)->sig;

    while(*pl)
    {
        //si entra es porque encontramos a P2 del alumno y es la misma materias
        if(cmp_dni((*pl)->info, aux->info)==0 && cmp_mat((*pl)->info, aux->info) ==0)
        {
            actualizar_datos(aux->info, (*pl)->info);

            //eliminamos el nodo que contenía el P2
            t_nodo *elim = *pl;
            *pl = (*pl)->sig;

            free(elim->info);
            free(elim);
        }

        if(*pl)
            pl = &(*pl)->sig;
    }
}

//voy a modificar la nota (que la pisaré con el promedio) y el código de la materia(PR, AU, CU, RE).
//estos datos quedarán asentados en el registro que contiene el P1 del alumno
void actualizar_datos(void * d1, void * d2)
{
    t_alumno * alu_ori = (t_alumno *)d1;
    t_alumno * alu_rep = (t_alumno *)d2;

    if((alu_ori->nota<4 && alu_rep->nota>=4) || (alu_ori->nota>=4 && alu_rep->nota<4))
        alu_ori->nota= 3;
    else
        alu_ori->nota = (alu_ori->nota + alu_rep->nota +1)/2;

    if(alu_ori->nota==0)
        strcpy(alu_ori->codigo_nota, "AU");
    else if(alu_ori->nota >=7)
        strcpy(alu_ori->codigo_nota, "PR");
    else if(alu_ori->nota<4)
        strcpy(alu_ori->codigo_nota, "RE");
    else
        strcpy(alu_ori->codigo_nota, "CU");
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void ordenar_lista_burbujeo(t_lista * pl, int (*cmp_dni)(const void *, const void *), int ce)
{
    while(*pl && ce)
    {
    ordenar_de_a_pares(pl, cmp_dni, &ce);
    }
}


void ordenar_de_a_pares(t_lista * pl, int (*cmp_dni)(const void *, const void *), int * ce)
{
    while((*pl)->sig && *ce)
    {
        if(cmp_dni((*pl)->sig->info, (*pl)->info)<0)
        {
            t_lista * men = pl;     //el siguiente a pl es menor entonces debo hacer el intercambio
            men = &(*men)->sig;

            intercambio(pl, men);
        }

        if(*pl)
            pl = &(*pl)->sig;
    }

    (*ce)--;
}


void intercambio(t_lista * pl, t_lista * men)
{
    t_nodo * aux = *men;
    *men = (*men)->sig;

    aux->sig = *pl;
    *pl = aux;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

