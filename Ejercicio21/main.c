//Desarrollar una funcion para obtener la parte entera de un numero real

#include <stdio.h>
#include <stdlib.h>

void obtenerParteEntera(float num);


int main()
{
    float num;

    printf("Ingrese numero real: ");
    fflush(stdin);
    scanf("%f",&num);

    printf("\nNumero ingresado: %.2f\n",num);
    obtenerParteEntera(num);

    system("pause");
    return 0;
}

//notar que en este ejercicio, no uso puntero ya que no quiero convertir al numero original en otro número
//simplemente me pide que devuelva su parte entera, pero el número original debe quedar tal como está

//por lo tanto en la función lo que estoy haciendo es pasarle una simple de copia de num como parámetro
//si hubiera hecho obtenerParteEntera(&num) en el main, y en la función void obtenerParteEntera(float * num)
//entonces no sería una copia, sino que estaría modificando a la variable num original
void obtenerParteEntera(float num)
{
    int entera = num/1;
    float decimal = num - entera;  ///esta parte no la pide pero la hago opcional

    printf("\nParte entera: %d. Parte decimal: %.2f\n", entera, decimal);
}
