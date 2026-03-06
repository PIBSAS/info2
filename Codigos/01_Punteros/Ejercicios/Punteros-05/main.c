// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variables enteras y punteros a int */
    int x, *pi, *pf, y, h;

    /* Declaracion de punteros a char */
    char *pc, *pd;

    /* Declaracion de variables float y punteros a float */
    float k, l, *pj, *pk;

    /* Asignacion de direcciones a punteros del mismo tipo */
    pi = &x;
    pf = &y;

    /* Resta de punteros a int.
     * La resta de punteros solo esta definida si ambos apuntan 
     * a elementos del mismo vector (o uno mas alla del final).
     * En este caso x e y no forman un vector (array), por lo tanto
     * el resultado es comportamiento indefinido (UB) */
    y = pf - pi;
    
    pj = &l;
    pk = &k;

    /* Resta de punteros a float.
     * Nuevamente, k y l no pertenecen al mismo vector (array),
     * por lo tanto la operacion produce comportamiento indefinido (UB). */
    x = pj - pk;

    /* Asignacion entre punteros de tipos incompatibles.
     * int* y float* son tipos distintos. 
     * Esto genera una advertencia del compilador.
     * Si luego se dereferencian puede producir comportamiento indefinido (UB). */
    pi = pj;
    pf = pk;

    /* Aunque ahora ambos son int*, originalmente apuntaban
     * a objetos float. La resta sigue siendo invalida porque
     * no pertenecen al mismo vector (array). Produce comportamiento indefinido (UB). */
    y = pi -pf;

    /*Asignacion de punteros float* a punteros char*.
     * Tipos incompatibles. Genera advertencia.
     * No es una conversion segura. */
    pc = pj;
    pd = pk;

    /* Resta de punteros char*.
     * Aunque la unidad de desplazamiento es 1 byte,
     * la operacion sigue siendo indefinida porque
     * no apuntan al mismo vector (array). */
    h = pc - pd;

    return 0;
}
