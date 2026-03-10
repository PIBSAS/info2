// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <conio.h>// Se usa getche(), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>
#include <string.h>

/* Se definen la cantidad de empleados y el largo de los strings */
#define MAX 20
#define LARGO 30

/* Se definen las estructuras que formaran los datos de los empleados */
struct dat_pers
{
	char nomb[LARGO], apell[LARGO]; // Cadenas de 29 caracteres + '\0'
};

struct fecha
{
	int anio, mes, dia;
};

struct domic
{
	char dire[LARGO], local[LARGO], prov[LARGO]; // Cadenas de 19 caracteres + '\0'
};

struct tele
{
	unsigned int carac, numer;
};

/* Estructura de estructuras para guardar los datos de los empleados */
struct agend
{
	struct dat_pers datos;
	struct domic direccion;
	struct fecha cumple, antig;
	unsigned int leg;
	struct tele partic, movil;
};

int main(void)
{
    /* Se declaran las variables */
	struct agend empleados[MAX];
	char i, resp, enc;
	unsigned int cons;

	/* Ingreso de los datos */
	for(i = 0; i < MAX; i++)
	{
		clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    	//system("cls");

		/* Limpieza del buffer */
		fflush(stdin); // Reemplazar con:
		//int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);
		
		/* Titulo */
        printf("\t\tIngrese los datos del personal\n\n");
		
		/* Carga de Apellido */
        printf("\nApellido: ");

		/* Se elimino en C11 por insegura, se puede reemplazar con fgets()
		 * Da -Wchar-subscripts se lo arregla haciendo cast a int.
		 */
		gets(empleados[i].datos.apell);
        //fgets(empleados[(int)i].datos.apell, sizeof(empleados[(int)i].datos.apell), stdin);
		
		/* Carga de Nombre */
        printf("\nNombre: ");

		/* Se elimino en C11 por insegura, se puede reemplazar con fgets()
		 * Da -Wchar-subscripts se lo arregla haciendo cast a int.
		 */
		gets(empleados[i].datos.nomb);
        //fgets(empleados[(int)i].datos.nomb, sizeof(empleados[(int)i].datos.nomb), stdin);
		
		/* Carga de Direccion */
        printf("\nDireccion: ");

		/* Se elimino en C11 por insegura, se puede reemplazar con fgets()
		 * Da -Wchar-subscripts se lo arregla haciendo cast a int.
		 */
		gets(empleados[i].direccion.dire);
        //fgets(empleados[(int)i].direccion.dire, sizeof(empleados[(int)i].direccion.dire), stdin);
		
		/* Carga de Localidad */
        printf("\nLocalidad: ");

		/* Se elimino en C11 por insegura, se puede reemplazar con fgets()
		 * Da -Wchar-subscripts se lo arregla haciendo cast a int.
		 */
		gets(empleados[i].direccion.local);
        //fgets(empleados[(int)i].direccion.local, sizeof(empleados[(int)i].direccion.local), stdin);
		
		/* Carga de Provincia */
        printf("\nProvincia: ");
		
		/* Se elimino en C11 por insegura, se puede reemplazar con fgets()
		 * Da -Wchar-subscripts se lo arregla haciendo cast a int.
		 */
		gets(empleados[i].direccion.prov);
        //fgets(empleados[(int)i].direccion.prov, sizeof(empleados[(int)i].direccion.prov), stdin);
		
		/* Carga de Fecha de nacimiento */
        printf("\nFecha de nacimiento (dia/mes/agno): ");
		scanf("%d/%d/%d", &empleados[i].cumple.dia, &empleados[i].cumple.mes, &empleados[i].cumple.anio); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%d/%d/%d", &empleados[(int)i].cumple.dia, &empleados[(int)i].cumple.mes, &empleados[(int)i].cumple.anio);

		/* Carga de Fecha de ingreso */
        printf("\nFecha de ingreso (dia/mes/agno): ");
		scanf("%d/%d/%d", &empleados[i].antig.dia, &empleados[i].antig.mes, &empleados[i].antig.anio); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%d/%d/%d", &empleados[(int)i].antig.dia, &empleados[(int)i].antig.mes, &empleados[(int)i].antig.anio);

		/* Carga de Telefono Particular */
        printf("\nTelefono particular (caracteristica-numero): ");
		scanf("%u-%u", &empleados[i].partic.carac, &empleados[i].partic.numer); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%u-%u", &empleados[(int)i].partic.carac, &empleados[(int)i].partic.numer);

		/* Carga de Telefono Movil */
        printf("\nTelefono movil (caracteristica-numero): ");
		scanf("%u-%u", &empleados[i].movil.carac, &empleados[i].movil.numer); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%u-%u", &empleados[(int)i].movil.carac, &empleados[(int)i].movil.numer);

		/* Carga de Numero de legajo */
        printf("\nNumero de legajo: ");
		scanf("%u", &empleados[i].leg); // da -Wchar-subscripts se lo arregla haciendo cast a int:
		//scanf("%u", &empleados[(int)i].leg);
	}

    clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    //system("cls");

	/* Inicializacion de variable para entrar al bucle */
    resp = 'S';

	/* Consulta de un enpleado */
	while(resp == 'S' || resp == 's')
	{
		/* Inicializacion de bandera de encontrado */
		enc = 0;

		clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    	//system("cls");
		
		/* Consulta por legajo */
        printf("\n\nIngrese el numero de legajo: ");
		scanf("%u", &cons);

		/* Busqueda del empleado */
		for(i = 0; i < MAX && !enc; i++)
        {
			/* Compara la consulta con los legajos */
			if(cons == empleados[i].leg) // da -Wchar-subscripts se lo arregla haciendo cast a int:
			//if(cons == empleados[(int)i].leg)
			{
				enc = 1; // Marca como encontrado
				i--; // Retrocede indice porque el for lo incrementara
			}

			/* Impresion de los datos del empleado encontrado */
			if(enc)
			{
				printf("El empleado %s, %s\n", empleados[i].datos.apell, empleados[i].datos.nomb); // da -Wchar-subscripts se lo arregla haciendo cast a int:
				//printf("El empleado %s, %s\n", empleados[(int)i].datos.apell, empleados[(int)i].datos.nomb);

				printf("se domicilia en %s, %s, %s\n", empleados[i].direccion.dire, empleados[i].direccion.local, empleados[i].direccion.prov); // da -Wchar-subscripts se lo arregla haciendo cast a int:
				//printf("se domicilia en %s, %s, %s\n", empleados[(int)i].direccion.dire, empleados[(int)i].direccion.local, empleados[(int)i].direccion.prov);
				
                printf("el telefono particular es : %u-%u \tel celular es 15-%u-%u", empleados[i].partic.carac, empleados[i].partic.numer, empleados[i].movil.carac, empleados[i].movil.numer); // da -Wchar-subscripts se lo arregla haciendo cast a int:
				//printf("el telefono particular es : %u-%u \tel celular es 15-%u-%u", empleados[(int)i].partic.carac, empleados[(int)i].partic.numer, empleados[(int)i].movil.carac, empleados[(int)i].movil.numer);
				
                printf("\nel ingreso en la empresa fue el %d/%d/%d,", empleados[i].antig.dia,empleados[i].antig.mes, empleados[i].antig.anio); // da -Wchar-subscripts se lo arregla haciendo cast a int:
				//printf("\nel ingreso en la empresa fue el %d/%d/%d,", empleados[(int)i].antig.dia,empleados[(int)i].antig.mes, empleados[(int)i].antig.anio);
				
				printf("su retiro se producira en el agno %d  ", empleados[i].cumple.anio + 65); // da -Wchar-subscripts se lo arregla haciendo cast a int:
				//printf("su retiro se producira en el agno %d  ", empleados[(int)i].cumple.anio + 65);
			}
			else
            {
				/* Mensaje si no fue encontrado */
				printf("Este legajo no existe");
            }

			/* Nueva consulta */
			printf("\n\nDesea buscar otro empleado (S/N)? ");
			/* getche():
         	 * - Lee un caracter con eco en pantalla (lo muestra) y lo guarda en resp
		 	 */
			resp = getche();
        }
	}

    return 0;

}
