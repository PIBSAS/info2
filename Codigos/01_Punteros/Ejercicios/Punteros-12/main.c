// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de vector de 4 int, puntero a int y variable entera*/
    int V1[4], *pi, i;

    /* Asignacion al puntero de la direccion del primer elementos del vector */
    pi = &V1[0]; // Equivalente a pi = V1;

    /* Carga los valores de los elementos del vector a traves del puntero */
    for (i = 0; i < 4; i++)
        scanf("%d", pi + i); // Equivalente a &V1[i]

    /* Muestra los valores de los elementos del vector a traves del puntero(desreferenciacion) mediante aritmetica
     * pi[i] es quivalente a *(pi + i) */
    for (i = 0; i < 4; i++)
        printf("%d\t", pi[i]);

    printf("\n\n");
    
    return 0;
}
