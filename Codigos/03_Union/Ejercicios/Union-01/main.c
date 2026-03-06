// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de estructura 
 * Cada miembro posee su propia region en memoria.
 * Los campos pueden utilizarse simultaneamente. 
 */
struct Beta
{
    int A;
    char B;
};

/* Declaracion de union 
 * Todos los miembros comparten la misma region de memoria.
 * Solo uno de los campos puede considerarse valido a la vez.
 */
union Alfa
{
    int A; 
    char B;
};

int main(void)
{
    /* Declaracion de variables tipo union Alfa y struct Beta*/
    union Alfa Ua;
    struct Beta Sb;

    /* Asignaciones de los campos de la estructura */
    Sb.A = 297;
    Sb.B = 'K';

    /* Asignacion de los campos de la union, 
     * como comparten la memoria, al declararse B, deja de ser valido A,
     * Tras esto el unico campo valido es B, 
     * Leer Ua.A luego de esta linea implicaria comportamiento indefinido (UB). */
    Ua.A = 297;
    Ua.B = 'K';
    
    return 0;
}
