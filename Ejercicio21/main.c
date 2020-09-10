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

//notar que en este ejercicio, no uso puntero ya que no quiero convertir al numero original en otro n�mero
//simplemente me pide que devuelva su parte entera, pero el n�mero original debe quedar tal como est�

//por lo tanto en la funci�n lo que estoy haciendo es pasarle una simple de copia de num como par�metro
//si hubiera hecho obtenerParteEntera(&num) en el main, y en la funci�n void obtenerParteEntera(float * num)
//entonces no ser�a una copia, sino que estar�a modificando a la variable num original
void obtenerParteEntera(float num)
{
    int entera = num/1;
    float decimal = num - entera;  ///esta parte no la pide pero la hago opcional

    printf("\nParte entera: %d. Parte decimal: %.2f\n", entera, decimal);
}
