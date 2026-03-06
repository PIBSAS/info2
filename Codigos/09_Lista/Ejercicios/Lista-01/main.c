// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa system(), exit(), malloc(), free()
#include <conio.h> // Se usa getch() y getche()

/* Nodo de lista simplemente enlazada.
 * - Dato => valor almacenado.
 * - Sig  => puntero al siguiente nodo.
 */
struct Lis
{
    int Dato;
    struct Lis *Sig;
};

/* Prototipos de funciones */
void Ingresa(struct Lis **);
void Lee(struct Lis **);
void Borra(struct Lis **);
void Elimina(struct Lis **);

int main(void)
{
    int Opcion;

    /* Inicio apunta al primer nodo de la lista.
     * Si es NULL => lista vacia.
     */
    struct Lis *Inicio = NULL;

    /* Bucle infinito tipo menu */
    for (;;)
    {
        system("cls"); // Limpia la pantalla.

        printf("\n1 - Ingresa datos\n");
        printf("2 - Lee datos\n");
        printf("3 - Borra datos\n");
        printf("4 - Salir\n\n");
        printf("Ingrese una opcion (1 - 4): ");
        
        Opcion = getche(); // Lee el caracter y lo muestra, sin esperar Enter

        switch(Opcion)
        {
            case '1':
                Ingresa(&Inicio);
                break;

            case '2':
                Lee(&Inicio);
                break;

            case '3':
                Borra(&Inicio);
                break;

            case '4':
                /* Antes de salir, libera toda la memoria. */
                Elimina(&Inicio);
                exit(0);
        }
    }

    return 0;
}

/* Inserta nodo al final de la lista. 
 * **Principio es un puntero a puntero porque:
 * Necesitamos poder modificar el puntero original cuando la lista esta vacia.
 */
void Ingresa(struct Lis **Principio)
{
    /* *Actual:
     * - Se usa para recorrer la lista, comienza apuntando al primer nodo.
     *
     * *Nuevo:
     * - Sera el nodo recien creado con malloc().
     */
    struct Lis *Actual = *Principio, *Nuevo;

    system("cls"); // Limpia la pantalla.

    /* Se reserva memoria dinamica para un nodo.
     * sizeof() reserva spacio para Dato y *Sig
     * Si malloc devuelve NULL => no hay memoria disponible.
     */
    if (! (Nuevo = (struct Lis *)malloc(sizeof(struct Lis))))
    {
        system("cls"); // Limpia la pantalla.

        printf("\n\nNo hay memoria disponible\n");
        
        printf("\n\nPresiones una tecla para continuar\n");
        getch(); // Espera que se presione una tecla.

        return;
    }

    printf("\n\nIngrese el dato: ");
    /* Se carga el valor en el nuevo nodo.
     * Nuevo->Dato accede al campo Dato del nodo recien creado.
     */
    scanf("%d", &Nuevo->Dato);

    Nuevo->Sig = NULL; // Siempre apunta a NULL al crearse.

    /* Si la lista esta vacia, el nuevo nodo pasa a ser el primero. */
    if (!*Principio)
    {
        *Principio = Nuevo;

        return;
    }

    /* Recorre hasta el ultimo nodo el que tiene Sig == NULL */
    while(Actual->Sig)
        Actual = Actual->Sig;

    /* Enlaza el nuevo al final. */
    Actual->Sig = Nuevo;
}

/* Recorre e imprime la lista completa, desde el inicio hasta NULL. */
void Lee(struct Lis **Principio)
{
    /* *Actual empieza apuntando al primer nodo */
    struct Lis *Actual = *Principio;
    
    system("cls"); // Limpia la pantalla.

    /* Mientras Actual NO sea NULL, significa que aun hay nodos por recorrer. */
    while (Actual)
    {
        printf("\nEl dato es: %d", Actual->Dato);
        Actual = Actual->Sig; // Avanza al siguiente nodo.
    }

    printf("\n\nPresione una tecla para continuar\n");
    getch(); // Espera que se presione una tecla. 
}

/* Borra un nodo por valor */
void Borra(struct Lis **Principio)
{
    /* *Actual comienza apuntando al primer nodo, se usa para recorrer la lista.
     * *Anterior comienza apuntando al primer nodo, guarda el nodo previo, necesario para reconectar enlaces.
     */ 
    struct Lis *Actual = *Principio, *Anterior = *Principio;
    int b;
    
    system("cls"); // Limpia la pantalla.

    printf("\nIngrese el dato a borrar: ");
    scanf("%d", &b);

    /* Busca el nodo que contenga el valor */
    while ((Actual) && (b != Actual->Dato))
    {
        Anterior = Actual;
        Actual = Actual->Sig;
    }

    /* Caso 1: es el primer nodo */
    if ( (Actual) && (*Principio == Actual))
    {
        /* Se mueve el inicio al segundo nodo. */
        *Principio = Actual->Sig;
        free(Actual); // Se libera la memoria del nodo eliminado.

        return;
    }

    /* Caso 2: esta en medio o final */
    if (Actual)
    {
        /* El nodo Anterior ahora apunta al siguiente del nodo eliminado. */
        Anterior->Sig = Actual->Sig;
        free(Actual);

        return;
    }

    /* Caso 3: no encontrado */
    system("cls"); // Limpia la pantalla

    printf("\nEl dato no ha sido encontrado");
    printf("\n\nPresiones una tecla para continuar\n");

    getch(); // Espera  que se presione una tecla
}

/* Libera completamente la memoria de todos los nodos de la lista */
void Elimina(struct Lis **Principio)
{
    struct Lis *Actual;

    /* Mientras la lista no este vacia */
    while (*Principio)
    {
        Actual = *Principio;            // Guarda el nodo actual.
        *Principio = (*Principio)->Sig; // Avanza el inicio al siguiente nodo.
        free(Actual);                   // Libera el nodo que estaba primero (Actual).
    }
    /* Al terminar el bucle:
     * *Principio == NULL
     * La lista quedo completamente vacia.
     */
}