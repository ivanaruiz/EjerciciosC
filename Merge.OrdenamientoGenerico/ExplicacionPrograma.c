
/*  Ejercicio m�o:
Este programa mezcla varios conceptos a la vez, vectores, estructuras, archivos binarios, merge entre archivos,
ordenamiento gen�rico.
Indicaciones: construir dos archivos binarios, uno llamado productos.dat y otro movimiendos.dat
En productos.dat tendremos una estructura de productos. El mismo tendr� c�digo, descripci�n, precio y
stock. E inicializamos varios productos en �l. Ejemplo: {1, "leche", 70, 50}.
En el otro archivo, usaremos el mismo struct, pero en este caso solo tendremos registros con el c�digo y el stock
(que el stock sera diferente al otro archivo). Ejemplo: {1,"",0,20}.
Ambos archivos est�n ordenados por c�digo. Esto nos da pie para hacer uso del merge. Por lo tanto debemos buscar el c�digo
de producto del primer archivo en el segundo archivo. En caso de encontrarlo, se actualiza el stock (en nuestro ejemplo
de arriba quedar�a {1, "leche", 70, 70}.
En caso de no encontrarlo, saltamos al siguiente. Pero ojo, si en el archivo de movimientos, hay un c�digo que NO est� en
productos, guardaremos ese registro en productos tambi�n. Por lo que al terminar el merge, productos.dat podr�a (o no)
tener m�s registros, ademas de actualizado algunos stocks. Tener en cuenta que los stocks no pueden quedar en negativo.
Adem�s el archivo actualizado debe quedar perfectamente ordenado.
Por �ltimo, en caso de que haya habido nuevos registros, �stos mismos tienen campos vac�os (descripci�n y precio).
Preguntar al usuario si desea modificarlos, y en caso afirmativo, actualizar nuevamente el archivo.


Mi resoluci�n: primero creo ambos archivos binarios. El de movimientos lo hago en una funci�n, pero el de productos lo
hago en el main porque luego necesito el vector creado para ese archivo. Ademas necesito saber qu� cantidad registros
tiene inicialmente mi vector. A esa cantidad la llamar� cant_ini. Y el vector ser� vec_prod.
Empiezo a hacer el merge y tambi�n all� usar� un vector (reg_nuevos) para acumular los nuevos registros, es decir,
los que figuran solo en movs.dat. Tambi�n tengo un contador para estos registros (cant_nuevos). Lo necesitar� luego.
Una vez terminado el merge, cierro el archivo de movimientos y ya no lo vuelvo a usar. Pero s� usar� productos.dat
Utilizar� una funci�n para abrir productos.dat y volcar todos los datos grabados y actualizados a un nuevo vector que
llamar� vec. Este vec tendr� una cantidad de registros total, es decir cant_ini + cant_nuevos.
No uso los dos vectores anteriores(vec_prod y reg_nuevos) ya que cada uno estaba seteado con una cantidad distinta,
y no podr� asignarle mas registros de lo que permiten. Es por eso que utilizo este nuevo vector vec y adem�s tambi�n
ordenar� en base a �l, usando m�todo de ordenamiento gen�rico con t�cnica de burbujeo.
Luego de ordenado, actualizamos el archivo.
Y finalmente preguntamos al usuario si desea completar los campos que quedaron vac�os.

Lote de juego de pruebas:
productos.dat:
                            {2, "peras", 10, 5},
                            {4, "bananas", 5, 8},
                            {5, "manzanas", 40, 20},
                            {7, "naranjas", 30, 15},
                            {8, "uvas", 50, 20},
                            {9, "paltas", 70, 12},
                            {10, "mandarinas", 35, 7},
                            {12, "frutillas", 80, 10},
                            {13, "cerezas", 20, 20},
                            {14, "damascos", 45, 15},
                            {15, "ciruelas", 30, 8}
movimientos.dat:
                            {1,"", 0,7},
                            {2,"", 0,7},
                            {5,"", 0,-10},
                            {6,"", 0,-15},
                            {8,"", 0,-5},
                            {10,"", 0,-10},
                            {11,"", 0,10},
                            {12,"", 0,5},
                            {14,"", 0,-10},
                            {16,"", 0,5},
                            {17,"", 0,5}

Otro lote:
productos:
                            {1, "LECHE", 60, 50},
                            {2, "HARINA", 40, 40},
                            {4, "ARROZ", 35, 20},
                            {5, "POLENTA", 25, 15},
                            {6, "GALLETAS", 30, 45},
                            {8, "MAYONESA", 55, 15},
                            {9, "MOSTAZA", 45, 10},
                            {10, "MANTECA", 50, 25},
                            {13, "YOGUR", 55, 20},
                            {14, "CAFE", 70, 30},
                            {16, "AZUCAR", 40, 30},
                            {17, "YERBA", 65, 20},
                            {19, "JUGO", 60, 40},
                            {20, "GASEOSA", 80, 35},

movimientos.dat:
                            {2,"", 0,20},
                            {3,"", 0,-10},
                            {5,"", 0,-20},
                            {7,"", 0,15},
                            {11,"", 0,5},
                            {12,"", 0,-30},
                            {14,"", 0,10},
                            {15,"", 0,15},
                            {17,"", 0,-15},



*/
