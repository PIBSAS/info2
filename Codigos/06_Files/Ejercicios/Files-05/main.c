// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

    /* Variable de tipo char inicializada en 0.
     * Se utiliza para almacenar cada caracter leido del archivo
     * y como condicion de corte del bucle.
     */
    char c = 0;

    /* Apertura de archivo en modo lectura.
     * El cursor se posiciona al inicio del archivo.
     */
    fp = fopen("nuevoarc.txt", "r");

    /* Verificacion de error en la apertura.
     * Si fopen devuelve NULL, la operacion fallo (problemas de permisos, ruta invalida, etc.).
     */
    if (fp == NULL)
    {
        printf("\n\nError de apertura\n\n");

        /* Finalizacion del programa con codigo de error */
        exit(1);
    }
    
    /* Bucle do-while. Se ejecuta al menos una vez.
     * En cada iteracion:
     * - fgetc() lee un caracter del archivo.
     * - putchar() lo muestra en pantalla.
     */
    do
    {
        /* fgetc():
         * Lee el siguiente caracter del flujo.
         * Avanza automaticamente el cursor.
         */
        c = fgetc(fp);

        /* putchar():
         * Muestra en la salida estandar (stdout) el caracter leido.
         */
        putchar(c);
    }
    /* feof():
     * Devuelve verdadero cuando se alcanza el fin de archivo (EOF).
     */
    while(!feof(fp));

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo abierto en modo lectura.
     */
    fclose(fp);

    return 0;
}
