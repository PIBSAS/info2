// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <string.h> // Se usa strcpy()
#include <stdlib.h> // Se usa exit()

/* Declaracion de estructura */
struct x
{
    int i;
    float f;
    char c, str[10];
};

int main(void)
{
	/* Declaracion de un puntero a FILE.
     * Almacena la direccion del flujo asociado al archivo.
     */
    FILE *fp;

	/* Vectores de caracteres (cadenas).
     * Capacidad maxima 49 caracteres + '\0'.
     * Variable de tipo char inicializada con el caracter 'x' y variable no inicializada
     */
	char str[50], c = 'x', str1[50], c1;

	/* Variables enteras:
     * i => se utiliza como contador en los bucles.
     * j => se utiliza como contador independiente en la lectura.
	 * Vector de tipo int de dimension 10.
     */
	int i, j, k[10];

	/* Variable de tipo float inicializada y vector de tipo float de dimension 10 */
	float f = 1.1, g[10];

	/* Variables de tipo struct x */
	struct x st, st1;
	
	/* Inicializacion de los campos de la estructura*/
    st.i = 11;
	st.f = 3.14159;
	st.c = 'J';

	/* strcpy():
	 * Copia la cadena constante "prueba" dentro del campo str de la estructura st.
     * Copia la cadena constante "PRUEBA" dentro del vector str 
     */
	strcpy(st.str, "prueba");
	strcpy(str, "PRUEBA");
	
	/* Apertura del archivo apuntado por fp en modo escritura-binaria.
	 * w => escritura (crea el archivo o lo sobreescribe si existe).
	 * b => modo binario.
     * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if(!(fp = fopen("arch.bin", "wb")))
	{
		printf("\n\nError de apertura\n\n");
		exit(1);
	}

	printf("\nESCRITURA DEL ARCHIVO\n\n");
	
	/* fwrite():
	 * Escribe datos binarios en el archivo.
	 * str         => direccion del bloque de memoria a escribir.
	 * sizeof(str) => dimension total del vector (50 bytes).
	 * 1           => cantidad de bloques a escribir.
	 * fp          => puntero a FILE.
	 */
    fwrite(str, sizeof(str), 1, fp);
	
	/* Muestra el vector str*/
    printf("%s\n", str);
	
    for(i = 0; i < 10; i++)
	{
		/* fwrite():
		 * Escribe datos binarios en el archivo.
		 * &i        => direccion de la variable i.
		 * sizeof(i) => dimension de un entero en bytes.
		 * 1         => se escribe un elemento por iteracion.
		 * fp        => puntero a FILE.
		 */
		fwrite(&i, sizeof(i), 1, fp);
		printf("%d\n", i); // Muestra la iteracion
	}

	/* fwrite():
	 * Escribe datos binarios en el archivo.
	 * &c           => direccion del caracter.
	 * sizeof(char) => dimension de un byte.
	 * 1            => cantidad de elementos.
	 * fp           => puntero a FILE.
	 */
	fwrite(&c, sizeof(char), 1, fp);
	printf("%c\n", c); // Muestra el caracter con salto de linea
	
    for(i = 0; i < 10; i++)
	{
		/* fwrite():
		 * Escribe datos binarios en el archivo.
		 * &f            => direccion de la variable f.
		 * sizeof(float) => dimension de un float en bytes.
		 * 1             => se escribe un elemento por iteracion.
		 * fp            => puntero a FILE.
		 */
		fwrite(&f, sizeof(float), 1, fp);
		printf("%f\n", f); // Muestra el valor de f
		f *= 1.1; // Reasigna el valor de f
	}

	/* fwrite():
	 * Escribe datos binarios en el archivo.
	 * &st              => direccion de la estructura.
	 * sizeof(struct x) => dimension total de la estructura en memoria.
	 * 1                => se escribe una estructura completa como bloque binario.
	 * fp               => puntero a FILE.
	 */
	fwrite(&st, sizeof(struct x), 1, fp);

	/* Muestra todos los campos de la estructura st */
    printf("\n%c, %d, %f, %s\n", st.c, st.i, st.f, st.str);
	
	/* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(fp);
	
	/* Apertura del archivo apuntado por fp en modo lectura-binaria.
     * r => lectura (el archivo debe existir).
	 * b => modo binario.
	 * Se realiza la asignacion dentro de la condicion.
     * Si fopen devuelve NULL, la expresion es verdadera y se ejecuta el bloque de error.
     */
    if(!(fp = fopen("arch.bin", "rb")))
	{
		printf("\n\nError de apertura\n\n");
		exit(1);
	}

	printf("\nLECTURA DEL ARCHIVO\n\n");
	
	/* fread():
	 * str1         => direccion donde se almacenan los datos leidos.
	 * sizeof(str1) => dimension total del vector (50 bytes).
	 * 1            => cantidad de bloques a leer.
	 * fp           => puntero a FILE.
	 */
    fread(str1, sizeof(str1), 1, fp);
	
	/* puts():
     * Muestra la cadena en la salida estandar.
     * Agrega automaticamente un salto de linea.
     */
    puts(str1);
	
    printf("\n");
	
	/* fread():
	 * k           => vector donde se almacenan los enteros.
	 * sizeof(int) => dimension de cada entero.
	 * 10          => cantidad de elementos a leer.
	 * fp          => puntero a FILE.
	 */
    fread(k, sizeof(int), 10, fp);
	
	/* Recorre el vector k */
    for(j = 0; j < 10; j++)
		printf("%d\n", k[j]); // Muestra cada elemento
	
    printf("\n");
	
	/* fread():
	 * c1           => direccion donde se almacena el caracter.
	 * sizeof(char) => dimension de un byte.
	 * 1            => cantidad de elementos.
	 * fp          => puntero a FILE.
	 */
    fread(&c1, sizeof(char), 1, fp);
	printf("%c", c1); // Muestra el caracter leido, no hay salto de linea automatico
	printf("\n"); // Salto de linea manual
	
	/* fread():
	 * g             => vector donde se almacenan los floats.
	 * sizeof(float) => dimension de cada float.
	 * 10            => cantidad de elementos a leer.
	 * fp            => puntero a FILE.
	 */
    fread(g, sizeof(float), 10, fp);
	
	/* Recorre el vector g */
    for(i = 0; i < 10; i++)
		printf("%f\n", g[i]); // Muestra cada elemento
	
	/* fread():
	 * &st1             => direccion donde se almacena la estructura leida.
	 * sizeof(struct x) => dimension total de la estructura.
	 * 1                => se lee una estructura completa.
	 * fp               => puntero a FILE.
	 */
    fread(&st1, sizeof(struct x), 1, fp);
	
	/* Muestra todos los campos de la estructura st1 */
    printf("\n%c, %d, %f, %s\n", st1.c, st1.i, st1.f, st1.str);
	
	/* Cierre del archivo.
     * Libera los recursos asociados al flujo.
     */
    fclose(fp);
    
	/* Nota:
	 * En archivos binarios los datos se almacenan en su representacion
	 * interna en memoria, no en formato legible.
	 * Por eso se utilizan fwrite() y fread().
	 */
    return 0;
}