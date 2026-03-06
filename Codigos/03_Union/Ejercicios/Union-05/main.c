// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
//////////// Es Union-04 sin comentarios /////////////
#include <stdio.h>
#include <conio.h>// No pertenece al estandar ISO C. clrscr() no esta disponible en GCC/MinGW.
#include <stdlib.h> // system("cls"); al no poder compilar con clrscr()
#include <math.h>

union alfa
{
    int x;
    char y;
};

union alfa ingreso(char);
void imprime(union alfa, char);

int main(void)
{
    union alfa A;
    char c;

    do
    {
        clrscr();

        printf("\n\n\t\t\tIngrese una opcion ");
        printf("\n\n (C) ingreso de un caracter");
        printf("\n\n (E) ingreso de un entero ");

        c = getche();

        printf("\n\n");

        A = ingreso(c);

        imprime(A, c);

        printf("\n\nDesea ingresar otro valor (S/N) ");

        c = getche();
    }
    while((c == 's') || (c == 'S'));

    return 0;
}

union alfa ingreso(char b)
{
    union alfa C;

    printf("Ingrese un ");

    if ((b == 'c') || (b == 'C'))
    {
        printf(" caracter ");

        c.y = getche();
    }
    else
    {
        printf(" entero ");
        scanf("%d", &C.x);
    }

    printf("\n\n");

    return (C);
}

void imprime(union alfa B, char c)
{
    if ((c == 'c') || (c == 'C'))
    {
        printf("\n\nUsted ingreso el caracter %c", B.y);
    }
    else
    {
        printf("\n\nUsted ingreso el entero %d", B.x);
    }
}