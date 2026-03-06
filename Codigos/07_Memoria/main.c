// gcc -std=c11 -Wall -Wextra -pedantic main.c -o dinamica

/*
    Que es la memoria dinamica - Heap?
        Es memoria que:
            - Se solicita en tiempo de ejecucion(runtime)
            - Vive en una zona especial llamada heap.
            - Permanece valida hasta que el programador la libere explicitamente.
        En C, el programador es responsable de:
            - Pedir memoria.
            - Verificar que se asigno correctamente.
            - Liberarla cuando ya no se usa.
    
    Para que se usa?
        Se usa cuando:
            - No conoces la dimension de los datos al compilar
            - La dimension puede variar (arrays dinamicos)
            - Trabajamos con:
                - Archivos - FILE *
                - Listas - List, pilas - stack, colas - queue.
                - Estructuras dinamicas -dinamics struct
                - Grandes volumenes de datos.
        Ej.:
            - int n;
            - scanf("%d",&n);
            - int v[n]; // NO estandar solo en algunos compiladores
            La forma correcta y portable:
            - int *v = malloc(n * sizeof(int));
    
    Asignacion dinamica de memoria:
        Se hace principalmente con funciones de <stdlib.h>, por lo cual deberemos incluirla
        cuando deseamos manejar la memoria dinamicamente.
        
        Funciones:
            - malloc();
            - calloc();
            - realloc();
            - free();
        
        Funcion malloc():
            Que es?:
                malloc significa memory allocation.

                - Es una funcion que:
                    - Reserva un bloque de meoria en el heap.
                    - Devuelve la direccion inicial del bloque.
                    - NO inicializa la memoria.
            
            Sintaxis:
                - void *malloc(size_t size);
                    - size => Cantidad de bytes a reservar.
                    - Retorna:
                        - Un puntero a la memoria reservada.
                        - NULL si no pudo reservar.
                    
                    Porque devuelve void*?
                        - malloc no sabe que tipo de datos vamos a guardar.
                        - El void * puede convertirse a cualquier puntero.
                    En C no es obligatorio castear, pero suele pedirse:
                        - int *p = (int *) malloc(sizeof(int));
                        - int *v = malloc(n * sizeof(int)); // Para arrays
                        - vector = (int *) malloc((size_t)n * sizeof(int)); // Es una forma mas robusta, el compilador convierte n implicitamente a size_t lo que puede emitir warnings si n es negativo, de esta forma ya casteamos correctamente nosotros.
            Verificacion de error (OBLIGATORIO)
                Siempre hay que comprobar si malloc devolvio NULL:
                    - int *p = malloc(sizeof(int));
                    -
                    - if (p == NULL)
                    - {
                    -   printf("Error: no se pudo asignar memoria\n");
                    -   return 1;
                    - }
                    No hacerlo es un error grave.
            
            Acceso a la memoria asignada
                Una vez asignada, se usa como cualquier puntero:
                    - *p = 10;
                    - printf("%d\n", *p);
                    Para arrays dinamicos:
                    - v[i] = i * 2;
            
            Liberacion de memoria free
                Toda memoria solicitada con malloc DEBE liberarse:
                    - free(p);
                    - p = NULL;
                    Evita:
                        - Memory leaks.
                        - Dangling pointers.
                
            Errores comunes con malloc
                - NO verificar NULL.
                - Usar memoria sin asignar.
                - Olvidar free.
                - Liberar dos veces el mismo puntero.
                - Acceder fuera del bloque reservado.
        Ej.:
        - int *p;
        -
        - p = (int *) malloc(sizeof(int)); // Pedimos memoria para el puntero p
        - 
        - if (p == NULL) // Verificamos que malloc no devolvio NULL
        - {
        -     printf("No se pudo asignar memoria\n");
        -     return 1;
        - }
        -
        - *p = 25; // Pasamos por valor un dato a la direccion del puntero
        - printf("Valor: %d\n", *p);
        - 
        - free(p); 
        - p = NULL; // Liberamos la memoria solicitada
    
    Dangling pointer - puntero colgado o suelto:
        Un puntero que sigue apuntando a una zona de memoria que ya fue liberada
        o que dejo de ser valida.
        En otras palabras:
            - El puntero existe.
            - Tiene una direccion guardada.
            - Pero esa memoria ya no nos pertenece porque fue liberada con free().
            - Usarlo es comportamiento indefinido (UB).
        Ej.:
            - int *p = malloc(sizeof(int)); // Reservamos memoria
            - *p = 10;
            - free(p); // Liberamos del heap la memoria solicitada, dejando de ser valida
            - printf("%d\n", *p); // Error: p es un dangling pointer
            
            Como se evita?
            - int *p = malloc(sizeof(int)); // Reservamos memoria
            - *p = 10;
            - free(p); // Liberamos del heap la memoria solicitada, el puntero queda colgado (dangling)
            - p = NULL; // NULL no apunta a memoria valida
            - printf("%d\n", *p); // Acceder a *p cuando p == NULL es facil de detectar.
            Asignar NULL invalida el puntero y evita su uso accidental.
*/

#include <stdio.h>
#include <stdlib.h> // Se agrega la libreria estandar para trabajar con memoria dinamica

/*
     Las llaves auxiliares se utilizan para aislar los ejemplos,
     limitando el alcance de las variables
     y mostrar usos independientes de la memoria dinamica.
     Se pueden omitir.
*/
int main(void)
{
    /* ---- ASIGNACION DINAMICA DE UNA VARIABLE SIMPLE (int) ---- */
    {
        int *p;

        /* El casteo no es obligatorio en C, pero se usa con fines didacticos */
        p = (int *) malloc(sizeof(int)); // Pedimos memoria para el puntero p

        if (p == NULL) // Verificamos que malloc no devolvio NULL
        {
            printf("No se pudo asignar memoria\n");
            return 1;
        }

        *p = 25; // Pasamos por valor un dato a la direccion del puntero
        printf("Valor almacenado en *p = %d\n\n", *p);

        free(p); 
        p = NULL; // Liberamos la memoria solicitada
    }

    /* ---- ASIGNACION DINAMICA DE UN VECTOR DE ENTEROS ---- */
    {
        int *vector;
        int n, i;

        printf("Ingrese la cantidad de elementos: "); // Solicitamos n al usuario, para asi luego solicitar la memoria correspondiente
        // Validar scanf
        if (scanf("%d", &n) != 1 || n <= 0)
        {
            printf("Entrada invalida\n");
            return 1;
        }

        vector = (int *) malloc(n * sizeof(int)); // Pedimos memoria para el puntero vector
        
        if (vector == NULL) // Verificamos que malloc no devolvio NULL
        {
            printf("Error: no se pudo asignar memoria para el vector\n");
            return 1;
        }

        // Carga del vector
        for (i = 0; i < n; i++)
        {
            vector[i] = i + 1;
        }

        // Mostrar contenido
        printf("Contenido del vector:\n");
        for (i = 0; i < n; i++)
        {
            printf("vector[%d] = %d\n", i, vector[i]);
        }

        free(vector); // Liberamos la memoria solicitada del heap
        vector = NULL; // Evitamos dangling pointer
    }

    return 0;
}