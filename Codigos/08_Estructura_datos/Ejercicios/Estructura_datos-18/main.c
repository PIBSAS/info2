// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Punteros a estructuras */

#include <stdio.h>

/* Declaracion de estructura */
struct A
{
    int a;
    char b;
    float c;
};

int main(void)
{
    /* Declaracion de variable tipo struct A
     * Declaracion de puntero a struct A 
     */
    struct A var, *ps;
    
    /* Asignacion de campo b de la estructura */
    var.b = 'C';
    /* Asignacion de la direccion en memoria de var al puntero ps */
    ps = &var;

    /* Asignacion a campo de estructura mediante puntero por desreferenciacion y acceso al campo por operador (.) (FORMA LARGA) */
    (*ps).c = 3.14;

    /* Asignacion mediante puntero a campo de estructura por -> (desreferencia y acceso) (FORMA CORTA) */
    ps->a = 7;
    
    /*(*ps).a equivale a ps->a */
    return 0;
}
