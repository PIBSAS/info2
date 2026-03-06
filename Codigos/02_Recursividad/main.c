// gcc -std=c11 -Wall -Wextra -pedantic main.c -o recursividad
/*
    Que es la recursividad-recursion?
    Es una tecnica donde una funcion se llama a si misma para resolver un problema.
    - La idea clave es esta:
        Un problema grande se resuelve dividiendolo en subproblemas mas chicos del mismo tipo.
    - Ejemplos:
        Para calcular factorial(5)
        - Necesito factorial(4)
            - Necesito factorial(3)
                - ...
                    - Hasta llegar a un caso simple que se resolver directo.
    
    Las 2 partes OBLIGATORIAS de toda funcion recursiva
        Si falta alguna de estas, el programa entra en recursion infinita (y termina en stack overflow)
    - Caso base:
        Es la condicion de corte.
        El caso mas simple del problema, que NO hace mas llamadas recursivas.
    - Caso recursivo:
        Es donde la funcion se llama a si misma, pero con un problema mas chico.
        - IMPORTANTE:
            Cada llamada recursiva debe acercarse al caso base.
    
    Para que se usa?
    Cuando el problema tiene estructura naturalmente recursiva, por ejemplo:
    - Definiciones matematicas:
        - Factorial.
        - Potencia
        - Fibonacci
    - Estructuras de datos:
        - Arboles-Tree
        - Listas enlazadas-Linked list
    - Algoritmos clasicos:
        - Busqueda binaria
        - Quicksort
        - Mergesort
    - Procesar cosas "anidadas":
        - Directorios
        - Expresiones matematicas
        - Parentesis
    IMPORTANTE:
        No todo lo recursivo es mejor que lo iterativo. En C muchas veces el for o while es:
        - Mas rapido
        - Mas eficiente en memoria
        Pero la recursividad:
        - Es mas clara
        - Expresa mejor la idea del problema

    Tiene alguna sintaxis especial?
    - NO, la recursividad-recursion NO tiene sintaxis propia en C.
    Es una funcion comun, la unica diferencia es que:
    - Dentro de su cuerpo.
    - Se llama a si misma.

    Tipos de Recursividad-Recursion:
        - Directa:
            - Una funcion se llama a si misma directamente.
            - void f(...)
            - {
            -   ...
            -   f(...);
            - }
            - Factorial, Suma, Fibonacci, Recursividad con arrays.
        - Indirecta:
            - Una funcion no se llama a si misma, sino que llama a otra, que eventualmente vuelve a llamar a la primera.
            - void A(int n)
            - {
            -   if (n > 0)
            -       B(n - 1);
            - }
            - void B(int n)
            - {
            -   if (n > 0)
            -       A(n - 1);
            - }
            Llamadas A -> B -> A -> B -> ...
            Esto casi no se usa en C inicial.
            Aparece en:
            - Analisis sintactico.
            - Automatas.
            - Estados.
        - Recursividad lineal:
            En cada llamada:
            - La funcion hace una sola llamada recursiva.
            - int f(n)
            - {
            -   return algo + f(n -1);
            - }
            Como sucede en:
            - Factorial.
            - Suma.
            - Recursividad con arrays.
            Son fáciles de razonar y convertir en iterativas.

        Profundidad de la recursión

            En la recursividad lineal, cada llamada genera una sola llamada recursiva.
            Esto provoca que la cantidad máxima de llamadas activas al mismo tiempo en la pila (stack)
            sea proporcional al tamaño del problema.

            Por eso se dice que la profundidad de la recursión es O(n):
            - si n crece, la cantidad de llamadas en la pila crece de forma lineal.

        - Recursividad multiple:
            En una llamada:
            - Se hacen 2 o mas llamadas recursivas.
            - int f(n)
            - {
            -   return f(n - 1) + f(n - 2);
            - }
            Como sucede en:
            - Fibonacci
            Son muy ineficientes, explosion de llamadas (Se llama 2 o mas veces en una llamada. Existiendo una duplicacion de subproblemas), crecimiento exponencial.

    Ejemplo clasico:
    - Factorial:
        - n! = n * (n - 1)!
        - 0! = 1
    Que pasa internamente con factorial(5)?
        Fase de llamadas (expansion de la expresion):
        - factorial(5)
        -> 5 * factorial(4)
        -> 5 * (4 * factorial(3))
        -> 5 * (4 * (3 * factorial(2)))
        -> 5 * (4 * (3 * (2 * factorial(1))))
        -> 5 * (4 * (3 * (2 * (1 * factorial(0)))))
        Caso base:
        -> factorial(0) = 1 // Caso base, ya no se llama asi mismo
        
        Sustitucion y evaluacion:
        -> 5 * (4 * (3 * (2 * (1 * 1))))
        -> 5 * (4 * (3 * (2 * 1)))
        -> 5 * (4 * (3 * 2))
        -> 5 * (4 * 6)
        -> 5 * 24
        -> 120
        
        Una vez alcanzado el caso base, las llamadas retornan en orden inverso al que fueron realizadas, liberandose los marcos de activacion de la pila-stack.
    
    La pila (stack): concepto clave
        Cada llamada a funcion:
        - Guarda parametros.
        - Variables locales.
        - Direccion de retorno.
        Esto va a la pila de ejecucion.
        En recursividad:
        - Cada llamada ocupa un nuevo "nivel" en la pila.
        - Demasiadas llamadas => stack overflow
        Por eso:
        - SIEMPRE debe haber CASO BASE.
        - Y la dimension del problema debe reducirse.
    
    Ejemplo 2:
    - Suma de los primeros N numeros:
        - suma(n) = n + suma(n - 1)
        - suma(0) = 0
        - int suma(int n)
        - {
        -   if (n == 0) Caso base
        -       return 0;
        -   else
        -       return n + suma(n - 1);
        - }
        Esto es recursivo por definicion, pero ...
    - Version iterativa:
        - int suma(int n)
        - {
        -   int total = 0;
        -   for (int i = 1; i <= n; i++)
        -       total += i;
        -   return total;
        - }
        Aca se ve claro:
        - Recursiva: mas "elegante"
        - iterativa: mas eficiente.
    
    Ejemplo 3:
    - Fibonacci:
        - fib(0) = 0 Caso base
        - fib(1) = 1 Caso base
        - fib(n) = fib(n - 1) + fib(n - 2)
    - int fib(int n)
    - {
    -   if (n == 0) // Caso base
    -       return 0;
    -   if (n == 1) // Caso base
    -       return 1;
    -   return fib(n - 1) + fib(n - 2);
    - }
    Este ejemplo es didactico, pero:
    - Es muy ineficiente.
    - Repite calculos.
    - Explota rapido la pila-stack

    Ejemplo 4:
    - Recursividad con arrays
        Imprimir un array recursivamente.
        - void imprimir(int v[], int n)
        - {
        -   if (n == 0) Caso base
        -       return;
        -   imprimir(v, n - 1);
        -   printf("%d ", v[n - 1]);
        - }
        IMPORTANTE:
        - La dimension se reduce (n - 1).
        - El array NO SE COPIA, solo se pasa la direccion.
    
    Errores tipicos:
        - No tener caso base.
        - Caso base mal definido.
        - No reducir el problema.
        - Confundir retorno con impresion.
        - Creer que es "mas magica" que un loop.
    
    Consideraciones para resolver ejercicios de recursividad-recursion:
        Cuando vemos un ejercicio recursivo, preguntarnos:
        - Cual es el caso base mas simple?
        - Como expresamos el problema en funcion del mismo problema mas chico?
        - Que parametro se achica en cada llamada?
        Si no podemos responder esas tres preguntas entonces todavia no es recursivo.
    
    La recursividad es mas relevante en:
        - Listas enlazadas - Linked list
        - Arboles - Tree
        - Backtracking.
*/

