// gcc -std=c11 -Wall -Wextra -pedantic main.c -o data

/*
    Que es una estructura de datos (data structure)?
        Es una forma particular de:
            - Organizar datos en memoria.
            - Acceder a ellos
            - Insertar y eliminar informacion.
            Con reglas bien definidas. NO es solo "guardar datos", sino como se comportan.
    
    Stack - Pila
        Que es?:
            Es una estructura de datos que sigue el principio:
                - LIFO: Last In, First Out.
                - Ultimo en entrar, primero en salir.
                Analogia:
                    - Una pila de platos.
                    - El ultimo plato que ponemos arriba es el primero que sacamos.

        Operaciones basicas del stack:
            - push: insertar un elemento.
            - pop: quitar un elemento.
            - peek/ top: ver el elemento del tope.
            - isEmpty: verificar si esta vacio.
        
        Usos tipicos del stack:
            - Llamadas a funciones (call stack)
            - Recursividad.
            - Deshacer.
            - Evaluacion de expresiones.
            - backtracking.
    
    Queue - Cola
        Que es?:
            Una cola es una estructura de datos que sigue el principio:
                - FIFO: First In, First Out.
                - Primero en entrar, primero en salir.
                Analogia:
                    - Fila del banco.
                    El primero que llega, es el primero que se atiende.

        Operaciones basicas del queue:
            - enqueue: insertar al final.
            - dequeue: eliminar del frente.
            - front: ver el primer elemento.
            - isEmpty: verificar si esta vacia.
        
        Usos tipicos del queue:
            - Planificacion de procesos.
            - Impresoras.
            - Buffers.
            - Atencion por orden de llegada.
            - Sistemas operativos.
    
    Stack vs Queue (Pila vs Cola)

    | Caracteristica | Pila (Stack) | Cola (Queue) |
    | -------------- | ------------ | ------------ |
    | Orden          | LIFO         | FIFO         |
    | Insercion      | Tope         | Final        |
    | Eliminacion    | Tope         | Frente       |
    | Analogia       | Platos       | Fila         |

    Circular Queue - Cola circular
        Que es?:
            Es una mejora de la cola lineal que permite reutilizar
            el espacio liberado cuando se desencolan elementos.
        
        Problema de la cola lineal:
            - El indice de escritura (final) solo avanza.
            - Aunque se liberen posiciones al frente, el espacio no puede reutilizarse.
            - Puede darse la condicion de:
                - Cola vacia y cola llena logicamente al mismo tiempo.
        
        Solucion:
            - Los indices de lectura (frente) y escritura (final) avanzan de forma circular.
            - Cuando alcanzan el final del arreglo, vuelven al inicio (salto circular).
        
        Caracteristicas:
            - FIFO
            - Uso eficiente de la memoria.
            - Requiere un criterio adicional para distinguir:
                - Cola vacia.
                - Cola llena.
        
        Formas de distinguir vacia y llena:
            - Uso de un flag (bandera)
            - Uso de un contador de elementos.
            - Dejar una posicion vacia (muy comun).
        
        En esta implementacion:
            - Se utiliza un contador de elementos.
            - La cola esta vacia cuando cantidad == 0;
            - La cola esta llena cuando cantidad == MAX.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* ..............................*/
/* ---- PILA (STACK) - LIFO ---- */
/* ..............................*/

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

/* --- Inicializar Pila (Stack) --- */
void inicializarPila(Pila *p)
{
    p->tope = -1;
}

/* --- Verificar si la Pila (stack) esta vacia --- */
int pilaVacia(Pila *p)
{
    return p->tope == -1;
}

/* --- Verificar si la Pila (stack) esta llena --- */
int pilaLlena(Pila *p)
{
    return p->tope == MAX - 1;
}

/* --- PUSH - APILAR --- */
int push(Pila *p, int valor)
{
    if (pilaLlena(p))
    {
        return 0;
    }

    p->datos[++p->tope] = valor;

    return 1;
}

/* --- POP - DESAPILAR --- */
/*
    Devuelve:
        - 1: Si pudo extraer el elemnto.
        - 0: Si la pila esta vacia.
*/
int pop(Pila *p, int *valor)
{
    if (pilaVacia(p))
    {
        return 0;
    }

    *valor = p->datos[p->tope--];
    
    return 1;
}

