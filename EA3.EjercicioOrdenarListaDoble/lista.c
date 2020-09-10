#include "lista.h"

/*HAY DOS VERSIONES DE LA FUNCIÓN ORDENAR. SON MUY PARECIDAS.
AMBAS SON CORRECTAS.*/

//////////////////////////////PRIMERA VERSION///////////////////////////////////////////
//////////////////////////////PRIMERA VERSION///////////////////////////////////////////
//////////////////////////////PRIMERA VERSION///////////////////////////////////////////
//////////////////////////////PRIMERA VERSION///////////////////////////////////////////
//////////////////////////////PRIMERA VERSION///////////////////////////////////////////

/**
void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    if(!*p)
        return;

    tNodo   * mayor;
    tNodo   * inicio = irInicio(p);
    tNodo   * auxSig,
            * auxAnt;

    int primeraVez=0;   //esta variable la uso solo para el primer mayor encontrado

    while(inicio)
    {
        int cont=0;
        primeraVez++;

        mayor = buscarMayor(inicio, comparar, &cont);

        if(cont<=1)     //cuando ya no hay nodos que se repitan, simplemente salgo
            return;

        if(primeraVez==1)       //entro cuando se trata del primer nodo que ordenaré
        {
            if(mayor!=inicio)   //cuando mi primer mayor es el primer nodo de la lista,
            {                   //no hace falta reordenarlo, como en nuestro ejemplo
                reacomodarElPrimero(inicio, mayor);
            }
            auxAnt = mayor;
            auxSig = auxAnt->sig;
        }
        else    //para todos los siguientes nodos que voy a reacomodar
            {auxSig= inicio;
            auxAnt = auxSig->ant;}

        inicio = reacomodarLosSiguientes(auxAnt, auxSig, mayor, comparar);
    }
}
//con esta función, acomodo el primer nodo al principio de la lista
void reacomodarElPrimero(tNodo * inicio, tNodo * mayor)
{
    mayor->sig->ant = mayor->ant;
    mayor->ant->sig = mayor->sig;

    mayor->sig = inicio;
    mayor->ant = NULL;

    inicio->ant = mayor;
}

tNodo * reacomodarLosSiguientes(tNodo * auxAnt, tNodo * auxSig, tNodo * mayor,
             int (*comparar)(const void *, const void *))
{
    tNodo * aux = auxSig;

    while(aux)
    {   //cuando encuentre los nodos correspondientes, haré los desenganches y enganches
        if((comparar(mayor->info , aux->info )==0 && auxSig!=aux))
        {
            if(aux->sig)
                {aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;}
            else
                aux->ant->sig = NULL;

            aux->sig = auxSig;
            aux->ant = auxAnt;

            auxSig->ant = aux;
            auxAnt->sig = aux;

            auxAnt= auxAnt->sig;
        }
        else if(comparar(mayor->info , aux->info )==0  && aux->sig)
            {auxSig = auxSig->sig;
            auxAnt = auxAnt->sig;}

        aux = aux->sig; //finalmente avanzo para seguir buscando los otros nodos
    }
    return auxSig;
}

//con mayor nos referimos al que tiene mas ocurrencias
tNodo * buscarMayor(tNodo * inicio, int (*comparar)(const void *, const void *), int * max)
{
    tNodo * maxNodo = inicio;
    tNodo * aux = inicio;

    while((inicio)->sig)
    {
        int cont=0;
        while(aux)
        {
            if(comparar( (inicio)->info, (aux)->info)==0)
                cont++;

            aux= aux->sig;
        }
        if(cont>*max)
            {*max=cont;
            maxNodo = inicio;}  //acá encontramos al de mayor ocurrencia (por ahora)

        inicio= (inicio)->sig;
        aux = inicio;
    }
    return maxNodo;
}

tNodo * irInicio(tLista *p)
{
    while((*p)->ant)
            p = &(*p)->ant;
    tNodo * aux= *p;
    return aux;
}

**/

