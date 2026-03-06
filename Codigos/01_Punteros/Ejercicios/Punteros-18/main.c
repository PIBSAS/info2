// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable entera, puntero a int, puntero a puntero a int */
    int i, *pi, **ppi;

    /* Inicializacion de variable y asignacion de direcciones */
    i = 65;
    pi = &i;
    ppi= &pi;

    /* Modificacion del valor de i a traves de pi por desreferencia:
     * *pi es i, por lo tanto; i = i + 4, i pasa a 69*/
    *pi += 4;

    /* Modificacion del valor de i por desreferencia doble:
     * ppi => &pi
     * *ppi => pi
     * **ppi => i
     * Se asigna 1000 a i. */
    **ppi = 1000;
    
    return 0;
}
