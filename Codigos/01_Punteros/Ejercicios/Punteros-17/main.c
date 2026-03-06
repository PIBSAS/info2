// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable entera, puntero a int, puntero a puntero a int */
    int i, *pi, **ppi;

    /* Asignacion de direcciones e inicializacion de variable,
     * Modificacion por desreferencia de la variable, de 7 a 9,
     * Modificacion por desreferencia doble de la variable, de 9 a 28,
     * ppi apunta a pi, *ppi es pi, **ppi es i */
    pi = &i;
    ppi = &pi;
    i = 7;
    *pi = 9;
    **ppi = 28;
     
    return 0;
}