#include <stdio.h>

/* ---- FACTORIAL ---- */
int factorial(int n)
{
    if (n == 0) // Caso base
        return 1;
    else
        return n * factorial(n - 1); // Caso recursivo
}

/* ---- SUMA ---- */
int suma(int n)
{
    if (n == 0) // Caso base
        return 0;
    else
        return n + suma(n - 1); // Caso recursivo
}

/* ---- FIBONACCI ---- */
int fib(int n)
{
    if (n == 0) // Caso base
        return 0;
    if (n == 1)
        return 1; // Caso base
    return fib(n - 1) + fib(n - 2); // Caso recursivo
}

/* ---- RECURSIVIDAD CON ARRAYS ---- */
void imprimir(int v[], int n)
{
    if (n == 0) // Caso base
        return;
    imprimir(v, n -1); // Caso recursivo
    printf("%d ", v[n -1]);
}

int main(void)
{
    /* ---- FACTORIAL ---- */
    int n = 5;
    printf("Factorial de %d = %d\n", n, factorial(n));

    /* ---- SUMA ---- */
    printf("Suma de los primeros %d numeros = %d\n", n, suma(n));

    /* ---- RECURSIVIDAD CON ARRAYS ---- */
    int v[]= {1, 2, 3, 4, 5};
    imprimir(v, 5);

    return 0;
}