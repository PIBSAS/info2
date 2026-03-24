// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Comando de compilacion:
 * - -std=c11  => utiliza el estandar C11.
 * - -Wall     => activa advertencias comunes.
 * - -Wextra   => activa advertencias adicionales.
 * - -pedantic => exige cumplimiento estricto del estandar.
 * - -0 main   => genera el ejecutable llamado 'main'.
*/

#include <stdlib.h> // Se usa malloc(), free(), exit(), system()
#include <stdio.h>  // Se usa printf(), scanf()
#include <conio.h> // Se usa getch()

int main(void)
{
	/* Declaracion de puntero a int */
	int *p;

  	system("cls"); /* Limpia la pantalla en Windows en Linux "clear" */

	/* Reserva memoria dinamica para un entero */
	p = malloc(sizeof(int));
	
	/* Verifica si malloc fallo (No hay memoria disponible) */
	if (!p)
	{
		printf("\nNo hay memoria suficiente");
		printf("\nPresione una tecla para continuar");
		getch(); /* Espera que se presione una tecla */
		exit(1); /* Finaliza inmediatamente el programa */
	}
	else
	{
		/* Muestra el contenido de la memoria recien reservada */
		printf("\n\nEl valor existente en la direccion %p es %d", p, *p); // %p espera un puntero a void (void *), cambiar p a (void *)p

		/* Pide al usuario que ingrese un valor entero */
		printf("\nIngrese un valor entero ");
		/* Guarda el valor ingresado directamente en la direccion apuntada por p */
		scanf("%d", p);
	}
	/* Muestra el valor que el usuario ingreso */
	printf("\n\nEl valor ingresado en la direccion %p es %d", p, *p); // %p espera un puntero a void (void *), cambiar p a (void *)p
  
	/* Libera la memoria reservada */
	free(p);
	
	return 0;
}