/*Creamos un primer vector entero desordenado. Y haremos funcion generica para ordenar el vector mediante el metodo
de seleccion. Es decir usaremos punteros de tipo void, que no estan definidos qué tipo de datos son.
Luego crearemos otro vector pero de char, y veremos que podemos reutilizar las mismas funciones de ordenamiento
ya que son genericas y nos permiten manipular datos de cualquier tipo.
Lo unico que cambian son las funciones de comparacion, que habra dos, una de enteros, y otra de char.
Estas funciones son las que se pasan como parametros dentro de las funciones principales.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * ordenar_vec_x_sel(void *vec, int ce, size_t tam, int (*cmp)(const void * , const void*));
void * buscar_menor(void *vec, void *fin, size_t tam, int (*cmp)(const void*, const void*));
void intercambio(void *vec, void* men, size_t tam);
int cmp_ent(const void * vec, const void * men);
int cmp_char(const void * vec, const void * men);


int main()
{
    int vec[]={14,12,5,4,1,3,6,8,15,2,7,9,13,10,11};
    int ce= sizeof(vec) / sizeof(int);

    ordenar_vec_x_sel(vec, ce, sizeof(int), cmp_ent);

    int i;
    for(i=0; i<ce; i++)
        printf("%d ", vec[i]);


    printf("\n\n");

    char vecc[]={'b','d','f','a','c','g','e'};
    ce= sizeof(vecc)/sizeof(char);

    ordenar_vec_x_sel(vecc, ce, sizeof(char), cmp_char);

    for(i=0; i<ce; i++)
        printf("%c ", vecc[i]);


    system("pause");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//devuelvo un puntero a void, ya que es un dato genérico
void * ordenar_vec_x_sel(void * vec, int ce, size_t tam, int (*cmp)(const void *, const void *))
{
    void *ini= vec;
    void *fin= vec+(ce-1)*tam;
    void *men;

    while(vec<fin)
    {
        men= buscar_menor(vec, fin, tam, cmp);

        if(vec!=men)    //si fueran iguales, significa que no encontró uno menor a vec
            intercambio(vec, men, tam);
        vec+= tam;
    }

    return ini;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void * buscar_menor(void *vec, void *fin, size_t tam, int (*cmp)(const void* vec, const void* men))
{
    void * men= vec;

    while(vec<=fin)
    {
        if(cmp(vec, men) <0)
            men=vec;
        vec+=tam;
    }
    return men;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



int cmp_ent(const void * vec, const void * men)
{
    const int *a1 = (const int*)vec;
    const int *a2 = (const int*)men;

    return *a1- *a2;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


int cmp_char(const void * vec, const void * men)
{
    const char *a1 = (const char*)vec;
    const char *a2 = (const char*)men;

    return strcmp(a1,a2);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void intercambio(void *vec, void* men, size_t tam)
{
    void * aux = malloc(tam);   //pido memoria para un dato generico aux

    memcpy(aux, vec, tam);
    memcpy(vec, men,  tam);
    memcpy(men, aux, tam);

    free(aux);
}

/*
El programa ordena un vector de enteros por el metodo de seleccion (con datos genéricos).
El mismo hace una primera recorrida por todo el vector buscando el menor.
A ese menor lo conoca en la primera posicion del vector.
Luego se hara otro recorrido pero ya desde la segunda posicion del vector hasta el final,
buscando al siguiente menor. Y el mismo se colocara en esa segunda posicion.
Así sucesivamente.
*/

