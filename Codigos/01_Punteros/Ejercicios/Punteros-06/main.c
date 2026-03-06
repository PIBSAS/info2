// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable entera y punteros a int, char y float */
    int *pi, i;
    char *pc;
    float *pf;

    /* Asignacion de valor 0 a los punteros.
     * El valor 0 es convertido a puntero nulo.
     * Sin embargo, estos punteros no apuntan a ningun objeto
     * ni a ningun vector valido */
    pi = pc = pf = 0x0000;

    /* Aritmetica de punteros.
     * La aritmetica de punteros solo esta definida cuando el puntero
     * apunta a elementos de un mismo vector (o uno mas alla del final).
     * Como aca no apuntan a un objeto valido, los incrementos
     * producen comportamiento indefinido (UB). */
    for (i = 0; i < 10; i++)
    {
        printf("%p\t%p\t%p\n", pi, pf, pc);
        pi++; // Avanza 1 elemento de tipo int
        pf++; // Avanza 1 elemento de tipo float
        pc++; // Avanza 1 elemento de tipo char
    }

    /* Muestra las direcciones despues de los 10 incrementos:
    * pi = pi_inicial + 10 elementos de tipo int
    * pf = pf_inicial + 10 elementos de tipo float
    * pc = pc_inicial + 10 elementos de tipo char 
    * Ademas, el especificador %p espera argumentos de tipo void *,
    * por lo que corresponde realizar el cast explicito, pero en la cursada no se realiza.
    * Tener en cuenta que la aritmetica se realizo fuera de un vector valido,
    * por lo tanto, el comportamiento sigue siendo indefinido (UB). */
    printf("%p\t%p\t%p\n\n", pi, pf, pc);

    return 0;
}
