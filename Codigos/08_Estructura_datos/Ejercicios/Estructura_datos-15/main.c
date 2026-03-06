// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Definicion de estructuras y variables globales */
struct alumno
{
	int legajo;
	float promedio;
}ALUMNO;

struct fecha
{
	int dia,mes,anio;
}fechanac;

/* Declaracion de estructura */
struct fe
{
	int dia,mes,anio;
};

int main(void)
{
	/* Variable local de tipo struct alumno y de tipo struct fecha inicializada y de tipo struct fe */
    struct alumno Alumej;
	struct fecha FecIng = {9,7,1816}, fech;
	struct fe FF;

	/* Asignacion de campos de la estructura */
	fechanac.dia = 27;
	fechanac.mes = 4;
	fechanac.anio = 2009;

	/* Copia todos los campos de FecIng a fech */
	fech = FecIng;

	/* Copia de un campo individual */
	FF.dia = fech.dia;
    
    return 0;
}
