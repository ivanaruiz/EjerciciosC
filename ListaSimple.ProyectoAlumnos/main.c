#include "lista.h"
#include "alumno.h"

int comparar_dni(const void * a1, const void * a2);
int comparar_materia(const void * a1, const void * a2);


/*Primero cargamos una lista de alumnos y mostramos la lista y cantidad de registros.
Cada alumno tiene nota del primer parcial (P1) y nota del segundo parcial (P2) de una
misma materia.
(Aclaraci�n: puede haber alumnos que tengan m�s materias).
En actualizar_lista debemos aunar los datos de P1 y P2 de cada alumno, y sacar promedio
de las dos notas. Tambi�n debe actualizarse el c�digo de materia.
Los c�digos son: PR, de "promocion�", en caso de que la nota final sea >=7
Si alguna de las notas es 0, se considera ausente, entonces queda como AU.
Si la nota final queda entre 1 y 3, es RE de "recursar".
Y entre 4 y 6, es CU de "curs�".
Tener en cuenta que si un parcial es <4 y el otro es >=4, entonces no se promedia
y la nota final es 3.
De los dos registros de cada alumno, solo debe quedar uno. Por tanto uno de los nodos
se elimina (el segundo).
Tambi�n devolvemos la cantidad de registros que quedaron (deber�a quedar la mitad).
Luego procedemos a ordenar la lista seg�n dni de manera ascendente y haciendo uso
del m�todo de burbujeo.
Por �ltimo podemos contar cu�ntos alumnos hay realmente, ya que puede haber alg�n alumno
que haya cursado m�s materias, entonces tendr�a m�s registros. */

int main()
{
    t_lista pl;
    crear_lista(&pl);

    int cant_reg = cargar_lista(&pl);


    printf("--Lista de alumnos--\n");
    cant_reg = mostrar_lista(&pl);
    printf("\nCantidad de registros: %d\n", cant_reg);


    printf("\n--Lista actualizada--\n");
    cant_reg = actualizar_lista(&pl, comparar_dni, comparar_materia);


    system("pause");
    mostrar_lista(&pl);
    printf("\nCantidad de registros: %d\n", cant_reg);

    ordenar_lista_burbujeo(&pl, comparar_dni, cant_reg);

    puts("");
    printf("\n--Lista ordenada por dni--\n");
    mostrar_lista(&pl);


    puts("");
    system("pause");
    return 0;
}


int comparar_dni(const void * a1, const void * a2)
{
    const t_alumno * alu1 = (const t_alumno*)a1;
    const t_alumno * alu2 = (const t_alumno*)a2;

    return alu1->dni - alu2->dni;
}


int comparar_materia(const void * a1, const void * a2)
{
    const t_alumno * alu1 = (const t_alumno*)a1;
    const t_alumno * alu2 = (const t_alumno*)a2;

    return strcmpi(alu1->materia, alu2->materia);
}

