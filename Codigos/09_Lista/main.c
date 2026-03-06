// gcc -std=c11 -Wall -Wextra -pedantic main.c -o simple

/*
    Lista simple - Singly linked list

    Que es?:
         Una lista simple enlazada es una estructura de datos dinamica
         formada por nodos, donde:
            - Cada nodo contiene:
                - Un dato.
                - Un puntero al siguiente nodo.
            - El ultimo nodo apunta a NULL.
            - La lista se recorre en un solo sentido.
        Visualmente:
        - [ dato | siguiente ] => [ dato | siguiente ] => [ dato | siguiente ] => NULL

    Porque usar una lista simple?:
        Se usa cuando:
            - No conocemos de antemano cuantos elementos habra.
            - No queremos el costo de mover elementos como en arrays.
            - Necesitamos inserciones y borrados eficientes.
            - Queremos usar memoria dinamica (heap).
            El limite lo impone la memoria disponible, no una dimension fija.
    
    Conceptos fundamentales
        1. Nodo (struct autoreferenciado).
            Se llama estructura autoreferenciada porque contiene un puntero a su mismo tipo.
        Sintaxis:
            - struct Nodo {
            -   int dato;
            -   struct Nodo *sig;
            - };

        2. Puntero de comienzo (head)
            La lista se maneja mediante un puntero.
            Sintaxis:
            - struct Nodo *lista = NULL;
                - NULL => lista vacia.
                - Apunta siempre al primer nodo.
    
    Operaciones basicas sobre listas simples (singly linked list)
        - Crear nodo (memoria dinamica):
            - nuevo = malloc(sizeof(struct Nodo));
                Siempre:
                    - Verificar malloc.
                    - inicializar puntero (sig).
        
        - Recorrer la lista:
            - for (aux = lista; aux != NULL; aux = aux->sig)
                Se avanza saltando de nodo en nodo.
    
    Insercion
        Puede hacerse:
            - Como primer elemento.
            - Como ultimo elemento.
            - Como elemento intermedio.
            - Ordenada por una clave (muy comun)

        Insecion al comienzo:
            Sintaxis:
                - nuevo->sig = lista;
                - lista = nuevo;
            Donde:
                - nuevo es el nodo a insertar.
                - lista apunta al primer nodo de la lista.
            Nota:
                - El nuevo nodo pasa a ser el primer elemento.
                - Funciona tanto si la lista esta vacia como si no.

        Insercion intermedia:
            Sintaxis:
                - nuevo->sig = act->sig;
                - act->sig = nuevo;
            Donde:
                - act apunta al nodo anterior al lugar de insercion
                - nuevo ya tiene cargado el dato.

        Insercion al final:
            Sintaxis:
                - while (aux->sig != NULL)
                -   aux = aux->sig;
                - 
                - aux->sig = nuevo;
                - nuevo->sig = NULL;
            Donde:
                - aux se usa para recorrer la lista.
                - nuevo es el nodo a insertar.
            Nota:
                - Requiere recorrer toda la lista.
                - Si la lista esta vacia, este caso se reduce a insercion al comienzo.

        Insercion ordenada (general)
            Caso general que cubre todos:
                - Lista vacia.
                - Primer elemento.
                - Intermedio.
                - Ultimo.
            Nota:
                - Se recorre la lista buscando la posicion segun una clave.
                - Se usan punteros para mantener el orden.
                - Es el caso mas general y reutilizable.

    Busqueda
        Siempre es secuencial (no hay acceso directo):
            Sintaxis:
                - while (aux != NULL && aux->dato != buscado)
                -   aux = aux->sig;
            Donde:
                - aux se usa para recorrer la lista.
                - buscado es el valor a encontrar.
            Nota:
                - Puede terminar por encontrar el dato o llegar a NULL.
    
    Borrado
        Puede ocurrir:
            - Borrar el primer nodo.
            - Borrar un nodo intermedio.
            - Borrar el ultimo nodo.
        
        Siempre implica:
            - Reconectar punteros.
            - Liberar memoria (free)
        
        Borrado del primer nodo:
            Sintaxis:
                - aux = lista;
                - lista = aux->sig;
                - free(aux);
            Donde:
                - aux apunta temporalmente al nodo a borrar.
            Nota:
                - El segundo nodo pasa a ser el primero.
                - Si la lista tiene un solo nodo, queda vacia.
        
        Borrado de un nodo intermedio:
            Sintaxis:
                - ant->sig = act->sig;
                - free(act);
            Donde:
                - act apunta al nodo a borrar.
                - ant apunta al nodo anterior.
            Nota:
                Siempre se reconectan punteros antes del free.
        
        Borrado del ultimo nodo:
            Sintaxis:
                - ant->sig = NULL;
                - free(act);
            Donde:
                - act apunta al ultimo nodo (act->sig == NULL)
                - ant apunta al penultimo nodo.
            Nota:
                Si la lista tiene un solo nodo, este caso se reduce al borrado del primero.
        
        Borrado general (por dato):
            Se usan dos punteros:
                - *act (actual)
                - *ant (anterior)
            Descripcion:
                - Se recorre la lista buscando el nodo cuyo dato coincide con el valor buscado.
                - El puntero act apunta al nodo actual a evaluar.
                - El puntero ant mantiene referencia al nodo anterior.
            Casos que cubre:
                - Lista vacia.
                - Borrado del primer nodo.
                - Borrado de un nodo intermedio.
                - Borrado del ultimo nodo.
            Nota:
                - Permite resolver todos los casos de borrado con un solo algoritmo.
                - Siempre se deben reconectar los punteros antes de liberar la memoria.
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

/* ---- INSERTA ORDENADO ---- */
/*
    Insercion ordenada por clave:
        - Si la lista esta vacia o el valor es menor que el primero, se inserta al comienzo.
        - Caso general: se avanza mientras el valor sea mayor que el dato actual.
        - Se inserta entre ant y act (intermedio o ultimo).
*/
void insertar(struct Nodo **lista, int valor)
{
    struct Nodo *nuevo, *act, *ant;

    nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL)
    {
        printf("No hay memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;

    /* --- Lista vacia o insertar al comienzo --- */
    if (*lista == NULL || valor < (*lista)->dato)
    {
        nuevo->sig = *lista;
        *lista = nuevo;
        return;
    }

    ant = *lista;
    act = (*lista)->sig;
    
    // Avanza hasta encontrar la posicion correcta segun la clave
    while(act != NULL && act->dato < valor)
    {
        ant = act;
        act = act->sig;
    }

    ant->sig = nuevo;
    nuevo->sig = act; // Enlaza con el siguiente nodo (NULL si es el ultimo)
}

/* ---- MOSTRAR LA LISTA ---- */
void mostrar(struct Nodo *lista)
{
    while (lista != NULL)
    {
        printf("%d -> ", lista->dato);
        lista = lista->sig;
    }
    printf("NULL\n");
}

/* ---- BUSCAR UN VALOR ---- */
struct Nodo *buscar(struct Nodo *lista, int valor)
{
    while (lista != NULL && lista->dato != valor)
    {
        lista = lista->sig;
    }

    return lista;
}

/* ---- BORRA UN NODO POR VALOR ---- */
void borrar(struct Nodo **lista, int valor)
{
    struct Nodo *act, *ant;

    if (*lista == NULL)
        return;

    /* --- Borrar primer nodo --- */
    if ((*lista)->dato == valor)
    {
        act = *lista;
        *lista = act->sig;
        free(act);
        return;
    }

    ant = *lista;
    act = ant->sig;

    // Recorre la lista buscando el nodo con el valor a borrar
    while (act != NULL && act->dato != valor)
    {
        ant = act;
        act = act->sig;
    }

    if (act != NULL)
    {
        /* Borrar el nodo encontrado: 
            - Intermedio si: ( act->sig != NULL) 
            - Ultimo si: (act->sig == NULL)
        */
        ant->sig = act->sig;
        free(act);
    }
}

/* ---- LIBERAR TODA LA LISTA ---- */
void liberar(struct Nodo **lista)
{
    struct Nodo *aux;

    while (*lista != NULL)
    {
        aux = *lista;
        *lista = aux->sig;
        free(aux);
    }
}

int main(void)
{
    struct Nodo *lista = NULL; // Inicializamos el puntero a struct Nodo vacio.
    
    /* ---- INSERCIONES ---- */
    insertar(&lista, 10); // Lista vacia -> Primer nodo
    insertar(&lista, 5);  // Insercion al comienzo
    insertar(&lista, 20); // Insercion al final
    insertar(&lista, 15); // Insercion intermedia entre 10 y 20

    mostrar(lista); // 5 -> 10 -> 15 -> 20 -> NULL 

    /* ---- BORRADOS ---- */
    borrar(&lista, 5); // Borrar Primero
    mostrar(lista);    // 10 -> 15 -> 20 -> NULL

    borrar(&lista, 15); // Borrar Intermedio
    mostrar(lista);     // 10 -> 20 -> NULL

    borrar(&lista, 20); // Borrar Ultimo
    mostrar(lista);     // 10 -> NULL

    /* ---- BUSQUEDA ---- */
    if (buscar(lista, 20))
    {
        printf("Encontrado\n");
    }
    else
    {
        printf("No encontrado\n");
    }

    if (buscar(lista, 10))
    {
        printf("Encontrado\n");
    }
    else
    {
        printf("No encontrado\n");
    }

    liberar(&lista); // lista queda en NULL
    mostrar(lista); // Solo didactico para ver la liberacion

    return 0;
}