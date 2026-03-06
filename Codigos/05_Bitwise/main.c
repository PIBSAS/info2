// gcc -std=c11 -Wall -Wextra -pedantic main.c -o bitwise
/*
    Operadores Bitwise - Operadores a nivel de bits

    Que son?:
        Son operadores que no trabajan con valores "numericos" 
        en el sentido aritmetico, sino bit por bit sobre la
        representacion binaria de un dato entero.
    
    Se aplican sobre:
    - char
    - short
    - int
    - long
    - Sus versiones unsigned
    NO APLICA a float, double, estructuras, etc.

    Representacion binaria:
        Supongamos un unsigned char (8 bits):
        - valor decimal: 13
        - Binario: 0000 1101
        Cada operador va a actuar bit a bit, comparando o modificando esos 0 y 1.
    
    Operador AND bit a bit (&)
        NO CONFUNDIR con el AND logico (&&)
        Sintaxis:
        - resultado = a & b;
        Regla:
        Un bit vale 1 solo si ambos bits son 1.

        | a | b | a & b |
        | - | - | ----- |
        | 0 | 0 |   0   |
        | 0 | 1 |   0   |
        | 1 | 0 |   0   |
        | 1 | 1 |   1   |

        Ej.:
        - unsigned char a = 12; // 0000 1100
        - unsigned char b = 10; // 0000 1010
        - unsigned char c = a & b; // 0000 1000 -> 8

        Para que se usa?
        - Enmascarar bits.
        - Ver si un bit especifico esta activo.
        Ej. Tipico:
        - if (estado & 0x01) {
        -   // el bit 0 esta en 1
        - }
    
    Operador OR bit a bit (|)
        NO CONFUNDIR con el or logico (||)
        Sintaxis:
        - resultado = a | b;
        Regla:
        Un bit vale 1 solo si al menos uno es 1.

        | a | b | a | b |
        | - | - | ----- |
        | 0 | 0 |   0   |
        | 0 | 1 |   1   |
        | 1 | 0 |   1   |
        | 1 | 1 |   1   |

        Ej.:
        - unsigned char a = 12; // 0000 1100
        - unsigned char b = 10; // 0000 1010
        - unsigned char c = a | b; // 0000 1110 -> 14

        Para que se usa?
        - Prender bits (setear flags).
        Ej. Tipico:
        - estado = estado | 0x04; // pone en 1 el bit 2

    Operador XOR (^)
        Este es el mas "raro" al principio.
        Sintaxis:
        - resultado = a ^ b;
        Regla:
        Un bit vale 1 solo si son distintos.

        | a | b | a ^ b |
        | - | - | ----- |
        | 0 | 0 |   0   |
        | 0 | 1 |   1   |
        | 1 | 0 |   1   |
        | 1 | 1 |   0   |

        Ej.:
        - unsigned char a = 12; // 0000 1100
        - unsigned char b = 10; // 0000 1010
        - unsigned char c = a ^ b; // 0000 0110 -> 6

        Para que se usa?
        - Invertir bits especificos.
        - Truco historico, hacer swap sin variable auxiliar, hoy en dia solo didactico.
        Ej. Tipico:
        - estado ^= 0x01; // invierte el bit 0
        Swap sin variable auxiliar:
        - a = a ^ b;
        - b = a ^ b;
        - a = a ^ b;
    
    Operador NOT o Complemento a uno (~)
        Sintaxis:
        - resultado = ~a;
        Regla:
        Invierte todos los bits:
            - 0 => 1
            - 1 => 0

        | a | ~a |
        | - | -- |
        | 0 | 1  |
        | 1 | 0  |
        

        Ej.:
        - unsigned char a = 5; // 0000 0101
        - unsigned char b = ~a; // 1111 1010 -> 250
        IMPORTANTE:
            En tipos con signo, el resultado de la representacion (Complemento a dos).
            Por eso para bitwise - bit a bit conviene usar unsigned.

        Para que se usa?
        - Apagar bits con mascara.
        Ej. Tipico:
        - estado &= ~0x04; // pone en 0 el bit 2
    
    Desplazamiento a la izquierda - Shift left (<<)
        Sintaxis:
        - resultado = a << n;

        Que hace?
            Desplaza los bits n posiciones a la izquierda, rellenando con ceros a la derecha.
        
        Ej.:
        - unsigned char a = 3; // 0000 0011
        - unsigned char b = a << 2; // 0000 1100 => 12
        Interpretacion:
            Equivale para unsigned a multiplicar por 2^n.
            - a << 1 // Si a vale 1: 1 * 2^1 => 2
            - a << 2 // Si a vale 1: 1 * 2^2 => 4
    
    Desplazamiento a la derecha - Shift right (>>)
        Sintaxis:
        - resultado = a >> n;

        Que hace?
            Desplaza los bits n posiciones a la derecha, rellenando con ceros a la izquierda.
        
        Ej.:
        - unsigned char a = 8; // 0000 1000
        - unsigned char b = a >> 2; // 0000 0010 => 2
        Interpretacion:
            Equivale para unsigned a dividir por 2^n.
            - a >> 1 // Si a vale 1: 1 / 2^1 => 0 (truncado)
            - a >> 2 // Si a vale 1: 1 / 2^2 => 0
        - Tipo signed: Dependiente de la implementacion
            - Puede rellenar con ceros
            - O repetir el bit de signo (Shift aritmetico). Por eso para bit a bit(bitwise) serio, se usa unsigned
        Nota:
            En C, los operadores de desplazamiento trabajan sobre enteros.
            Cualquier división descarta la parte fraccionaria (truncamiento).

    Bitwise - bit a bit vs Logicos:

    | Operador | Tipo    | Resultado       |
    | -------- | ------- | --------------- |
    |     &    | bitwise | opera bit a bit |
    |    &&    | logico  |     0 o 1       |
    |     |    | bitwise | opera bit a bit |
    |    ||    | logico  |     0 o 1       |
    |     ^    | bitwise |     bit a bit   |
    |     !    | logico  | negacion logica |
    |     ~    | bitwise | complemento     |

*/

#include <stdio.h>

/* Funcion auxiliar para mostrar unsigned char en binario */
void binprint(unsigned char x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
        if (i == 4)
            printf(" ");
    }
}

int main(void)
{
    unsigned char a = 12; // 0000 1100
    unsigned char b = 10; // 0000 1010
    unsigned char r;

    printf("Valores iniciales:\n");
    printf("a = %3u = ", a); binprint(a); printf("\n");
    printf("b = %3u = ", b); binprint(b); printf("\n\n");

    /* ---- AND bitwise ---- */
    r = a & b;
    printf("AND bitwise (a & b):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    /* ---- OR bitwise ---- */
    r = a | b;
    printf("OR bitwise (a | b):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    /* ---- XOR bitwise ---- */
    r = a ^ b;
    printf("XOR bitwise (a ^ b):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    /* ---- NOT bitwise ---- */
    r = ~a;
    printf("NOT bitwise (~a):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    /* ---- SHIFT LEFT ---- */
    r = a << 2;
    printf("Shift left (a << 2):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    /* ---- SHIFT RIGHT ---- */
    r = a >> 2;
    printf("Shift right (a >> 2):\n");
    printf("%3u = ", r); binprint(r); printf("\n\n");

    return 0;
}