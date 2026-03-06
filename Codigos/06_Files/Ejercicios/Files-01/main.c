// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

    /* Apertura de archivo en modo lectura y asignacion a fp
     * r => Modo lectura, el archivo debe existir, de no existir la funcion devuelve NULL
     */
    fp = fopen("nuevoarc.txt", "r");

    /* Si fopen falla, muestra mensaje y llama a la funcion exit con el parametro 1 */
    if (fp == NULL)
    {
        printf("\n\nError de apertura\n\n");

        /* exit(1):
         * - Finaliza el programa inmediatamente.
         * - El 1 indica terminacion con error.
         * - Por convencion:
         *   - 0    => Ejecucion correcta.
         *   - != 0 => Error
         */
        exit(1);
    }

    /* SIEMPRE se debe cerrar el archivo asociado al puntero para liberar recursos del sistema, el archivo debio abrirse correctamente */
    fclose(fp);

    return 0;
}