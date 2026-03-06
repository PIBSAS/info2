// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // No pertenece al estandar ISO C. clrscr() no esta disponible en GCC/MinGW.
#include <stdlib.h> // system("cls"); al no poder compilar con clrscr()

/* Declaracion de la union 
 * En este caso probablemente 10 bytes por y[10] sera la dimension minima,
 * aunque puede haber padding por alineacion.
 * Padding por alineacion:
 * - Es memoria extra que el compilador agrega automaticamente
 *   para que los datos respeten los requisitos de alineacion de la arquitectura
 *   En una struct:
 *   - Puede haber padding entre miembros.
 *   - Puede haber padding al final.
 *
 *   En una union:
 *   - No hay padding entre miembros (todos comienzan en la misma direccion)
 *   - Puede haber padding al final para que la dimension total
 *     cumpla con la alineacion mas estricta de sus miembros.
 */
union alfa
{
    int x;
    char y[10];
    float z;
};

/* Prototipos de funciones */
int suma(int, int);
int ingreso(void);

int main(void)
{
    /* Declaracion de variables tipo union alfa*/
    union alfa A, B;

    /* No estandar. Solo disponible en algunos compiladores. No es portable. Puede usarse system("cls") */
    clrscr(); // Comentar y usar system("cls") de stdlib.h
    //system("cls"); // Descomentar y comentar la linea previa para compilar

    /* Se almacenan enteros en el miembro x, devueltos por la llamada a la funcion */
    A.x = ingreso();
    B.x = ingreso();

    /* Mostrar la suma entre los miembros x como cuenta */
    printf("\n%d + %d = ", A.x, B.x);

    /* Asignar al miembro x de A la suma entre los miembros x de A y B */
    A.x = suma(A.x, B.x);

    /* Mostrar el resultado de la suma */
    printf("%d\n", A.x);

    /* fflush(stdin) es comportamiento indefinido segun el estandar.
     * fflush solo esta definido para streams de salida fflush(stdout)
     * Algunos compiladores lo aceptan como extension, pero no es portable. 
     */
    fflush(stdin);

    /* gets() fue eliminada del estandar C11 (El cual se esta usando para compilar)
     * Es insegura porque no controla la dimension del buffer.
     * Puede provocar desbordamiento (buffer overflow). */
    gets(A.y); // Se reemplazo con fgets(buffer, sizeof(buffer), stdin)
    //fgets(A.y, sizeof(A.y), stdin); // Comentar la linea anterior y descomentar esta para que el programa compile

    /* Se accede al tercer caracter del vector de la union.
     * No se verifica que el usuario haya ingresado al menos 3 caracteres,
     * Lo que podria provocar acceso a memoria no inicializada.
     * Esto sobreescribe la memoria previamente usada por x.
     * A partir de aca, x deja de ser valido. */
    if (A.y[2] > 'F')
        {
            /* Se escribe el campo z, esto vuelve a sobreescribir
             * la memoria compartida. Ahora el unico miembro valido es z. */
            A.z = 3.14;

            /* Se lee un float en B.z
             * B.x deja de ser valido luego de esta operacion. */
            scanf("%f", &B.z);

            /* Se muestra como perimetro el producto de los miembros z */
            printf("\n\nPerimetro = %f", A.z * B.z);
        }

    return 0;
}

/* Declaracion de funcion ingreso:
 * Lee un entero y lo devuelve*/
int ingreso(void)
{
    /* Declaracion de variable local no inicializada */
    int a;

    /* Se lee el valor de la variable */
    scanf("%d", &a);

    /* Se retorna el valor de la variable */
    return (a);
}

/* Declaracion de funcion suma:
 * Recibe dos enteros.
 * Devuelve la suma de los dos enteros. 
 */
int suma(int a, int b)
{
    /* Declaracion de variable local no inicializada */
    int c;

    /* Se asigna a la variable la suma de los argumentos ingresados al llamar a la funcion */
    c = a + b;

    /* Se devuelve la variable con el resultado de la suma */
    return (c);
}