// gcc -std=c11 -Wall -Wextra -pedantic main.c -o operadores
/*
    Operadores de punteros:
    - Operador & (Direccionamiento:address-of)
        Que hace?:
        - Obtiene la direccion de memoria de una variable
        - int x;
        - int *pi = &x;
        - x: valor
        - &x: direccion de x
        - int *: tipo de dato de &x
        Se usa para:
        - Inicializar punteros.
        - Pasar variables a funciones.
        - scanf.
        
    - Operador * (Desreferenciacion:Indireccion:object-of)
        Que hace?:
        - Accede al valor almacenado en la direccion a la que apunta el puntero.
        - int x = 10;
        - int *pi = &x;
        - printf("%d", *pi); Muestra 10
        - pi: direccion de x.
        - *pi: valor almacenado en esa direccion
        - Usar * sobre un puntero no inicializado da un comportamiento indefinido-Undefined Behaviour (UB)
*/

#include <stdio.h>
int main(void)
{
    int x = 10;
    int y = 20;

    /*
        Operador & address-of
    */
    int *p1 = &x;
    int *p2 = &y;

    printf("Valores iniciales:\n");
    printf("x = %d, y = %d\n", x, y);

    /*
        Operador * Desrefenciacion, object-of
    */
    printf("\nAcceso mediante punteros a los valores almacenados en la direccion apuntada:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);

    return 0;
}