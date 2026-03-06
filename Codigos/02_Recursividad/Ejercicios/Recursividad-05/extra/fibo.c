#include "fibo.h"

/* Declaracion de funcion fibo, iterativa */
int fibo(int n)
{
    /* Declaracion de variables enteras.
     * fn1 y fn2 almacenan los dos terminos anteriores.
     * i es contador del bucle. */
    int fn1, fn2, f, i;
    
    fn1 = 1;
    fn2 = 2; // Inconsistente con la definicion recursiva

    /* Caso base: si n es 0 o 1 devuelve 1. */
    if ((n == 1) || (n == 0))
        return 1;
    /* Bucle iterativo: Calcula la sucesion sin usar recursion */
    for (i = 2; i <= n; i++)
    {
        f = fn1 + fn2;
        fn2 = fn1;
        fn1 = f;
    }

    return f;
}

/* Declaracion de funcion recursiva Fibo */
/* Problema:
 * Si n es negativo:
 * - No entra en ningun if.
 * - No retorna nada.
 * - Comportamiento indefinido (UB). */
int Fibo(int n)
{
    /* Caso recursivo:
     * Si n es mayor a 1, llama dos veces.
     * Complejidad exponencial. */
    if (n > 1)
        return Fibo(n - 1) + Fibo(n - 2);
    if ((n == 1) || (n == 0)) // Caso base si n es 0 o 1 devuelve 1
        return 1;
    
    /* Arreglo para que el compilador no se queje:
     * warning: control reaches end of non-valid function [-Wreturn-type]
     */
    return 0;
}