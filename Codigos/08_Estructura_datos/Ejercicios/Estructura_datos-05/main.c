// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Ejemplo de la utilizacion del operador punto:
 * Este programa demuestra como acceder a los campos de una estructura
 * mediante el operador (.)
 */

#include <stdio.h>

/* Definicion de la estructura a utilizar */
struct productos
{
    int codigo, cantidad;
    float precio;
};

int main(void)
{
    /* Declaracion de variable de tipo 'struct productos'.
     * Esta variable contiene los campos:
     * - lista.codigo
     * - lista.cantidad
     * - lista.precio
     */
    struct productos lista;

    /* Asignacion de valores a los campos de la estructura utilizando el operador punto (.) */
    lista.codigo = 104;
    lista.cantidad = 5;
    lista.precio = 54.39;

    /* Impresion de los campos en pantalla */
    printf("\n%d\t%d\t%.2f$", lista.codigo, lista.cantidad, lista.precio);
        
    return 0;
}

