// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
/*
    Busqueda binaria recursiva
*/
#include <stdio.h>
#include <stdlib.h> // Se usa system(), No estaba en el programa de catedra, pero sin ella no compila.

/* Falta el prototipo de la funcion declarada, se agrega para compilacion: */
int buscar(int vector[], int inf, int sup, int X);

int main(void)
{
    /* Declaracion de variables y vector.
     * La busqueda binaria SOLO funciona si el vector esta ordenado */
    int vec[] = {2, 4, 5, 7, 8, 12, 14, 17, 21, 23, 24, 32, 43, 54, 65, 88};
    int X;
    int pos, longitud;
    
    system("CLS"); // Limpia la pantalla solo en windows. No es portable.
    
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &X);
    
    /* Error: tipo no existe.
     * Debe ser sizeof(vec[0]) */
    longitud = sizeof(vec) / sizeof(tipo);
    /* Para compilar es necesario cambiar por esta linea, descomentar tras ver el error y comentar la errada */
    //longitud = sizeof(vec) / sizeof(vec[0]);

    /* Almacenamos en la variable entera lo devuelto por la llamada a la funcion,
     * Se pasan como argunmentos el vector ordenado, el indice inferior, el indice superior que se da de restar 1 a la longitud y el valor buscado */
    pos = buscar(vec, 0, longitud - 1, X);

    /* Si se encontro o no, si se encuentra se indica su posicion */
    if (pos < 0)
        printf("\n\nNo se encontro");
    else
        printf("\n\nLa posicion del valor buscado es %d", pos);

    return 0;
}

/* Declaracion de la funcion buscar (Busqueda binaria recursiva).
 * Se agrega el tipo int, ya que en el programa de la catedra no figuraba.*/
//buscar(int vector[], int inf, int sup, int X)

/* Busqueda binaria recursiva:
 * Parametros:
 * - vector => vector ordenado.
 * - inf => indice inferior.
 * - sup => indice superior.
 * - X => valor a buscar.
 *
 * Devuelve:
 * - indice donde esta X o -1 si no se encuentra */
int buscar(int vector[], int inf, int sup, int X)
{
    /* Declaracion de variables sin inicializar */
    int mitad;
    int posicion; // No es utilizada

    /* Caso base: 
     * Si el intervalo se colapso (inf > sup) o queda un solo elemento
     * significa que no se encontro el elemento*/
    if ((inf >= sup) && (vector[inf] != X))
        return -1;

    /* Se calcula el indice centtral.
     * Posible problema teorico:
     * - (inf + sup) podria desbordar (overflow) si los indices fueran muy grandes.
     * - Fomra mas segura: inf + (sup - inf) / 2
     * En este caso no es relevante por la dimension minuscula del vector.
     * Se almacena el promedio en la variable entera mitad, el promedio sera truncado */
    mitad = (inf + sup) / 2;

    /* Si el elemento central coincide, se devuelve su posicion */
    if (vector[mitad] == X)
        return mitad;

    /* Si el valor buscado es mayor que el central, se busca en la mitad derecha */
    if (X > vector[mitad])
        return buscar(vector, mitad + 1, sup, X);
    /* Si el valor buscado es menor que el central, se busca en la mitad izquierda. */
    return buscar(vector, inf, mitad - 1, X);
}
