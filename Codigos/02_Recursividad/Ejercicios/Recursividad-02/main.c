// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
/*
    Caso base mal hecho
*/
#include <stdio.h>

/* Declaracion variable global.
 * Tiene almacenamiento estatico.
 * Se inicializa en 0 si el usuario no ingresa nada válido. */
int g;

/* Prototipo de funcion recursiva */
int fun(int);

int main(void)
{
    /* Declaracion de variable entera y asignacion de un entero.
     * Vive en el stack de main */
    int i;
    i = 5;
    
    /* Se lee un valor para la variable global g, pero no es utilizada. */
    scanf("%d", &g);

    /* Asigna a la variable lo que devuelva la funcion recursiva, pasando como argumento (5 * 3).
     * Esta es la primera llamada recursiva. */
    i = fun(i * 3);

    /* Mostrar el valor de la variable i*/
    printf("\n%d\n", i);

    return 0;
}

/* Definicion de la funcion recursiva
 * Recibe como argumento una variable entera.
 * Cada llamada crea:
 * - Su propia copia de j.
 * - Su propia variable entera k. La cual retorna. */
int fun(int j)
{
    int k;
    
    j++;

    /* Caso recursivo si j es menor que 20, se vuelve a llamar a fun*/
    if (j < 20)
        k = fun(j);

    /* Problema grave:
     * Si j es mayor o igual a 20, k queda sin inicializar
     * se retorna basura, comportamiento indefinido (UB).
     * No existe un caso base explicito con return definido.
     * TODA funcion recursiva debe tene un caso base claro que retorne un valor valido. */
    return k;
}