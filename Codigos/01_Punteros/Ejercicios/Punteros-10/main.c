// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    long int l, *pl;
    char *pc;
    float f, *pf;
    
    pl = &l;

    /* Obtener la direccion de la variable l*/
    scanf("%ld", &l);

    /* Mostrar la variable de l en formato decimal y hexadeximal y su direccion */
    printf("\n%ld\t%lx\t%p\n", l, l, &l);

    /* Se recorre la memoria del objeto 1 byte a byte (Mostrar la representacion en memoria del tipo de dato)
     * Esto permite observar:
     * Endianness (little vs big endian)
     * Representacion IEEE-754 del float.
     * Orden real de bytes.
     * En C esta permitido inspeccionar cualquier objeto
     * a traves de un puntero a char.
     * Esto permite observar su representacion interna
     * en memoria (orden de bytes, etc.).
     * Nota:
     * El limite +4 asume sizeof(long) == 4,
     * lo cual no esta garantizado por el estandar.
     * Si el sistema es de 32bits es correcto, pero
     * en la actualidad con sistemas de 64bits seria +8.
     * Seria mas correcto usar (unsigned char *) porque evita
     * posibles problemas de interpretacion de signo al imprimir*/
    for (pc = pl; pc < (char *)pl + 4; pc++) // Para hacerlo portable seria mejor for (pc = (char *)pl; pc < (char *)pl + sizeof(l); pc++)
        /* %2x espera unsigned int pero *pc es char que 
         * se promociona a int, deberia hacer cast (unsigned char)*pc
         * %p espera void * por lo tanto tambien un cast a (void *)pc */
        printf("%p\t%2x\n", pc, *pc); // Lo correcto  seria: printf("%p\t%2x\n", (void *)pc, (unsigned char)*pc); 
    
    /* Se repite el flujo para float */
    pf = &f;

    scanf("%f", &f);

    printf("\n%f\t%p\n", f, &f);

    for (pc = pf; pc < (char *)pf + 4; pc++) // Portable seria: for (pc = (char *)pf; pc < (char *)pf + sizeof(f); pc++) 
        printf("%p\t%2x\n", pc, *pc); // Lo correcto seria: printf("%p\t%2x\n", (void *)pc, (unsigned char)*pc); 
    
    return 0;
}
