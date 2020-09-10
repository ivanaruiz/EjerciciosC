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
    char frase [100];
    int cont_pal;
    int cont_let;
}t_linea;


int crearArchivo(const char *archEnt);
void probarArchivosYPila();
int  ordenarArchivo_MIO(const char *archEnt, const char *archSal);
void analizar_linea(char * linea, int * cont_pal, int * max);
int actualizar_arch_sal(tPila *p, char * modo_de_escritura);
void comparar_con_dos_pilas(tPila *p, t_linea *lin);

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
    tPila p;
    crearPila_MIO(&p);

    FILE * pf_ent= fopen(ARCH_ENT, "rt");
    if(!pf_ent)
        return ERROR_ARCH_ENT;

    t_linea lin;
    char linea[100];

    int cont_pal_x_linea;
    int cont_let_pal_max;
    int primera_vez=0;

    while(!feof(pf_ent))
    {
        fgets(linea, 100, pf_ent);

        cont_let_pal_max=0;
        cont_pal_x_linea=0;

        analizar_linea(linea, &cont_pal_x_linea, &cont_let_pal_max);

        strcpy(lin.frase, linea);
        lin.cont_pal = cont_pal_x_linea;
        lin.cont_let = cont_let_pal_max;

        //la técnica que pensé fue poner la primera línea leída en la pila p
        //las demás que saque las iré comparando con el tope de pila
        //y sacando y poniendo según corresponda, ayudándome con una segunda pila p_aux

        if(primera_vez==0)    //para la primera línea leida
        {
            ponerEnPila_MIO(&p, &lin, sizeof(t_linea));
            primera_vez++;
        }

        else    //compararé cada linea sacada con la que esté en la pila
        {
            comparar_con_dos_pilas(&p, &lin);
        }
    }

    fclose(pf_ent); //llegado a este punto, ya tengo mi pila p ordenada

    if(!actualizar_arch_sal(&p, "wt"))
        return ERROR_ARCH_SAL;

    return 1;
}

//En la pila p es dónde iré alojando en orden
void comparar_con_dos_pilas(tPila *p, t_linea *lin )
{
    tPila p_aux;
    crearPila_MIO(&p_aux);
    t_linea elem;

    verTope_MIO(p, &elem, sizeof(t_linea));

    if( ( (lin->cont_pal>=elem.cont_pal && lin->cont_let>elem.cont_let ) ||lin->cont_pal>elem.cont_pal ) && !pilaVacia_MIO(p))
    {
            while( ( (lin->cont_pal>=elem.cont_pal && lin->cont_let>elem.cont_let ) ||lin->cont_pal>elem.cont_pal ) && !pilaVacia_MIO(p))
            {
                sacarDePila_MIO(p, &elem, sizeof(t_linea));
                ponerEnPila_MIO(&p_aux, &elem, sizeof(t_linea));
                verTope_MIO(p, &elem, sizeof(t_linea));
            }

                ponerEnPila_MIO(p, lin, sizeof(t_linea));

            while(!pilaVacia_MIO(&p_aux))
            {
                sacarDePila_MIO(&p_aux, &elem, sizeof(t_linea));
                ponerEnPila_MIO(p, &elem, sizeof(t_linea));
            }
    }
    else
            ponerEnPila_MIO(p, lin, sizeof(t_linea));
}



int actualizar_arch_sal(tPila *p, char * modo_de_escritura)
{
    FILE * pf_sal= fopen(ARCH_SAL, modo_de_escritura);
    if(!pf_sal)
        return ERROR_ARCH_SAL;
    t_linea linea;
    while(!pilaVacia_MIO(p))
    {
        sacarDePila_MIO(p, &linea, sizeof(t_linea));
        printf("%s", linea.frase);
        fprintf(pf_sal, "%s", linea.frase);
    }
    fclose(pf_sal);
    return 1;
}

//en esta función contaré la cantidad de palabras por línea,
//y además obtendré la cantidad de letras de la palabra más larga de esa linea
void analizar_linea(char * linea, int * cont_pal, int * max)
{
    int cont_letras=0;
    int hubo_contrabarra_n=0;  //para los renglones que no tienen '\n'

    while(*linea!='\0')
    {
        if(ES_LETRA(*linea))
        {
            cont_letras=0;  //ante una nueva palabra, reseteo el contador de letras
            while(ES_LETRA(*linea))
            {
                linea++;
                cont_letras++;
            }
            linea--;
            *cont_pal+=1;

            if(cont_letras>*max)
                *max= cont_letras;
        }
        if(*linea=='\n')
            hubo_contrabarra_n=1;

        linea++;
    }

        if(!hubo_contrabarra_n)
        {
            linea--;
            *linea='\n';
        }
}
