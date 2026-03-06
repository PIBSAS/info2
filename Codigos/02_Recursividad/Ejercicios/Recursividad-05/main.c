// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/*
    Comparacion recursion vs iteracion
*/
#include <stdio.h>
#include <conio.h> // No se usa nada de la biblioteca, deberia eliminarse.

/* Prototipo de funciones recursivas */
int fibo(int n); // Iterativa
int Fibo(int n); // Recursiva

int main(void)
{
    /* Declaracion de variables enteras sin inicializar */
    int n, fi, fr;
    
    /* Lectura del valor de n sin validar */
    scanf("%d", &n);

    /* Primer llamada a ambas funciones, parametro por valor, lo que devuelve se almacena en variables enteras */
    fi = fibo(n);
    fr = Fibo(n);

    /* Mostrar los valores que devolvieron las funciones */
    printf("\n\n%d\t\t%d\n", fi, fr);

    return 0;
}

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
}