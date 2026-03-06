// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getch();
#include <stdlib.h> // Se usa system("cls");

/* Declaracion de estructuras con miembros campos de bits
 * basados en unsigned char.
 *
 * El rango de cada campo depende de la cantidad de bits
 * El valor maximo representable es 2^n -1 donde n es la cantidad de bits.
 * - 1 bit  => 0 a 1
 * - 2 bits => 0 a 3
 * - 3 bits => 0 a 7
 */
struct alfa
{
    unsigned char A:1;
    unsigned char B:2;
    unsigned char C:3;
};

struct beta
{
    unsigned char A:3;
    unsigned char B:2;
    unsigned char C:1;
};

struct gamma
{
    unsigned char A:5; // 0 a 31
    unsigned char B:2;
    unsigned char C:3;
    unsigned char D:4; // 0 a 15
};

/* Declaracion de union cuyos miembros son estructuras con campos de bits y un vector de 2 bytes
 * Todos los miembros comparten la misma region de memoria.
 * La dimension de la union sera la del miembro mas grande.
 */
union delta
{
    struct alfa D;
    struct beta E;
    struct gamma F;
    char G[2];
};

int main(void)
{
    /* Declaracion de variable auxiliar char para control de bucles, variable de tipo struct alfa y de tipo union delta */
    char a;
    struct alfa b;
    union delta e;

    /* Limpiar pantalla */
    system("CLS");

    /* Se inicializa el campo de bit A en 0 y se lo incrementa 4 veces.
     * Como A tiene 1 bit, opera modulo 2 (0 y 1)
     * Se observa el comportamiento de la aritmetica modular (wrap-around) 
     */
    for (b.A = 0, a = 0; a < 4; b.A++, a++)
    {
        printf("%d   ", b.A);
        printf("\n");
    }

    /* Se inicializa el campo de bit B en 0 y se lo incrementa 8 veces.
     * Como B tiene 2 bits, opera modulo 4 (0 a 3)
     * El incremento produce desbordamiento modular. 
     */
    for (b.B = 0, a = 0; a < 8; b.B++, a++)
    {
        printf("%d   ", b.B);
        printf("\n");
    }

    /* Se inicializa el campo de bit C en 0 y se lo incrementa 16 veces.
     * Como C tiene 3 bits, opera modulo 8 (0 a 7)
     * Se imprime cada valor antes de esperar una tecla. 
     */
    for (b.C = 0, a = 0; a < 16; b.C++, a++)
    {
        printf("%d   ", b.C);
        printf("\n\nPresione una tecla para continuar");
    }

    getch(); // Espera una tecla

    system("CLS");

    /* Inicializacion del miembro G de la union.
     * Se escriben ambos bytes en 0.
     * En este momento, el miembro activo es G. 
     */
    e.G[0] = 0;
    e.G[1] = 0;

    /* Mostrar valores del vector de la union */
    printf("\ne.G[0] = %d\te.G[1] = %d", e.G[0], e.G[1]);

    /* Se escriben los campos del miembro D (struct alfa).
     * A partir de este momento, el miembro activo de la union es D.
     * Como todos comparten memoria, G reflejara los mismos bits.
     */
    e.D.A = 1;
    e.D.B = 2;
    e.D.C = 5;

    /* Mostrar los campos de bits de D.
     * Acceder a otro miembro distinto del ultimo escrito (D)
     * puede ser comportamiento indefinido (UB) segun el estandar,
     * excepto cuando se accede mediante char para inspeccion de la representacion en memoria.
     * Por esto se puede mostrar e.G[0] y e.G[1] en hexadecimal sin que produzca (UB). 
     */
    printf("\ne.D.A = %d\te.D.B = %d\te.D.C = %d", e.D.A, e.D.B, e.D.C);
    printf("\ne.G[0] = %X\te.G[1] = %X", e.G[0], e.G[1]); 

    /* Se escriben los campos del miembro E.
     * Ahora el miembro activo pasa a ser E.
     * El contenido previo se sobreescribe en la misma memoria. 
     */
    e.E.C = 1;
    e.E.B = 2;
    e.E.A = 5;

    printf("\ne.E.A = %d\te.E.B = %d\te.E.C = %d", e.E.A, e.E.B, e.E.C);
    printf("\ne.G[0] = %X\te.G[1] = %X", e.G[0], e.G[1]);

    /* Se escriben los campos del miembro F (struct gamma),
     * que probablemente sea el miembro de mayor dimension.
     */
    e.F.A = 18;
    e.F.B = 2;
    e.F.C = 5;
    e.F.D = 11;

    printf("\ne.F.A = %X\te.F.B = %X\te.F.C = %X\te.F.D = %X", e.F.A, e.F.B, e.F.C, e.F.D);
    printf("\ne.G[0] = %X\te.G[1] = %X\n\n", e.G[0], e.G[1]);
    
    return 0;
}
