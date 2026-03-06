// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getch(), getche(), clrscr() No viene en GCC MinGW, usar de stdlib.h system()

/* Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux */
#include <stdlib.h>
#include <math.h> // Se usa cos(), sin(), sqrt(), atan2()

/* Se define el valor de pi */
#define PI 3.14159

/* Definicion de la estructura */
struct complejo
{
    float x, y;
};

/* Prototipo de las funciones */
float modulo(float, float);
float argumento(float, float);
float absi(float, float);
float orde(float, float);

int main(void)
{
    /* Declaracion de las variables */
    char c;
    struct complejo A, B;
    
    do
    {
        clrscr(); // Para reemplazar a clrscr() con system("cls") en Windows, system("clear") en Linux
    	//system("cls");

        printf("\n\n\n\t\t\tPasaje de coordenadas");
        printf("\n\n\n\t\tIngrese la opcion\n\n\t\t (P) polar a cartesiona");
        printf("\n\n\t\t (C) cartesiana a polar ");
        printf("\n\n\t\t (S) Salir ");

        c = getche(); // Lee opción con eco

        switch(c)
        {
            /* Eleccion de pasaje de polar a cartesiana */
            case 'c':
            case 'C':
                printf("\n\nIngrese el modulo: ");
                scanf("%f", &A.x);

                printf("\n\nIngrese el argumento: ");
                scanf("%f", &A.y);

                /* Calcula abscisa y ordenada */
                B.x = absi(A.x, A.y);
                B.y = orde(A.x, A.y);

                /* Muestra abscisa y ordenada */
                printf("\n\nLa abscisa es: %f",B.x);
                printf("\n\nLa ordenada es: %f",B.y);

                printf("\n\nPresione una tecla para continuar");
                getch(); // Espera que se presione una tecla

                break;
            /* Eleccion de pasaje de cartesiana a polar */
            case 'p':
            case 'P':
                printf("\n\nIngrese la abscisa: ");
                scanf("%f", &A.x);

                printf("\n\nIngrese la ordenada: ");
                scanf("%f", &A.y);

                /* Calcula modulo y argumento */
                B.x = modulo(A.x, A.y);
                B.y = argumento(A.x, A.y);

                /* Muestra modulo y argumento */
                printf("\n\nEl modulo es: %f", B.x);
                printf("\n\nEl argumento es: %f", B.y);

                printf("\n\nPresione una tecla para continuar");
                getch(); // Espera que se presione una tecla

                break;
            /* Opcion de salir */
            case 's':
            case 'S':
                c = 0; // Fuerza la salida del do-while
        }
    }
    while(c); // Se repite mientras c sea distinto de 0

    return 0;
}

/* Calculo de la abscisa */
float absi(float r, float f)
{
    float ab;

    ab = r * cos(f * PI / 180); // Calculo y conversion de grados a radianes

    return(ab);
}

/* Calculo de la ordenada */
float orde(float r, float f)
{
    float or;

    or = r * sin(f * PI / 180); // Calculo y conversion de grados a radianes

    return(or);
}

/* Calculo del modulo */
float modulo(float x, float y)
{
    float mo;

    mo = x*x + y*y; // Suma de cuadrados

    mo = sqrt(mo);  // raiz cuadrada

    return(mo);
}

/* Calculo del argumento */
float argumento(float x, float y)
{
    float ar;

    ar = atan2(y, x); // Calculo del angulo considerando el cuadrante correcto

    ar *= (180 / PI); // Comversion de radianes a grados

    return(ar);
}