/* Código de ejemplo para comprender porque
    preferir indicar el std al compilar en lugar
    de usar el standard por defecto del gcc instalado,
    en esta pc es C23.
    Con:
    gcc -std=c11 ejemplo.c -o ejemplo
    Compila sin errores y se ejecuta perfectamente,
    es decir, pese a estar programadas con malas practicas para
    la actualidad, funciona.
    Por otro lado:
    gcc ejemplo.c -o ejemplo
    No compila, indica que el prototipo de la funcion no coincide
    con el numero de argumentos pasados, se espera 0 argumentos
    y fueron pasados 2, muestra la linea de declaracion de  funcion.
    Ademas del warning: old-style function definition.
    Es por esto, que para la cursada, se debe indicar el standard que establezca la catedra 
*/

/* Compilar este archivo con:
 * Para ver los errores y warnings que nos indica el compilador.
 * gcc ejemplo_porque_usar_c11_y_no_c23.c -o ejemplo
 *
 * Luego indicar el estandar C89 para ver que compila sin ningun problema:
 * gcc -std=c89 ejemplo_porque_usar_c11_y_no_c23.c -o ejemplo
 *
 * Tambien con C11:
 * gcc -std=c11 ejemplo_porque_usar_c11_y_no_c23.c -o ejemplo
 *
 * En cambio si agregamos los warnings veremos un -Wreturn-type:
 * gcc -std=c11 -Wall -Wextra -pedantic ejemplo_porque_usar_c11_y_no_c23.c -o ejemplo
 * Esta ultima forma es la que se usara en los programas para compilar.
 */
#include <stdio.h>

int f(); // Declaracion ambigua, parametros no especificados

int main(void)
{
    f(1, 2);
    return 0;
}

/* Las siguientes lineas son una definicion de funcion estilo K&R (pre-ANSI C) Funciona con C89 */
int f(a, b)
int a;
int b;
{
    printf("%d %d\n", a, b);
}