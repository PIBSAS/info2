// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

#define n 5

int main(void)
{
    /* Declaracion de vector 5 int, punteros a int y variable entera */
    int vec[n], *p, *max, i;

    /* Asigna la direcion del primer elemento del vector al puntero,
     * mientras p sea menor que vec + n (puntero one-past-the-end),
     * Se realiza aritmetmetica con el puntero para recorrer el vector.
     * Carga los elementos del vector mediante el puntero */
    for (p = vec; p < vec + n; p++)
        scanf("%d", p);

    /* Inicializacion: p y max apuntan al primer elemento., inicializacion de variable entera para iterar,
     * Se recorre el arreglo usando indice.
     * Si el valor apuntado por (p + i) es mayor que el apuntado por max,
     * se actualiza max para que apunte al nuevo mayor. */
    for (max = p = vec, i = 0; i < n; i++)
        if (*(p + i) > *max)
            max = p + i;
    
    /* Mostrar el valor almacenado en max que es el mayor de p por dereferencia.
     * Resta entre vectores devuielve ptrdiff_t, lo correcto seria usar el especificador %td, y agregar <stddef.h>
     * pero en la cursada no se sigue ese estandar, pero veremos que el compilador nos lo indica como warning al compilar. */
    printf("\n\nmax = %d", *max);
    printf("\npos = %d\n", max - vec);
    //printf("\npos = %td\n", max - vec); //Puede usarse %lld
    
    return 0;
}
