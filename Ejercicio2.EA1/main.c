#include <stdio.h>
#include <stdlib.h>

#define FILAS       15
#define COLUM       13

void probarMatrices();
int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum);
void rotarMat180_MIO(int m[][COLUM], int filas, int colum);
void mostrarMat(int m[][COLUM], int filas, int colum);
void cargarMatConsec(int m[][COLUM], int filas, int colum);

/*Dado un array bidimensional de enteros, rotarlo 180 grados, y luego debe mostrar
los elementos que pertenecen a la diagonal secundaria además de los que están
por debajo de la misma.
Elija una buena estrategia para hacer ambas cosas, porque debe funcionar no solo
con matrices cuadrada, sino también con matrices rectangulares.*/
/*Ejemplo matriz original:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16
17 18 19 20

Rotamos:
20 19 18 17
16 15 14 13
12 11 10  9
 8  7  6  5
 4  3  2  1

Diagonal secundaria inf:
         17
      14 13
   11 10  9
 8  7  6  5
 4  3  2  1   */



int main()
{
    probarMatrices();
    system("pause");
    return 0;
}



void probarMatrices()
{
    int     mat[FILAS][COLUM];

    puts("/////////////////////////////////////////////////");

    cargarMatConsec(mat, FILAS, COLUM);
    mostrarMat(mat, FILAS, COLUM);
    printf("(MIO)\n\nLa matriz rotada en 180 grados queda:\n");
    rotarMat180_MIO(mat, FILAS, COLUM);
    mostrarMat(mat, FILAS, COLUM);
    printf("(MIO)\nLos elementos de la matriz rotada que pertenecen\n"
           "o estan por debajo de la diagonal secundaria son:\n");
    mostrarMatTriangDerInf_MIO(mat, FILAS, COLUM);

    puts("/////////////////////////////////////////////////\n");
}

void cargarMatConsec(int m[][COLUM], int filas, int colum)
{
    int n=1;
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<colum; j++)
        {
            m[i][j]= n;
            n++;
        }
    }
}

void mostrarMat(int m[][COLUM], int filas, int colum)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<colum; j++)
        {
            printf("%4d", m[i][j]);
        }
        puts("");
    }
}
void rotarMat180_MIO(int m[][COLUM], int filas, int colum)
{
    int aux;
    int i,j;

    for(i=0; i< filas; i++)     //invierto en un eje vertical
    {
        for(j=0; j< colum /2 ; j++)
        {
            aux= m[i][j];
            m[i][j]= m[i][colum-j-1];
            m[i][colum-j-1]= aux;
        }
    }

    for(i=0; i<filas/2; i++)    //invierto en un eje horizontal
    {
        for(j=0; j<colum; j++)
        {
            aux= m[i][j];
            m[i][j] = m[filas-1-i][j];
            m[filas-1-i][j] = aux;
        }
    }

}

int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum)
{
    int i,j;
    int ce=0;   //cantidad de elementos

    //con esta variable n me ayudé para que se muestre el dibujo del triángulo,
    //el 4 lo tomé por la cantidad de digitos de cada numero, que son hasta 3; y 1 caracter por espacio
    int n= (colum-1)*4;

    for(i= 0; i< filas ; i++)
    {
        printf("%*s",n,"");

        for(j= (i<colum ? colum-1-i : 0 ) ; j< colum ; j++)
        //otra opción que es lo mismo:
        //for(int j= (colum-i-1)>=0 ? colum-i-1 : 0 ; j<colum ; j++)
        {
                printf("%4d", m[i][j]);
                ce++;
        }

        printf("\n");

        n-=4;
        if(n<0)
            n+=4;
    }
    //si bien en el ejercicio ni el main no encontré que digan que esta función devuelva algo,
    //opté por devolver la cantidad de elementos que hay en la diagonal y debajo de ella.
    return ce;
}