/* ..............................*/
/* ---- COLA (QUEUE) - FIFO ---- */
/* ---- COLA LINEAL         ---- */ 
/* ..............................*/

typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

/* --- Inicializar Cola (Queue) --- */
void inicializarCola(Cola *c)
{
    c->frente = 0;
    c->final = -1;
}

/* --- Verificar si la Cola (queue) esta vacia --- */
int colaVacia(Cola *c)
{
    return c->frente > c->final;
}

/* --- Verificar si la Cola (queue) esta llena --- */
int colaLlena(Cola *c)
{
    return c->final == MAX - 1;
}

/* --- ENQUEUE - ENCOLAR --- */
int enqueue(Cola *c, int valor)
{
    if (colaLlena(c))
    {
        return 0;
    }

    c->datos[++c->final] = valor;

    return 1;
}

/* --- DEQUEUE - DESENCOLAR --- */
/*
    Devuelve:
        - 1: Si pudo extraer el elemnto.
        - 0: Si la cola esta vacia.
*/
int dequeue(Cola *c, int *valor)
{
    if (colaVacia(c))
    {
        return 0;
    }

    *valor = c->datos[c->frente++];
    
    return 1;
}

/* ................................................*/
/* ---- COLA CIRCULAR (CIRCULAR QUEUE) - FIFO ---- */
/* ................................................*/

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int cantidad;
} ColaCircular;

/* --- Inicializar Cola Circular (Circular queue) ---*/
void inicializarColaCircular(ColaCircular *c)
{
    c->frente = 0;
    c->final = 0;
    c->cantidad = 0;
}

/* --- Verificar si la Cola Circular (circular queue) esta vacia --- */
int colaCircularVacia(ColaCircular *c)
{
    return c->cantidad == 0;
}

/* --- Verificar si la Cola Circular (circular queue) esta llena --- */
int colaCircularLlena(ColaCircular *c)
{
    return c->cantidad == MAX;
}

/* --- CIRCULAR ENQUEUE - ENCOLAR CIRCULAR --- */
int enqueueCircular(ColaCircular *c, int valor)
{
    if (colaCircularLlena(c))
    {
        return 0;
    }

    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX; // % MAX es el "salto circular"
    c->cantidad++;

    return 1;
}

/* --- CIRCULAR DEQUEUE - DESENCOLAR CIRCULAR --- */
int dequeueCircular(ColaCircular *c, int *valor)
{
    if (colaCircularVacia(c))
    {
        return 0;
    }

    *valor = c->datos[c->frente];
    c->frente = (c->frente +1) % MAX; // % MAX es el "salto circular"
    c->cantidad--;

    return 1;
}

int main(void)
{
    Pila p;
    Cola c;
    int x;

    /* ---- PRUEBA DE PILA ---- */
    printf("PILA (STACK) - LIFO\n");
    inicializarPila(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    while (pop(&p, &x)) // x recibe el dato y el tope baja
    {
        printf("Pop: %d\n", x);
    }

    /* ---- PRUEBA DE COLA LINEAL ---- */
    printf("\nCOLA (QUEUE) - FIFO\n");
    inicializarCola(&c);

    enqueue(&c, 10);
    enqueue(&c, 20);
    enqueue(&c, 30);

    while(dequeue(&c, &x)) // x recibe el dato y el frente avanza
    {
        printf("Dequeue: %d\n", x);
    }

    /* ---- PRUEBA DE COLA CIRCULAR ---- */
    printf("\nCOLA CIRCULAR (FIFO)\n");

    ColaCircular cc;
    inicializarColaCircular(&cc);

    enqueueCircular(&cc, 1);
    enqueueCircular(&cc, 2);
    enqueueCircular(&cc, 3);
    enqueueCircular(&cc, 4);
    enqueueCircular(&cc, 5);

    while (dequeueCircular(&cc, &x)) // x recibe el dato y el frente avanza
    {
        printf("Dequeue circular: %d\n", x);
    }

    return 0;
}