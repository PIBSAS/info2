// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de una estructura con campos de bits basados en unsigned int,
 * El comportamiento ante overflow en campos unsigned es aritmetica modular (wrap-around), 
 * es decir, al superar maximo vuelven a cero.
  */
struct CB
{
    unsigned int A : 3; // Puede almacenar valores de 0 a 7
    unsigned int B : 1; // Puede almacenar valores de 0 a 1
    unsigned int C : 2; // Puede almacenar valores de 0 a 3
};

int main(void)
{
    /* Declaracion de una variable de tipo struct CB y una variable auxiliar para el bucle */
    struct CB bit;
    int i;

    /* Inicializacion de los campos de bits de la estructura, se podria reducir con struct CB bit = {0}; */
    bit.A = 0;
    bit.B = 0;
    bit.C = 0;

    /* Bucle que se ejcuta 10 veces.
     * En cada iteracion se incrementan los tres campos de bits.
     * Debido a la cantidad limitada de bits:
     * - A (3 bits) desborda al superar 7
     * - B (1 bit) alterna entre 0 y 1
     * - C (2 bits) desborda al superar 3
     * El desbordamiento (overflow) en tipos unsigned produce wrap-around (al superar el maximo vuelve a cero)
     */
    for(i = 0; i < 10; i++)
    {
        bit.A++; // 3 bits = 2^n - 1 = 7. 0 => 1 => 2 => 3 => 4 => 5 => 6 => 7 => 0 => 1 => 2
        bit.B++; // 1 bit  = 2^n - 1 = 1. 0 => 1 => 0 => 1 => 0 => 1 => 0 => 1 => 0 => 1 => 0
        bit.C++; // 2 bits = 2^n - 1 = 3. 0 => 1 => 2 => 3 => 0 => 1 => 2 => 3 => 0 => 1 => 2
    }

    /* El programa original no hace nada mas, podria imprimirse los valores finales de los campos y la dimension en memoria de la estructura */
    printf("A = %u\n", bit.A);
    printf("B = %u\n", bit.B);
    printf("C = %u\n", bit.C);
    printf("Dimension del struct = %zu\n", sizeof(struct CB));

    return 0;
}
