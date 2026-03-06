// gcc -std=c11 -Wall -Wextra -pedantic main.c -o bitfields
/*
    Que es un campo de bits-bit fields?
        Los campos de bit son una forma especial de declarar miembros de una estructura
        donde, en vez de ocupar toda la dimension del tipo (int, unsigned, etc),
        se indica cuantos bits exactos ocupa el campo.
    
    Para que sirven?
        Para empaquetar informacion y ahorrar memoria, o para representar flags y registros de hardware.
        Ej.:
            - Necesitamos guardar:
                - Un estado que solo vale 0 o 1 => 1 bit.
                - Un numero de 0 a 7 => 3 bits.
                - Un codigo de 0 a 15 => 4 bits.
            No tiene sentido gastar 3 int completos para eso
    
    Sintaxis:
        La sintaxis SOLO EXISTE dentro de un struct:
        - tipo nombre_campo : cantidad_de_bits;
        Ej.:
        - struct Ejemplo {
        -   unsigned campo1 : 1; // Campo : Cantidad de bits que ocupa
        -   unsigned campo2 : 3;
        -   unsigned campo3 : 4;
        - };
        IMPORTANTE:
            - cantidad_de_bits debe ser una constante entera positiva.
            - Solo se permiten tipos enteros:
                - int
                - unsigned int
                - signed int
                - _Bool (desde C99)
            - NO SE PUEDE USAR float, double, punteros, structs, etc.
    
    Ejemplo simple:
        - struct flags {
        -   unsigned listo : 1;
        -   unsigned error : 1;
        -   unsigned prioridad : 2;
        - };
        Uso:
        - struct flags f = {1, 0, 3};
        - printf("listo = %u\n", f.listo);
        - printf("error = %u\n", f.error);
        - printf("prioridad = %u\n", f.prioridad);
    Que sucede aqui?
    - listo ocupa 1 bit => Valores posibles: 0 o 1
    - error ocupa 1 bit => Valores posibles: 0 o 1
    - prioridad ocupa 2 bit => Valores posibles: 0 a 3
    Si intentamos hacer:
    - f.prioridad = 5; (UB)
    Comportamiento dependiente de la implementacion (generalmente se truncan bits)

    Cuanta memoria ocupan?
        Aca aparece la primera gran advertencia:
        - El estandar NO garantiza el layout exacto en memoria.
        Pero en la practica:
        - El compilador agrupa campos de bit en unidades de la dimension del tipo base.
        - Generalmente usa palabras-Word de 1, 2 o 4 bytes
        Ej.:
        - struct A {
        -   unsigned a : 1;
        -   unsigned b : 1;
        -   unsigned c : 1;
        - };
        Aunque solo usa 3 bits:
        - Probablemente sizeof(struct A) sea 4 bytes (si unsigned es de 4 bytes)
    
    Conclusion importante:
        Los campos de bit reducen espacio logico, pero no siempre reducen sizeof como uno imagina.
    
    Campos de relleno (padding explicito)
        Podemos usar campos sin nombre para forzar alineacion:
        - struct B {
        -   unsigned a : 3;
        -   unsigned : 5; // Padding-Relleno
        -   unsigned b : 8;
        - };
        Esto:
        - Descarta bits.
        - Sirve para alinear a limites especificos.
        - Es comun en registros de hardware.
    
    Campos de bit con signo:
        - struct C {
        - signed valor : 3;
        - };
        Con 3 bits:
        - Valores posibles (normalmente): -4 a +3
        El signo y representacion depende del compilador(Complemento a 2- Two's complement es lo comun, pero el estandar no lo obliga).
            Regla practica:
            - Usamos unsigned siempre que podemos.
            - Evitamos campos de bit con signo salvo que sea estrictamente necesario
    
    Acceso y uso:
        Se acceden igual que cualquier miembro de estructura:
        - f.error = 3;
        - if (f.listo) {
        -   printf("Todo Ok\n");
        - }
        NO SE PUEDE:
        - Tomar la direccion de un campo de bit.
        - unsigned *p = &f.error; // ERROR
        Porque no ocupa una direccion de memoria independiente.
    
    Pasaje a funciones:
        Los campos de bit no se pasan individualmente, pero si la estructura:
        - void procesar(struct Flags f)
        - {
        -   if (f.error)
        -   {
        -       ...
        -   }
        - }
        O por puntero:
        - void limpiar(struct Flags *f)
        - {
        -   f -> error = 0;
        - }
    
    Diferencia con operaciones a nivel bit:
        Muchos confunden campos de bits con operadores bit a bit (& | ^ << >> ).
        Campos de bit - bit-fields:
        - Mas legibles.
        - Expresan intencion.
        - layout NO portable.
        - NO direccionables.
        Operadores bit a bit:
        - Totalmente controlables.
        - Portables.
        - Usados en protocolos y mascaras.
        - Menos legibles.
        Ej. equivalente con mascara:
        - # define LISTO (1 << 0)
        - # define ERROR (1 << 1)
        - # define PRIORIDAD (3 << 2)
    
    Cuando usarlos (y cuando no):
        - Estamos modelando flags logicos.
        - Estamos representando registros de hardware.
        - La portabilidad exacta no es critica.
        - El codigo es didactico o interno.
        No usarlos cuando:
        - Necesitamos layout binario exacto.
        - Escribimos archivos binarios.
        - Hacemos comunicacion de red.
        - Necesitamos direcciones de los campos.

    Nota:
         El orden de los bits dentro de la unidad de almacenamiento (LSB -> MSB o viceversa)
         es dependiente de la implementacion y no esta garantizado por el estandar.
         Es por esto que en el codigo solemos declarar por convencion los bit-fields de LSB -> MSB.
    Resumen:
        - Solo dentro de struct.
        - Ocupan bits, no bytes.
        - Sintaxis: tipo campo : bits;
        - No direccionables, ni portables.
        - Layout dependiente del compilador.
        - Muy utiles para flags y hardware
    
    Los campos de bit definen la dimension lógica de los datos en bits, 
    pero el almacenamiento físico y la dimension medida por sizeof dependen 
    del empaquetado y alineación del compilador, 
    ya que la memoria es direccionable por bytes.

    Extra: Que es alineacion?:
        Cada tipo de dato suele requerir que su direccion de memoria
        sea multiplo de cierto valor.
        Ej.:
        - char => alineacion 1 byte.
        - short => alineacion 2 bytes.
        - int / unsigned => alineacion 4 bytes.
        El compilador inserta padding-relleno para cumplir eso.
*/

