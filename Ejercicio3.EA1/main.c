/*Se tiene un archivo de texto y valiéndose de dos pilas, hay que ordenarlo
y generar un nuevo archivo ordenado.
Si no se pudiera generar el archivo de salida, se debe mostrar por pantalla.
Esta función ordenará de menor a mayor bajo el criterio de que se primero se
compara por cantidad de palabras. Si la cantidad de palabras coincide,
se tiene en cuenta la longitud de la palabra más larga. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARCH_ENT    "datos.txt"
#define ARCH_SAL    "nuevo.txt"

#define ERROR_ARCH_ENT      -1
#define ERROR_ARCH_SAL      -2


#define ES_LETRA(X) (((X)>='A' && (X)<='Z') || ((X)>='a' && (X)<='z') || ((X)=='á' || (X)=='é' || (X)=='í' || (X)=='ó' || (X)=='ú'))


#include "Pila_estatica.h"


typedef struct
{
    char frase[100];
    int cont_pal;
    int max_pal;
}tFrase;

int crearArchivo(const char *archEnt);
void probarArchivosYPila();
void analizarLinea(char * cad, tFrase * f);
int  ordenarArchivo_MIO(const char *archEnt, const char *archSal);


int main()
{
    probarArchivosYPila();
    system("pause");
    return 0;
}


void probarArchivosYPila()
{
    int valDevuelto;

    if(!crearArchivo(ARCH_ENT))
        fprintf(stderr, "ERROR - creando archivo de texto \"%s\"\n", ARCH_ENT);
    else
    {
        valDevuelto = ordenarArchivo_MIO(ARCH_ENT, ARCH_SAL);

        if(valDevuelto == ERROR_ARCH_ENT)
        {
            fprintf(stderr, "ERROR - No existe el archivo a leer.\n");
            return;
        }

    }
    puts("/////////////////////////////////////////////////\n");
}


int crearArchivo(const char *archEnt)
{
    FILE * fp =fopen(archEnt, "wt");
    if(!fp)
        return 0;

    fprintf(fp,"%s","             Marcha Mi Bandera\n");

    fprintf(fp,"%s","\n");

    fprintf(fp,"%s","     Salve, Argentina, bandera azul y blanca,\n");
    fprintf(fp,"%s","     jiron del cielo en donde impera el sol;\n");
    fprintf(fp,"%s","     tu, la más noble, la mas gloriosa y santa;\n");
    fprintf(fp,"%s","     el firmamento tu color te dio,\n");
    fprintf(fp,"%s","     el firmamento tu color te dio,\n");
    fprintf(fp,"%s","     el firmamento tu color te dio.\n");

    fprintf(fp,"%s","\n");

    fprintf(fp,"%s","     Yo te saludo, bandera de mi patria,\n");
    fprintf(fp,"%s","     sublime ensena de libertad y honor,\n");
    fprintf(fp,"%s","     jurando amarte, como asi defenderte,\n");
    fprintf(fp,"%s","     mientras palpite mi fiel corazon,\n");
    fprintf(fp,"%s","     mientras palpite mi fiel corazon.\n");
    fprintf(fp,"%s","                              (Juan Enrique Chassaing)");

    fclose(fp);

    return 1;
}


int  ordenarArchivo_MIO(const char *archEnt, const char *archSal)
{
    FILE * fpDatos = fopen(archEnt, "rt");
    FILE * fpNuevo = fopen(archSal, "wt");
    if(!fpDatos || !fpNuevo)
        return 0;

    tPila p1;
    tPila p2;

    crearPila_MIO(&p1);
    crearPila_MIO(&p2);

    char linea[100];

    //creo una estructura donde voy a guardar cada linea leída
    //también allí guardaré su cantidad de palabras, y la cantidad de letras
    //de la palabra más larga
    tFrase f;

    //primero uso la pila p1 para almacenar y registrar datos de cada frase
    while(!feof(fpDatos))
    {
        fgets(linea, 100, fpDatos);
        analizarLinea(linea, &f);
        ponerEnPila_MIO(&p1, &f, sizeof(tFrase));
    }


    //aca empiezo a ordenar con p1 y p2
    //en p2 me quedará ordenado
    //para entender cómo funciona mi método de ordenamiento, leer abajo de todo
    sacarDePila_MIO(&p1, &f, sizeof(tFrase));
    ponerEnPila_MIO(&p2, &f, sizeof(tFrase));

    //esta estructura me servirá para ir viendo topes o sacando elementos de p2
    tFrase tope;

    while(!pilaVacia_MIO(&p1))
    {

    sacarDePila_MIO(&p1, &f, sizeof(tFrase));
    verTope_MIO(&p2, &tope, sizeof(tFrase));

    //comparo por cantidad de palabras
    if(f.cont_pal<tope.cont_pal)
        ponerEnPila_MIO(&p2, &f, sizeof(tFrase));

    else if(f.cont_pal>tope.cont_pal)
        {
            do
            {
            sacarDePila_MIO(&p2, &tope, sizeof(tFrase));
            ponerEnPila_MIO(&p1, &tope, sizeof(tFrase));

            verTope_MIO(&p2, &tope, sizeof(tFrase));

            }while( (f.cont_pal>tope.cont_pal || f.max_pal>tope.max_pal) && !pilaVacia_MIO(&p2));

            ponerEnPila_MIO(&p2, &f, sizeof(tFrase));
        }

    //si llego acá es porque las frases tienen misma cantidad de palabras
    //entonce me fijo cuál tiene la palabra más larga
    else
    {
        if(f.max_pal<=tope.max_pal)
            ponerEnPila_MIO(&p2, &f, sizeof(tFrase));
        else
        {
            do
            {
            sacarDePila_MIO(&p2, &tope, sizeof(tFrase));
            ponerEnPila_MIO(&p1, &tope, sizeof(tFrase));

            verTope_MIO(&p2, &tope, sizeof(tFrase));

            }while(f.max_pal>tope.max_pal && !pilaVacia_MIO(&p2));

            ponerEnPila_MIO(&p2, &f, sizeof(tFrase));
        }
    }
    }

    //finalmente desapilo p2 que ya quedó ordenado y guardo en el txt
    while(!pilaVacia_MIO(&p2))
    {
        sacarDePila_MIO(&p2, &f, sizeof(tFrase));
        printf("%s", f.frase);
        fprintf(fpNuevo, "%s", f.frase);
    }


    return 1;
}


void analizarLinea(char * cad, tFrase * f)
{
    char * inicio = cad;    //me servirá para resetear cad, es decir volver al inicio
    int cont_pal=0;
    int cont_letras_x_pal=0;
    int max_pal=0;

    int huboContrabarraN=0;

    while(*cad!='\0')
    {
        if(*cad=='\n')
            huboContrabarraN=1;

        if(ES_LETRA(*cad))
        {
            cont_letras_x_pal=0;

            while(ES_LETRA(*cad))
            {
                cont_letras_x_pal++;
                cad++;
            }
            cont_pal++;

            if(cont_letras_x_pal>max_pal)
                max_pal=cont_letras_x_pal;
        }
        cad++;
    }
    if(!huboContrabarraN)   //es para la última frase, porque no tiene '\n'
        *cad='\n';

    cad = inicio;

    //finalmente añado la frase con sus datos a la estructura
    strcpy(f->frase, cad);
    f->cont_pal = cont_pal;
    f->max_pal  = max_pal;
}


//método de ordenamiento con dos pilas: Por ej de menor a mayor.
/*
En p1, tenemos los datos desordenados. Y en p2 no tenemos nada aún.
El primero paso es desapilar el primer dato de p1 y alojarlo en p2.
Vamos a tomar como que ese es el menor.
Luego entramos a un while. Desapilamos el siguiente elemento de p1,
y lo vamos a comparar con lo que haya en p2, PERO SIN DESAPILAR.
Para entonces nos valemos de la función ver_tope, que no desapila.
Así podemos comparar ambos datos. Si el dato extraido de p1 es mayor,
entonces lo apilo correctamente en p2.
De no serlo, entonces tengo que reordenar ésto, y para eso me valgo
de un do while. Lo que haré es extraer el dato de p2 y ponerlo en p1.
Y ahora sí colocamos al dato extraido anteriormente de p1 y lo ponemos
en p2. (Eso sería al inicio, para ya más adelante, ese dato lo estoy
comparando siempre con el tope de p2 y mientras que éste último sea
mayor, entonces lo voy llevando a p1.
Así se irá ordenando.
Breve ejemplo:

p1: p2:
3   nada
1   nada
4   nada
2   nada

desapilo el 3 de p1. me queda en una variable llamada por ejemplo val=3
y lo meto en p2.
p1:     p2:
1       3
4       nada
2       nada
nada    nada

saco el siguiente de p1. que me quedará en val. y luego comparo con ver_tope
p1:     p2:
4       3
2       nada
nada    nada
nada    nada              val=1  <  ver_tope_p2=3

comprobamos que val=1 es menor que el ver_tope de p2, entonces lo sacamos
en una variable que llamaremos aux
p1:     p2:
4       3
2       nada
nada    nada
nada    nada                val=1 < aux=3

Y metemos a aux en p1, y a val en p2
p1:     p2:
3       1
4       nada
2       nada
nada    nada

Luego acá se repite todo de nuevo. Sacamos el primer dato de p1 y comparamos
con ver_tope_p2:
p1:     p2:
4       1
2       nada
nada    nada
nada    nada            val=3  >  ver_tope_p2 = 1

En este caso es correcto asi que lo apilamos en p2 a val:
p1:     p2:
4       3
2       1
nada    nada
nada    nada

Repetimos:
p1:     p2:
2       3
nada    1
nada    nada
nada    nada             val=4  >  ver_tope_p2=3

También es mayor, asi que apilamos val a p2:
p1:     p2:
2       4
nada    3
nada    1
nada    nada

Sacamos el 2, y acá sí es donde se usa el while, ya que
tendremos que extraer más de p2. Vamos paso por paso:
p1:     p2:
nada    4
nada    3
nada    1
nada    nada           val=2  < ver_tope_p2=4

No está en orden. así que desapilamos e 4 de p2 y lo alojamos en el aux:
p1:     p2:
nada    4
nada    3
nada    1
nada    nada            val=2 < aux=4

Apilamos aux en p1, y hacemos otra comparacion con el siguiente ver_tope_p2:
p1:     p2:
4       3
nada    1
nada    nada
nada    nada            val=2  < ver_tope_p2=3

Val sigue siendo menor , asíqeu volvemos a desapilar p2:
p1:     p2:
4       1
nada    nada
nada    nada
nada    nada            val=2  <  aux=3

Apilamos aux en p1 , y val en p2:
p1:     p2:
3       2
4       1
nada    nada
nada    nada

Ahora repetimos y sacamos el siguiente de p1 a var.
p1:     p2:
4       2
nada    1
nada    nada
nada    nada        var=3   >  ver_tope_p2 = 2

Es mayor así que es correcto y apilamos var en p2:
p1:     p2:
4       3
nada    2
nada    1
nada    nada

Repetimos para el último dato:
p1:     p2:
nada    3
nada    2
nada    1
nada    nada            var=4  >  ver_tope_p2 = 3

Es mayor así que apilamos var en p2:
p1:     p2:
nada    4
nada    3
nada    2
nada    1

Finalmente se termina el ciclo while de p1 (pila_vacia!)
y vemos que p2 quedó totalmente ordenada.
*/
