// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <string.h> // Se usa strcmp()
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

    /* Vector de caracteres (cadena).
     * Capacidad maxima: 49 caracteres + '\0'.
     */
    char str[50];

    /* Apertura del archivo en modo escritura.
     * Si no existe, se crea.
     * Si existe se sobreescribe.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if (!(fp = fopen("arcstr.txt", "w")))
    {
        printf("\n\nError de apertura\n\n");
        exit(1);
    }

    printf("\nESCRITURA DEL ARCHIVO\n\n");
    
    /* gets():
     * Lee una linea desde teclado hasta presionar ENTER.
     * Almacena la cadena en str.
     * No controla la dimension del buffer.
     * Fue eliminada en C11, por ser insegura y no controlar overflow buffer y se puede reemplazar con fgets():
     * fgets(str, sizeof(str),stdin);
     */
    gets(str);

    /* strcmp():
     * Compara dos cadenas.
     * Devuelve 0 si son iguales.
     * El bucle se repite mientras str sea distinta de FIN.
     */
    while(strcmp(str, "FIN"))
    {
        /* fputs():
         * Escribe una cadena en el archivo apuntado por fp.
         * No agrega automaticamente salto de linea.
         * Y como gets() lo elimina, el archivo se va a escribir sin saltos de linea.
         */
        fputs(str, fp);

        /* En C11 se elimino, se puede reemplazar con: 
         * fgets(str, sizeof(str), stdin);
         */
        gets(str);
    }

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(fp);

    /* Apertura del archivo apuntado por fp en modo lectura.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error-
     */
    if (!(fp = fopen("arcstr.txt", "r")))
    {
        printf("\n\nError de apertura\n\n");
        exit(1);
    }

    printf("\nLECTURA DEL ARCHIVO\n\n");

    /* feof():
     * Devuelve verdadero cuando se alcanza el fin de archivo (EOF).
     */
    while (!feof(fp))
    {
        /* fgets():
         * Lee hasta (n - 1) caracteres del archivo.
         * En este caso, como n = 5:
         * - Lee hasta 4 caracteres por vez.
         * - Agrega '\0' al final.
         * Puede detenerse antes si encuentra '\n' o EOF
         */
        fgets(str, 5, fp);

        /* puts():
         * Muestra la cadena en la salida estandar.
         * Agrega automaticamente un salto de linea.
         */
        puts(str);
    }

    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(fp);
    
    return 0;
}
