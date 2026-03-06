// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable i de tipo int, y de los punteros *pi, *pj del mismo tipo, lo mismo para char y float */
    int i, *pi, *pj;
    char c, *pc;
    float f, *pf;

    /* Asignacion de la direccion en memoria de las variables i, c, f a sus correspondientes punteros del mismo tipo */
    pi = &i;
    pc = &c;
    pf = &f;

    /* Mostrar la direccion de las variables y el contenido almacenado en los punteros,
     * el especificador %p espera el cast a void * segun nos advierte el compilador (void*)&variable y (void *)puntero */
    printf("\nLa direccion de i es: %p\nEl contenido de pi es: %p\n", &i, pi);
    printf("\nLa direccion de c es: %p\nEl contenido de pc es: %p\n", &c, pc);
    printf("\nLa direccion de f es: %p\nEl contenido de pf es: %p\n", &f, pf);

    /* Asignacion de un puntero a otro, se copia su direccion no el contenido, observar que ambos son del mismo tipo */
    pj = pi;

    /* Nuevamente mostrar direccion y contenido sin cast a void * de i, pi, pj que ahora tiene el contenido de pi */
    printf("\nLa direccion de i es: %p\nEl contenido de pi es: %p\n", &i, pi);
    printf("\nEl contenido de pj es: %p\n", pj);
    
    /* Asignacion de direccion ficticia al puntero pc, es erroneo, no se sabe si la direccion existe ni cual
     * es su contenido y asignacion de valor entero como direccion al puntero pf, deberia ser una direccion de un float*/
    pc = 0x7A34; // Es INCORRECTO, asignacion invalida de direccion (peligroso). Si se dereferencia produce comportamiento indefinido (UB).
    pf = 567; // Es INCORRECTO, asignacion invalida de direccion (peligroso). Si se dereferencia produce comportamiento indefinido (UB).

    /* Mostrar la nueva direccion almacenada en pc que cambio su direccion,
     * Mostrar el contenido del puntero pf que ahora se le asigno un entero, 
     * el compilador advertira el tipo de dato incorrecto.
     * Ahora continen valores invalidos (direcciones arbitrarias) */
    printf("\nEl contenido de pc es: %p\nEl contenido de pf es: %p\n",pc, pf);

    return 0;
}
