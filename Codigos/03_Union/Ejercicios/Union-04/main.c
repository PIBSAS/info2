// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // getche() y crlscr() esta ultima no viene en GCC/MinGW
#include <math.h> // No se usa nada de la biblioteca, podria borrarse.

/* Para reemplazar a clrscr() con system("cls");*/
#include <stdlib.h> // system("cls");

/*
    Se define una union con dos campos uno "int" y el otro "char"
*/

union alfa
{
    int x;
    char y;
};

/*
    Se declaran los prototipos de las funciones
*/

union alfa ingreso(char);
void imprime(union alfa, char);

int main(void)
{
    /* Se declaran las variables */
    union alfa A;
    char c;

    do
    {
        /* Menu de opciones */
        //clrscr(); // No existe en GCC/MinGW reemplazar con system("cls");
        system("cls"); // Comentar la linea anterior y descomentar esta linea para compilar

        printf("\n\n\t\t\tIngrese una opcion");
        printf("\n\n (C) ingreso de un caracter");
        printf("\n\n (E) ingreso de un entero \n\n");
        
        // Almacena en la variable c el ingreso del usuario, si apreto ENTER queda un \n en el buffer. Puede provocar comportamiento raro en la siguiente lectura
        c = getche(); // Se puede reemplazar con getchar() que pertenece al estandar, pero requiere ese ENTER.

        printf("\n\n");

        /* Se invoca a la funcion "ingreso" */
        A = ingreso(c);

        /* Se invoca a la funcion "imprime" */
        imprime(A, c);
        
        printf("\n\n\nDesea ingresar otro valor (S/N): ");

        c = getche();

    }
    while((c == 's') || (c == 'S'));

    return 0;
}

/*  Se define a la funcion "ingreso"  *
 * Devuelde una union de tipo "alfa" *
 * Recibe un "char"                  */

 union alfa ingreso(char b)
 {
    union alfa C;
    
    printf("Ingrese un ");

    if ((b == 'c') || (b == 'C'))
    {
        printf(" caracter ");

        C.y = getche();
    }
    else
    {
        printf(" entero ");
        scanf("%d", &C.x);
    }

    printf("\n\n");

    /* Devuelve el valor de la union */
    return (C);
 }

 /* Se define la funcion "imprime"            *
  * Recibe una union de tipo alfa llamada "B" *
  * Y un char denominado "c", devuelve "void" */
  void imprime(union alfa B, char c)
  {
    if ((c == 'c') || (c == 'C'))
        printf("\n\nUsted ingreso el caracter %c", B.y);
    else
        printf("\n\nUsted ingreso el entero %d", B.x);
  }