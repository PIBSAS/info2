// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Se desea almacenar cierto número de enteros en una estructura *
 * de tipo Cola, diseñe una solución que permita, insertar y     *
 * eliminar datos de la cola.                                    */
#include <stdio.h>
#include <conio.h> // Se usa getch()
#include <stdlib.h> // Se usa malloc(), free() y system()

/* Declaracion de la cola */
/*
 * Nodo de la lista enlazada.
 * Cada nodo contiene:
 * - elemento  => Dato almacenado.
 * - siguiente => Puntero al proximo nodo 
 */
struct nodo
{
    int elemento;
    struct nodo *siguiente;
};

/* Estructura Cola:
 * - frente => Primer nodo (FIFO: First In First Out)
 * - final  => Ultimo nodo
 */
struct Cola
{
    struct nodo *frente;
    struct nodo *final;
};

/* Declaracion de los prototipos de las funciones */
void CrearCola(struct Cola *cola);
void insert(struct Cola *cola, int x);
int remover(struct Cola *cola);
int empty(struct Cola cola);

int main(void)
{
    int x, opc = 8, j = 0;
    struct Cola cola;

    /* Inicializa frente y final en NULL */
    CrearCola(&cola);

    /* Limpia la pantalla en Windows, en Linux system("clear") */
    system("cls"); //clrscr();

    while(opc != 3)
    {
        printf("\t\t\tMENU PRINCIPAL\n\n\n");
        printf("\t 1. Insertar\n");
        printf("\t 2. Eliminar\n");
        printf("\t 3. Salir\n");
        scanf("%d", &opc);
        
        switch(opc)
        {
            case 1:
                printf("Ingrese el numero a introducir:\n");
                scanf("%d", &x);
                insert(&cola, x); // Inserta al final
                ++j; // Incrementa contador
                break;
            case 2:
                x = remover(&cola); // Remueve del frente
                
                /* Condicion algo redundante:
                 * empty(cola) verifica si esta vacia
                 * j tambien controla cantidad insertada
                 */
                if(!empty(cola) || j)
                {
                    printf("%d fue eliminado de la cola\n", x);
                    --j;
                }
                
                getch(); // Espera que se presione una tecla
                
                break;
        }
        system ("cls"); //clrscr ();
    }
    getch(); // Espera que se presione una tecla

    return 0;
}

/* Definicion de las funciones */

/* Inicializa la cola vacia */
void CrearCola(struct Cola *cola)
{
    cola->frente = cola->final = NULL;
}

/* Funcion que inserta el dato en la parte final de la cola (operacion enqueue) */
void insert (struct Cola *cola, int x)
{
    struct nodo *nuevo;

    /* Reserva memoria dinamica para nuevo nodo */
    nuevo = (struct nodo*)malloc(sizeof(struct nodo));

    nuevo->elemento = x;
    nuevo->siguiente = NULL; // Sera el ultimo

    /* Si esta vacia */
    if(empty(*cola))
    {
        cola->frente = nuevo; // Frente y final seran el mismo nodo
    }
    else
    {
        cola->final->siguiente = nuevo; // Enlaza al ultimo
    }
    cola->final = nuevo; // Actualiza el final
}

/* Elimina el elemento que esta al frente de la cola (operacion dequeue) */
int remover (struct Cola *cola)
{
    int temp = 0; //=NULL;
    struct nodo *nuevo;

    /* Si no esta vacia */
    if(!empty(*cola))
    {
        nuevo = cola->frente;                   // Guarda el nodo actual
        temp = cola->frente->elemento;          // Guarda el dato
        cola->frente = cola->frente->siguiente; // Avanza el frente
        free(nuevo); // Libera memoria
    }
    else
        printf("ERROR, cola vacia, se puede eliminar\a\n");
    return (temp);
}

/* Devuelve 1 si esta vacia, 0 si no */
int empty(struct Cola cola)
{
    return (cola.frente==NULL);
}