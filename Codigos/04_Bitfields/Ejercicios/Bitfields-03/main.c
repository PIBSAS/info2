// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa rand()

/* Declaracion de estructura con campos de bits. */
struct alfa
{
    unsigned d:5; // 0 a 31
    unsigned s:2; // 0 a 3
    unsigned v:1; // 0 o 1
};

struct beta
{
    unsigned d:5;
    unsigned s:2;
};

int main(void)
{
    /* inp se utiliza como estructura auxiliar para generar datos.
     * datos es un vector de estructuras donde se almacenan los valores generados
      */
    struct alfa inp;
    struct beta dat[20];
    int a;
    
    /* Se genera un valor aleatorio 0 o 1.
     * rand()%2 produce 0 o 1.
     * Se almacena en el campo de 1 bit v.
     */
    inp.v = rand()%2;

    /* Se repoite 20 veces:
     * - Se generan valores aleatorios para s (0 a 3) y d (0 a 31)
     * - Mientras v sea 0, se sigue generando hasta que sea 1
     * - Se copian los valores de d y s al vector dat
     * - Se vuelve a generar un nuevo valor para v
     */
    for (a = 0; a < 20; a++)
    {
        inp.s = rand()%4;  // 2 bits => 0 a 3
        inp.d = rand()%32; // 5 bits => 0 a 31

        while (!inp.v)
        {
            inp.v = rand()%2;
        }

        dat[a].d = inp.d;
        dat[a].s = inp.s;

        inp.v = rand()%2;
    }

    /* Mostrar mensaje como titulos de una tabla */
    printf("CAN\tDAT\tCAN\tDAT\n");

    /* Se imprimen los valores almacenados.
     * ATENCION: cuando a == 19 se accede a dat[20],
     * lo que esta fuera de los limites del vector y produce (UB).
      */
    for (a = 0; a < 20; a++)
    {
        printf("%d\t%d\t%d\t%d\n", dat[a].s, dat[a].d, dat[a + 1].s, dat[a + 1].d);
    }

    return 0;
}