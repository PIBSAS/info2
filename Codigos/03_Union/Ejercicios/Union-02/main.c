// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Declaracion de union 
 * Al compartir la misma region en memoria
 * La dimension de la union sera la del miembro mas grande.
 */
union Gamma
{
    int A;
    char B[4];
    float C;
};

int main(void)
{
    /* Declaracion de variable de tipo union Gamma*/
    union Gamma Ug;

    /* Asignacion de campos de la union */
    Ug.C = 27.892E-5; // A partir de aqui, el unico miembro valido es C.
    Ug.B[2]++; // El valor de C deja de ser valido por el incremento de B.
    /* El valor valor de B deja de ser valido, 
     * A tambien comparte memoria con los otros miembros.
     * Esta operacion interpreta los mismos bytes ahora como si fueran un int.
     * Esto constituye comportamiento indefinido segun el estandar,
     * ya que se esta leyendo un miembro distinto al ultimo escrito.
     * El resultado depende de la arquitectura,
     * representacion interna (IEEE 754), y endianness del sistema.
     */
    Ug.A *= 2;  
    
    return 0;
}
