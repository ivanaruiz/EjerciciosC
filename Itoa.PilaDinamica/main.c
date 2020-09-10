
#include "pila_dinamica.h"
#include "mi_itoa.h"

/*En este ejercicio realizamos nuestra propia funcion de itoa pero implementando una pila dinamica para apilar los
numeros que vamos convirtiendo a ascii, es decir apilamos los caracteres del tipo char. Luego sacamos de la pila los
elementos, y al ser pila, ya no hace falta ordenarlos, puesto que salen "en orden" en este caso, es decir, sale
del ultimo ingresado hasta el primero.
*/


int main()
{
    int num= 7000;
    int base= 16;
    printf("numero: %d\nbase: %d\nConvertido a ascii con funcion mi_itoa: ", num, base);

    mi_itoa(num, base);

    puts("");
    system("pause");
    return 0;
}

