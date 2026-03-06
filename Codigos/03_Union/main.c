// gcc -std=c11 -Wall -Wextra -pedantic main.c -o union
/*
    Que es una union?
        Una union es un tipo de dato compuesto, parecido a un struct, 
        pero con una diferencia clave:
            Todos sus miembros comparten la misma zona de memoria.
        En un struct:
            - Cada campo tiene su propio espacio.
        En una union:
            - Hay un solo bloque de memoria, reutilizado por todos los campos.
        Es decir:
            - Una union puede guardar una cosa u otra, pero no varias a la vez.
    
    Para que se usan?
        Principalmente para:
            - Ahorrar memoria (muy comun en sistemas embebidos o protocolos)
            - Interpretar los mismos bits de distintas formas (ej: un int como bytes)
            - Representar datos mutuamente excluyentes (ej: un valor que puede ser int o float)
    
    Declaracion:
        Sintaxis basica:
            - union Nombre {
            -   tipo campo1;
            -   tipo campo2;
            -   ...
            - };
            Ejemplo:
                - union Dato {
                -   int i;
                -   float f;
                -   char c;
                - };
                Esto NO significa que tenga espacio para los tres, sino solo para el mas grande (sizeof(tipo))
    
    Declarar variables de una union:
        - union Dato d;
        O todo junto:
        - union Dato {
        -   int i;
        -   float f;
        - } d;
    
    Acceso a los campos:
        Se accede igual que en un struct con el operador "."
        - d.i = 10:
        - d.f = 3.14f;
        ADVERTENCIA:
            - Si escribimos un campo y luego leemos otro, el resultado es indefinido (UB)

    Dimension y ubicacion en memoria:
        - sizeof de una union.
        La dimension de una union es:
            - La dimension del miembro mas grande.
            - Ej.:
                - union Ejemplo {
                -   char c;
                -   int i;
                -   double d;
                - };
                - int main(void)
                - {
                -   printf("sizeof(union Ejmplo) = %zu\n", sizeof(union Ejemplo));
                -   return 0;
                - }
                Va a valer sizeof(double) (o mas si hay alineacion).
    
    Direccion de los campos:
        Todos los campos empiezan en la misma direccion:
        - union U {
        -   int i;
        -   float f;
        - };
        - union U u;
        - printf("&u\t = %p\n", (void *)&u); Direcion de u
        - printf("&u.i\t = %p\n", (void *)&u.i); Direccion del campo i
        - printf("&u.f\t = %p\n", (void *)&u.f); Direccion del campo f
        Las direcciones seran iguales!!!
    
    Pasaje de miembros de una union a funciones:
        Podemos pasar un campo como cualquier variable:
        - void imprimir_int(int x)
        - {
        -   printf("x = %d\n", x);
        - }
        Uso:
        - union Dato d;
        - d.i = 20;
        - imprimir_int(d.i);
    
    Pasaje de una union completa a una funcion:
        Por valor (Copia):
            - void mostrar(union Dato d)
            - {
            -   printf("d.i = %d\n", d.i);
            - }
            Uso:
            - union Dato d;
            - d.i = 10;
            - mostrar(d);
        Por referencia (recomendado)-Modifica la original:
            - void modificar(union Dato *d)
            - {
            -   d->i = 50;
            - }
            Uso:
            - modificar(&d);
    
    Retorno de una union desde una funcion:
        - union dato crear_dato(void)
        - {
        -   union Dato d;
        -   d.i = 100;
        -   return d;
        - }
        Uso:
        - union Dato d = crear_dato();
    
    Uniones dentro de estructuras (IMPORTANTE):
        Este es el uso mas comun en la practica.
        - struct Registro {
        -   int tipo;
        -   union {
        -       int i;
        -       float f;
        -       char c;
        -   } dato;
        - };
        Uso:
        struct Registro r;
        r.tipo = 1; Asignacion del campo tipo
        r.dato.i = 42 Asignacion del campo i de la union dato
        Aca el campo tipo indica como interpretar la union, patron clasico: tagged union
    
    Uniones de struct:
        Es una union cuyos miembros son struct. La variable puede contener una estructura u otra,
        pero nunca ambas al mismo tiempo, y todas comparten la misma memoria.
        Es el mismo concepto de union, pero el "bloque alternativo" ahora es una estructura completa.
        
        Para que se usa: 
        - Representar formatos de datos distintos.
        - Protocolos.
        - Registros que cambian de forma segun el contexto.
        - Ahorrar memoria cuando las estructuras son grandes.

        Declaracion de una union de struct:
        - Declarar las struct:
            - struct Alumno {
            -   int legajo;
            -   float promedio;
            - };
            - struct Docente {
            -   int id;
            -   int horas;
            -  };
        - Declarar la union:
            - union Persona {
            -   struct Alumno alumno;
            -   struct Docente docente;
            - };
        La memoria de union Persona sera:
            - max(sizeof(struct Alumno), sizeof(struct Docente))
        Uso:
        - struct Registro {
        -   int tipo;  // 0 = Alumno, 1 = Docente
        -   union Persona persona;
        - };
    
    Diferencia clave struct vs union:

    | Caracteristica   | struct                      | union              |
    | ---------------- | --------------------------- | ------------------ |
    | Memoria          | Cada campo tiene su espacio | Todos comparten    |
    | Uso tipico       | Datos simultaneos           | Datos alternativos |
    | Dimension        | Suma de campos              | Maximo de campos   |

    Errores comunes:
    - Leer un campo distinto al ultimo escrito.
    - Creer que una union guarda varios valores.
    - Olvidar indicar que campo es valido (con un tipo)
    - Una union de estructuras no contiene varias estructuras, contiene memoria suficiente para la mas grande

*/

