// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa malloc(), system()

int main(void)
{
	system("cls"); /* Limpia la pantalla en Windows en Linux "clear" */
	
	/* Muestra la dimension en bytes de distintos tipos de datos
	 * sizeof devuelve la cantidad de memoria que ocupa cada tipo
	 */
	printf("char %d\nint %d\nfloat %d", sizeof(char), sizeof(int), sizeof(float)); // sizeof devuelve long long unsigned int usar el especificado %zu en lugar de %d
	
	/* Reserva memoria para un char y muestra la direccion asignada
	 * malloc devuelve un puntero a la memoria reservada
	 */
	printf("\n%p", malloc(sizeof(char)));
	
	/* Reserva memoria para un int y muestra la direccion */
	printf("\n%p", malloc(sizeof(int)));
	
	/* Reserva memoria para un flot y muestra la direccion */
	printf("\n%p", malloc(sizeof(float)));
	
	return 0;
}