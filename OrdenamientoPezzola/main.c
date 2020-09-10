#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dni;
    char apyn [30];
}t_alumno;


int * ord_sel_vec_ent(int * vec, int ce);
int * buscar_menor_ent_fin(int * vec, int* fin);
void intercambiar_ent(int * e1, int * e2);
t_alumno * ord_sel_vec_alu(t_alumno * vec, int ce, int (*cmp)(const t_alumno *, const t_alumno *));
t_alumno * buscar_menor_alu_fin(t_alumno * vec, t_alumno* fin, int (*cmp)(const t_alumno *, const t_alumno *));
void intercambiar_alu(t_alumno * e1, t_alumno * e2);
int cmp_alu_dni(const t_alumno * a1, const t_alumno * a2);
int cmp_alu_apyn(const t_alumno * a1, const t_alumno * a2);
int main()
{
    int vec[]={14,12,5,4,1,3,6,8,15,2,7,9,13,10,11};
    float fvec[]={12.4,12.2,5,4,1,3,6,8,15,2,7,9,12.3,10,11};
    t_alumno avec[]={
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
    int ce = sizeof(vec)/sizeof(int);
    int i;
    ord_sel_vec_ent(vec, ce);
    for(i=0; i<ce;i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
    ord_sel_vec_alu(avec, ce, cmp_alu_dni);
    for(i=0; i<ce;i++)
    {
        printf("%d, %s ", avec[i].dni, avec[i].apyn);
    }
    printf("\n\n");
    ord_sel_vec_alu(avec, ce, cmp_alu_apyn);
    for(i=0; i<ce;i++)
    {
        printf("%d, %s ", avec[i].dni, avec[i].apyn);
    }
    return 0;
}
/**
    Metodo Seleccion
    Para cada posicion del vector
    1. Seleccionar el menor
    2. Intercambiarel menor con el actual
    3. Avanzar
*/
int * ord_sel_vec_ent(int * vec, int ce)
{
    int * ini = vec,
        * fin = vec + ce -1,
        * men;
    while (vec < fin)
    {
        men = buscar_menor_ent_fin(vec, fin);
        if(vec!=men)
            intercambiar_ent(vec, men);
        vec++;
    }
    return ini;
}
void intercambiar_ent(int * e1, int * e2)
{
    int aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}
int * buscar_menor_ent_fin(int * vec, int* fin)
{
    int * men = vec;
    vec++;
    while(vec<=fin)
    {
        if(*vec<*men)
            men = vec;
        vec++;
    }
    return men;
}

t_alumno * ord_sel_vec_alu(t_alumno * vec, int ce, int (*cmp)(const t_alumno *, const t_alumno *))
{
    t_alumno * ini = vec,
             * fin = vec + ce -1,
             * men;
    while (vec < fin)
    {
        men = buscar_menor_alu_fin(vec, fin, cmp);
        if(vec!=men)
            intercambiar_alu(vec, men);
        vec++;
    }
    return ini;
}
void intercambiar_alu(t_alumno * e1, t_alumno * e2)
{
    t_alumno aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}
t_alumno * buscar_menor_alu_fin(t_alumno * vec, t_alumno* fin, int (*cmp)(const t_alumno *, const t_alumno *))
{
    t_alumno * men = vec;
    vec++;
    while(vec<=fin)
    {
        if(cmp(vec, men)<0)
            men = vec;
        vec++;
    }
    return men;
}

int cmp_alu_dni(const t_alumno * a1, const t_alumno * a2)
{
    return a1->dni - a2->dni;
}
int cmp_alu_apyn(const t_alumno * a1, const t_alumno * a2)
{
    return strcmpi(a1->apyn, a2->apyn);
}
/**
    e1 e2
    e1<e2 ===> negativo
    e1=e2 ===> 0
    e1>e2 ===> positivo
*/
