// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> /* Se usa getche(); */
/* Se agrega stdlib.h por que usa system("cls");*/
#include <stdlib.h>

int main(void)
{
    int i, j;

    system("CLS");

    do
    {
        printf("\n\n\t\tIngrese un numero entero:");
        scanf("%d", &i);

        /* El especificador %04X:
         * 0 => Completa con ceros a la izquierda
         * 4 => Minimo 4 digitos
         * X => Imprime en hexadecimal mayuscula
         */
        printf("\n\t\tEl numero en hexadecimal es: %04X", i);

        /* Complementa a dos manual:
         * ~i => invierte todos los bits (Complemento a uno)
         * +1 => suma 1 (Complemento a dos)
         *
         * Esto equivale matematicamente a:
         * j = -i;
         */
        j = ~i + 1;

        /* Muestra el complemento a dos */
        printf("\n\n\t\tEl numero en complementos a dos es: %d", j);

        /* Muestra en formato hexadecimal mayuscula, minimo 4 digitos*/
        printf("\n\n\t\t En formato hexadecimal es %04X", j);

        /* Mostrar mensaje para usuario */
        printf("\n\n\nDesea continuar (S/N)? ");
    }
    while(getche() != 'N'); /* Sale si se presiona N */
    
    return 0;
}
