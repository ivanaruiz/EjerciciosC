#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dni;
    char apyn [30];
}t_alumno;
void * ord_sel_vec(void * vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *));
void * buscar_menor_fin(void * vec, void * fin, size_t tam, int (*cmp)(const void *, const void *));
void intercambiar(void * e1, void * e2, size_t tam);
int cmp_alu_dni(const void * a1, const void * a2);
int cmp_alu_apyn(const void * a1, const void * a2);
int cmp_ent(const void * a1, const void * a2);
int main()
{
    int vec[]={14,12,5,4,1,3,6,8,15,2,7,9,13,10,11};
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
    ord_sel_vec(vec, ce, sizeof(int), cmp_ent);
    for(i=0; i<ce;i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
    ord_sel_vec(avec, ce, sizeof(t_alumno), cmp_alu_dni);
    for(i=0; i<ce;i++)
    {
        printf("%d, %s \n", avec[i].dni, avec[i].apyn);
    }
    printf("\n\n");
    ord_sel_vec(avec, ce, sizeof(t_alumno), cmp_alu_apyn);
    for(i=0; i<ce;i++)
    {
        printf("%d, %s \n", avec[i].dni, avec[i].apyn);
    }
    system("pause");
    return 0;
}
/**
    Metodo Seleccion
    Para cada posicion del vector
    1. Seleccionar el menor
    2. Intercambiarel menor con el actual
    3. Avanzar
*/
void * ord_sel_vec(void * vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *))
{
    void * ini = vec,
         * fin = vec + (ce - 1) * tam ,
         * men;
    while (vec < fin)
    {
        men = buscar_menor_fin(vec, fin, tam, cmp);
        if(vec!=men)
            intercambiar(vec, men, tam);
        vec+=tam;
    }
    return ini;
}
void intercambiar(void * e1, void * e2, size_t tam)
{
    char aux[1000];
    memcpy(aux, e1, tam);
    memcpy(e1, e2, tam);
    memcpy(e2, aux, tam);
}
void * buscar_menor_fin(void * vec, void * fin, size_t tam, int (*cmp)(const void *, const void *))
{
    void * men = vec;
    vec+=tam;
    while(vec<=fin)
    {
        if(cmp(vec, men)<0)
            men = vec;
        vec+=tam;
    }
    return men;
}

int cmp_alu_dni(const void * a1, const void * a2)
{
    const t_alumno *alu1 = (const t_alumno *)a1,
                   *alu2 = (const t_alumno *)a2;
    return alu1->dni - alu2->dni;
}
int cmp_alu_apyn(const void * a1, const void * a2)
{
    const t_alumno *alu1 = (const t_alumno *)a1,
                   *alu2 = (const t_alumno *)a2;
    return strcmpi(alu1->apyn, alu2->apyn);
}
int cmp_ent(const void * a1, const void * a2)
{
    const int * e1 = (const int *)a1;
    return *e1-*(const int*)a2;
}
