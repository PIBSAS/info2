// gcc -std=c11 -Wall -Wextra -pedantic main.c -o vectores
 /*
    En C, un vector y un puntero NO son lo mismo, pero estan intimamente relacionados
    Que es un array?:
    - Un array es un objeto que representa N objetos del mismo tipo, almacenados en memoria contigua, cuyo tipo incluye su tamaño.
    - int a[5] = {10, 20, 30, 40, 50}; 
    - a no es una variable asignable.
    - a no es un puntero.
    - a representa un objeto de tipo "array de N elementos"

    Que pasa cuando usamos el nombre del array?
    - En la mayoria de las expresiones, un array se convierte implícitamente en un puntero al primer elemento:
    - a
    - Se convierte automaticamente en:
    - &a[0] Es decir:
    - Tipo: int *
    - Valor: direccion del primer elemento.
    - Ejemplo:
    - int *p = a; Es correcto, se declara el puntero a int p y se le asigna la direccion de memoria del primer elemento de a[0]
    - int *q = &a[0]; Es correcto y exactamente lo mismo que en la linea anterior.
    - Pero esto no convierte a a en un puntero, solo significa que en esa expresion se usa su direccion inicial
    - Excepciones donde el array NO decae (decay) a puntero.
    - sizeof(a)
    - &a
    - Inicializacion directa del array.

    Diferencia fundamental con el puntero:
    - int a[5];
    - sizeof(a) es 5 * sizeof(int) = 5 * 4 bytes = 20 bytes su dimension
    - a = p; NO PERMITIDO
    - No puede cambiar a  que direccion de memoria apunta
    - Puntero: 
    - int *p;
    - sizeof(p) Dimension del puntero segun arquitectura
    - p = a; PERMITIDO
    - Puede apuntar a otra cosa.

    Acceso a elementos
    - Misma sintaxis, distinto significado.
    - a[2] Acceso al elemento 2 del array a.
    - p[2] Acceso al objeto que esta 2 elementos despues de la direccion que guarda el puntero p.
    - Ambos significan:
    - *(a + 2)
    - *(p + 2)
    . []: El operador [] es pura aritmetica de punteros.

    Relacion formal entre punteros y arrays
    - Por definicion del lenguaje
    - a[i] == *(a + i) 
    - p[i] == *(p + i)
    - Esto explica porque funciona esto:
    - int *p = a;
    - printf("%d", p[3]); Imprime 40

    &a NO es lo mismo que a
    - Esto es clave y suele confundir
    - &a tipo: int (*)[5] Puntero al array completo
    - a  tipo: int * Puntero al primer int
    - Direcciones iguales, tipos distintos. Ej:
      - int a[5];
      - int *p =a;
      - printf("a\n", (void *)a);
      - printf("&a\n", (void *)&a); Direccion del array completo
      - printf("p\n", (void *)p);
    - Las direcciones se ven iguales, los tipos NO, el compilador las trata distinto
   
   Un array no es un puntero, 
   pero en la mayoría de las expresiones se convierte implícitamente en un puntero al primer elemento.
   El operador [] está definido en términos de aritmética de punteros, 
   lo que explica por qué la misma sintaxis funciona 
   tanto con arrays como con punteros.

*/
 
 #include <stdio.h>

 int main(void)
 {
   int a[5] = {10, 20, 30, 40, 50}; // Declaracion de un array de 5 elementos del tipo int con dimension 20 bytes(5*sizeof(int))
   int *p = a; // Declaracion de puntero a int p y asignacion de la primer direccion de memoria del array a (a[0])

   printf("a[2] = %d\n", a[2]);
   printf("p[2] = %d\n", p[2]);

   printf("*(a + 2) = %d\n", *(a + 2));
   printf("*(p + 2) = %d\n", *(p + 2));

   printf("\nsizeof(a) = %zu\n", sizeof(a));
   printf("\nsizeof(p) = %zu\n", sizeof(p));

   // Direccion de a cast a (void *)a. Ya que a (en esta expresion) decae a int *. &a es tipo: int (*)[5] array de 5 int(20bytes-array completo). p es tipo int *
   printf("\na\t = %p\n", (void *)a); // Direccion a traves de a
   printf("\n&a\t = %p\n", (void *)&a); // Direccion de a
   printf("\np\t = %p\n", (void *)p); // Direccion del puntero p
   
   return 0;
 }