// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include<stdlib.h> // Se usa exit(), system()
#include<conio.h> // se usa getch()
#include<ctype.h> // No se usa

#define MAX 100

/* Prototipos de funciones */
void Ingreso(int *,int *,float *);
void Lee(int *,int *,float *);

int main(void)
{
    /* Ingresa => indice de escritura (cola 'final')
     * Extrae  => indice de lectura   (cola 'frente')
     */
    int Ingresa = 0, Extrae = 0, Opcion;

    /* Cola implementada como vector estatico */
    float Cola[MAX];
    do
    {
        system("CLS"); // Limpia pantalla
        printf("1 - Ingresar datos\n");
        printf("2 - Leer datos\n");
        printf("3 - Salir\n\n");
        printf("Ingrese una opcion ( 1 - 3 ) : ");
        scanf("%d", &Opcion);
        switch(Opcion)
        {
        case 1:
        /* Se pasa la direccion de los indices,
         * porque se modifican dentro de la funcion
         */
            Ingreso(&Ingresa, &Extrae, Cola);
            break;

        case 2:
            Lee(&Ingresa, &Extrae, Cola);
            break;

        case 3:
            exit(0); // Termina el programa inmediatamente
        }
    }
    while(Opcion != 3); // Mientras opcion no sea tres

    return 0;
}

/* Inserta un elemento en la cola (enqueue)
 * Escritura => indice donde se escribe
 * Lectura => indice de lectura (no se uso)
 */
void Ingreso(int *Escritura, int *Lectura, float *Cola)
{
    /* Si Escritura llego al limite del vector la cola esta llena */
    if(*Escritura == MAX)
    {
        system("CLS"); // Limpia la pantalla

        printf("\n\nCola llena");
        
        printf("\nPresione una tecla para continuar");
        getch(); // Espera que se presione una tecla
        
        return;
    }
    
    printf("\nIngrese el dato : ");
    scanf("%f", &Cola[*Escritura]); // Se escribe en la posicion actual de Escritura
    
    (*Escritura)++; // Se avanza el indice de escritura
    
    printf("\n\n\nPresione una tecla para continuar");
    getch(); // Espera que se presione una tecla
}

/* Lee (extrae) un elemento de la cola (dequeue) */
void Lee(int *Escritura,int *Lectura,float *Cola)
{
    /* Si ambos indices son iguales, significa que no hay elementos para leer */
    if(*Escritura == *Lectura)
    {
        system("CLS"); // Limpia la pantalla
        
        printf("\n\nCola vacia");
        
        printf("\nPresione una tecla para continuar");
        getch(); // Espera que se presione una tecla
        
        return;
    }
    
    /* Se muestra el dato en la posicion de lectura */
    printf("\nEl dato es : %f",Cola[*Lectura]);
    
    (*Lectura)++; // Se avanza el indice de lectura
    
    printf("\n\n\nPresione una tecla para continuar");
    getch(); // Espera que se presione una tecla
}