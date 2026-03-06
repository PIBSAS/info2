// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <string.h> // Se usa strcpy()
#include <stdlib.h> // Se usa exit()

int main(void)
{
	/* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
	FILE *fp;

	/* Vector de caracteres (cadena).
     * Capacidad maxima 49 caracteres + '\0'.
     * Variable de tipo char inicializada con el caracter 'x'
     */
	char str[50], c = 'x';

	/* Variables enteras:
     * i => se utiliza como contador en los bucles.
     * j => se utiliza como contador independiente en la lectura.
     */
	int i, j;

	/* Variable de tipo float inicializada */
	float f = 1.1;

	/* strcpy():
     * Copia la cadena constante "PRUEBA" dentro del arreglo str 
     */
	strcpy(str, "PRUEBA");
	
	/* Apertura del archivo en modo escritura.
     * Si no existe, se crea.
     * Si existe se sobreescribe.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if(!(fp = fopen("arch2.txt", "w")))
	{
		printf("\n\nError de apertura\n\n");
		exit(1);
	}
	
    printf("\nESCRITURA DEL ARCHIVO\n\n");
	
	/* fprintf():
     * Escribe datos formateados en el archivo al que apunta fp.
     * %s\n => indica escritura de cadena con separador '\n'.
     */
    fprintf(fp, "%s\n", str);
	printf("%s\n", str);
	
    for(i = 0; i < 10; i++)
	{
		/* fprintf():
         * Escribe datos formateados en el archivo al que apunta fp.
         * %d => escribe un entero en formato decimal.
         */
		fprintf(fp, "%d,", i);
		printf("%d\n", i);
	}
	
	/* fprintf():
     * Escribe datos formateados en el archivo al que apunta fp.
     * %c => escribe un caracter.
     */
    fprintf(fp,"%c,", c);
	printf("%c\n", c);
	
    for(i = 0; i < 10; i++)
	{
		/* fprintf():
         * Escribe datos formateados en el archivo al que apunta fp.
         * %f => escribe un numero de tipo float en formato decimal.
         */
		fprintf(fp, "%f,", f);
		printf("%f\n", f);

		f *= 1.1;
	}

	/* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
	fclose(fp);
	
	/* Apertura del archivo apuntado por fp en modo lectura.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if(!(fp = fopen("arch2.txt", "r")))
	{
		printf("\n\nError de apertura\n\n");
		exit(1);
	}

	printf("\nLECTURA DEL ARCHIVO\n\n");
	
	/* fscanf():
     * Lee datos formateados desde el archivo al que apunta fp.
     * %s => lee una cadena hasta espacio o salto de linea. 
	 * '\n' en el formato No representa un salto literal,
	 * Sino que indica consumir cualquier cantidad de espacios en blanco
	 * (incluyendo '\n') posteriores.
     */
    fscanf(fp, "%s\n", str);
	
	/* puts():
     * Muestra la cadena en la salida estandar.
     * Agrega automaticamente un salto de linea.
     */
    puts(str);

	printf("\n");
	
    for(j = 0; j < 10; j++)
	{
		/* fscanf():
         * Lee datos formateados desde el archivo al que apunta fp.
         * %d, => lee un entero del archivo. Se usa el separado ','.
         * Se pasa la direccion de memoria (&i).
         */
		fscanf(fp, "%d,", &i);
		printf("%d\n", i);
	}

	printf("\n");
	
	/* fscanf():
     * Lee datos formateados desde el archivo al que apunta fp.
     * %c, => lee una caracter del archivo. NO ignora espacios en blanco.
     * Si hubiera un '\n' pendiente en el buffer, podria leerse como caracter.
	 * Se usa separador ','.
     */
    fscanf(fp, "%c,", &c);
	printf("%c", c);
	
    printf("\n");
	
    for(i = 0; i < 10; i++)
	{
		/* fscanf():
         * Lee datos formateados desde el archivo al que apunta fp.
         * %f, => lee un numero de tipo float. Se usa separador ','.
         */
		fscanf(fp, "%f,", &f);
		printf("%f\n", f);
	}

	/* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
	fclose(fp);
    
    return 0;
}
