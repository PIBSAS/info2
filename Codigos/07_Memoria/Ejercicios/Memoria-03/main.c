// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include<stdio.h>
#include<stdlib.h>// Se usa malloc(), system()

int main(void)
{
	/* Declaracion puntero a char */
	char *p;

	/* Declaracion variable de tipo long int para acumular la cantidad de memoria reservada */
	long l;
  
	system("cls"); /* Limpia la pantalla en Windows en Linux "clear" */
	
	/* Inicializacion del contador de memoria en cero */
	l = 0;
	
	/* Bucle que intenta reservar memoria repetidamente */
	do
	{
		/* Intenta reservar 100000 bytes (aprox. 100 KB) */
		p = malloc(100000);

		/* Si la reserva fue exitosa (p != NULL) */
		if (p)
			l += 100000; /* Suma el total de memoria */
	}
	while (p); /* Continua hasta que malloc falle (devuelva NULL) */
	
	/* Muestra cuanta memoria se pudo reservar en total*/
	printf("tiene %ld bytes de memoria\n", l);
  
	return 0;
}