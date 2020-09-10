#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "cola_dinamica.h"


typedef struct
{
    int nro_cliente;    //los tres primeros enteros los determino yo
    int demora;
    int arribo;
    int llega;          //este sale por cálculo, es el min en que realmente se pone en la cola
    int hasta;          //este tambien sale por cálculo, es cuánto realmente sale de la cola

}t_cliente;

void generar_clientes(t_cliente * vec, int ce, int * ocupado_hasta_min);
void buscar_quien_entra(t_cliente * vec, int ce, t_cola * pc, int min, int * hubo_primer_movimiento, int *sigue_cola_vacia);
void buscar_quien_sale(t_cliente * vec, int ce, t_cola * pc, int min);

/**Enunciado oficial de la guia**/
/**Resuelava la simulación de la cola de espera de un cajero automático. Suponga que cada cliente demora
en el mismo un tiempo aleatorio de 1,3 o 5 minutos con igual probabilidad, y que los clientes llegan al mismo
de a uno, con intervalo de arribo aleatorio de 1,5 o 9 minutos, con igual probabilidad.
La simulación termina después de que la cola queda vacía cinco veces**/

/** Simulación de cajero de banco **/
/** Para resolver este ejercicio y entenderlo, conviene hacerse una guia del tiempo en una hoja, y un cuadro
de vector de clientes con todos sus datos. En el proyecto hay un excel para comparar.**/
/** El ejercicio simula el cajero de un banco, y avanzaremos en una línea de tiempo. En el minuto 0 abrimos el cajero.
Cada cliente lo guardaremos en una estructura con sus 3 datos principales, y luego 2 datos más qe necesitamos para resolver.
La frecuencia de llegada, o también llamada de arribo, es la frecuencia entre uno y otro cliente.Esta puede variar entre
1, 5 o 9 minutos, (le asignamos aleatoriamente). Es decir que por ejemplo si llega un primer cliente en el min 5
(y si pone en la cola); y si el siguiente tiene un arribo (o frencuencia) de 3 min, significa que llegará al min 8 e ingresa
a la cola (primitiva poner en cola). Y así.
Con la demora significa cuánto tiempo tarda en la caja. Este valor varía entre 1, 3 o 5 min. Por ejemplo, si el primer
cliente llegó al min 5, y tiene una demora de 5 min, significa que recién a los 10 min de abierta la caja, sale ese primer
cliente. Luego se atiende al cliente de atrás que está en espera. Y así.
Por lo tanto, si tenemos el siguiente ejemplo. Un primer cliente llega al min 1, y tiene demora de 5 min. Luego llega
un segundo ciente con arribo de 1 min, esto significa que llegaria un minuto despues que el primero, es decir en el min 2.
Pero debe esperar. Ya que el primer cliente saldra recien al min 6. Recien alli se hace atender el segundo cliente.
**/


#endif // BANCO_H_INCLUDED
