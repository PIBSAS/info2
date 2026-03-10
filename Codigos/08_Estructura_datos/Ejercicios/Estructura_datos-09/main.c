// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getche(), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>
#include <math.h> // No se usa, podria omitirse

/* Define una estructura */
struct valor
{
	char x;
	int j;
	float l, m, n[4];
};

int main(void)
{
    /* Declaracion de vector de estructura */
    struct valor dato[2];
    /* Variables de control de bucles y variable auxiliar*/
	char i, ii;
	float aux;

	clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");
    
    /* Carga de datos */
    for (i = 0; i < 2; i++)
    {
        printf("\n\n\n\t\tIngrese los siguientes datos: ");
		
        printf("\n\nUn caracter alfabetico: ");
		
        /* getche():
         * - Lee un caracter con eco en pantalla (lo muestra)
         */
        dato[i].x = getche(); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//dato[(int)i].x = getche();

        /* Carga de un entero */
        printf("\n\nUn numero entero : ");
		scanf("%d", &dato[i].j); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%d", &dato[(int)i].j);

        /* Carga de un float */
        printf("\n\nUn numero real : ");
		scanf("%f", &dato[i].l); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%f", &dato[(int)i].l);
        
        /* Carga de un float */
        printf("\nReintente con un numero real :");
		scanf("%f", &aux); 
		
        /* Copia el valor almacenado en aux al campo m */
        dato[i].m = aux; // da -Wchar-subscripts se lo arregla haciendo cast a int:
        //dato[(int)i].m = aux;
		
        /* Bucle para cargar el vector */
        for(ii = 0; ii < 4; ii++)
        {
            /* Lee cada elemento del vector */
			scanf("%f", &dato[i].n[ii]); // da -Wchar-subscripts se lo arregla haciendo cast a int:
            //scanf("%f", &dato[(int)i].n[(int)ii]);
        }
    }

    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

    /* Bucle para mostrar los datos cargados */
	for (i = 0; i < 2; i++)
	{
		printf("Usted ingreso los siguientes valores\n\n");
		
        /* Muestra el caracter, su valor en ASCCI Code (promocion a int) y su valor en hexadecimal en mayusculas*/
        printf("Un caracter %c, cuyo valor ASCII es %d, y ", dato[i].x, dato[i].x); // da -Wchar-subscripts se lo arregla haciendo cast a int:
        //printf("Un caracter %c, cuyo valor ASCII es %d, y ", dato[(int)i].x, dato[(int)i].x);

		printf("en formato hexadecimal es %X\n\n", dato[i].x); // da -Wchar-subscripts se lo arregla haciendo cast a int:
        //printf("en formato hexadecimal es %X\n\n", dato[(int)i].x);

        /* Muestra el entero y su valor en hexadecimal en mayusculas */
        printf("Un numero entero %d, ", dato[i].j); // da -Wchar-subscripts se lo arregla haciendo cast a int:
        //printf("Un numero entero %d, ", dato[(int)i].j);

		printf("que en formato hexadecimal es %X\n\n", dato[i].j); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//printf("que en formato hexadecimal es %X\n\n", dato[(int)i].j);

        /* Muestra el float */
        printf("El primer valor real es %f\n\n", dato[i].l); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//printf("El primer valor real es %f\n\n", dato[(int)i].l);

        /* Muestra el contenido actual de aux (Sera el ultimo valor leido) */
        printf("Luego ingreso este valor en el auxiliar %f", aux);

        /* Muestra el valor almacenado en el campo m */
		printf(" que coincide con el guardado en la estructura %f", dato[i].m); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//printf(" que coincide con el guardado en la estructura %f", dato[(int)i].m);

        /* Bucle para mostrar los elementos del vector*/
        for(ii = 0; ii < 4; ii++)
        {
            /* En formato float */
			printf("%f", dato[i].n[ii]); // da -Wchar-subscripts se lo arregla haciendo cast a int:
            //printf("%f", dato[(int)i].n[(int)ii]);
        }
	}

    return 0;
}

