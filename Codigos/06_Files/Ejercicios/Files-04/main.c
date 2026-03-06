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
    
    /* Bucle de lectura caracter por caracter desde el archivo.
     * En cada iteracion:
     * - fgetc() lee el siguiente caracter del flujo.
     * - putchar() lo muestra en pantalla.
     * Finaliza cuando se detecta el caracter numeral.
     */
    while (c != '#')
    {
        /* fgetc():
         * Lee un caracter del archivo apuntado por fp.
         * Avanza automaticamente la posicion del cursor.
         */
        c = fgetc(fp);

        /* putchar():
         * Escribe en la salida estandar (stdout) el caracter leido.
         */
        putchar(c);
    }

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo abierto en modo lectura.
     */
    fclose(fp);

    return 0;
}
