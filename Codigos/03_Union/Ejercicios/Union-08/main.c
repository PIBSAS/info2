// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets()
#include <conio.h> // clrscr() no existe en GCC/MinGW reemplazo con system("cls") de stdlib.h

/* Reemplazo de clrscr() */
#include <stdlib.h> // system("cls");

/* Declaracion de constante global */
#define MAX 3

/* Declaracion de estructuras */
struct coupe
{
    char nro_cil;
    int cilind, veloc_max;
    char marchas;
};

struct sedan
{
	char puertas, color[10], familiar;
};

struct cuotas
{
	int cant;
	float val;
};

/* Declaracion de union de estructuras */
union clase
{
	struct coupe dat;
	struct sedan dat1;
};

/* Declaracion union que contiene tipo primitivo y estructura */
union fina
{
	float contado;
	struct cuotas pagos;
};

/* Declaracion de estructura que contiene miembros de tipo union */
struct autos
{
	char marca[10];
	int modelo;
	char tipo;
	union clase caract;
	char vendido, cont;
	union fina valor;
};

/* Prototipos de funciones */
int ingreso(struct autos stock[], int);
void listado(struct autos stock[], int);

int main(void)
{
	/* Declaracion de vector de tipo struct autos */
    struct autos stock[MAX];

	/* Declaracion de variables */
	int i,j=0;

	do
	{
		clrscr(); // Comentar y reemplazar con la siguiente linea
		//system("cls"); // Desomentar y comentar la linea anterior

		/* Menu principal */
		printf("\n\t\t\t\tMenu principal");
		printf("\n\t1 - Ingreso de datos");
		printf("\n\t2 - Listado de datos");
		printf("\n\t3 - Salir");
		printf("\n\nIngrese una opcion ( 1 - 4 ): ");

		/* Leer el valor intriducido */
		scanf("%d", &i);

		/* Caso 1: llamar a la funcion ingreso con los argumentos vector de estructura stock y la variable entera j y almacenar lo que devuelve en j 
         * Caso 2: llamar a la funcion listado con los argumentos vector de estructura stock y la variable entera j.
         */
		switch(i)
		{
		case 1:
			j = ingreso(stock, j);
			break;

		case 2:
			listado(stock, j);
		}
	}
	while (i != 3); // Mientras la variable sea distinta de 3.

    return 0;
}

/* Funcion para permitir el ingreso de los datos */
int ingreso(struct autos stock[], int j)
{
	/* Declaracion de las variables a utilizar para *
     * realizar el ingreso de los valores de tipo   *
     * "char" con formato numerico y para poder     *
     * ingresar los valores de tipo "float"         *
	 */
	int i;

	/* Verifica que no se exceda el maximo del vector */
	if (j == MAX)
		return (j);

	/* Comienzo del ingreso de los datos */
	do
	{
		clrscr(); // Comentar y reemplazar con la siguiente linea
		//system("cls"); // Desomentar y comentar la linea anterior

		printf("\n\t\t\tINGRESO DE DATOS");
		printf("\n\n\tMarca : ");

		fflush(stdin);// Produce comportamiento indefinido, puede ser remplazaodo por las 2 siguientes lineas
        //int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);

		gets(stock[j].marca); // Eliminado en C11 reemplazar con fgets
		//fgets(stock[j].marca, sizeof(stock[j].marca), stdin);

		printf("\tModelo : ");
		scanf("%d", &stock[j].modelo);

		printf("\tTipo (C-S): ");

		/* Ingreso de datos selectivo segun el tipo elegido */
		do
		{
			stock[j].tipo = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

			if (stock[j].tipo == 'C' || stock[j].tipo == 'c')
			{
				printf("\tNumero de cilindros : ");

				/* Utilizacion de una variable auxiliar para *
                 * ingresar un valor con formato numerico en *
                 * una variable de tipo "char"               *
				 */
				scanf("%d", &i);

				/* Almacenar en struct autos => union clase caract => struct coupe dat => char nro_cil el valor almacenado en la variable entera i */
				stock[j].caract.dat.nro_cil = i;

				printf("\tCilindrada : ");
				scanf("%d", &stock[j].caract.dat.cilind);

				printf("\tVelocidad maxima : ");
				scanf("%d", &stock[j].caract.dat.veloc_max);

				printf("\tCantidad de marchas : ");
				scanf("%d", &i); // Se sobreescribe el valor de la variable entera i

				/* Almacenar en struct autos => union clase caract => struct coupe dat => char marchas el valor almacenado en la variable entera i */
				stock[j].caract.dat.marchas = i;
			}

			if (stock[j].tipo == 'S' || stock[j].tipo == 's')
			{
				printf("\tCantidad de puertas : ");
				scanf("%d", &i); // Se sobreescribe el valor de la variable entera i
				
				/* Almacenar en struct autos => union clase caract => struct sedan dat1 => char puertas el valor almacenado en la variable entera i */
				stock[j].caract.dat1.puertas=i;
				
				fflush(stdin); // Produce comportamiento indefinido, puede ser remplazaodo por la siguiente linea
                //while ((basura = getchar()) != '\n' && basura != EOF);

				printf("\tColor : ");

				gets(stock[j].caract.dat1.color); // Eliminado en C11, reemplazar con fgets(), comentar esta linea y descomentar la siguiente
                //fgets(stock[j].caract.dat1.color, sizeof(stock[j].caract.dat1.color), stdin);
				
				printf("\tFamiliar (S/N) : ");

				stock[j].caract.dat1.familiar = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER
			}
		}
		while (stock[j].tipo == 'C' || stock[j].tipo == 'c' || stock[j].tipo == 'S' || stock[j].tipo == 's');

		printf("\tVendido (S/N) : ");

		/* Ingreso selectivo de los datos de venta */
		do
		{
			stock[j].vendido = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

			if (stock[j].vendido == 'S' || stock[j].vendido == 's')
			{
				printf("\tVenta al contado (S/N) : ");
				do
				{
					stock[j].cont = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

					if (stock[j].cont == 'S' || stock[j].cont == 's')
					{
						printf("\tValor : ");
						scanf("%f", &stock[j].valor.contado);
					}

					if (stock[j].cont == 'N' || stock[j].cont == 'n')
					{
						printf("\tNumero de cuotas : ");
						scanf("%d", &stock[j].valor.pagos.cant);

						printf("\tValor de la couta : ");
						scanf("%f", &stock[j].valor.pagos.val);
					}
				}
				while (stock[j].cont == 'S' || stock[j].cont == 's' || stock[j].cont == 'N' || stock[j].cont == 'n');
				//while (stock[j].cont != 'S' && stock[j].cont != 's' && stock[j].cont != 'N' && stock[j].cont != 'n');
			}

			if (stock[j].vendido == 'N' || stock[j].vendido == 'n')
			{
				stock[j].valor.pagos.cant = 0;
				stock[j].valor.pagos.val = 0;
			}
		}
		while (stock[j].vendido == 'S' || stock[j].vendido == 's' || stock[j].vendido == 'N' || stock[j].vendido == 'n');
		//while (stock[j].vendido != 'S' && stock[j].vendido != 's' && stock[j].vendido != 'N' && stock[j].vendido != 'n');

		printf("\n\t\tDesea ingresar otro vehiculo (S/N): ");
		
		i = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER
		j++;
	}
	while (i == 'N' || i == 'n' || j >= MAX); // Deberia ser, como en el codigo anterior:
	//while ((i == 'S' || i == 's') && j >= MAX);

	/* Se retorna el ultimo valor de la posicion maxima de los valores ingresados */
	return (j);
}

