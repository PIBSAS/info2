// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

/* Definicion de la estructura */
struct lista
{
    int art, cant;
    float prec;
};

int main(void)
{
    /* Declaracion de dos variables del tipo 'struct lista'
     * valcom: significa valor de compra
     * valven: Significa valor de venta
     */
     struct lista valcom, valven;

     /* Asignacion de valores a los campos de la variable valcom */
     valcom.art = 56;
     valcom.cant = 3;
     valcom.prec = 23.59;

     /* Asignacion del valor de la variable valcom a la variable valven
      * Se realiza una copia completa de la estructura,
      * todos los campos de valcom se copian en valven.
      * Esto es una copia por valor. Contienen los mismos datos,
      * pero ocupan posiciones de memoria distintas.
      */
     valven = valcom;

     /* Verificacion de los valores de los campos de cada variable */
     printf("\n\n%d\t%d\t%.2f", valcom.art, valcom.cant, valcom.prec);
     printf("\n\n%d\t%d\t%.2f", valven.art, valven.cant, valven.prec);

     /* Adicion de un 15% al precio de venta (solo se modifica valven, no valcom) */
     valven.prec *= 1.15;

     /* Verificacion de los valores de los campos de cada variable */
     printf("\n\n%d\t%d\t%.2f", valcom.art, valcom.cant, valcom.prec);
     printf("\n\n%d\t%d\t%.2f", valven.art, valven.cant, valven.prec);

    return 0;
}
