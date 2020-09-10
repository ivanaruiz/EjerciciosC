#include "banco.h"

#include <time.h>


void generar_clientes(t_cliente * vec, int ce, int * ocupado_hasta_min)
{
srand(time(NULL));
int acum=0;


for(int i=0; i< ce; i++)
    {
        vec[i].nro_cliente= i+1;

        do
        {
        vec[i].demora= rand() % 5+1;
        }while(vec[i].demora== 2 || vec[i].demora== 4);


        do
        {
        vec[i].arribo= rand() % 9+1;
        }while(vec[i].arribo==2 || vec[i].arribo== 3 || vec[i].arribo== 4 || vec[i].arribo== 6 || vec[i].arribo== 7 || vec[i].arribo== 8 );

        vec[i].llega=0;
        vec[i].hasta=0;
        acum+= vec[i].arribo;
        vec[i].llega+= acum;    //ya determiné en qué min llega


        if(vec[i].llega>= *ocupado_hasta_min)    //si es mayor o igual es porque no se suponerpone con otros clientes
            {
            *ocupado_hasta_min= vec[i].llega+ vec[i].demora;
            vec[i].hasta= vec[i].llega + vec[i].demora;
            }
        else    //si viene por aca, es porque se superpone con otro/s cliente/s anterior/es, es decir que debe esperar
        {
            *ocupado_hasta_min+= vec[i].demora;
            vec[i].hasta= *ocupado_hasta_min;
        }
    }

}

////////////////////////////////////////////
////////////////////////////////////////////


void buscar_quien_entra(t_cliente * vec, int ce, t_cola * pc, int min, int * hubo_primer_movimiento, int *sigue_cola_vacia)
{
    //recorro cada cliente, y veo si el cliente coincide su min de llega con el min en el que nos encontramos
    int j=0;
    while(j<ce)
    {
        if(vec->llega==min)
        {
            printf("Entra en cola el cliente %d\n", vec->nro_cliente);
            poner_en_cola(pc, vec, sizeof(t_cliente));

            //notar que ambas banderas se setean al poner un nuevo cliente en cola
            *hubo_primer_movimiento=1;
            *sigue_cola_vacia=0;
        }
        j++;
        vec++;
    }
}

////////////////////////////////////////////
////////////////////////////////////////////


void buscar_quien_sale(t_cliente * vec, int ce, t_cola * pc, int min)
{
    //recorro cada cliente
    int j=0;
    t_cliente elem;
    while(j<ce)
    {
        if(vec->hasta == min)
        {
            sacar_de_cola(pc, &elem, sizeof(t_cliente));
            printf("Sale de cola el cliente %d\n", elem.nro_cliente);
        }
    j++;
    vec++;
    }
}

