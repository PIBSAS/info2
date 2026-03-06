// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de un vector de 4 int, 
     * puntero a int y variable int */
    int V1[4], *pi, i;

    /* Asignacion al puntero de la direccion del primer elemento del vector.
     * V1 en una expresion decae a puntero a su primer elemento,
     * por lo que tambien podria escribirse: pi = V1; */
    pi = &V1[0];
    
    /* Intentar hacer aritmetica sobre el nombre del vector es incorrecto */
    for (i = 0; i < 4; i++)
        /* V1 es un vector, no es modificable, 
         * no es un puntero variable, 
         * no es un lvalue modificable, 
         * Aunque en expresiones V1 decae a int *, 
         * esa conversion produce un valor temporal,
         * no convierte a V1 en una variable puntero al cual hacerle aritmetica.
         * El compilador nos indica:
         * error: lvalue required as increment operand 
         * En cambio si usamos el puntero declarado y 
         * hacemos pi++; Compila sin error ni advertencias de que no se uso pi! */
        V1++; // NO 
        //pi++;
    
    /* Carga de los elementos del vector.
     * &V1[i] es la direccion del elemento i. */
    for (i = 0; i < 4; i++)
        scanf("%d", &V1[i]);

    /* Acceso a los elementos mediante aritmetica de punteros.
     * V1 decae a int *, por lo que:
     * *(v1 + i) es equivalente a V1[i] */
    for (i = 0; i < 4; i++)
        printf("%d\t", *(V1 + i));
    
    return 0;
}
