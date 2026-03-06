// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>

int main(void)
{
    /* Declaracion de variable entera y puntero a int,
     * vector de 5 float y puntero a float. */
    int i;
    int *pi;
    float v[5], *pf;

    /* Asignacion de un literal hexadecimal.
     * El valor puede no ser representable en int con signo,
     * lo que produce comportamiento implementation-defined. 
     * Asignacion de la direccion de i */
    i = 0xA1B2C3D4;
    pi = &i;

    /* Desreferenciacion del puntero.
     * *pi es exactamente i. */
    printf("%d\n", *pi);

    /* Modificacion del contenido de i a traves del puntero */
    *pi = 0xFFEEDDCC;

    /* Recorrer el vector usando aritmetica.
     * &v[0] + 5 es el puntero one-past-the-end (valido para comparar). */
    for (pf = &v[0]; pf < (&v[0] + 5); pf++)
        scanf("%f", pf);

    printf("\n\n");

    /* Acceso mediante puntero + desplazamiento */
    for (pf = &v[0], i = 0; i < 5; i++)
        printf("\n%f", *(pf + i));

    printf("\n\n");

    /* Acceso clasico mediante indice */
    for (i = 0; i < 5; i++)
        printf("\n%f", v[i]);

    printf("\n\n");

    /* Asignacion de la primera direccion del vector al puntero a float */
    pf = &v[0];

    /* En esta expresion, v (de tipo float[5]) se convierte
     * implicitamente en puntero a su primer elemento (&v[0]) al hacer v + i */
    for (i = 0; i < 5; i++)
        printf("\n%f", *(v + i));

    printf("\n\n");
    
    return 0;
}
