// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variables de tipo char (8 bits) */
    char A, B, C, D, E, F;

    /* Asignacion de valores hexadecimales:
     * 0xAC = 1010 1100
     * 0x69 = 0110 1001
     */
    A = 0xAC;
    B = 0x69;

    /* OR bit a bit (|)
     * A | B = C
     * 1 | 0 = 1
     * 0 | 1 = 1
     * 1 | 1 = 1
     * 0 | 0 = 0
     *
     *   1010 1100
     * | 0110 1001
     * -----------
     * 1110 1101 = 0xED
     */
    C = A | B;

    /* AND bit a bit (&)
     * A | B = C
     * 1 | 0 = 0
     * 0 | 1 = 0
     * 1 | 1 = 1
     * 0 | 0 = 0
     *
     * 1 & 1 = 1
     * Cualquier otro caso = 0
     *
     *   1010 1100
     * & 0110 1001
     * -----------
     *   0010 1000 = 0x28
     */
    D = A & B;

    /* XOR bit a bit (^)
     * A | B = C
     * 1 | 0 = 1
     * 0 | 1 = 1
     * 1 | 1 = 0
     * 0 | 0 = 0
     *
     *   1010 1100
     * ^ 0110 1001
     * -----------
     *   1100 0101 = 0xC5
     */
    E = A ^ B;

    /* Not (~) Invierte todos los bits:
     * A | F(~A)
     * 1 | 0
     * 0 | 1
     * 1 | 0
     * 0 | 1
     * 
     * A  = 1010 1100
     * ~A = 0101 0011 = 0x53
     */
    F = ~A;

    /* En esta linea se pisa el valor anterior de F.
     * A & 0x40
     * 0x40 = 0100 0000
     *
     * Esto es una MASCARA para aislar el bit 6 (contando desde 0: bit 0 es el menos significativo).
     *
     *   1010 1100
     * & 0100 0000
     * -----------
     *   0000 0000 => En este caso da 0
     *
     * Sirve para verificar si ese bit esta en 1.
     */
    F = A & 0x40;

    /* Lo mismo pero aplicado a B:
     *
     *   0110 1001
     * & 0100 0000
     * -----------
     *   0100 0000 => distinto de 0
     * Entonces el bit 6 de B esta en 1.
     */
    E = B & 0x40;
    
    return 0;
}
