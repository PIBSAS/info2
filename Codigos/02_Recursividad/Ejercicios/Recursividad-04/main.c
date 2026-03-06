// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
/*
    Recursion correcta pero ineficiente (fibonacci)
*/
#include <stdio.h>

/* Prototipo de la funcion recursiva Fibonacci*/
int fibo(int);

int main(void)
{
    /* Declaracion de variables enteras sin inicializar */
    int x, f;
    
    /* Lectura del valor de x sin validacion */
    scanf("%d", &x);

    /* Primer llamada recursiva, pasado el argumento x 
     * y almacenado su retorno en la variable entera f. */
    f = fibo(x);

    /*Mostrar el valor ingresado y lo devuelto por la funcion usando los especificadores correctos. */
    printf("\n%d\t%d", x, f);

    return 0;
}

/* Declaracion de funcion recursiva fibo:
 * Parametro:
 * - n (Cada llamada tiene su propia copia)
 * Devuelve:
 * - a, valor calculado de la sucesion */
int fibo(int n)
{
    /* Declaracion de variable sin inicializar */
    int a;

    /* Caso base, si ne es menor a 2, a devuelve 1*/
    if (n < 2)
        a = 1;
    else
        a = fibo(n - 2) + fibo(n - 1); // Caso recursivo. se llama dos veces a la funcion, cada llamada genera dos nuevas llamadas. PROBLEMA: Explosion exponencial de llamadas (overflow)

    return a;
}
