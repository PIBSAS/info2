// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    float *p, *q;
    int a;

    /* Asignacion de valores enteros a punteros.
     * Estas direcciones son arbitrarias y no 
     * corresponden a objetos reales en memoria. */
    p = 0x2000;
    q = 0x200a;

    /* La resta de punteros solo esta definida cuando ambos
    * apuntan a elementos del mismo vector (o one-past-the-end).
    * En este caso no apuntan a un vector valido, por lo tanto
    * la operacion produce comportamiento indefinido (UB). 
    * Si la operacion estuviera definida, el resultado de la resta
    * representa la cantidad de elementos de tipo float entre
    * ambas direcciones (segun el modelo del lenguaje).
    * La resta de punteros devuelve un valor de tipo ptrdiff_t */
    a = q-p;

    printf("\n%d %p %p\n\n", a, p, q);
    
    return 0;
}
