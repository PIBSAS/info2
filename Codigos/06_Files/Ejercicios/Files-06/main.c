// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getch()
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de punteros a FILE.
     * in  => flujo de entrada (archivo origen).
     * out => flujo de salida (archivo destino).
     */
    FILE *in, *out;

    /* Variable de tipo char inicializada en 0.
     * Se utiliza para almacenar cada caracter leido del archivo
     * y como condicion de corte del bucle.
     */
    char c;

    /* Apertura del archivo origen en modo lectura.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if (!(in = fopen("Archiv1.c", "r")))
    {
        printf("\n\nError de apertura\n\n");
        exit(1);
    }

    /* Apertura del archivo destino en modo escritura.
     * Si no existe, se crea.
     * Si existe se sobreescribe.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error-
     */
    if (!(out = fopen("Arc.c", "w")))
    {
        printf("\n\nError de apertura\n\n");
        exit(1);
    }

    printf("\n\n");

    /* Bucle de copia caracter por caracter.
     * Mientras no se alcance el fin del archivo origen:
     * - fgetc() lee un caracater desde in.
     * - fputc() lo escribe en el archivo out.
     * - printf() lo muestra en pantalla.
     */
    while(!feof(in))
    {
        c = fgetc(in);

        /* Escritura del caracter leido en el archivo destino */
        fputc(c,out);

        /* Visualizacion en salida estandar */
        printf("%c", c);
    }

    /* Cierre de los archivos.
     * Libera los recursos asociados al flujo.
     */
    fclose(in);
    fclose(out);

    /* getch():
     * Pausa la ejecucion hasta presionar una tecla.
     */
    getch();

    return 0;
}
