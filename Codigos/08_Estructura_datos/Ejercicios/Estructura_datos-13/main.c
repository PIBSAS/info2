// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getch(), getche((), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>
#include <math.h> // Se usa cos(), sin(), sqrt(), atan2()

/* Se define el valor de pi */
#define PI 3.14159

/* Definicion de la estructura */
struct complejo
{
	float x,y;
};

/* Prototipo de las fuinciones */
float modulo(struct complejo);    // Calcula modulo desde coordenadas cartesianas
float argumento(struct complejo); // Calcula argumento desde coordenadas cartesianas
float absi(struct complejo);      // Calcula abscisa desde coordenadas polares
float orde(struct complejo);      // Calcula ordenada desde coordenadas polares

int main(void)
{
    /* declaracion de las variables */
	char c;
	struct complejo A, B;
	do
	{
		//clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
        system("cls");

		printf("\n\n\n\t\t\tPasaje de coordenadas");
		printf("\n\n\t\tIngrese la opcion\n\n\t\t (P) polar a cartesiana");
		printf("\n\n\t\t (C) cartesiana a polar ");
		printf("\n\n\t\t (S) salir              ");

		c = getche(); // Lee una tecla y la muestra en pantalla
		
        switch(c)
		{
			/* Eleccion de pasaje de polar a cartesiana */
            case 'c':
            case 'C':
                printf("\n\nIngrese el modulo : ");
                scanf("%f", &A.x);
                
                printf("\nIngrese el argumento : ");
                scanf("%f", &A.y);
                
                /* Calcula abscisa y ordenada usando estructura*/
                B.x = absi(A);
                B.y = orde(A);
                
                /* Muestra abscisa y ordenada */
                printf("\n\nLa abscisa es: %f", B.x);
                printf("\n\nLa ordenada es: %f", B.y);
                
                printf("\n\nPresione una tecla para continuar");
                getch(); // Espera que se presione una tecla
                
                break;
            /* Eleccion de pasaje de cartesiana a polar */
            case 'P':
            case 'p':
                printf("\n\nIngrese la abscisa: ");
                scanf("%f", &A.x);
                
                printf("\nIngrese la ordenada: ");
                scanf("%f", &A.y);
                
                /* Calcula modulo y argumento usando estructura */
                B.x = modulo(A);
                B.y = argumento(A);
                
                /* Muestra modulo y argumento */
                printf("\n\nEl modulo es: %f", B.x);
                printf("\n\nEl argumento es: %f", B.y);
                
                printf("\n\nPresione una tecla para continuar");
                getch(); // Espera que se presione una tecla
                
                break;
                /* opcion de salir */
            case 'S':
            case 's':
                c = 0; // Fuerza salida del bucle
		}
	}
	while(c); // Se repite mientras c sea distinto de cero

    return 0;
}

/* calculo de la abscisa */
float absi(struct complejo A)
{
	float ab;

	ab = A.x * cos(A.y * PI / 180); // Se convierte a radianes antes de usar cos()
	
    return(ab);
}

/* calculo de la ordenada */
float orde(struct complejo A)
{
	float or;

	or = A.x * sin(A.y * PI / 180); // Se convierte a radianes antes de usar sin()

	return(or);
}

/* calculo del modulo */
float modulo(struct complejo A)
{
	float mo;

	mo = A.x * A.x + A.y * A.y; // Suma de cuadrados
	mo = sqrt(mo);              // Raiz cuadrada
	
    return(mo);
}

/* calculo del argumento */
float argumento(struct complejo A)
{
	float ar;

	ar = atan2(A.y, A.x); // Argumento en radianes considerando cuadrante correcto
	ar *= (180 / PI);     // Conversion de radianes a grados
	
    return(ar);

}
