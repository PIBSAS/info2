// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de estructura */
struct A
{
	int a;
	char b;
	float c;
};

/* Declaracion de estructura autoreferenciada
 * Esto es la base de:
 * Listas enlazadas (Simple linked lists), arboles (tree), estructuras dinamicas
 */
struct AR
{
	int i;
	struct AR *p; // Puntero a struct AR
};

int main(void)
{
	/* Declaracion de variable tipo struct A
     * Declaracion de puntero a struct A 
     */
    struct A var, *ps;
	
	/* Variables de tipo struct AR */
	struct AR PEPE, x;

	/* Asignacion de campo b de la estructura */
	var.b = 'C';

	/* Asignacion de la direccion en memoria de var al puntero ps */
	ps = &var;

	/* Asignacion a campo de estructura mediante puntero por desreferenciacion y acceso al campo por operador (.) (FORMA LARGA)*/
	(*ps).c = 3.14;
	
	/* Asignacion mediante puntero a campo de estructura por -> (desreferencia y acceso) (FORMA CORTA) */
	ps->a = 7;
	
	/* Asignacio a campo de estructura */
	PEPE.i = 6;

	/* Asignacio a campo de estructura */
	x.i = 3;

	/* Enlace entre estructuras
	 * PEPE.p apunta a x
	 */
	PEPE.p = &x; // Asignar direccion de x a campo puntero a struct AR
	
	/* x.p apunta a si misma
	 * (estructura autoreferenciada circular)
	 */
	x.p = &x;
    
    return 0;
}