/* Funcion que permite la visualizacion de los datos */
void listado(struct autos stock[], int j)
{
	/* Declaracion de variable a utilizar en la funcion */
	int i;

	/* Lazo para poder realizar la visualizacion de los datos *
     * dentro del rango ingresado                             *
	 */
	for (i = 0; i < j; i++)
	{
		/* Mostrar marca, modelo y tipo */
		printf("\n\n\tMarca : %s", stock[i].marca);
		printf("\tModelo : %d", stock[i].modelo);
		printf("\tTipo : %c", stock[i].tipo);

		/* Listado selectivo segun el tipo */
		if (stock[i].tipo == 'C' || stock[i].tipo == 'c')
		{
			/* Mostrar numero de cilidros, cilindrada, velocidad maxima, cantidad de marchas para tipo Coupe */
			printf("\n\tNumero de cilindros : %d", stock[i].caract.dat.nro_cil);
			printf("\tCilindrada : %d", stock[i].caract.dat.cilind);
			printf("\n\tVelocidad maxima : %d", stock[i].caract.dat.veloc_max);
			printf("\tCantidad de marchas : %d", stock[i].caract.dat.marchas);
		}

		if (stock[i].tipo == 'S' || stock[i].tipo == 's')
		{
			/* Mostrar cantidad de puertas, color, familiar para tipo Sedan */
			printf("\tCantidad de puertas : %d", stock[i].caract.dat1.puertas);
			printf("\tColor : %s", stock[i].caract.dat1.color);
			printf("\tFamiliar (S/N) : %c", stock[i].caract.dat1.familiar);
		}

		/* Mostrar vendido */
		printf("\n\tVendido : %c", stock[i].vendido);

		/* Listado selectivo de los datos de venta */
		if (stock[i].vendido == 'S' || stock[i].vendido == 's')
		{
			if (stock[i].cont == 'S' || stock[i].cont == 's')
				printf("\tValor : %f", stock[i].valor.contado); // Mostrar valor de contado

			if (stock[i].cont == 'N' || stock[i].cont == 'n')
			{
				printf("\tNumero de cuotas : %d", stock[i].valor.pagos.cant); // Mostrar numero de cuotas
				printf("\tValor de la couta : %f", stock[i].valor.pagos.val); // Mostrar valor de cada cuota
			}
		}

		printf("\n\t\tDesea listar otro vehiculo (S/N): ");

		i = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

		/* Seleccion que permite seguir visualizando o no      *
         * los datos del vector segun la eleccion del operador *
		 */
		if (i == 'N' || i == 'n')
			return;
	}

}
