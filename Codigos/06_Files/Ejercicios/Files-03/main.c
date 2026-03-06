// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getche()
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

    /* Variable de tipo char inicializada en 0.
     * Almacena cada caracter ingresado por teclado.
     * Se utiliza como condicion de corte del bucle */
    char c = 0;

    /* Apertura de archivo en modo escritura.
     * w => Modo write:
     *      - Si el archivo NO existe, lo crea.
     *      - Si el archivo EXISTE, lo sobreescribe pero perdiendo el contenido anterior
     */
    fp = fopen("nuevoarc.txt", "w");

    /* Verificacion de error en la apertura.
     * Si fopen devuelve NULL, la operacion fallo (problemas de permisos, ruta invalida, etc.).
     */
    if (fp == NULL)
    {
        printf("\n\nError de apertura\n\n");

        /* Finalizacion del programa con codigo de error */
        exit(1);
    }
    
    /* Bucle de ingreso de caracteres.
     * Se ejecuta hasta que el usuario ingrese numeral.
     */
    while (c != '#')
    {
        /* getche():
         * Lee un caracter desde el teclado (stdin) y lo muestra en pantalla (stdout).
         */
        c = getche();

        /* fputc():
         * Escribe un caracter en el archivo apuntado por fp.
         * El caracter se almacena en el buffer del flujo.
         */
        fputc(c, fp);
    }

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     * En modo w. si el archivo fue creado, queda efectivamente generado al cerrarlo.
     */
    fclose(fp);

    return 0;
}
