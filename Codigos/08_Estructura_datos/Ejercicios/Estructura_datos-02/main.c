// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Programa de ejemplo: 
 * Declaracion y uso de estructuras anonimas.
 * Calculo del modulo y argumento de la suma
 * de dos numeros complejos.
 */

#include <stdio.h>
#include <math.h> // Se usa sqrt(), pow(), atan2()

/* Declaracion de una estructura SIN etiqueta (estructura anonima).
 * Representa un numero complejo en forma binomica:
 * z = x + yi
 *
 * Al no tener nombre (no hay 'struct complejo'),
 * este tipo no puede reutilizarse luego.
 * Solo existen las variables a y b.
 */
struct
{
    float x, y; /* x => Parte real, y => Parte imaginaria */
} a, b;

/* Declaracion de estructura anonima.
 * Almacena:
 * - modulo (magnitud).
 * - argumento (angulo en radianes).
 *
 * Tampoco puede reutilizarse como tipo.
 */
struct
{
    float mod, arg;
} res;

int main(void)
{
    /* Ingreso del numero a */
    a.x = 5;
    a.y = 7;

    /* Ingreso del numero b */
    b.x = 2;
    b.y = 8;

    /* Calculo de la suma de los numeros complejos a y b
     * Suma de complejos:
     * (a + b) = (a.x + b.x) + (a.y + b.y)i
     *
     * Calculo del modulo:
     * |z| = sqrt(x^2 + y^2)
     *
     * Se utilizan funciones de math.h:
     * - pow()  => potencia.
     * - sqrt() => raiz cuadrada.
     */
    res.mod = sqrt(pow((a.x + b.x), 2) + pow((a.y + b.y), 2));

    /* Calculo del argumento:
     * arg(z) = atan2(y, x)
     *
     * Se utiliza la funcion atan2 de math.h:
     * atan2() => devuelve el angulo en radianes, considerando correctamente el cuadrante.
     */
    res.arg = atan2((a.y + b.y), (a.x + b.x));

    /* Impresion de los resultados */
    printf("\nEl modulo de la suma de (%2.2f + %2.2fi) y (%2.2f + %2.2fi) es: ", a.x, a.y, b.x, b.y);
    printf("\t%2.2f\n\n", res.mod);

    printf("\nEl argumento de la suma de (%2.2f + %2.2fi) y (%2.2f + %2.2fi) es: ", a.x, a.y, b.x, b.y);
    printf("\t%2.2f\n\n", res.arg);
    
    return 0;
}