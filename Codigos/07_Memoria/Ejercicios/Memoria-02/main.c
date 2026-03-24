// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include<stdio.h> // Se usa printf(), scanf()
#include<stdlib.h> // Se usa malloc(), free(), exit(), system(), getchar()

int main(void)
{
	/* Declaracion de puntero a int */
	int *p;
    
	system("cls"); /* Limpia la pantalla en Windows en Linux "clear" */
	
	/* Reserva memoria dinamica para un entero y verifica si fallo */
	if (!(p = malloc(sizeof(int))))
	{
		printf("\nNo hay memoria suficiente");
		printf("\nPresione una tecla para continuar");
        getchar(); /* Espera entrada del usuario */
		exit(1); /* Finaliza inmediatamente el programa */
	}

	/* Muestra el valor que hay en la memoria recien reservada */
	printf("\n\nEl valor existente en la direccion %p es %d", (void *)p, *p); // %p espera un puntero a void (void *), cambiar p a (void *)p
	
	/* Solicita al usuario quue ingrese un numero entero */
	printf("\nIngrese un valor entero ");
	/* Guarda el valor ingresado directamente en la direccion apuntada por p */
	scanf("%d", p);

	/* Muestra el valor que el usuario ingreso */
	printf("\n\nEl valor existente en la direccion %p es %d", (void *)p, *p); // %p espera un puntero a void (void *), cambiar p a (void *)p
	
	/* Libera la memoria reservada */
	free(p);

	/* ERROR logico:
	 * Se esta accediendo a memoria ya liberada (dangling pointer)
	 * Esto produce comportamiento indefinido (UB)
	 */
	printf("\n\nEl valor existente en la direccion %p es %d", (void *)p, *p);
	
	return 0;
}
