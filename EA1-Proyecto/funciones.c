
#include "funciones.h"


#define CONVERSOR_MAYUS_MINUS(X,Y) ((X)-(Y)==32 || (Y)-(X)==32)
#define minimo(x,y)     ((x)<=(y) ? (x) : (y))
#define ES_LETRA(X) (((X)>='A' && (X)<='Z') || ((X)>='a' && (X)<='z') || ((X)=='á' || (X)=='é' || (X)=='í' || (X)=='ó' || (X)=='ú'))

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

typedef struct
{
    char frase[100];
    int cont_pal;
    int max_pal;
}tFrase;

int mi_strlen(const char * sub);
void controlarLinea(char * cad, tFrase * f);


int contarOcurrencias1_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int contOcurrencias=0;
    int contLetras=0;
    int ce_sub = mi_strlen(sub);


    if(ce_sub==0)
        return 1;

    while(*cad!= '\0')
    {

        if(*cad==*sub || CONVERSOR_MAYUS_MINUS(*cad, *sub))
        {
            while((*cad==*sub || CONVERSOR_MAYUS_MINUS(*cad, *sub)) && *sub)
            {
                contLetras++;
                cad++;
                sub++;
            }

            if(ce_sub==contLetras)
            {
                contOcurrencias++;
                if(ce_sub!=1)
                    cad--;
            }

            sub = reset_sub;
            contLetras=0;
            cad--;
        }

        cad++;
    }

    return contOcurrencias;
}

int contarOcurrencias2_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int contOcurrencias=0;
    int contLetras=0;
    int ce_sub = mi_strlen(sub);


    if(ce_sub==0)
        return 1;

    while(*cad!= '\0')
    {

        if(*cad==*sub || CONVERSOR_MAYUS_MINUS(*cad, *sub))
        {
            while((*cad==*sub || CONVERSOR_MAYUS_MINUS(*cad, *sub)) && *sub)
            {
                contLetras++;
                cad++;
                sub++;
            }

            if(ce_sub==contLetras)
            {
                contOcurrencias++;
            }

            sub = reset_sub;
            contLetras=0;
            cad--;
        }

        cad++;
    }


    return contOcurrencias;
}

int mi_strlen(const char * sub)
{
    int cont=0;
    while(*sub!='\0')
    {
        cont++;
        sub++;
    }
    return cont;
}

void rotarMat_MIO_180(int m[][COLUM], int filas, int colum)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<(colum/2); j++)
        {
            int aux = m[i][j];
            m[i][j] = m[i][colum-j-1];
            m[i][colum-j-1] = aux;
        }
    }

    for(int i=0; i<filas/2; i++)
    {
        for(int j=0; j<colum ; j++)
        {
            int aux= m[i][j];
            m[i][j]= m[filas-i-1][j];
            m[filas-i-1][j] = aux;
        }
    }
}

int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum)
{
    int cont=0;
    int num=(colum-1)*4 ;
    for(int i=0; i<filas ; i++)
    {
        printf("%*s", num, "");
        for(int j= (colum-i-1)>=0 ? colum-i-1 : 0 ; j<colum ; j++)
        {
            printf("%4d",m[i][j]);
            cont++;
        }
        num-=4;
        if(num<0)
            num+=4;
        puts("");
    }
    return cont;
}



int  ordenarArchivo_MIO(const char *archEnt, const char *archSal)
{
    FILE * fpDatos = fopen(archEnt, "rt");
    FILE * fpNuevo = fopen(archSal, "wt");
    if(!fpDatos || !fpNuevo)
        return 0;

    tPila p1;
    tPila p2;

    crearPila(&p1);
    crearPila(&p2);

    char linea[100];

    tFrase f;

    //primero uso la pila 1 para almacenar y validar datos de cada frase
    while(!feof(fpDatos))
    {
        fgets(linea, 100, fpDatos);
        controlarLinea(linea, &f);
        ponerEnPila_MIO(&p1, &f, sizeof(tFrase));
    }

    //aca empiezo a ordenar con p2
    sacarDePila_MIO(&p1, &f, sizeof(tFrase));
    ponerEnPila_MIO(&p2, &f, sizeof(tFrase));

    tFrase tope;

    while(!pilaVacia_MIO(&p1))
    {

    sacarDePila_MIO(&p1, &f, sizeof(tFrase));
    verTope_MIO(&p2, &tope, sizeof(tFrase));

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

    //aca desapilo p2 que ya quedó ordenado y guardo en el txt
    while(!pilaVacia_MIO(&p2))
    {
        sacarDePila_MIO(&p2, &f, sizeof(tFrase));
        printf("%s", f.frase);
        fprintf(fpNuevo, "%s", f.frase);
    }


    return 1;
}

void controlarLinea(char * cad, tFrase * f)
{
    char * inicio = cad;
    int cont_pal=0;
    int cont_letras_x_pal=0;
    int max_pal=0;

    int huboN=0;

    while(*cad!='\0')
    {
        if(*cad=='\n')
            huboN=1;

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
    if(!huboN)
        *cad='\n';

    cad = inicio;

    strcpy(f->frase, cad);
    f->cont_pal = cont_pal;
    f->max_pal  = max_pal;
}

void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}

/**
int  pilaLlena_MIO(const tPila *p, unsigned cantBytes)
{

}
**/

int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes+sizeof(unsigned))
    {
        printf("pila llena\n");
        return 0;
    }

    p->tope-= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);

    p->tope-= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}


int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    int tam_aux;

    if(p->tope == TAM_PILA)
        return 0; //pila_vacia

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));

    memcpy(d, p->pila+p->tope + sizeof(unsigned), minimo(tam_aux, cantBytes));

    return 1;
}


int  pilaVacia_MIO(const tPila *p)
{
    return p->tope==TAM_PILA;
}


int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tam_aux;

    if(p->tope == TAM_PILA)
        return 0;   //pila_vacia

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));
    p->tope+= sizeof(unsigned);

    memcpy(d, p->pila+p->tope, minimo(tam_aux, cantBytes));
    p->tope+= tam_aux;

    return 1;
}

/**
void vaciarPila_MIO(tPila *p)
{

}
**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
