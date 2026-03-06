// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de estructura */
struct A
{
	int i;
	char c[10];
};

int main(void)
{
	/* Declaracion de variable y puntero a struct A */
    struct A e1, *pe1;
	int i;
	
	/* Asignacion de campo de estructura */
    e1.i = 22;
	
	/* Carga del vector con valores consecutivos:
	 * 'A', 'B', ... hasta 10 elementos.
	 */
    for (i = 0; i < 10; i++)
		e1.c[i] = 'A' + i;
	
	/* Asignacion de la direccion de e1 al puntero */
    pe1 = &e1;

	/* Asignacion de campo de estructura mediante puntero (desreferenciacion, forma larga) */
	(*pe1).i = 29; // e1.i cambia de 22 a 29

	/* Asignacion de campo (4) de estructura mediante puntero (forma corta) */
	pe1->c[4] = '#'; // 'E' cambia a '#'

    return 0;
}
