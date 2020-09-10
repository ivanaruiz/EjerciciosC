#include <stdio.h>
#include <stdlib.h>

/*Debemos encontrar la subcadena (si es que existe) dentro de la cadena y eliminarla.
Puede que haya varias repeticiones de subcadena, así que deben eliminarse todas. */

//prototipos
void desplazar(char * iniElim, char * cad);
void eliminar(char * cad, char * sub);
int mi_strlen(char * sub);

int main()
{
    char cad [] = "hola pedro hola juan como estan";
    char sub [] = "hol";

    printf("CADENA   : %s\n", cad);
    printf("SUBCADENA: %s\n", sub);

    eliminar(cad, sub);

    printf("\nCADENA SIN SUBCADENA: %s\n", cad);

    system("pause");
    return 0;
}


void eliminar(char * cad, char * sub)
{
    int ce_sub = mi_strlen(sub);

    //necesitamos coincidencia de esta variable con ce_sub
    //para confirmar que hay coincidencia de palabra
    //en caso de que no se complete, se reinicia la búsqueda
    int cont_let_cad = 0;

    char * reset_sub = sub;

    //cuando empiece a encontrar la posible palabra, este puntero apuntará al inicio
    //cuestión de que si hay match, mandaremos este puntero a función de desplazar
    char * iniElim;

    while(*cad)
    {
        if(*cad == *sub)
        {
            iniElim = cad;  //notar que ya lo inicializamos

            while(*cad== *sub && *cad && *sub)  //empieza a haber coincidencias..
            {
                cont_let_cad++;
                cad++;
                sub++;
            }

            if(ce_sub== cont_let_cad)   //si entra, es porque era la palabra
            {
                desplazar(iniElim, cad);
            }
            sub = reset_sub;    //reseteo para volver a buscar nuevas coincidencias
            cont_let_cad = 0;
            cad--;
        }
        cad++;
    }
}


//lo que haremos es ir copiando lo que hay en cad sobre iniElim
//notar que cad quedó apuntando al final de la palabra encontrada
//a partir de allí, todo el texto debe desplazarse a partir de iniElim
void desplazar(char * iniElim, char * cad)
{
    while(*cad)
    {
        *iniElim = *cad;
        iniElim++;
        cad++;
    }
    *iniElim = '\0';
}


int mi_strlen(char * sub)
{
    int cont=0;
    while(*sub)
    {
        cont++;
        sub++;
    }
    return cont;
}
