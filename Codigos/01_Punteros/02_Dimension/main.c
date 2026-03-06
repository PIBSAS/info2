// gcc -std=c11 -Wall -Wextra -pedantic main.c -o dimension
/*
    TODOS los punteros tienen la misma dimension/tamanio (usemos el sinonimo dimension para tamanio, para claridad en los comentarios).
    Sin importar a que tipo apunten, ya que su dimension proviene del tipo de arquitectura en 32 bits es de 4 bytes, en 64 bits es de 8 bytes, se puede verificar con sizeof()
    - sizeof(int *)
    - sizeof(float *)
    - sizeof(char *)
    - sizeof(double *)
    No confundir con sizeof(int).

    Ej:
    - int *pi;
    - float *pf;
    - char *pc;
    En una misma arquitectura, siempre sera cierto que:
    - sizeof(pi) == sizeof(pf) == sizeof(pc)

    Para imprimir sizeof(puntero a tipo de dato) usamos el especificador de formato %zu.
    Ej:
    - printf("%zu", sizeof(int *));
    - printf("%zu", sizeof(char *));
    Van a imprimir lo mismo, que corresponde a la dimension del puntero en esa arquitectura.

    No confundir:
    - int x;
    - int *pi = &x;
    - printf("%zu", sizeof(pi)); Dimension del puntero pi. Mostrara 8 bytes.
    - printf("%zu", sizeof(*pi)); Dimension del tipo de dato al que apunta pi. Mostrara 4 bytes ya que sizeof(int) es 4 bytes

    Relacion con arrays:
    - int a[10]; sizeof(a) da 10 * sizeof(int) = 10 * 4 bytes = 40 bytes
    - int *p = a; sizeof(p); da sizeof(int *) = 8 bytes
*/
#include <stdio.h>

int main(void)
{
    int x;
    char c;
    double d;

    int *pi = &x;
    char *pc = &c;
    double *pd = &d;

    printf("int *:\t%zu bytes\n", sizeof(pi)); // Dimension de puntero
    printf("int:\t%zu bytes\n", sizeof(*pi));  // Dimension de tipo de dato

    printf("char *:\t%zu bytes\n", sizeof(pc));
    printf("char:\t%zu bytes\n", sizeof(*pc));

    printf("double *:\t%zu bytes\n", sizeof(pd));
    printf("double:\t%zu bytes\n", sizeof(*pd));

    return 0;
}