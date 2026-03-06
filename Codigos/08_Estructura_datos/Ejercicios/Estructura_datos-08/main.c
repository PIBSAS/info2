// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <conio.h> // Se usa getch(), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>

#include <string.h>

/* Constantes */
#define N 100
#define PANT 20

/* Define la estructura a utilizar */
struct stock
{
    int art, cant;
    char desc[30]; // Cadena de 29 caracteres + '\0'
};

int main(void)
{
    /* Variables de control para los bucles */
    int i, j;

    /* Declara un vector de estructuras y una variable auxiliar de tipo 'struct stock' */
    struct stock prod[N], aux;

    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

    /* Lazo de ingreso de datos */
    for (i = 0; i < N; i++)
    {
        /* Carga de el numero de articulo */
        printf("articulo[%d]\t", i + 1);
        scanf("%d", &prod[i].art);

        /* Carga la cantidad en stock */
        printf("cantidad\t");
        scanf("%d", &prod[i].cant);

        /* Limpia el contenido del buffer de teclado */
        fflush(stdin); // Reemplazar con:
        //int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);

        /* Lee la descripcion del producto */
        printf("descripcion\t");
        gets(prod[i].desc); // Se elimino en C11 por insegura, se puede reemplazar con fgets()
        //fgets(prod[i].desc, sizeof(prod[i].desc), stdin);
        printf("\n");
    }

    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

    /* Rutina de ordenamiento del vector, Ordena segun cantidad de mayot a menor */
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            /* Compara cantidades */
            if (prod[j].cant > prod[i].cant)
            {
                /* Intercambio de los valores a ordenar */
                aux = prod[j];     // Guarda temporalmente prod[j]
                prod[j] = prod[i]; // Copia prod[i] en j
                prod[i] = aux;     // Coloca el valor guardado en la posicion i.
            }
        }
    }

    /* Rutina de impresion de los datos en pantalla dividido por paginas */
    for (i = 0; i < N; i += PANT)
    {
        /* Titulos de la tabla */
        printf("Articulo\tCantidad\tDescripcion\n");
        
        for (j = 0; (j < PANT) && (i + j < N); j++)
        {
            /* Muestra articulo, cantidad y descripcion 
             * prod[i + j] permite recorrer por bloques de PANT elementos */
            printf("%d\t\t%d\t\t%s\n", prod[i+j].art, prod[i+j].cant, prod[i+j].desc);
        }

        /* Mensaje de pausa */
        printf("\n\tPresione una tecla para continuar");
        /* Espera que el usuario presione una tecla */
        getch();
        
        clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
        //system("cls");
    }
    
    return 0;
}
