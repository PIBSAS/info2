// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // De la biblioteca usamos getche()

int main(void)
{
    /* Declaracion de vector de 5 char y vector de 5 punteros a char, puntero a char y variables enteras*/
    char c[5], *pc[5], *aux;
    int i, j;

    printf("Ingrese 5 caracteres: ");
    /* Se leen 5 caracteres y se almacenan en el vector c.
     * getche() devuelve el caracter tipeado y lo muestra en pantalla. */
    for (i = 0; i < 5; i++)
        c[i] = getche();

    /* cada elemento de pc recibe la direccion del correspondiente elemento de c.
     * Es decdir:
     * pc[0] => &c[0]
     * ...
     * pc[4] => &c[4] */
    for (i = 0; i < 5; i++)
        pc[i] = &c[i];

    /* Ordenamiento (tipo burbuja/simple)
        * sobre el vector de punteros.
        * Se comparan los caracteres apuntados:
        * *pc[i] y *pc[j]
        * Si el primero es mayor, se intercambian los punteros (no los caracteres). */
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (*pc[i] > *pc[j])
            {
                aux = pc[i];
                pc[i] = pc[j];
                pc[j] = aux;
            }
    
    printf("\n");
    
    /* Se imprime:
     * *pc[i] => caracteres ordenados.
     * c[i] => Vector original (sin modificar) */
    for (i = 0; i < 5; i ++)
        printf("%c\t%c\n", *pc[i], c[i]);

    return 0;
}
