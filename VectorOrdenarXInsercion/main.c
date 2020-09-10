/*Metodo de insercion: se basa en imaginarnos que existe una parte del vector que ya está
ordenado (subvector), y se van insertando en orden los elementos restantes, hasta que todos
los elementos hayan quedado en el subvector. Es decir, la primera posicion ya esta ordenada
(tomaremos esa parte como subvector ordenado). Luego se toma la siguiente posicion y se lo
"lleva al subvector" y se lo acomoda. Y asi sucesivamente. Ejemplo:
Vector desordenado: 4 2 5 1 3. Pensamos que el 4 ya esta ordenado. Asi que tomamos al 2 y
evaluamos. Como es menor hay cambio.
Primer cambio: 2 4 5 1 3. Por lo tanto el vector subordenado es 2 4. Ahora tomamos el 5.
Queda igual en este caso ya que no es menor. Tomamos el siguiente, el 1.
Segundo cambio: 1 2 4 5 3. El vector subordenado queda conformado por 1 2 4 5. Tomamos el 3.
Tercer cambio: 1 2 3 4 5*/

#include <stdio.h>
#include <stdlib.h>

int * ordenar(int * vec, int ce);
void insertar_en_subvec_ord(int *vec, int *iniOrd, int *finOrd);
void mostrar(int * vec, int ce);
void intercambio(int *vec, int * iniOrd);

int main()
{
    int vec[]= {34,13,8,21,1,2,5,3};
        int ce= sizeof(vec)/sizeof(int);

    printf("Vector desordenado:\n");
    mostrar(vec,ce);

    ordenar(vec,ce);

    printf("Vector ordenado:\n");
    mostrar(vec,ce);


    system("pause");
    return 0;
}

///////////////////////////////////////////////
///////////////////////////////////////////////


int * ordenar(int * vec, int ce)
{
    int * inicial= vec;
    int * fin= vec+ce-1;
    //estos dos punteros son los que manejaran el subvector ordenado
    int * iniOrd= vec;
    int * finOrd= vec;

    //adelanto el vector un puesto ya que sería en vano que empiece desde el primer puesto
    vec++;

    //vec es el que recorre todo, y va tomando cada posicion para compararla con el vector subordenado
    while(vec<=fin)
    {
        insertar_en_subvec_ord(vec, iniOrd, finOrd);

        iniOrd= inicial;
        finOrd++;

        vec++;
    }
    return inicial;
}

///////////////////////////////////////////////
///////////////////////////////////////////////


void insertar_en_subvec_ord(int *vec, int *iniOrd, int *finOrd)
{
    while(iniOrd <= finOrd)
    {
        if(*vec < *iniOrd)
            intercambio(vec, iniOrd);


        iniOrd++;
    }
}

///////////////////////////////////////////////
///////////////////////////////////////////////

void mostrar(int * vec, int ce)
{
    int i;
    for(i=0; i<ce; i++)

        printf("%d ", vec[i]);

    puts("");
}

///////////////////////////////////////////////
///////////////////////////////////////////////

void intercambio(int *vec, int * iniOrd)
{
    int aux=*vec;
    *vec= *iniOrd;
    *iniOrd= aux;
}
