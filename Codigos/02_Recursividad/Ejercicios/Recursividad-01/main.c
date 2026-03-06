// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
/*
Recursion infinita
- no existe caso base (condicion de corte), por lo tanto
el problema no se resolvera, provocando un desbordamiento de la pila (stack overflow)

El compilador nos advierte:
- infinite recursion detected [-Winfinite-recursion]
- note: f(i + 1) recursive call
*/
#include <stdio.h>

int f(int);

int main(void)
{
    int i;
    i = f(3);

    printf("\ni = %d\n", i);

    return 0;
}

// Función recursiva sin caso base. Carece de condición de corte.
int f(int i)
{
    printf("\ni = %d\n", i);
    i = f(i+1); // Caso recursivo

    return i;
}