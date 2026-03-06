// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Prototipo de funcion que recibe un puntero a int.
 * El parametro V no es un vector, es un int *. 
 * Cuando se llama con un vector, este decae a puntero a su primer elemento. */
void ingresar(int *V);

int main(void)
{
    /* Declaracion de vector de 109 enteros */
    int vec[10];

    /* Al pasar vec como argumento, el vector decae a &vec[0].
     * La funcion recibe un int * apuntando al primer elemento del vector. */
    ingresar(vec);

    return 0;
}

void ingresar(int *V)
{
    int i;

    /* Se recorre el arreglo mediante indice.
     * V es un puntero a int.
     * V + i realiza aritmetica de punteros (Equivale a &V[i]).
     * scanf recibe la direccion donde almacenar el valor. */
    for (i = 0; i < 10; i++)
        scanf("%d", V + i);
}
