// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <string.h> // Se usa strcpy()

/* Prototipos de funcion */
struct FECHA f1(void);   // Devuelve una estructura FECHA
struct PERSONA f2(void); // Devuelve una estructura PERSONA

/* Definicion de estructura */
struct FECHA
{
    int dia, mes, anio;
};

/* Definicion de estructura de estructuras */
struct PERSONA
{
    char nom[30];
    char apell[30];
    struct FECHA fnac;
};

/* Definicion de estructura */
struct A
{
    int a;
    float b;
};

int main(void)
{
    /* Declaracion de variables tipo struct */
    struct PERSONA pers;
    struct A a;

    /* Copia de cadenas en los campos char[] */
    strcpy(pers.nom, "JUAN");
    strcpy(pers.apell, "PEREZ");

    /* Asignacion a campos de la estructura */
    a.a = 5;
    a.b = 2.1;

    /* LLamada a funcion que devuelve struct FECHA
     * Se asigna directamente al campo fnac
     */
    pers.fnac = f1();
    
    /* Llamada a funcion que devuelve struct PERSONA completa
     * Se reemplaza toda la estructura pers (incluyendo nombre, apellido y fecha)
     */
    pers = f2();

    return 0;
}

/* Funcion que devulev una estructura PERSONA
 * Inicializacion compuesta al momento de declarar
 */
struct PERSONA f2(void)
{
    /* Inicializacion directa de los campos */
    struct PERSONA P = {"pablo", "Marmol", {10, 3, -2528}};

    return P; // Devuelve la estructura completa
}

/* Funcion que devuelve una estructura FECHA */
struct FECHA f1(void)
{
    struct PERSONA pers; // Variable local
    struct A a;          // Variable local
    struct FECHA hoy;    // Fecha a retornar

    /* Uso de strcpy para demostrar string.h*/
    strcpy(pers.nom, "PEDRO");

    /* Asignacion del campo b de la estructura a de tipo struct A*/
    a.b = 7.89;

    /* Ingreso por teclado de la fecha (no hay validacion) */
    scanf("%d", &hoy.dia);
    scanf("%d", &hoy.mes);
    scanf("%d", &hoy.anio);

    return hoy; // Se devuelve la estructura completa
}
