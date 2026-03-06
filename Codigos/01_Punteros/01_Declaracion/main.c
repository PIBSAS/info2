// gcc -std=c11 -Wall -Wextra -pedantic main.c -o declaracion
/*
    Un puntero es una variable que almacena una direccion de memoria.
    A traves de este, se puede acceder o modificar el valor almacenado alli.
    Uso:
    - Acceder y modificar variables desde funciones.
    - Manejar arrays y strings.
    - Usar memoria dinamica (malloc, free).
    - Estructura de datos (listas-lists, pilas-stack, arboles-tree)
    - Eficiencia y control de memoria

    Como se declara:
    - tipo_de_dato *nombre_del_puntero;
        Ej: int *pi
        pi: es un puntero.
        apunta a una direccion donde hay un int
        El * indica que es un puntero, no una multiplicacion.
        Para que el puntero tenga sentido, debe apuntar a una variable existente:
        int x = 10;
        int *pi;
        pi = &x; Direccion de memoria de x, pi ahora guarda esa direccion.
    
    Acceder al valor usando un puntero(desreferenciar-object-of):
    - Para acceder al contenido de la direccion a la que apunta el puntero se usa el operador * (Desreferencia-object-of):
    - printf("%d", *pi) Imprime 10.
    - pi: direccion.
    - *pi: valor guardado en esa direccion.

    Especificador de formato para direcciones:
    - %p: El estandard para este especificador de formato esta definido para imprimir punteros a void. Es por esto que el compilador nos advierte que con &x le estamos pasando int *, pero espera void *.
    - Para solucionar esto se hace un cast: (void *)&x
*/
#include <stdio.h>

int main(void)
{
    int x = 5;
    int *pi = &x; //Declaracion y asignacion de memoria

    printf("Valor de x: %d\n", x);
    printf("Direccion de x: %p\n", &x); // El compilador espera que a la direccion se le haga un cast (void*)&x, pero lo deja pasar con solo un Warning, con esa solucion.
    printf("Direccion usando pi: %p\n", pi); // El compilador espera que a la direccion se le haga un cast (void*)&x, pero lo deja pasar con solo un Warning, con esa solucion.
    printf("Direccion de x: %p\n", (void *)&x); // Siguiendo el estandard
    printf("Direccion usando pi: %p\n", (void *)pi); //Siguiendo el estandard
    printf("Acceso al valor de x usando el puntero %d\n", *pi);
    
    return 0;
}