#include <stdio.h>

/* ---- UNION ----*/
union Dato {
    int i;
    float f;
    char c;
};

/* ---- FUNCIONES ---- */

/* Pasaje por valor */
void mostrar_union(union Dato d)
{
    printf("[mostrar_union] d.i = %d\n", d.i);
}

/* Pasaje por referencia */
void modificar_union(union Dato *d) // d es un puntero a union Dato
{
    d->i = 100;
}

/* Retorno de una union */
union Dato crear_union(void)
{
    union Dato d;
    d.i = 200;

    return d;
}

/* ---- UNION EN STRUCT ---- */
struct Registro {
    int tipo; // 0 = int, 1 = float, 2 = char
    union {
        int i;
        float f;
        char c;
    } dato;
};

/* ---- UNION DE STRUCT ---- */
struct Alumno {
    int legajo;
    float promedio;
};

struct Docente {
    int id;
    int horas;
};

union Persona {
    struct Alumno alumno;
    struct Docente docente;
};

struct  RegistroPersona {
    int tipo; // 0 = Alumno, 1 = Docente
    union Persona dato;
};

int main(void)
{
    union Dato d; // Declaracion de Variable d del tipo union Dato

    /* ---- ESCRITURA Y LECTURA DEL MISMO CAMPO ---- */
    d.i = 65; // Asignacion del campo i de la union Dato d

    printf("d.i = %d\n", d.i); // Mostrar el valor del campo i de la union Dato d
    printf("d.c = %c (misma memoria)\n", d.c); // Distinta interpretacion, para la misma memoria, aca es ASCII 65 = 'A' 

    /* ---- ESCRITURA DE OTRO CAMPO (CAMBIA LA INTERPRETACION) ---- */
    d.f = 3.14f;
    printf("d.f = %f\n", d.f);

    /* ---- DIMENSION ---- */
    printf("sizeof(union Dato) = %zu bytes\n", sizeof(union Dato)); // Va a valer 4 bytes ya que sizeof(int) y sizeof(float) miden lo mismo 

    /* ---- DIRECCIONES ---- */
    printf("&d\t = %p\n", (void *)&d);
    printf("&d.i\t = %p\n", (void *)&d.i);
    printf("&d.f\t = %p\n", (void *)&d.f);
    printf("&d.c\t = %p\n", (void *)&d.c);

    /* ---- PASAJE POR VALOR ---- */
    d.i = 10;
    mostrar_union(d);

    /* ---- PASAJE POR REFERENCIA ----*/
    modificar_union(&d);
    printf("Luego de modificar_union: d.i = %d\n", d.i);

    /* ---- RETORNO DE UNION ---- */
    d = crear_union();
    printf("Luego de crear_union: d.i = %d\n", d.i);

    /* ---- UNION EN STRUCT ---- */
    struct Registro r;
    
    r.tipo = 0; // int
    r.dato.i = 42;

    if (r.tipo == 0) {
        printf("Registro contiene int: %d\n", r.dato.i);
    }

    /* ---- UNION DE STRUCT ---- */
    struct RegistroPersona rp;

    /* CASO ALUMNO */
    rp.tipo = 0;
    rp.dato.alumno.legajo = 1234; // struct.union.struct.campo
    rp.dato.alumno.promedio = 8.5f;

    if (rp.tipo == 0)
    {
        printf("Alumno - legajo: %d, promedio: %.2f\n", rp.dato.alumno.legajo, rp.dato.alumno.promedio);
    }

    /* CASO DOCENTE (reutiliza la misma memoria) */
    rp.tipo = 1;
    rp.dato.docente.id = 77;
    rp.dato.docente.horas = 20;

    if (rp.tipo == 1)
    {
        printf("Docente - id: %d, horas: %d\n",rp.dato.docente.id, rp.dato.docente.horas);
    }

    return 0;
}