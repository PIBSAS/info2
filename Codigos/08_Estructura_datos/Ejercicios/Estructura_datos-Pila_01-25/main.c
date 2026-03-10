// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* PILA (stack) estatica utilizando vector */
#include <stdio.h>
#include <stdlib.h> // Se usa exit() y system()
#include <conio.h> // Se usa getch()

/* Dimension maxima de la pila */
#define MAX 100

/* Prototipos de funciones */
void Inicio(int *,float *);
void Lee(int *,float *);

int main(void)
{
    /* Declaracion de variables y vector.
     * Indice => representa el tope de la pila.
     * Siempre apunta a la proxima posicion libre.
     */
    int Indice = 0, Opcion;
    float Pila[MAX]; // Almacena los datos (estructura LIFO)
    
    do
    {
        system("CLS"); // Limpia la pantalla.
        
        printf("1 - Ingresa datos\n");
        printf("2 - Lee datos\n");
        printf("3 - Salir\n\n");
        printf("Ingrese una opcion ( 1 - 3 ) : ");
        scanf("%d", &Opcion);

        switch(Opcion)
        {
            case 1:
                /* Inserta elemento (push)
                 * Se pasa la direccion de Indice porque se modifica.
                 */
                Inicio(&Indice, Pila);
                break;

            case 2:
                /* Extrae elemento (pop) */
                Lee(&Indice, Pila);
                break;

            case 3:
                exit(0);
        }
    }
    while(Opcion != 3);

    return 0;
}

/* Insercion en pila (PUSH) */
void Inicio(int *Indice, float *Pila)
{
    /* Si Indice llego al maximo, la pila esta llena. */
    if(*Indice == MAX)
    {
        system("CLS"); // Limpia la pantalla.
        
        printf("\n\nPila llena");
        
        printf("\n\nPresione una tecla para continuar\n");
        getch(); // Espera que se presione una tecla.
        
        return;
    }

    system("CLS"); // Limpia la pantalla.
    
    printf("\nIngrese el dato : ");

    /* Se escribe en la posicion actual del tope. */
    scanf("%f", &Pila[*Indice]);
    
    /* Se incrementa el tope.
     * Ahora apunta a la siguiente posicion libre.
     */
    (*Indice)++;
}

/* Extraccion en pila (POP) */
void Lee(int *Indice, float *Pila)
{
    /* Si Indice es cero, no hay elementos (pila vacia). */
    if(!*Indice)
    {
        system("CLS"); // Limpia la pantalla.

        printf("\n\nPila vacia");
        
        printf("\n\nPresione una tecla para continuar\n");
        getch(); // Espera que se presione una tecla.
        
        return;
    }

    /* Se decrementa primero el indice,
     * porque siempre apunta a la proxima posicion libre.
     */
    (*Indice)--;
    
    /* Se muestra el elemento del tope */
    printf("\nEl dato es : %f", Pila[*Indice]);
    
    printf("\n\nPresione una tecla para continuar\n");
    getch(); // Espera que se presione una tecla.

}
