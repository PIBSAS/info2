// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de estructura*/
struct fecha
{
    int dia, mes, anio;
};

/* Declaracion de estructura con un campo estructura (estructura de estructura) */
struct persona
{
    int legajo;
    long dni;
    struct fecha nacimiento;
};

int main(void)
{
    /* Declaracion de variable tipo struct persona */
    struct persona P;

    /* Declaracion de variable tipo struct fecha inicializada */
    struct fecha f = {10, 8, 2010};

    /* Asignacion de campos a estructura */
    P.legajo = 2398;
    P.dni = 19265989;
    
    /* Asignacion directa entre estructuras del mismo tipo
     * Como P y f son ambos de tipo struct fecha,
     * se permite asignacion completa.
     * Copia:
     * - dia
     * - mes
     * - anio
     */
    P.nacimiento = f;
    
    return 0;
}
