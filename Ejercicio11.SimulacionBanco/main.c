#include "cola_dinamica.h"
#include "banco.h"


int main()
{
    t_cliente vec[] =  /* {{1,5,1,0,0}, //primer juego de lotes para probar
                        {2,5,1,0,0},
                        {3,5,1,0,0},
                        {4,3,1,0,0},
                        {5,5,1,0,0},  } ; */


                     {{1,5,1,0,0}, //segundo juego de lotes para probar, también funciona
                        {2,3,5,0,0},
                        {3,3,1,0,0},
                        {4,5,1,0,0},
                        {5,1,5,0,0},
                        {6,3,9,0,0},
                        {7,5,1,0,0},
                        {8,3,5,0,0},
                        };

    int ce= sizeof(vec)/sizeof(t_cliente);
    t_cola pc;
    crear_cola(&pc);

    int acum=0; //con este acumulador me ayudo para calcular el 'llega' de cada cliente
    int ocupado_hasta=0;    //hasta qué minuto está ocupada la caja, es decir los clientes que vayan llegando deben esperar

    //con este for recorro primero cada cliente para determinar cuándo llega (en qué min) y hasta cuándo está(en qué min)
    for(int i=0; i< ce; i++)
    {
        acum+= vec[i].arribo;
        vec[i].llega+= acum;    //ya determiné en qué min llega

        if(vec[i].llega>= ocupado_hasta)    //si es mayor o igual es porque no se suponerpone con otros clientes
            {
            ocupado_hasta= vec[i].llega+ vec[i].demora;
            vec[i].hasta= vec[i].llega + vec[i].demora;
            }
        else    //si viene por aca, es porque se superpone con otro/s cliente/s anterior/es, es decir que debe esperar
        {
            ocupado_hasta+= vec[i].demora;
            vec[i].hasta= ocupado_hasta;
        }
    }


    t_cliente elem;
    //este for recorre los minutos, y en cada minuto busco qué cliente llega y se pone en cola, y cuál sale
    for(int i=0; i<= ocupado_hasta ; i++)   //el ocupado_hasta me dira en qué min se va de cola el ultimo cliente
    {
        printf("Minuto %d: \n", i);

            if(i==0)
                printf("Se abre el cajero del banco.\n");
            else
            {
                if(ver_frente_de_cola(&pc, &elem, sizeof(t_cliente)))
                    printf("En este momento se esta atendiendo al ciente %d.\n", elem.nro_cliente);
                else
                    printf("Nadie en la cola.\n");
            }

        buscar_quien_entra(vec, ce, &pc, i);

        buscar_quien_sale(vec,ce, &pc, i);
    }
    printf("Se cierra el cajero del banco.\n\n");

    system("pause");
    return 0;
}


////////////////////////////////////////////
////////////////////////////////////////////


void buscar_quien_entra(t_cliente * vec, int ce, t_cola * pc, int min)
{
    //recorro cada cliente, y veo si el cliente coincide su min de llega con el min en el que nos encontramos
    int j=0;
    while(j<ce)
    {
        if(vec->llega==min)
        {
            printf("Entra en cola el cliente %d\n", vec->nro_cliente);
            poner_en_cola(pc, vec, sizeof(t_cliente));
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
