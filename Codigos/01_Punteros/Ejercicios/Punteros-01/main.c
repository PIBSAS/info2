// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Comando de compilacion:
 * - -std=c11  => utiliza el estandar C11.
 * - -Wall     => activa advertencias comunes.
 * - -Wextra   => activa advertencias adicionales.
 * - -pedantic => exige cumplimiento estricto del estandar.
 * - -0 main   => genera el ejecutable llamado 'main'.
*/
#include <stdio.h>

int main(void)
{
    int i = 1; // Declarar variable de tipo int inicializada en 1
    int *pi = &i; // Declaracion de puntero a int y asignacion de direccion en memoria de la variable i del mismo tipo

    printf(" i = %d\n", i); // Mostrar variable
    printf("dir i = %p\n", &i); // Mostrar direccion en memoria de la variable, se usa el especificador %p, el cual esperra void *, el compilador indica que deberia pasarse el cast (void *)&i
    //printf("dir i = %p\n", (void *)&i);
    printf(" i = %d\n", *pi); // Mostrar el valor almacenado en la direccion del puntero, esto es desreferenciar el puntero
    printf("dir i = %p\n", pi); // Mostrar la direccion a la que apunta el puntero usando el especificador %p, el cual esperra void *, el compilador indica que deberia pasarse el cast (void *)pi
    //printf("dir i = %p\n", (void  *)pi);

    return 0;
}
