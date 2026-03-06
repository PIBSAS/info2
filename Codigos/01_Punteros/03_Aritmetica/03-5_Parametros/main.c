// gcc -std=c11 -Wall -Wextra -pedantic main.c -o parametros

/*
    Pasaje de parametros por referencia
    - En C NO existe el pasaje por referencia como concepto del lenguaje.
    - C siempre pasa los argumentos por valor.
    - Lo que hacemos en C es:
        - Pasar la direccion de un objeto.
        - Y operar sobre ese objeto a traves de un puntero.
    
    Ejemplo clasico:
    - Porque NO funciona el "pasaje por valor"
    - void cambiar(int x)
    - {
    -   x = 100;
    - }
    - int main(void)
    - {
    -   int a = 10;
    -   cambiar(a);
    -   printf("%d\n", a); // Imprime 10
    -   return 0;
    - }
    Que sucede aca?
    - a vale 10.
    - Se copia su valor en x
    - Se modifica la copia.
    - a nunca cambia
    - Esto es pasaje por valor puro

    Solucion:
    - Pasar la direccion(Puntero)
    - void cambiar(int *p)
    - {
    -   *p = 100;
    - }
    - int main(void)
    - {
    -   int a = 10;
    -   cambiar(&a);
    -   printf("%d\n", a); // Imprime 100
    -   return 0;
    - }
    Que sucede aca?
    - int a = 10; // Asignacion de variable
    - cambiar(&a); Direccion de memoria de a, se pasa esa dioreccion a la funcion
    - void cambiar(int *p) p recibe una copia de la direccion, p apunta a a

    Desreferenciacion object-of a:
    - *p = 100; Se escribe en la memoria de a el valor 100, a cambia.
    - No se paso a por referencia.
    - Se paso la direccion de a por valor

    Relacion con arrays:
    - void imprimir(int *p, int n)
    - {
    -   for (int i = 0; i < n; i++)
    -       printf("%d ", p[i]);
    - }

    Llamada:
    - int a[5] = {1, 2, 3, 4, 5};
    - imprimir(a, 5);
    - a decae a &a[0]
    - Se pasa un puntero
    - La funcion accede al array original. Los arrays siempre se pasan por referencia en la practica
    - Porque lo que se pasa es su direccion inicial.
*/

#include <stdio.h>

/* ---------- Ejemplo 1: PASAJE POR VALOR (NO FUNCIONA) ---------- */

void cambiar_valor(int x)
{
    x = 100;   // Se modifica SOLO la copia
}

/* ---------- Ejemplo 2: PASAJE DE DIRECCION (FUNCIONA) ---------- */

void cambiar_direccion(int *p)
{
    *p = 100;  // Se modifica el objeto apuntado
}

/* ---------- Ejemplo 3: ARRAY COMO PARAMETRO ---------- */

void imprimir_array(int *p, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int main(void)
{
    /* ===== Ejemplo 1 ===== */
    int a = 10;

    printf("Antes de cambiar_valor: a = %d\n", a);
    cambiar_valor(a);
    printf("Despues de cambiar_valor: a = %d\n", a);

    /*
        a NO cambia porque:
        - Se paso el valor 10
        - Se modifico una copia
    */

    /* ===== Ejemplo 2 ===== */
    printf("\nAntes de cambiar_direccion: a = %d\n", a);
    cambiar_direccion(&a);
    printf("Despues de cambiar_direccion: a = %d\n", a);

    /*
        a cambia porque:
        - Se paso su direccion
        - Se escribio en su memoria
    */

    /* ===== Ejemplo 3 ===== */
    int v[5] = {1, 2, 3, 4, 5};

    printf("\nArray original:\n");
    imprimir_array(v, 5);

    /*
        v decae a &v[0]
        Se pasa la direccion del primer elemento
        La funcion accede al array original
    */

    return 0;
}