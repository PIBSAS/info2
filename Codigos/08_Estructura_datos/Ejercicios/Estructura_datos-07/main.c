// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <string.h>
#include <conio.h> // Se usa getch(), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>

/* Define a la estructura "pers" */
struct pers
{
    char nom[20], apel[20]; // Cadenas de 19 caracteres + '\0'
    char edad; //tipo char (internamente es un entero pequeño)
    //signed char edad;
    float peso, altura;
};

int main(void)
{
    /* Declara una variable del tipo struct pers llamada "habit" */
    struct pers habit;

    /* Declara una variable auxiliar */
    float aux;

    /* Limpiar pantalla */
    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

    /* Ingreso de los datos a la estructura */

    /* Titulo para el ingreso de datos */
    printf("\n\t\tINGRESE LOS DATOS DE LA PERSONA\n\n");

    /* Carga de Nombre */
    printf("Nombre: ");
    gets(habit.nom); // Se elimino en C11 por insegura, se puede reemplazar con fgets()
    //fgets(habit.nom, sizeof(habit.nom), stdin);

    /* Carga de Apellido */
    printf("\nApellido: ");
    gets(habit.apel); // Se elimino en C11 por insegura, se puede reemplazar con fgets()
    //fgets(habit.apel, sizeof(habit.apel), stdin);

    /* Carga de Edad */
    printf("\nEdad: ");
    /* Ingresa el valor de la edad como valor numerico utilizando
     * el formato de control "%d" y no el formato de control "%c"
     * que se utilizaria para ingresar un caracter desde el
     * teclado sin importar que la variable a la que se ingrese
     * Aunque "int" o "char" son enteros,
     * en scanf el especificador de formato debe coincidir exactamente
     * con el tipo de la variable, ya que se pasa un puntero
     * y no existen promociones automaticas.
     * El especificador "%d" espera un "int *",
     * mientras que "habit.edad" es un "char *".
     * Por eso el compilador advierte -Wformat format "%d" espera tipo "int *", pero el argumento 2 tiene tipo "char *"
     * Es por esto que para leer un "char" numerico se debe usar "%hhd" y cambiar char edad a signed char edad en la estructura.
     */
    scanf("%d", &habit.edad); // Tras ver el warning en el compilador comentar y reemplazar con la siguiente linea
    //scanf("%hhd", &habit.edad);
    
    /* Carga de Peso en una variable auxiliar */
    printf("\nPeso: ");
    scanf("%f", &aux);

    /* Se asigna el valor almacenado en la variable auxiliar al campo peso de la estructura */
    habit.peso = aux;

    /* Carga de Altura en una variable auxiliar */
    printf("\nAltura: ");
    scanf("%f", &aux);

    /* Se asigna el valor almacenado en la variable auxiliar al campo altura de la estructura */
    habit.altura = aux;

    /* Mensaje antes de pausar */
    printf("\n\n\t\tPresione una tecla para continuar");

    /* Espera que el usuario presione una tecla para visualizar los datos en pantalla */
    getch();

    /* Limpiar pantalla */
    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

    /* Impresion de los datos en pantalla con un formato distinto */
    printf("\n\n\t\tDatos de %s, %s", habit.apel, habit.nom); // Formato string

    printf("\n\n\n\tEdad: %d\t\t Altura: %1.2f", habit.edad, habit.altura); // Formato entero y decimal con dos digitos

    printf("\t\tPeso: %2.2f", habit.peso); // Formato decimal con dos digitos

    return 0;
}