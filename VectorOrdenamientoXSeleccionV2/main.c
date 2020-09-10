#include <stdio.h>
#include <stdlib.h>


//esta funcion devuelve un puntero al inicio del vector
int *ord_vec_x_sel(int *vec, int ce);
//devuelve un puntero a entero tambien
int *buscar_menor(int *vec, int *fin);
void intercambio(int *vec, int *men);



int main()
{

    printf("Vector desordenado: \n");

    int vec[]= {3,7,9,1,2,6,8,12,16,4,20,5,10};
    int ce= sizeof(vec) / sizeof(int);
    //sizeof(vec) me da la cantidad de bytes del vector (en este caso hace 4*13=52)
    //sizeof(int) me dara 4. ya que un entero tiene 4 bytes. entonces ce=52/4 = 13 elementos del vector

    int i;
    for(i=0; i<ce; i++)
        printf("%d  ", vec[i]);

    ord_vec_x_sel(vec, ce);

    printf("\nVector ordenado: \n");


    for(i=0; i<ce; i++)
        printf("%d  ", vec[i]);

    printf("\n");

    system("pause");
    return 0;
}


int * ord_vec_x_sel(int *vec, int ce)
{

    int * ini = vec;
    int * fin = vec+ce-1;
    int * men;

    //vec es el que se ira moviendo buscando el menor
    //no hace falta recorrer hasta vec<=fin porque por descarte en la ultima vuelta, el mayor quedara en la ultima posicion
    //ya que el vector se fue ordenando

    while(vec < fin)
    {
        men = buscar_menor(vec, fin);

        //validamos para que las posiciones que intercambiamos no sean las mismas
        if(vec!=men)
            intercambio(vec, men);

        vec++;
        //notar que menor no incrementa porque a él mismo se le asigna una funcion que devuelve un puntero a entero
        //es decir va cambiando por sí mismo
    }

    return ini; //una vez todo ordenado, devuelve el puntero a inicio del vector
}

void intercambio(int *vec, int *men)
{
    int aux = *vec;
    *vec = *men;
    *men = aux;
}

int *buscar_menor(int *vec, int *fin)
{
    int *men = vec;

    //nos movemos una posicion hacia adelante para no comparar una vez de mas
    vec++;

    //cuando encuentre uno menor que vec, men apuntara a esa nueva posicion
    while(vec<=fin)
    {
        if(*vec < *men)
            men = vec;
        vec++;
    }

    return men;
}


//Metodo de ordenamiento por seleccion:
//Para cada posicion del vector
//1.Seleccionar el menor
//2.Intercambiar el menor con el actual
//3.Avanzar
