//ESTE PROYECTO ANDA PERFECTO

#include "cola_dinamica.h"
#include "banco.h"

int main()
{
    t_cliente vec[10];  //elegimos un numero cualquiera de total de clientes permitidos

    int ce= sizeof(vec)/sizeof(t_cliente);
    t_cola pc;
    crear_cola(&pc);

    int ocupado_hasta_min=0;

    generar_clientes(vec, ce, &ocupado_hasta_min);

    int cont_colas_vacias=0;
    t_cliente elem; //esto lo uso para ver el frente de la cola, si es que hay algun elemento en cola

    //esta bandera la uso para el tema del contador de colas vacias
    //cuando apenas abro el cajero (min 0), capaz tarda en venir un primer cliente (puede tardar 1, 5 o 9 min)
    //por tanto en este primer periodo NO cuento cola vacia, lo contaré las posteriores veces
    int hubo_primer_movimiento=0;

    //esta bandera es cuando finalmente hubo clientes pero luego la cola vacía, entonces el contador aumenta
    //mientras siga vacía los siguientes minutos continuos, NO debe seguir aumentando el contador, sino la prox vez que se vacíe
    int sigue_cola_vacia=0;

    int i=0;
    //el while puede cerrar por alguno de estos motivos, o porque el contador de colas vacias llegó a 5
    //que es parte del enunciado,
    //o porque el minutero (i) llegó hasta el ocupado_hasta_min, es decir que se atendieron todos los clientes que creamos
    //i representa cada minuto
    while(cont_colas_vacias<5 && i<=ocupado_hasta_min)
    {
        printf("Minuto %d: \n", i);

            if(i==0)
                printf("Se abre el cajero del banco.\n");

            else
            {
                if(ver_frente_de_cola(&pc, &elem, sizeof(t_cliente)))
                    printf("En este momento se esta atendiendo al ciente %d.\n", elem.nro_cliente);
                else
                {
                    if(hubo_primer_movimiento==0)   //si viene por aca es porque aun NO entro el primer cliente a la cola
                        printf("Nadie en la cola aun.\n");
                    else
                    {
                        if(sigue_cola_vacia==0)
                        {
                        cont_colas_vacias++;
                        sigue_cola_vacia=1;
                        printf("Nadie en la cola. Contador de cola vacia numero: %d\n", cont_colas_vacias);
                        }
                        else
                            printf("Nadie en la cola.\n");

                        if(cont_colas_vacias==5)
                            break;
                    }
                }
            }

        buscar_quien_entra(vec, ce, &pc, i, &hubo_primer_movimiento, &sigue_cola_vacia);

        buscar_quien_sale(vec,ce, &pc, i);

        i++;
    }


    printf("\nSe cierra el cajero del banco a los %d minutos.\n", i);

    //Motivo por el cual salimos del while, es decir el motivo por el cual cerró el cajero y terminamos el proceso
    cont_colas_vacias==5 ? printf("Cerrado debido a que la cola quedo vacia un total de %d veces.\n\n", cont_colas_vacias)
    : printf("Cerrado debido a que se atendio el maximo de clientes permitidos.\n\n");

    system("pause");
    return 0;
}

