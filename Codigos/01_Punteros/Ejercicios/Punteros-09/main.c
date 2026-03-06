// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    int *pi, *pj;
    int i, j;

    pi = &i;
    pj = &j;

    /* La comparacion relacional (<, >, <=, >=) entre punteros solo esta definida:
    * Cuando ambos apuntan a elementos del mismo vector (o one-past-the-end)
    * En este caso apuntan a diferentes variables,
    * por lo tanto el comportamiento es indefinido (UB). */
    if (pi > pj)
        printf("\npi es mayor a pj\n");
    else
        printf("\npi es menor a pj\n");

    /* Esta comparacion (== y !=) entre punteros es valida
     * siempre que los tipos sean compatibles.
     * No requiere que apunten al mismo vector.
     * En este caso la condicion es verdadera porque
     * pi fue inicializado con &i. */
    if (pi == &i)
        printf("\npi es igual a &i\n");
    else
        printf("\npi no es igual a &i\n");
    /* Comparacion entre puntero y entero distinto de 0.
     * El estandar solo garantiza la conversion implicita
     * del entero 0 a puntero nulo.
     * Esta comparacion no esta definida por el lenguaje
     * y puede generar diagnostici del compilador. */
    if (pi > 0x300)
        printf("\npi apunta a una direccion mayor a 0x300\n");
    else
        printf("\npi apunta a una direccion menoir a 0x300\n");
    
    return 0;
}