//////////////////////////////SEGUNDA VERSION///////////////////////////////////////////
//////////////////////////////SEGUNDA VERSION///////////////////////////////////////////
//////////////////////////////SEGUNDA VERSION///////////////////////////////////////////
//////////////////////////////SEGUNDA VERSION///////////////////////////////////////////
//////////////////////////////SEGUNDA VERSION///////////////////////////////////////////


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    //no usaré p, usaré un puntero a nodo llamado actual
    tNodo * act = *p;
    tNodo * mayor;

    act = irAlInicio(act);

    int max=0;  //cuando vuelva de la función buscarMayor, me devuelve el nodo
                //con mayor cantidad de duplicados
                //en esta variable max, me quedará albergada esa cantidad

    int primeraVuelta=0;    //esta bandera la uso solo para reacomodarNodos el primer nodo
                            //en caso de que éste no se encuentre al principio de la lista
                            //(no es el ejemplo en este ejercicio, pero puede pasar)

    while(act)
    {
        primeraVuelta++;
        mayor = buscarMayor(act, &max);
        if(max==1)  //esto significa que ya no hay nodos con repeticiones
            return; //entonces no hace falta seguir reordenando
        if(!mayor)
            return;

        //notar que no avanzo con act, porque la función reacomodarNodosNodos, me devolverá
        //la nueva posición de act, que será dónde quedó el último acomodado
        act = reacomodarNodos(act, mayor, &primeraVuelta);
    }
}


tNodo * reacomodarNodos(tNodo *act, tNodo * mayor, int * primeravez)
{
    tNodo * aux = act;
    tNodo * nue;

    //Solo entra a este if cuando el primer nodo (de toda la lista) que debemos reacomodar,
    //no se encuentra en la primera posición. Entra acá SOLO UNA VEZ(o no) durante
    //toda la función ordenarLista.
    //Es decir mete al nodo en cuestión al inicio de la lista
    if(mayor!= aux && *primeravez==1)
    {
        //primero siepre hacer el desenganche de donde se encuentre
        mayor->ant->sig= mayor->sig;
        mayor->sig->ant= mayor->ant;

        //luego el enganche al inicio
        mayor->sig= aux;
        mayor->ant=NULL;
        aux->ant=mayor;

        aux=mayor;
        act= mayor->sig;
    }


    while(act)
    {
        if(compararFinal_MIO(act->info, mayor->info)==0 && *primeravez!=1)
        {
            nue = act;

            if(act->sig)    //primero desengancho
            {
            act->ant->sig = act->sig;
            act->sig->ant = act->ant;
            }
            else
                act->ant->sig=NULL; //pasa por acá cuando el nodo a desenganchar estaba
                                    //último en la lista. entonces hay que poner null

            //luego engancho, primero nue a los nodos, y luego de los nodos a nue
            //es decir recordar siempre hacer ese "doble" enganche
            nue->sig= aux->sig;
            nue->ant= aux;
            aux->sig->ant= nue;
            aux->sig=nue;

            //finalmente avanzo
            aux= aux->sig;
        }

        *primeravez=2;  //éste ya no lo uso más

        act= act->sig;
    }

    return aux;
}

tNodo * buscarMayor(tNodo * act, int * max)
{
    //este inicio lo necesito porque tendré dos while, por tanto se resetea constantemente act
    tNodo * inicio = act;
    tNodo * mayor = act;

    act= act->sig;

    //para obtener el máximo
    int cont =1;    //lo puse en 1 simplemente porque el primer nodo a evaluar no lo cuenta
    *max=1;

    //estos dos nodos los uso solo para saber cuando en la lista me quedaros varios
    //nodos pero son todos del mismo alumno.
    //esto sucede cuando el contDeNodos y contRepXNodo son iguales
    //pero ojo, también se puede dar que ésto pase para otras situaciones cuando
    //en los ciclos while se está examinando el último nodo, entonces siempre da 1=1
    //eso lo valido igualmente más adelante
    int contDeNodos=0;
    int contRepXNodo=0;


    while(inicio)
    {
        cont = 1;

        contRepXNodo=0;
        contDeNodos=0;

        while(act)
        {
            contDeNodos++;

            if(compararFinal_MIO(act->info, inicio->info)==0)
            {
                contRepXNodo++;
                cont++;
            }

           act= act->sig;
        }

        //aca obtengo el nodo mayor, y también su cantidad de apariciones
        if(cont>*max)
        {
            *max= cont;
            mayor= inicio;
        }

        //solo entra acá en el caso de, como dijimos, quedaros varios nodos,
        //pero son todos del mismo alumno, entonces no deseamos reordenar ésto
        //porque ya están ordenados
        if(contDeNodos==contRepXNodo && !act && mayor!=act && cont==*max)
        {
            mayor = NULL;   //le ponemos en NULL y en el main hacemos un return
            return mayor;
        }

        inicio = inicio->sig;

        if(inicio)
            act= inicio->sig;
    }

    return mayor;
}


tNodo * irAlInicio(tNodo * act)
{
    while(act->ant)
        act = act->ant;
    return act;
}

