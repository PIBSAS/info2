// gcc -std=c11 -Wall -Wextra -pedantic main.c -o aritmetica

/*
    - Aritmetica de punteros (+, -, ++, --)
        Que hace?:
        - NO trabaja en bytes, trabaja en elementos del tipo apuntado.
        - Un puntero "sabe" a que tipo apunta.
        - La aritmetica esta definida dentro de un mismo array.

        Operaciones permitidas:
        - +: p + n Donde n es un numero. Valido si el resultado permanece dentro del mismo array (o uno despues del ultimo).
        - -: p - n
        - ++: p++
        - --: p--
        - p1 -p2 Solo si apuntan al mismo array
    
        Operaciones que NO TIENEN SENTIDO con punteros:
        - p + p
        - *: Multiplicacion  p * n Causa error
        - /: Division p / n Causa error
        - %: Modulo p % n Causa error
        - Operaciones con float.
        - Desplazamientos (<<, >>)
        - Operaciones lógicas (&&, ||)

        Regla formal importante:
        - La aritmetica de punteros esta definida unicamente cuando el puntero
        - apunta a elementos de un mismo array (o one-past-the-end).
        - Fuera de ese contexto -> comportamiento indefinido (UB).

        Regla fundamental
        - Sea T cualquier tipo valido en C:
        - T *p;
        - Entonces:
        - p + 1 ==> avanza sizeof(T) bytes. NO SUMA 1 byte. NO SUMA direcciones arbitrariamente.
        - Suma 1 elemento del tipo T.

        En general:
            - p + n -> avanza n * sizeof(T) bytes
        
        Ejemplo con array:
        - int a[5] = {10, 20, 30, 40, 50}; vector de 5 elementos 0-4 de tipo entero llamado a
        - int *p = a; Equivale a &a[0] es decir le esta asignando la direccion el primer elemnto del array declarado
        - p = p + 1; Avanza sizeof(int) bytes, apunta al siguiente elemento (a[1] cuyo valor en esa direccion es 20). No suma bytes, suma elementos del tipo de dato.
        - Si sizeof(int) == 4 cada +1, mueve 4 bytes, pero eso es un detalle de implementacion.
        - Un puntero solo puede apuntar a elementos validos del array. Un elemento despues del ultimo (ome-past-the-end) como puntero pero no se puede desreferenciar
        - Un puntero NO puede desreferenciar fuera del array. Apuntar antes del primer elemento (a[-1])
        - Valido:
        - int *p = a + 5; Apunta "uno despues" de a[4]
        - Invalido:
        - *p = *(a + 5); Comportamiento indefinido(UB)
        - p = a - 1; Comportamiento indefinido(UB)
    
    - Especificador de formato %td
    - Especificador de formato para imprimir valores del tipo ptrdiff_t es %td
    Que es ptrdiff_t?:
        - Cuando restamos dos punteros del mismo array:
        - p - a; No devuelve int, ni size_t, devuelve ptrdiff_t
        Que representa?:
        - La cantidad de elementos entre ambos punteros
        - Puede ser positivo o negativo.
        Se debe incluir para seguir el estandar, la libreria stddef.h
    
*/

#include <stdio.h>
#include <stddef.h> //Puede omitirse porque no declaramos nada del tipo ptrdiff_t pero el estandar lo recomienda

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a; // Declaracion y asignacion de la direccion del primer elemento del array, es decir apunta a a[0].

    printf("p apunta a a[0] cuyo valor almacenado en esa direccion es: %d\n", *p);

    p = p + 1;
    printf("p + 1 apunta a a[1], cuyo valor almacenado en esa direccion es: %d\n", *p);

    p++; //sumamos 1 elemento, llevandonos de a[1] a a[2]
    printf("\np++ apunta a a[2], cuyo valor almacenado en la direccion es: %d\n", *p);

    p = p - 2;
    printf("\np - 2 vuelve a a[0], cuyo valor almacenado en la direccion es: %d\n", *p);

    /*
    One-past-the-end es valido como puntero
    pero NO se puede desreferenciar
    */
    p = a + 5;
    printf("\np apunta a one-past-the-end (a + 5)\n");
    printf("Direccion de p %p\n", (void *)p);
    /*
        Comparacion valida
    */
    if (p > a)
    {
        printf("p es mayor que a (apunta a una direccion mas alta)\n");
    }
    /*
        Diferencia entre punteros
    */
    printf("\nCantidad de elementos entre p y a: %td\n", p - a);
    

    return 0;
}