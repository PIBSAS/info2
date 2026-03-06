//gcc -std=c11 -Wall -Wextra -pedantic main.c fibo.c -o main

/*
    Extra:
    Forma profesional de organizar un proyecto en C
    - fibo.h => Declara las funciones (interfaz)
    - fibo.c => Define las funciones (implementacion)
    - main.c => Prgrama principal que utiliza la interfaz
    - Makefile => Compilacion y enlazado del proyecto.
*/
#include <stdio.h>
#include "fibo.h"

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