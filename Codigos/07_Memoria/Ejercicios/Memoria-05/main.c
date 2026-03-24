// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include<stdio.h>
#include <stdlib.h> // Se usa system()

int main(void)
{
  /* Declaracion de variables
   * Entero, char, vector de 15 elementos de tipo char
   * Numero real
   * Entero no signado
   * Char no signado
   * Entero largo
   * Entero largo no signado
   * Numero real (doble presicion)
   * Vector de 20 elementos de tipo int
   * */
	int a;
	char b, o[15];
	float c;
	unsigned int d;
	unsigned char e;
	long f;
	unsigned long g;
	double h;
	int i[20];

  /* Declaracion de estructura */
	struct l
	{
		char c, d, e;
	}j, k[10];
	
  /* Declaracion de union */
  union m
	{
		struct l a, b;
		char c[19];
	}n;


  system("cls"); /* Limpia la pantalla en Windows en Linux "clear" */
  
  /* Muestra la dimension en bytes de cada variable 
   * sizeof devuelve long long unsigned int usar el especificado %zu en lugar de %d
   */
  printf("La dimension de a es:%d\n", sizeof(a));
  printf("La dimension de b es:%d\n", sizeof(b));
  printf("La dimension de c es:%d\n", sizeof(c));
  printf("La dimension de d es:%d\n", sizeof(d));
  printf("La dimension de e es:%d\n", sizeof(e));
  printf("La dimension de f es:%d\n", sizeof(f));
  printf("La dimension de g es:%d\n", sizeof(g));
  printf("La dimension de h es:%d\n", sizeof(h));

  /* Muestra la dimension de los tipos de datos */
  printf("La dimension del int es:%d\n", sizeof(int));
  printf("La dimension del char es:%d\n", sizeof(char));
  
  /* Muestra la dimension de un vector completo */
  printf("La dimension de i es:%d\n", sizeof(i));

  /* Muestra la dimension de la estructura */
  printf("La dimension de j es:%d\n", sizeof(j));

  /* Muestra la dimension del vector de estructuras de 10 elementos */
  printf("La dimension de k es:%d\n", sizeof(k));

  /* Muestra la dimension del tipo de dato struct l */
  printf("La dimension de struct l es:%d\n", sizeof(struct l));
  
  /* Muestra la dimension del cuarto elemento del vector k */
  printf("La dimension de k es:%d\n", sizeof(k[4]));

  /* Muestra la dimension de la union (Depende del miembro mas grande) */
  printf("La dimension de n es:%d\n", sizeof(n));
  printf("La dimension de m es:%d\n", sizeof(union m));

  /* Muestra la dimension del vector de chars */
  printf("La dimension de o es:%d\n", sizeof(o));
  
  return 0;
}