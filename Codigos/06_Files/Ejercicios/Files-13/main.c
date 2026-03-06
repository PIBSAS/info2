// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa exit()

int main(void)
{
    /* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *in;

    /* Variable de tipo char.
     * Se utiliza para almacenar cada caracter leido del archivo.
     * Variable de tipo long.
     * Se utiiza para mostrar la posicion del indicador del archivo.
     */
	char c;
	long l;
	
    /* Apertura del archivo apuntado por 'in' en modo lectura.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if(!(in = fopen("Archiv01.c", "r")))
	{
		printf("\n\nError de apertura\n\n");
		exit(1);
	}

	printf("\n\n");
	
    /* ftell():
     * Devuelve la posicion actual del indicador de archivo medida en bytes desde el inicio.
     * in => puntero a FILE.
     */
    l = ftell(in);
	
    /* Muestra la posicion actual (inicio = 0) */
    printf("%ld", l);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 0 => desplazamiento
     * SEEK_END => referencia desde el final del archivo.
     *
     * Coloca el puntero al final del archivo.
     */
    fseek(in, 0, SEEK_END);
	
    printf("\n\n");
	
    /* ftell():
     * Devuelve la posicion actual del indicador de archivo medida en bytes desde el inicio.
     * in => puntero a FILE.
     */
    l = ftell(in);

    /* Muestra la posicion actual */
	printf("%ld", l);
	
    /* rewind():
     * Reposiciona el puntero al inicio del archivo.
     * Equivale a fseek(in, 0, SEEK_SET). 
     */
    rewind(in);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 200 => se desplaza 200 bytes
     * SEEK_SET => desde el inicio del archivo.
     *
     * Coloca el puntero en el byte 200 desde el inicio del archivo.
     */
    fseek(in, 200, SEEK_SET);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 220 => se desplaza 220 bytes
     * SEEK_SET => desde el inicio del archivo.
     *
     * Coloca el puntero en el byte 220 desde el inicio del archivo.
     */
    fseek(in, 220, SEEK_SET);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 1 => avanza 1 byte
     * SEEK_CUR => desde la posicion actual.
     */
    fseek(in, 1, SEEK_CUR);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 0 => no se mueve
     * SEEK_CUR => mantiene la posicion actual.
     */
    fseek(in, 0, SEEK_CUR);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 0 => no se mueve
     * SEEK_CUR => mantiene la posicion actual.
     *
     * No modifica la posicion actual del puntero.
     */
    fseek(in, 0, SEEK_CUR);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * -1 => retrocede 1 byte
     * SEEK_CUR => desde la posicion actual.
     */
    fseek(in, -1, SEEK_CUR);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 200 => se desplaza 200 bytes
     * SEEK_SET => desde el inicio del archivo.
     *
     * Coloca el puntero en el byte 200 desde el inicio del archivo.
     */
    fseek(in, 200, SEEK_SET);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * 200 => se desplaza 200 bytes
     * SEEK_SET => desde el inicio del archivo.
     *
     * Coloca el puntero en el byte 200 desde el inicio del archivo.
     */
    fseek(in, 200, SEEK_SET);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* fseek():
     * Desplaza el indicador de posicion del archivo.
     * in => puntero a FILE.
     * -150 => retrocede 150 bytes
     * SEEK_END => desde el final del archivo.
     *
     * Coloca el puntero 150 bytes antes del final del archivo.
     */
    fseek(in, -150, SEEK_END);
	
    /* fgetc():
     * Lee un caracter del archivo en la posicion actual
     * y avanza el puntero automaticamente una posicion.
     */
    c = fgetc(in);
	
    /* Muestra el caracter leido */
    printf("\n%c", c);
	
    /* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(in);
    
    return 0;
}