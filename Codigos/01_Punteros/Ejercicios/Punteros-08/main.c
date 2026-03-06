// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    int i, *pi;
    float j, *pj;
    char k, *pk;

    /* Asignacion de variables y direcciones a punteros segun su tipo */
    i = 1000;
    pi = &i;

    j = 3.18;
    pj = &j;

    k = 'c';
    pk = &k;

    /*Mostrar valores y direcciones, %p espera el cast a vopid * */
    printf("\n%d\t%p\t%f\t%p\t%c\t%p\n", i, pi, j, pj, k, pk);

    /* Se reutiliza la variable i como contador del bucle,
     * perdiendo el valor original (1000).
     * Los punteros se incrementan pero
     * La aritmetica de punteros solo esta definida dentro de un mismo vector
     * (o one-past-the-end).
     * Como aca apuntan a variables individuales y no a un vector,
     * los incrementos producen comportamiento indefinido (UB). */
    for (i = 5; i < 6; i++, pi++, pj++, pk++)
    {
        printf("\n%d\t%p\t%f\t%p\t%c\t%p\n", i, pi, j, pj, k, pk); // Se muestran variables y direcciones sin cast a void *
        /* Se desreferencian mediante el operador de indireccion * los punteros que ya fueron desplazados
        * fuera de un objeto valido. Esto produce comportamiento indefinido (UB) 
        * y puede provocar lectura de memoria invalida. */
        printf("\n%d\t%p\t%f\t%p\t%c\t%p\n", *pi, pi, *pj, pj, *pk, pk);
    }

    printf("\n\n");

    return 0;
}
