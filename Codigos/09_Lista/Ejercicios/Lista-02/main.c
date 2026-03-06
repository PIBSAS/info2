// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <stdlib.h> // Se usa system(), exit(), malloc(), free()
#include <conio.h> // Se usa getch() y getche()
#include <ctype.h> // Se usa toupper()

/* Definicion del nodo de la lista */
struct Lis
{
    int Dato;
    struct Lis *Sig; // Puntero al siguiente nodo
};

/* Prototipos de funciones */
void Ingresa(struct Lis **);
void Lee(struct Lis **);
void Borra(struct Lis **);
void Busca(struct Lis **);

int main(void)
{
    int Opcion;

    /* Inicio apunta al primer nodo de la lista.
     * Si es NULL => lista vacia.
     */
    struct Lis *Inicio = NULL;

    /* Bucle infinito tipo menu */
    for (;;)
    {
        system("cls"); // Limpia la pantalla.

        printf("\n1 - Ingresa datos\n");
        printf("2 - Lee datos\n");
        printf("3 - Borra datos\n");
        printf("4 - Busca datos\n");
        printf("5 - Salir\n\n");
        printf("Ingrese una opcion (1 - 5): ");
        
        Opcion = getche(); // Lee el caracter y lo muestra, sin esperar Enter

        switch(Opcion)
        {
            case '1':
                Ingresa(&Inicio);
                break;

            case '2':
                Lee(&Inicio);
                break;

            case '3':
                Borra(&Inicio);
                break;

            case '4':
                Busca(&Inicio);
                break;

            case '5':
                exit(0); // Finaliza inmediatamente el programa
        }
    }
    return 0;
}

/* Inserta un nodo en forma ordenada de mayor a menor */
void Ingresa(struct Lis **Principio)
{
    /* *Actual   => Se usa para recorrer la lista.
     * *Nuevo    => Nodo recien creado.
     * *Anterior => Mantiene el nodo previo para poder enlazar.
     */
    struct Lis *Actual, *Nuevo, *Anterior;
    
    /* Reserva dinamica de memoria para el nuevo nodo.
     * Si malloc devuelve NULL => No hay memoria disponible
     */
    if (! (Nuevo = (struct Lis *)malloc(sizeof(struct Lis))))
    {
        printf("\n\nNo hay memoria disponible\n");
        printf("\n\nPresiones una tecla para continuar\n");
        getch(); // Espera que se presione una tecla.

        return;
    }

    /* Carga del dato en el nodo nuevo */
    printf("\n\nIngrrese el dato: ");
    scanf("%d", &Nuevo->Dato);

    /* Caso 1: Si la lista esta vacia.
     * El Nuevo nodo pasa a ser el primero.
     */
    if (!*Principio)
    {
        *Principio = Nuevo;
        Nuevo->Sig = NULL;

        return;
    }

    /* Inicializacion de punteros para recorrer */
    Anterior = *Principio;
    Actual = *Principio;

    /* Busca la posicion correcta para mantener la lista ordenada de mayor a menor.
     * Busca mientras:
     * - No llegue al final.
     * - Y el valor Actual sea mayor que el Nuevo.
     */
    while((Actual->Dato > Nuevo->Dato) && Actual) // Deberia ser while(Actual && (Actual->Dato > Nuevo->Dato)) Dato no existiria si no existe Actual!
    {
        Anterior = Actual;
        Actual = Actual->Sig;
    }

    /* Caso 2: Si se llego al final (Actual == NULL). Insertamos al final. */
    if (!Actual)
    {
        Anterior->Sig = Nuevo;
        Nuevo->Sig = NULL;

        return;
    }

    /* Caso 3: Si se inserta al principio.
     * Ocurre cuando el nuevo valor debe ir antes del primero.
     */
    if (Anterior == Actual)
    {
        *Principio = Nuevo;
        Nuevo->Sig = Anterior;

        return;
    }

    /* Caso4: Insercion intermedia
     * Se reconectan los enlaces:
     * Anterior => Nuevo => Actual
     */
    Anterior->Sig = Nuevo;
    Nuevo->Sig = Actual;
}

/* Recorre e imprime la lista */
void Lee(struct Lis **Principio)
{
    /* *Actual apunta a el primer nodo */
    struct Lis *Actual = *Principio;

    /* Recorre hasta que Actual sea NULL, desde inicio a NULL */
    while (Actual)
    {
        printf("\nEl dato es: %d\n", Actual->Dato);
        Actual = Actual->Sig;
    }

    printf("\n\nPresione una tecla para continuar\n");
    getch(); // Espera que se presione una tecla.
}

/* Elimina un nodo si existe, con pedido de confirmacion de la eliminacion */
void Borra(struct Lis **Principio)
{
    struct Lis *Actual, *Anterior;
    int Valor;
    char Opcion;

    /* Carga del dato a eliminar */
    printf("\nIngrese el dato a borrar: ");
    scanf("%d", &Valor);
    
    Actual = *Principio;
    Anterior = *Principio;

    /* Busca el nodo */
    while ((Valor != Actual->Dato) && Actual) // Lo mismo la condicion && esta invertida, Si Actual no existe, Dato no existira!
    {
        Anterior = Actual;
        Actual = Actual->Sig;
    }

    /* Si fue encontrado */
    if (Actual)
    {
        printf("\nEl dato es: %d\n\n", Actual->Dato);
        printf("\n\nDesea eliminar este dato (S / N)");

        Opcion = toupper(getche()); // Cambia a mayuscula lo ingresado y lo muestra y almacena en la variable

        if (Opcion == 'S')
        {
            /* Caso 1: Si es el primer nodo */
            if (Anterior == Actual)
            {
                *Principio = Actual->Sig; // El segundo nodo pasa a ser el primero
                free(Actual); // Libera la memoria del nodo eliminado.

                return;
            }
            
            /* Caso 2: Nodo intermedio o final */
            Anterior->Sig = Actual->Sig; // Se saltea el nodo a eliminar
            free(Actual); // Libera la memoria del nodo eliminado

            return;
        }

        return;
    }

    /* Si no se encontro */
    printf("\nEl dato no ha sido encontrado");
    printf("\n\nPresione una tecla para continuar\n");

    getch(); // Espera que se presione una tecla.

}

/* Busca un nodo por valor */
void Busca(struct Lis **Principio)
{
    struct Lis *Actual;
    int Valor;

    printf("\nIngrese el dato a buscar: ");
    scanf("%d", &Valor);

    Actual = *Principio;

    /* Recorre la lista buscando coincidencia */
    while ((Valor != Actual->Dato) && Actual) // Nuevamente && con condiiones invertidas
    {
        Actual = Actual->Sig;
    }

    /* Si fue encontrado */
    if (Actual)
    {
        printf("\nEl dato es: %d\n\n", Actual->Dato);
        printf("\n\nPresione una tecla para continuar\n");

        getch(); // Espera que se presione una tecla.

        return;
    }

    /* Si no fue encontrado */
    printf("\nEl dato no ha sido encontrado");
    printf("\n\nPresione una tecla para continuar\n");

    getch(); // Espera que se presione una tecla.
    
}