#include <stdio.h>

/* ---- bit-fields ----*/
struct Flags {
    unsigned listo : 1;
    unsigned error : 1;
    unsigned prioridad : 2;
};

/* ---- CAMPOS DE RELLENO ---- */
struct ConPadding {
    unsigned a : 3;
    unsigned : 5; // Padding de 5 bits
    unsigned b : 8;
};

/* ---- CAMPOS DE BIT CON SIGNO ---- */
struct SignedBits {
    signed valor : 3;
};

/* ---- PASAJE A FUNCIONES POR PUNTERO ---- */
void limpiar_error(struct Flags *f)
{
    f->error = 0;
}

int main(void)
{
    struct Flags f = {1, 0, 3}; // listo: bit en 1, error: bit en 0, prioridad: bit en 3

    printf("listo = %u\n", f.listo);
    printf("error = %u\n", f.error);
    printf("prioridad = %u\n", f.prioridad);

    /* ---- MEMORIA OCUPADA ---- */
    printf("sizeof(struct Flags) = %zu bytes\n", sizeof(struct Flags));

    /* ---- TRUNCAMIENTO DE BITS ---- */
    f.prioridad = 5; // Se espera que el compilador indique el fuera de rango -Woverflow
    printf("prioridad luego de asignar 5 = %u\n", f.prioridad); // Mostrara 1, porque prioridad tiene 2 bits, le estamos asignando 5 => 101 pero solo entran 2 bits 01, se conservan los LSB 01 = 1

    /* ---- CAMPOS DE RELLENO ---- */
    printf("sizeof(struct ConPadding) = %zu bytes\n", sizeof(struct ConPadding));

    /* ---- CAMPOS DE BIT CON SIGNO ---- */
    struct SignedBits s = { -1 };
    printf("valor = %d\n", s.valor); 

    /* ---- PASAJE A FUNCIONES POR PUNTERO ---- */
    f.error = 1;
    limpiar_error(&f); // Modificacion del campo de bit - bit-field
    printf("error luego de limpiar = %u\n", f.error);

    return 0;
}