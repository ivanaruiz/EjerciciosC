#include "pila_estatica.h"

void crear_pila(t_pila *p)
{
    p->tope = TAM_PILA ;
}



int pila_vacia(const t_pila *p)
{
    return p->tope == TAM_PILA;
}


//el tope es la cantidad de bytes que hay hasta el primer dato ocupado!!!
//tam_dato es el tamaño del dato que yo quiero ingresar en la pila
//por eso es que si es tope es menor a esa cantidad que quiero ingresar, es porque estaria con el "vector" lleno!
//estaria en la primera posicion
int pila_llena(const t_pila *p, unsigned tam_dato)
{
    return p->tope < tam_dato + sizeof(unsigned);
}

//recordar que se va llenando desde el ultimo del "vector" hacia el inicio
//o sea desde el fondo de la pila hacia el inicio de la misma
int poner_en_pila(t_pila *p, const void *d, unsigned tam_dato)
{
    if (p->tope <tam_dato + sizeof(unsigned))
    {
        printf("pila llena!\n");
        return 0;
    }

    //retrocedo el tamaño del dato
    //ej si mi dato pesa 30 bytes, me muevo 30 bytes para atras
    p->tope -= tam_dato;
    //ahora copio en el lugar donde retrocedi
    //guardo el dato
    memcpy(p->pila + p->tope, d, tam_dato);
    //p->pila está siempre apuntando al principio
    //ojo que p->tope no es un puntero, es como un offset, me dice cuánto me tengo que mover
    //p->tope me dice cuánto me tengo que mover desde el principio de la pila

    //retrocedo de nuevo
    //ahora para guardar el tamaño del dato necesito el tamaño de un entero sin signo
    //con esto me muevo 4 bytes para atras, porque 4 bytes es el tamaño de un unsigned. aca siempre reservo esa cant.
    p->tope -= sizeof(unsigned);    //el tamaño del dato es un entero sin signo(sizeof(unsigned))
    //ahora guardo el tamaño del dato
    //copio los 4 bytes del tamaño del dato en p->pila+p->tope, o sea en el ej copiaria en la pila el numero 30
    memcpy(p->pila + p->tope, &tam_dato, sizeof(unsigned));
    //en &tam_dato le estoy pasando la direccion de inicio de los bytes que queres copiar
    return 1;
}
//otro ejemplo de poner en pila. yo tengo que poner el dato ABCDEFGH , que son 8 char, entonces son 8 bytes
//en mi pila , entonces ocupare 8 bytes (8 cuadradaditos) para meter ABCDEFGH. y antes de eso (porque retrocede)
//necesito unos 4 bytes para el sizeof(unsigned) para guardar el 8. Mi pila se veria algo asi:
// |0|1|2|3|4|5|6|7|8|9|10|11|  PILA VACIA DE 12 BYTES
// |   8   |    ABCEDFGH     |  PILA LLENA CON 8 OCUPANDO 4 BYTES Y LOS CHAR OCUPANDO 8 BYTES
//  ESTE 8 DE LOS PRIMEROS CUATRO BYTES AVISA QUE EL SIGUIENTE ELEMENTO OCUPARA 8 BYTES!



int sacar_de_pila(t_pila *p, void *d, unsigned tam_dato)
{
    unsigned tam_aux;

    if(p->tope == TAM_PILA)
    {
        printf("la pila esta vacia!\n");
        return 0;
    }

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);

    memcpy(d, p->pila + p->tope, minimo(tam_dato, tam_aux));
    p->tope += tam_aux;

    return 1;
}
//explico por qué usamos un tam_aux en sacar_de_pila: (y en ver_tope tambien)
/*Supongamos que estamos trabajando una estructura de 10 bytes.
Entonces vamos apilando. Pero qué pasa si el usuario por error quiere ingresar
una estructura de 15 bytes a la misma pila? Acá habría un error.
Por eso usamos el tam_aux. Pasaría lo siguiente:
El usuario mandaría por parámetro los cantBytes, que serían 15 (lo que manda x error).
Pero en nuestra pila lo que tenemos realmente son 10. Es decir:
| | | | | | | | | | | | | | |
|  10   | registro de struct|   //recordar que esos  primeros 4 bytes nos dicen el tam del dato

cuando en la primitiva hacemos:
memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));
nos queda tam_aux = 10 , lo cual es lo que tenemos en la pila
luego hacemos:
memcpy(d, p->pila + p->tope, minimo(tam_dato, tam_aux));
y en minimo entonces tenemos(15, 10)
es decir los 15 es lo que pasó el usuario por error, y los 10 es lo que realmente tenemos.
cual es el minimo? 10. entonces la macro nos devuelve 10.
por tanto habría un error en nuestro main y no se devolvería correctamente el dato.
ahí saltaría el error.
si el usuario hubiera mandado correctamente un struct de 10, no saltaría el error
y el resultado sería satisfactorio.
Por eso usamos el tam_aux. Para que siempre haya coincidencia entre lo que tenemos en la pila
y lo que nos solicita el usuario.
*/




int ver_tope(const t_pila *p, void *d, unsigned tam_dato)
{
    unsigned tam_aux;

    if(p->tope==TAM_PILA)
    {
        printf("pila vacia!\n");
        return 0;
    }

    memcpy(&tam_aux, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->tope + p->pila + sizeof(unsigned), minimo(tam_dato, tam_aux));

    return 1;
}


void vaciar_pila(t_pila *p)
{
    p->tope = TAM_PILA;
}
