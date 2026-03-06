// gcc -std=c11 -Wall -Wextra -pedantic main.c -o operaciones

/*
    Operaciones que admiten los punteros
    - Operador = (Asignacion entre punteros)
        Que hace?:
        - Copia la direccion de memoria, no el valor almacenado en esa direccion a la que apunta.
        - int *p1, *p2;
        - p1 = &x; Inicializa el puntero almacenando la direccion en memoria de x
        - p2 = p1; Se asigna la direccion del puntero p1 en el puntero p2, ambos apuntan a la misma direccion que almacena el tipo de dato, de este modo p1 y p2 apuntan a la misma direccion
    
    - Operadores de comparacion (==, !=, <, >, <=, >=)
        Que hace?:
        - Comparan direcciones, NO valores.
        - if(pi == p2) Si apuntan al mismo lugar se cumple el bucle
        Para comparar valores:
        - if(*p1 == *p2) Si almacenan el mismo valor en su direccion de memoria se cumple el bucle
*/

#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;

    int *p1 = &x;
    int *p2 = &y;

    /*
        Operador = Asignacion entre punteros
    */
    p2 = p1; // Ambos apuntan a la misma direccion, la de x

    printf("\n Despues de p2 = p1 los valores a los que acceden ambos punteros es:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);

    /*
        Modificacion del valor almacenado en la direccion a traves del puntero
    */
    *p1 = 50;

    printf("\nDespues de modificar *p1 el valor de x almacenado en la direccion a la que apunta es:\n");
    printf("x = %d\n", x);
    printf("*p2 = %d (p2 apunta a x)\n", *p2);

    /*
        Operadores de comparacion
    */
    if (p1 == p2)
    {
        printf("\np1 y p2 apuntan a la misma direccion\n");
    }

    return 0;
}