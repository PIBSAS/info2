// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

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

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     * En modo w. si el archivo fue creado, queda efectivamente generado al cerrarlo.
     */
    fclose(fp);

    return 0;
}