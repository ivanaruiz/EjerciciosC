#include <stdio.h>
#include <stdlib.h>

/*
Programa que emula la funcion strlen de la libreria string.
Es decir, cuenta los caracteres de un texto, cuenta hasta el '\0' que es fin de cadena.
*/

size_t mi_strlen(const char *texto);


int main()
{
    char texto[50];
    printf("Ingresar texto: ");
    fflush(stdin);
    gets(texto);

    printf("Texto: %s\n", texto);
    printf("Cantidad de letras: %d \n\n", mi_strlen(texto));

    system("pause");
    return 0;
}


size_t mi_strlen(const char *texto)
{
    int cont=0;

    while(*texto != '\0')
    {
        cont++;
        texto++;
    }
    return cont;
}

