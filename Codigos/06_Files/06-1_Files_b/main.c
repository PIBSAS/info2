// gcc -std=c11 -Wall -Wextra -pedantic main.c -o abm
/*
    ------------------ ARCHIVOS EN C ------------------
    ------------------    Parte 2    ------------------
    Binarios, acceso aleatorio, bloques de memoria, ABM
    ---------------------------------------------------

    Archivos binarios
    Que es un archivo binario?:
        - No guarda texto legible.
        - Guarda bytes tal cual estan en memoria.
        - Ideal para:
            - struct
            - arrays
            - registros
            - base de datos simples
    Ventaja:
        - Mas rapido.
        - Mas chico.
        - No hay parsing.
    Desventaja:
        - No es portable entre arquitecturas distintas.
        - No es legible a mano.
    
    Modos binarios

    | Modo  | Significado              |
    | ----- | ------------------------ |
    | "rb"  | leer binario             |
    | "wb"  | escribir binario (borra) |
    | "ab"  | agregar                  |
    | "rb+" | leer/escribir            |
    | "wb+" | leer/escribir (borra)    |
        En Windows es obligatorio usar b.
    
    Escritura de bloques
        - fwrite
        Sintaxis:
        - size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp);
        Que hace?:
        - Escribe nmemb elementos.
        - Cada uno de tamaño size.
        - Desde memoria => archivo.
        Ej.:
            - int x = 42;
            - fwrite(&x, sizeof(int), 1, fp);
            Escribe el int completo, no texto.
    
    Lectura de bloques
        - fread
        Sintaxis:
        - size_t fread(void *ptr, size_t size, size_t nmemb, FILE *fp);
        Que hace?:
        - Lee nmemb elementos.
        - Cada uno de tamaño size.
        - Desde memoria => archivo.
        Ej.:
            - int x;
            - fread(&x, sizeof(int), 1, fp);
            Retorna cuantos elementos leyo realmente.
    
    Ejemplo:
        Struct + archivo binario
        Definimos un registro:
            - typedef struct {
            -   int id;
            -   char nombre[30];
            -   float sueldo;
            - } Empleado;
        
        Escritura:
            - Empleado e = {1, "Diana", 120000.50};
            -
            - FILE *fp = fopen("empleados.dat", "wb");
            - fwrite(&e, sizeof(Empleado), 1, fp);
            - fclose(fp);
        Lectura:
            - Empleado e;
            -
            - FILE *fp = fopen("empleados.dat", "rb");
            - fread(&e, sizeof(Empleado), 1, fp);
            - fclose(fp);
            -
            - printf("%d %s %.2f\n", e.id, e.nombre, e.sueldo);
            No hay fscanf, no hay parsing, no hay texto.
    
    Lectura/escritura de varios registros
        - Empleado v[2] = {
        -   {1, "Diana", 100000},
        -   {2, "Lucia", 110000},
        -   {3, "Carlos", 105000}
        - };
        -
        - fwrite(v, sizeof(Empleado), 3, fp);

        Lectura:
            - Empleado v[3];
            - fread(v, sizeof(Empleado), 3, fp);
            Esto es memoria => disco => memoria, directo.
    
    Acceso aleatorio
        - fseek
        - ftell
        - rewind
        Sintaxis fseek:
            - int fseek(FILE *fp, long offset, int origen);

            | Origen   | Significado     |
            | -------- | --------------- |
            | SEEK_SET | inicio          |
            | SEEK_CUR | posicion actual |
            | SEEK_END | fin             |
        
        Ej. Ir al registro N:
            - fseek(fp, n * sizeof(Empleado), SEEK_SET);
            - fread(&e, sizeof(Empleado), 1, fp);
            Esto es archivo random / directo.
        
        Sintaxis ftell:
            - long pos = ftell(fp);
            Devuelve la posicion actual (en bytes).
        
        Sintaxis rewind:
            - rewind(fp);
            Vuelve al inicio (equivale a fseek(fp, 0, SEEK_SET) ).
        
    Altas, Bajas y Modificaciones (ABM)
        Alta:
            - fopen("ab")
            - fwrite
        Listado:
            - fopen("rb")
            - while (fread(...) == 1)
        Modificacion:
            - fopen("rb+")
            - buscar registro
            - fseek
            - fwrite
        Baja logica:
            - No borrar fisicamente.
            - Marcar como borrado
        
        Ej.:
            - typedef struct {
            -   int id;
            -   char nombre[30];
            -   float sueldo;
            -   int activo; // 1 = activo, 0 = borrado
            - } Empleado;
    
    Borrar un archivo
        - remove
        Sintaxis remove:
            - int remove(const char *filename);
        Que hace?:
            Borra un archivo del sistema (No del programa, del disco).
        Ej.:
        - remove("empleados.dat");
        Borra el archivo del sistema
    
    Liberar buffer manualmente
        - fflush
        Sintaxis:
            - fflush(fp);
        - Fuerza escritura inmediata.
        - Util en logs.
        - Normalmente no hace falta si usas fclose.
    
    -------------- CONCEPTOS TEORICOS --------------

    Streams:
        Es un flujo de datos entre el programa y un dispositivo (Teclado, Pantalla, Archivo, etc).
        Utiliza un buffer intermedio:
            - En salida stdout: se acumulan datos y luego se escriben.
            - En entrada stdin: se leen bloques desde el dispositivo.
        
        Streams standard:
            - stdin  : entrada estandar (teclado)
            - stdout : salida estandar (pantalla)
            - stderr : salida de errores (pantalla)

        En formato texto:
            - Se realizan conversiones (ASCII)
        
        En formato binario:
            - No hay conversiones.
            - Los datos se guardan tal cual en memoria.

    struct FILE:
        FILE es una estructura opaca definida por la libreria
        estandar que representa un stream de archivo.

        Contiene internamente:
            - Buffer.
            - Posicion actual.
            - Flags de estado.
            - Descriptor del sistema operativo.
        
        IMPORTANTE:
            - El contenido de FILE es dependiente del compilador.
            - No debe accederse a sus campos directamente.
            - Solo se manipula mediante funciones estandar (fopen, fread, fwrite, fseek, fclose, etc.)
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[30];
    double sueldo; // Usar double en lugar de float para dinero, porque modifica si la cifra es mayor a 7 cifras
    int activo;
} Empleado;

/* ---- PROTOTIPOS ---- */
void alta(void);
void listar(void);
void modificar(void);
void baja(void);

