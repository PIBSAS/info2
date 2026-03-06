// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de vector de 10 int
     * que en expresiones decae a puntero al primer elemento.
     * Punteros a int, variable entera */
    int a[10], *pa1, *pa2, i, *pa3;

    /* Carga el vector mediante el bucle:
     * a[0] = (0 + 1) * (0 + 1) => 1
     * a[..] = ...
     * a[9] = (9 + 1) * (9 + 1) => 100 
     * Quedando el vector:
     * a[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}*/
    for (i = 0; i < 10; i++)
        a[i] = (i + 1) * (i + 1);

    /* Asignacion de la primer direccion del vector 
     * que decae a puntero en el primer elemento al puntero
     * a se convierte implicitamente en &a[0] */
    pa1 = a;

    /* Asignacion del ultimo elemento al puntero */
    pa2 = &a[9];

    /* Resta entre punteros del mismo tipo, resultado: 
     * cantidad de elementos entre ellos, pa2 - pa1 = 9 
     * el resultado es de tipo ptrdiff_t no int, pero compila,
     * mas correcto seria: 
     * #include <stddef.h>
     * ptrdiff_t i;*/
    i = pa2 - pa1;

    /* Suma de un puntero + una variable entera, asignada
     * a otro puntero del tipo int pa3 = &a[0] + 9 = &a[9] 
      * haciendo que pa3 == pa2 apunten al mismo lugar */
    pa3 = pa1 + i;
    
    return 0;
}
