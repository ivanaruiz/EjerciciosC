/*Crearemos un vector desordenado y luego lo ordenamos con el metodo de burbujeo.
El cual consiste en tomar de a dos elementos y compararlos.
De ser el primero el menor, se queda tal cual esta. Caso contrario se invierten.
Y luego avanzo una posicion y sigo comparando de a pares.
En la primera pasada, quedara el mayor ordenado en la ultima posicion,
por lo que se vuelva a empezar desde el inicio. Por lo tanto se hacen reiteradas pasadas.
Ejemplo: 4 8 2 1 5
Primera pasada: 4 2 1 5 8. Segunda: 2 1 4 5 8. Tercera: 1 2 4 5 8.
Por otro lado usaremos una funcion del tipo generica,
porque lo que dicha funcion no solo resuelve un vector de enteros,
como en el ejemplo, sino que puede resolver de cualquier tipo.
Ej char. Tambien lo probaremos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERDADERO   1
#define FALSO   0

typedef struct
{
int cod;
char prod[10];
float precio;
}t_producto;


void* ordenar(void *vec, size_t ce, size_t tam, int (*cmp)(const void* vec, size_t tam));
void intercambio(void *vec, size_t tam);
int cmp_ent(const void *vec, size_t tam);
int cmp_char(const void *vec, size_t tam);
int cmp_float(const void *vec, size_t tam);
int cmp_float_st(const void *vec, size_t tam);
int cmp_ent_st(const void *vec, size_t tam);
int cmp_char_st(const void *vec, size_t tam);

int main()
{
    int vec[] = {4,8,10,2,11,9,13,6,3,1,12,5,7,15,14};
    int ce= sizeof(vec)/sizeof(int);

    printf("Ordeno vector de enteros:\n");
    ordenar(vec, ce, sizeof(int), cmp_ent);

    int i;
    for(i=0; i<ce; i++)
    {
        printf("%d ", vec[i]);
    }

    ///////////////////////////////////////////

    //hacemos otro vector pero de tipo char, y probamos la funcion generica
    char vecchar[] = {'c', 'f', 'g', 'b', 'e', 'i', 'd', 'h', 'a'};
    ce= sizeof(vecchar) /sizeof(char);

    ordenar(vecchar, ce, sizeof(char), cmp_char);

    printf("\nOrdeno vector de char:\n");
    for(int i=0; i<ce; i++)
    {
        printf("%c ", vecchar[i]);
    }


    ///////////////////////////////////////////


    t_producto vec_prod[] = {
                            {3, "leche", 60},
                            {5, "harina", 40},
                            {1, "polenta", 30},
                            {2, "arvejas", 35},
                            {4, "arroz", 40},
                            };

    ce= sizeof(vec_prod)/sizeof(t_producto);

    ordenar(vec_prod, ce, sizeof(t_producto), cmp_ent_st);

    printf("\nOrdeno estructura por codigo: \n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-9s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }


    ///////////////////////////////////////////

    ordenar(vec_prod, ce, sizeof(t_producto), cmp_char_st);

    printf("Ordeno estructura por nombre: \n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-9s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }

    ///////////////////////////////////////////

    ordenar(vec_prod, ce, sizeof(t_producto), cmp_float_st);

    printf("Ordeno estructura por precio:\n");
    for(int i=0; i<ce; i++)
    {
        printf("%d %-9s %5.2f\n", vec_prod[i].cod, vec_prod[i].prod, vec_prod[i].precio);
    }


    system("pause");
    return 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/*Explicacion de la bandera hubocambios: primero lo seteo en VERDADERO. porque suponemos que va a haber cambios,
y ademas porque para entrar al while (y continuar en los siguientes ciclos necesitamos que haya habido cambios en
cada iteracion, de no haberlas no es necesario seguir con el proceso y deberia cortarse) necesitamos que este en
VERDADERO. es decir que haya habido intercambios. al entrar al primer while ya lo seteamos en cero, o sea FALSO.
porque realmente todavia no evaluamos si hubo o no cambios. entramos al segundo ciclo y vemos si en la primera iteracion
hubo o no intercambios. en caso de haber, entonces cambia nuestra variable, la cual nos permitira seguir con otro ciclo
mas y asi sucesivamente. en caso de que algun momento no haya mas intercambios, es porque el vector se ordenó
completamente entonces cortamos ciclo.
*/


void * ordenar(void *vec, size_t ce, size_t tam, int (*cmp) (const void* vec, size_t tam))
{
    void *ini=vec;
    void *fin= vec+(ce-1)*tam;
    int hubocambios= VERDADERO;

    while(ini<fin && hubocambios== VERDADERO)
    {
        hubocambios=FALSO;

        while(vec<fin)
        {
            //también podría haber hecho if(cmp(vec, vec+tam)>0)
            if(cmp(vec, tam) >0 )
                    {
                    intercambio(vec, tam);
                    hubocambios= VERDADERO;
                    }
            vec+=tam;
        }
        //ante una pasada, vec quedó adelantado, asi que vuelvo a poner al inicio para la siguiente pasada
        vec=ini;
        //retrocedo con fin ya que en cada iteracion queda la ultima posiicion ordenada con el numero mayor
        //asi que la busqueda se achica en cada iteracion
        fin-=tam;

    }
    return ini;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

void intercambio(void *vec, size_t tam)
{
    //reservo memoria dinamica con malloc. creo una variable de tipo puntero a void.
    void *aux= malloc(tam);
    memcpy(aux, vec, tam);
    memcpy(vec, (vec+tam), tam);
    memcpy((vec+tam), aux, tam);
    //si o si debo liberar la memoria dinamica que utilicé
    free(aux);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_ent(const void *vec, size_t tam)
{
    const int *a1= (const int*) vec;
    const int *a2= (const int*) (vec+tam);
    return *a1 - *a2;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_ent_st(const void *vec, size_t tam)
{
    const t_producto *a1= (const t_producto*) vec;
    const t_producto *a2= (const t_producto*) (vec+tam);
    return a1->cod - a2->cod;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


int cmp_char(const void *vec, size_t tam)
{
    const char *a1 = (const char*) vec;
    const char *a2 = (const char*) (vec+tam);

    return strcmp(a1, a2);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_char_st(const void *vec, size_t tam)
{
    const t_producto *a1 = (const t_producto*) vec;
    const t_producto *a2 = (const t_producto*) (vec+tam);

    return strcmp(a1->prod, a2->prod);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_float(const void *vec, size_t tam)
{
    const float *a1 = (const float*) vec;
    const float *a2 = (const float*) (vec+tam);

    return *a1-*a2;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

int cmp_float_st(const void *vec, size_t tam)
{
    const t_producto *a1 = (const t_producto*) vec;
    const t_producto *a2 = (const t_producto*) (vec+tam);

    return a1->precio - a2->precio;
}
