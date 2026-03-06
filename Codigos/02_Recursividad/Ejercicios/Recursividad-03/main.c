// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
/*
    Recursion correcta (factorial)
*/
#include <stdio.h>

/* Prototipo de funcion recursiva */
long int fact(int);

int main(void)
{
    /* Declaracion de variables */
    int x;
    long int f;

    /* Lectura de valor de x, sin validacion de la entrada del usuario */
    scanf("%d", &x);

    /*Asignacion de variable long int,
     * De lo que devuelva la llamada a la funcion,
     * a la que se le pasa el valor de x leido anteiormente. 
     * Primer llamada a funcion recursiva. */
    f = fact(x);

    /* Mostrar el valor ingresado a la funcion y el valor devuelto por ella, usando los especificadores correspondientes:
     * %d para int.
     * %ld para long int. */
    printf("\n%d\t%ld", x, f);

    return 0;
}

/* Declaracion de la funcion recursiva:
 * Recibe parametro por valor de tipo int (Cada llamada tiene su propia copia).
 * Devuelve F de tipo long int. */
long int fact(int n)
{
    /* Declaracion variable local y asignacion. Caso base implicito.
     * Si n es menor e igual a 1 el bucle no se cumple pero la funcion devuelve F = 1. */
    long int F = 1;

    /* Caso recursivo:
     * Si n es mayor que 1
     * Se multiplica n por el factorial de (n - 1).*/
    if (n > 1)
        F = n * fact(n - 1);
    
    return F;
}
