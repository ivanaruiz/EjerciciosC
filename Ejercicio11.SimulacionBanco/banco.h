#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

typedef struct
{
    int nro_cliente;    //los tres primeros enteros los determino yo
    int demora;
    int arribo;
    int llega;          //este sale por c�lculo, es el min en que realmente se pone en la cola
    int hasta;          //este tambien sale por c�lculo, es cu�nto realmente sale de la cola

}t_cliente;

void buscar_quien_entra(t_cliente * vec, int ce, t_cola * pc, int min);
void buscar_quien_sale(t_cliente * vec, int ce, t_cola * pc, int min);

/** Simulaci�n de cajero de banco **/
/** Para resolver este ejercicio y entenderlo, conviene hacerse una guia del tiempo en una hoja, y un cuadro
de vector de clientes con todos sus datos. En el proyecto hay un excel para comparar.**/
/** El ejercicio simula el cajero de un banco, y avanzaremos en una l�nea de tiempo. En el minuto 0 abrimos el cajero.
Cada cliente lo guardaremos en una estructura con sus 3 datos principales, y luego 2 datos m�s qe necesitamos para resolver.
La frecuencia de llegada, o tambi�n llamada de arribo, es la frecuencia entre uno y otro cliente.Esta puede variar entre
1, 5 o 9 minutos, (le asignamos alguno de esos valores). Es decir que por ejemplo si llega un primer cliente en el min 5
(y si pone en la cola); y si el siguiente tiene un arribo (o frencuencia) de 3 min, significa que llegar� al min 8 e ingresa
a la cola (primitiva poner en cola). Y as�.
Con la demora significa cu�nto tiempo tarda en la caja. Este valor var�a entre 1, 3 o 5 min. Por ejemplo, si el primer
cliente lleg� al min 5, y tiene una demora de 5 min, significa que reci�n a los 10 min de abierta la caja, sale ese primer
cliente. Luego se atiende al cliente de atr�s que est� en espera. Y as�.
Por lo tanto, si tenemos el siguiente ejemplo. Un primer cliente llega al min 1, y tiene demora de 5 min. Luego llega
un segundo ciente con arribo de 1 min, esto significa que llegaria un minuto despues que el primero, es decir en el min 2.
Pero debe esperar. Ya que el primer cliente saldra recien al min 6. Recien alli se hace atender el segundo cliente.
Nota: la cola puede quedar vacia a veces (cuando no hay clientes nuevos). Se termina el programa cuando entraron y salieron
todos los clientes con su debida espera.
**/

#endif // BANCO_H_INCLUDED
