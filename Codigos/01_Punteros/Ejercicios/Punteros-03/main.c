// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable de tipo int, y de puntero a int */
    int i;
    int *pi;

    /* Asignacion de direccion de variable a puntero del mismo tipo,
     * Asignacion indirecta: se modifica el valor de i a traves del puntero,
     * usando el operador de indireccion (desreferenciacion), i = 45 */
    pi = &i;
    *pi = 45;

    /* Mostrar el valor de la variable */
    printf("El valor que contiene i es: %d\n", i);

    /* Reasignacion directa de i, ahora *pi contiene 39*/
    i = 39;

    /* Mostrar el valor de i mediante el puntero con el operador de indireccion (desreferenciacion) */
    printf("El valor que contiene i es: %d\n", *pi);

    return 0;
}
