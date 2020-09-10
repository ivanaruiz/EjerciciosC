
#include "cola_estatica.h"

//inicializamos los dos indicandores(ojo no son punteros)
//puede ser a cualquier lugar del vectors
void crear_cola(t_cola * pc)
{
    pc->pri = TAM_COLA - 70;    //aleatorio, mientras que esten dentro del vector
    pc->ult = TAM_COLA - 70;
    pc->tam_disponible =  TAM_COLA;
}

int poner_en_cola(t_cola *pc, const void * d, unsigned tam_dato)
{
    int ini, fin;   //ini seria la parte inicial del dato, en caso de que se parta mi dato

    //verifico si hay lugar disponible en la cola
    if( (tam_dato + sizeof(unsigned)) > pc->tam_disponible)
    {
        printf("cola llena!\n");
        return 0;
    }

    //primero ponemos el tamaño del dato, luego el dato
    //copio el tam del dato en el vector

    //primero me fijo si entra el unsigned
    if((ini= minimo(TAM_COLA-pc->ult, sizeof(unsigned)))>0)
       memcpy(pc->cola + pc-> ult, &tam_dato, ini);

    //si no entró todo el tamaño, entonces tengo que copiar lo que me resta de tam_dato
    if((fin = sizeof(unsigned) - ini) != 0)
        memcpy(pc->cola, ((char*)&tam_dato) + ini, fin);


    //muevo ese ultimo hacia la derecha
    pc->ult = fin!=0 ? fin : pc->ult + sizeof(unsigned);


    //y ahora copio el dato
    //tengo que ver si primero entra en el vector

    //aca copio la primera parte
    //si el dato entra entero, lo copio entero
    //sino se copia una parte
    if((ini= minimo(TAM_COLA - pc->ult , tam_dato))>0)
        memcpy(pc->cola + pc->ult, d, ini);

    //si no entró entero antes, entonces se activa este if
    //si el dato se copió entero en el if anterior, entonces este if no hace nada
    //y copia al inicio del vector lo que falte copiar
    if((fin= tam_dato - ini)!= 0 )
        memcpy(pc->cola, d+ini, fin); //copia al principio del vec
                                        //fin es la cant de bytes que me faltaba copiar

    //y aca me fijo si tuve que partir al medio al dato
    //para saber si lo reinicie o no lo reinicie al vector
    pc->ult = fin ? fin : pc->ult + tam_dato;
    //si es distinto de cero, es porque tuve que reiniciar el vector

    pc->tam_disponible -= (tam_dato+ sizeof(unsigned));

    return 1;
}


int sacar_de_cola(t_cola *pc, void * d, unsigned tam_dato)
{
    unsigned tam_aux;
    int ini, fin;

    if(pc->tam_disponible == TAM_COLA)
    {
        printf("cola vacia\n");
        return 0;
    }

    //primero saco el tamaño del dato
    if((ini = minimo(TAM_COLA - pc->pri, sizeof(unsigned)))!=0)
        memcpy(&tam_aux, pc->cola + pc->pri , ini);
    if((fin = sizeof(unsigned) - ini!=0))
       memcpy(( (char*)&tam_aux) + ini , pc->cola , fin );

    pc->pri = fin!=0 ? fin : pc->pri + sizeof(unsigned);



    //ahora saco el dato
    if((ini = minimo(TAM_COLA - pc->pri, tam_aux))!=0)
        memcpy(d, pc->cola + pc->pri, minimo(ini, tam_dato));
    if((fin = tam_aux - ini)!=0 && tam_dato - ini >0) //si es distinto de cero, es porque no copié toda la info, me falta copiar aun
        memcpy(d+ini, pc->cola , minimo(fin, tam_dato - ini));  //tam_dato - ini es el tamaño que tengo disponible en el dato, en la variable dato que me pasaron

    pc->pri = fin!=0 ? fin : pc->pri + tam_aux;

    pc->tam_disponible += (tam_aux+ sizeof(unsigned));

    return 1;
}


int cola_vacia(const t_cola * pc)
{
    return pc->tam_disponible == TAM_COLA;
}


int cola_llena(const t_cola * pc, unsigned tam_dato)
{
    //si el tamaño que me solicita el usuario es mas grande de lo que tengo disponible, cola llena
    return (tam_dato + sizeof(unsigned)) > pc->tam_disponible;
}

