// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de estructura */
struct B
{
	int i;
	float *pf;
};

/* Declaracion de estructura autoreferenciada */
struct C
{
	int i;
	char c;
	struct C *sig; // Puntero a otra estructura C (permite encadenarlar => base de listas enlazadas)
};

int main(void)
{
	/* Declaracion de variable tipo struct B y tipo float y dos tipo struct C */
    struct B e2;
	float f;
	struct C ar1, ar2;
	
	/* Asignacion de la direccion de f, Ahora pf apunta a f */
	e2.pf = &f;

	/* Desreferenciacion del puntero y asignacion del valor, entonces f = 2.46 */
	*(e2.pf) = 2.46;

	/* Encadenamos estructuras tipo C
	 * ar1.sig apunta a ar2
	 * ar2.sig apunta a si misma
	 * Esto genera una autoreferencia.
	 * Es valido, pero puede producir bucles infinitos si se recorre sin condicion de corte.
	 */
	ar1.sig = &ar2;
	ar2.sig = &ar2;

	/* Acceso enlazado:
	 * ar1.sig apunta a ar2, entonces ar1.sig->c modifica ar2.c
	 */
	ar1.sig->c = 'X';

    return 0;
}