int main(void)
{
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Alta\n");
        printf("2. Listar\n");
        printf("3. Modicar\n");
        printf("4. Baja\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                alta();
                break;
            case 2:
                listar();
                break;
            case 3:
                modificar();
                break;
            case 4:
                baja();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);

    return 0;
}

/* ---- ALTA ---- */
void alta(void)
{
    FILE *fp = fopen("empleados.dat", "ab");
    if (fp == NULL) {
        printf("Error al abrir archivo\n");
        return;
    }

    Empleado e;

    printf("ID: ");
    scanf("%d", &e.id);

    printf("Nombre: ");
    scanf("%29s", e.nombre);

    printf("Sueldo: ");
    scanf("%lf", &e.sueldo);

    e.activo = 1;

    fwrite(&e, sizeof(Empleado), 1, fp);
    fflush(fp); // Vacia buffer (normalmente no es necesario, solo es didactico, se usa fclose(fp))

    printf("Empleado agregado\n");
}

/* ---- LISTAR ---- */
void listar(void)
{
    FILE *fp = fopen("empleados.dat", "rb");
    if (fp == NULL) 
    {
        printf("No hay archivo\n");
        return;
    }

    /* DEMO SEEK_END + ftell */
    fseek(fp, 0, SEEK_END); // Va al final del archivo
    long tam = ftell(fp); // Dimension del archivo en bytes
    printf("Dimension del archivo: %ld bytes\n", tam);
    
    rewind(fp); // Vuelve al inicio del archivo (equivale a fseek(fp, 0, SEEK_SET))
    
    Empleado e;
    
    printf("\n --- LISTADO ---\n");
    
    while (fread(&e, sizeof(Empleado), 1, fp) == 1)
    {
        if (e.activo) {
            printf("ID: %d | Nombre: %s | Sueldo: %.2f\n", e.id, e.nombre, e.sueldo);
        }
    }

    long pos = ftell(fp); // Posicion actual
    printf("Posicion actual en bytes: %ld\n", pos); 

    fclose(fp);

}

/* ---- MODIFICAR ---- */
void modificar(void)
{
    FILE *fp = fopen("empleados.dat", "rb+");
    if (fp == NULL)
    {
        printf("No hay archivo\n");
        return;
    }

    int id;
    Empleado e;

    printf("ID a modificar: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Empleado), 1, fp) == 1)
    {
        if (e.id == id && e.activo)
        {
            printf("Nuevo sueldo: ");
            scanf("%lf", &e.sueldo);

            fseek(fp, -(long)sizeof(Empleado), SEEK_CUR);
            fwrite(&e, sizeof(Empleado), 1, fp);
            fclose(fp);

            printf("Empleado modificado\n");
            return;
        }
    }

    fclose(fp);
    printf("Empleado no encontrado\n");
}

/* ---- BAJA LOGICA ---- */
void baja(void)
{
    FILE *fp = fopen("empleados.dat", "rb+");
    if (fp == NULL)
    {
        printf("No hay archivo\n");
        return;
    }

    int id;
    Empleado e;

    printf("ID a dar de baja: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Empleado), 1, fp) == 1)
    {
        if(e.id == id && e.activo)
        {
            e.activo = 0;

            fseek(fp, -(long)sizeof(Empleado), SEEK_CUR);
            fwrite(&e, sizeof(Empleado), 1, fp);
            fclose(fp);

            printf("Empleado dado de baja\n");
            return;
        }
    }

    fclose(fp);
    printf("Empleado no encontrado\n");
}