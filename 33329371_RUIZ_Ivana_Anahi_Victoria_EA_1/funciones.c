
#include "funciones.h"
#define CONVERSOR_MAYUS_MINUS(X,Y)  ( (X-Y==32) || (Y-X)==32)
#define minimo(x,y) ((x)<(y) ? (x):(y))
#define ES_LETRA(x) ( (x>='a' && x<='z') || (x>='A' && x<='Z') )

typedef struct
{
    char frase [100];
    int cont_pal;
    int cont_let;
}t_linea;

//prototipos de nuevas funciones que usé
int mi_strlen(const char * sub);
void analizar_linea(char * linea, int * cont_pal, int * max);
int actualizar_arch_sal(tPila *p, char * modo_de_escritura);
void comparar_con_dos_pilas(tPila *p, t_linea *lin);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int contarOcurrencias1_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int ce= mi_strlen(sub);

    if(ce==0)   //para el caso de sub="", que sencillamente devuelva 1 para no hacer todo el cálculo siguiente
        return 1;

    int cont_letras=0;  //contador de letras de una (posible) ocurrencia
    int cont_ocurrencias=0;

    while(*cad != '\0')
    {
        if(*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) )
        {
            while( (*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) ) && *cad!='\0' && *sub!='\0')
            {
                cad++;
                sub++;
                cont_letras++;
            }
            if(cont_letras==ce) //con esto verifico si realmente se trata de la misma palabra
            {
                cont_ocurrencias++;
                if(ce!=1)   //salvo las casos en que sub sea de 1 caracter, ejemplo sub=" "
                    cad--;
            }
            //en caso de no ser la misma palabra, reseteo a sub para una próxima búsqueda
            cont_letras=0;
            sub= reset_sub;
            cad--;
        }
        cad++;
    }
    return cont_ocurrencias;
}


int contarOcurrencias2_MIO(const char *cad, const char *sub)
{
    char * reset_sub = (char*)sub;
    int ce= mi_strlen(sub);

    if(ce==0)
        return 1;

    int cont_letras=0;
    int cont_ocurrencias=0;

    while(*cad != '\0')
    {
        if(*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub)  )
        {
            while( (*cad == *sub || CONVERSOR_MAYUS_MINUS(*cad,*sub) ) && *cad!='\0' && *sub!='\0')
            {
                cad++;
                sub++;
                cont_letras++;
            }
            if(cont_letras==ce)
            {
                cont_ocurrencias++;
            }

            cont_letras=0;
            sub= reset_sub;
            cad--;
        }
        cad++;
    }
    return cont_ocurrencias;
}


int mi_strlen(const char * sub)
{
    int cant_de_caracteres=0;

    while(*sub!= '\0')
    {
        cant_de_caracteres++;
        sub++;
    }
    return cant_de_caracteres;
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
        //otra opción del for:
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

void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA ;
}

/** No uso esta función, por tanto no la desarrollo
int  pilaLlena_MIO(const tPila *p, unsigned cantBytes)
{
}
**/

int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{
    if (p->tope <cantBytes + sizeof(unsigned))
        return 0;

    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);

    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}


int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tam_aux;

    if(p->tope==TAM_PILA)
        return 0;

    memcpy(&tam_aux, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->tope + p->pila + sizeof(unsigned), minimo(cantBytes, tam_aux));

    return 1;
}


int  pilaVacia_MIO(const tPila *p)
{
    return p->tope == TAM_PILA;
}


int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tam_aux;

    if(p->tope == TAM_PILA)
        return 0;

    memcpy(&tam_aux, p->pila+p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);

    memcpy(d, p->pila + p->tope, minimo(cantBytes, tam_aux));
    p->tope += tam_aux;

    return 1;
}

/**No uso esta función, por tanto no la desarrollo
void vaciarPila_MIO(tPila *p)
{
}
**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
