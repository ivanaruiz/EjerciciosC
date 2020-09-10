#include <stdio.h>
#include <stdlib.h>
#define insertar scanf  //una macro
#define mostrar printf
#define ELMAYOR(a,b) ( (a)>(b) ? a : b )    //aca mezclo macro con operador ternario
/*
En este ejercicio simplemente hare varias pruebas de macro reemplazos y operadores ternarios con diferentes variables
para observar el comportamiento de cada uno. Tambien mezclare ambos.
*/


int main()
{
    int nota;
    mostrar("ingrese nota del examen: ");
    insertar("%d", &nota);

    mostrar("%s \n", (nota>=7 ? "Aprobado" : "Desaprobado"));   //ejemplo de ternaria


    int edad;
    mostrar("ingrese edad: ");
    insertar("%d", &edad);

    mostrar("usted es %s de edad\n", edad>=18 ? "mayor" : "menor");


    int nota2;
    mostrar("ingresar otra nota: ");
    insertar("%d", &nota2);



    //este es como un if anidado
    mostrar("%s \n" , nota2>6 ? "promociona" : (nota2 <4 ? "reprueba" : "aprueba") );


    //otra manera de resolver lo anterior
    //mostrar("\n%s\n", nota2>= 4 ? (nota2>= 7 ? "promociona" : "aprueba") : (nota2 >=4 ? "aprueba" : "reprueba"));


    int a, b;
    mostrar("ingresar dos numeros: ");
    insertar("%d%d", &a, &b);

    mostrar("\nel mayor numero es %d", ELMAYOR(a,b));


    FILE * pares   = fopen("pares.txt  ", "wt");
    FILE * impares = fopen("impares.txt", "wt");

    if(!pares || !impares)
        return 1;

    for(int i=1; i<=10; i++)
    {
        i%2==0 ? fprintf( pares, "%d ", i) : fprintf(impares, "%d ", i);
    }

    fclose(pares);
    fclose(impares);

    mostrar("\nSe han creado dos archivos txt con numeros pares y otro con numeros impares\n");

    system("pause");
    return 0;
}



