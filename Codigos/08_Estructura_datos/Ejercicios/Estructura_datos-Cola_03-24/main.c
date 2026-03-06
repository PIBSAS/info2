// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Cola circular con punteros */

#include <stdio.h>
#include<stdlib.h> // Se usa exit(), system()
#include<conio.h> // Se usa getch()
#include<ctype.h> // No se usa

#define MAX 100

/* Prototipos de las funciones */
void Inicio(int *,int **,int *,int *,int *);
void Lee(int *,int **,int *,int *,int *);

int main(void)
{
    /* Llena   => bandera: 1 si la cola esta llena
     * Vacia   => bandera: 1 si la cola esta vacia
     * Cola    => vector que almacena los datos
     * Extrae  => puntero de lectura (frente)
     * Ingreso => puntero de escritura (final)
     */
    int Llena = 0, Vacia = 1, Opcion, Cola[MAX], *Extrae = Cola, *Ingreso = Cola;
    
    do
    {
        system("CLS"); // Limpiar pantalla
        
        printf("1 - Ingresa datos\n");
        printf("2 - Lee datos\n");
        printf("3 - Salir\n\n");
        printf("Ingrese una opcion ( 1 - 3 ) : ");

        fflush(stdin); // Reemplazar con:
        //int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);
        
        scanf("%d", &Opcion);
        
        switch(Opcion)
        {
            case 1:
                /* Se pasa:
                 * - El vector base.
                 * - Direccion del puntero de escritura.
                 * - Banderas.
                 * - Puntero de lectura.
                 */
                Inicio(Cola, &Ingreso, &Llena, &Vacia, Extrae);
                break;

            case 2:
                Lee(Cola, &Extrae, &Vacia, &Llena, Ingreso);
                break;

            case 3:
                exit(0);
        }
    }
    while(Opcion != 3);

    return 0;
}

/* Insercion en cola circular */
void Inicio(int *Cola, int **Ingr, int *Llena, int *Vacia, int *Extr)
{
    /* Si la bandera indica llena, no se puede insertar */
    if(*Llena)
    {
        system("CLS");
        
        printf("\n\nCola llena");
        
        printf("\n\nPresione una tecla para continuar\n");
        getch(); // Espera que se presione una tecla.
        
        return;
    }
    
    printf("\n\nIngrese el dato : ");
    /* *Ingr es un puntero a puntero.
     * Apunta a la posicion actual de escritura.
     * scanf escribe directamente en esa direccion.
     */
    scanf("%d", *Ingr);
    
    *Vacia = 0; // Si se ingresa, ya no esta vacia
    
    /* Avanza el puntero de escritura */
    (*Ingr)++;
    
    /* Si llego al final fisico del vector,
     * vuelve al inicio => comportamiento circular.
     */
    if(*Ingr == Cola+MAX)
        *Ingr = Cola;
    
    /* Si escritura alcanza lectura,
     * significa que la cola esta llena.
     */
    if(*Ingr == Extr)
        *Llena = 1;
}

/* Extraccion en cola circular */
void Lee(int *Cola, int **Extr, int *Vacia, int *Llena, int *Ingr)
{
    /* Si bandera indica vacia, no se puede extraer */
    if(*Vacia)
    {
        system("CLS"); // Limpiar pantalla.

        printf("\n\nCola vacia");
        
        printf("\n\nPresione una tecla para continuar\n");
        getch(); // Esperea que se presione una tecla.
        
        return;
    }
    
    *Llena = 0; // Si se extrae, ya no esta llena.
    
    /* Se muestra el valor de **Extr:
     * - *Extr es el puntero de lectura.
     * - **Extr es el valor almacenado.
     */
    printf("\n\nEl dato es : %d\n", **Extr);
    
    printf("\n\nPresione una tecla para continuar\n");
    getch(); // Esperea que se presione una tecla.
    
    /* Avanza puntero de lectura. */
    (*Extr)++;
    
    /* Si llega al final fisico, vuelve al inicio (circular) */
    if(*Extr == Cola + MAX)
        *Extr = Cola;
    
    /* Si lectura alcanza escritura, la cola quedo vacia. */
    if(*Extr == Ingr)
        *Vacia = 1;
}