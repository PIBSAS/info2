// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable y puntero del mismo tipo */
    int i;
    int *pi;

    /* Mostrar la direccion de i, el compilador espera el cast a void * para el especificador %p */
    printf("La direccion de i es: %p\n", &i);

    /* Asignacion de la direccion de i al puntero del mismo tipo */
    pi = &i;

    /* Mostrar la direccion de i mediante el puntero, el compilador espera el cast a void * para el especificador %p */
    printf("\nLa direccion de i es: %p\n", pi);

    return 0;
}
