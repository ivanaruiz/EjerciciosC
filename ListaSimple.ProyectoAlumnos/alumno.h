#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
	int dni;
	char apyn[30];
	char materia[20];
	char codigo_nota[5]; ///PR = Promocion�, CU = Curs�, RE = Reprob�, AU = Ausente
	int nota;
}
t_alumno;


#endif // ALUMNO_H_INCLUDED
