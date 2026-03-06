// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> /* Se usa getch(), getche() */
/* Se agrega stdlib.h por que usa system("cls");*/
#include <stdlib.h>

/* Prototipos de funciones */
void conv(unsigned char, char, unsigned char, unsigned char);
void conv1(char, unsigned char, unsigned char);
void conv2(unsigned char, char, unsigned char, unsigned char);
void pasbin(unsigned char);

int main(void)
{
    /* Variables de 8 bits sin signo */
    unsigned char a, b, c;

    /* Variable auxiliar para ingreso y contadores */
    int i;
    do
    {
        /* Ingreso del primer numero */
        printf("\n\n\t\tIngrese un numero entero: ");
        scanf("%d", &i);

        /* Se guarda en variable de 8 bits (puede truncar) */
        a = i;

        /* Ingreso del segundo numero */
        printf("\n\t\tIngrese otro numero entero: ");
        scanf("%d", &i);

        /* Se guarda en variable de 8 bits (puede truncar) */
        b = i;

        /* Operador OR bit a bit y llamado a la funcion conv */
        printf("\n\n\t\t%d | %d = %d", a, b, a | b);
        conv(a, '|', b, a|b);

        /* Operador AND bit a bit y llamado a la funcion conv */
        printf("\n\n\t\t%d & %d = %d", a, b, a & b);
        conv(a, '&', b, a&b);

        /* Operador XOR bit a bit y llamado a la funcion conv */
        printf("\n\n\t\t%d ^ %d = %d", a, b, a ^ b);
        conv(a, '^', b, a^b);

        /* Operador NOT (complemento a uno) y llamado a la funcion conv1 para los numeros a y b */
        printf("\n\n\t\t~%d = %d", a, ~a);
        conv1('~', a, ~a);

        printf("\n\n\t\t~%d = %d", b, ~b);
        conv1('~', b, ~b);

        /* Pedido al usuario */
        printf("\n\n\t\t\tPresione una tecla para continuar");
        getch();

        /* Limpiar pantalla en Windows */
        system("CLS");

        printf("\n\n");

        /* Desplazamiento a la derecha y llamado a la funcion conv2 para a y b*/
        for (i = 0; i < 9; i++)
        {
            c = a >> i;

            printf("\n\t\t%d >> %d = %d", a, i, c);
            conv2(a, '>', i, c);
        }

        printf("\n\n");

        for (i = 0; i < 9; i++)
        {
            c = b >> i;

            printf("\n\t\t%d >> %d = %d ", b, i, c);
            conv2(b, '>', i, c);
        }

        printf("\n\n\t\t\tPresione una tecla para continuar");
        getch();

        system("CLS");

        printf("\n\n");

        /* Desplazamiento a izquierda y llamada a la funcion conv2 para a y b */
        for (i = 0; i < 9;i++)
        {
            c = a << i;

            printf("\n\t\t%d << %d = %d", a, i, c);
            conv2(a, '<', i, c);
        }

        printf("\n\n");

        for (i = 0; i < 9; i++)
        {
            c = b << i;

            printf("\n\t\t%d << %d = %d ", b, i, c);
            conv2(b, '<', i, c);
        }

        printf("\n\nDesea continuar (S/N)? ");
    }
    while(getche() != 'N'); /* Repite hasta presionar N */

    printf("\n\n");

    return 0;
}

/*
 * Muestra un numero de 8 bits en formato binario.
 * Recorre desde el bit mas significativo (0x80)
 * hasta el menos significativo (0x01).
*/
void pasbin(unsigned char nro)
{
    unsigned char aux;

    for (aux = 0x80; aux > 0; aux >>= 1)
    {
        if (nro & aux)
            printf("1");
        else
            printf("0");
    }
}

/*
 * Muestra la operacion binaria completa:
 * Ej.:
 *     10101010 | 01010101 = 11111111
 */
void conv(unsigned char a, char b, unsigned char c, unsigned char d)
{
    printf("\t\t");
    
    pasbin(a);
    
    printf(" %c ", b);

    pasbin(c);

    printf(" = ");

    pasbin(d);
}

/*
 * Muestra operacion NOT en formato binario.
 */
void conv1(char a, unsigned char b, unsigned char c)
{
    printf("\t\t%c", a);

    pasbin(b);

    printf(" = ");

    pasbin(c);
}

/*
 * Muestra desplazamientos << o >> en formato binario.
 */
void conv2(unsigned char a, char b, unsigned char c, unsigned char d)
{
    printf("\t\t");

    pasbin(a);

    printf(" %c%c %d = ", b, b, c);

    pasbin(d);
}