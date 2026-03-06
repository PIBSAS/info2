// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

    /* Vector de caracteres (cadena).
     * Capacidad maxima 49 caracteres + '\0'.
     */
    char str[50];

    /* Variable entera.
     * Almacena la cantidad maxima de caracteres a leer en cada llamada a fgets().
     */
    int largo;

    /* scanf():
     * Lee un valor entero ingresado por teclado
     * y lo almacena en la variable largo.
     * Se pasa la direccion de memoria (&largo).
     */
    scanf("%d", &largo);

    /* Apertura del archivo en modo lectura.
     * El archivo debe existir.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if (!(fp = fopen("arcstr.txt", "r")))
    {
        printf("\n\nError de apertura\n\n");
        exit(1);
    }

    printf("\nLECTURA DEL  ARCHIVO\n\n");

    /* Bucle de lectura hasta fin de archivo.
     * En cada iteracion:
     * - fgets() lee hasta (largo - 1) caracteres.
     * - Agrega el caracter '\0' al final de la cadena.
     * - puts() muestra la cadena en pantalla.
     */
    while(!feof(fp))
    {
        /* fgets():
         * Lee desde el archivo fp como maximo (largo - 1) caracteres.
         * Se detiene  si encuentra '\n' o EOF.
         */
        fgets(str, largo, fp);

        /* puts():
         * Muestra la cadena en la salida estandar
         * y agrega automaticamente un salto de linea.
         */
        puts(str);
    }

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(fp);

    return 0;
}
