// gcc -std=c11 -Wall -Wextra -pedantic main.c -o files
/*
    ------------------ ARCHIVOS EN C ------------------
    ------------------    Parte 1    ------------------
    ---------------------------------------------------
      
    Que es un archivo-file and stream?
        Una secuencia de bytes almacenada en algun dispositivo (disco, pendrive, etc)
        a la que se accede de forma secuencial o aleatoria mediante un flujo (stream).
    
    FILE *:
        En C NUNCA trabajamos directamente con el archivo.
        Siempre trabajamos con un puntero a una estructura interna:
        - FILE *fp;
        Ese FILE:
        - NO lo definimos nosotros.
        - NO sabemos como es por dentro. (A menos que nos documentemos al respecto, viendo la libreria estandar)
        - Lo maneja la biblioteca estandar.
        - Nosotros usamos el puntero.
    
    Apertura de un archivo:
        - fopen
        Sintaxis:
        - FILE *fopen(const char *nombre, const char *modo);
        Ej.:
            - FILE *fp = fopen("datos.txt", "r");
        Que hace?
        - Busca el archivo.
        - Prepara buffers.
        - Devuelve un FILE *
        Si falla devuelve NULL.
        Regla:
            - TODO fopen exitoso debe tener su fclose.

    Cierre de un archivo:
        - fclose
        Sintaxis:
        - int fclose(FILE *fp);
        Es la funcion que:
        - Cierra el archivo asociado al FILE *
        - Vacia los buffers pendientes
        - Libera recursos del sistema operativo
        Sin fclose, el archivo NO esta realmente terminado.

        Que pasa internamente cuando usamos fclose?
            Aunque no lo vemos, pasan varias cosas:
            - Se vacian los buffers:
                - Lo escrito con fputc, fprintf, etc.
                - Puede que todavia no este en el disco.
            - Se libera memoria:
                - Estructuras internas (FILE)
                - Descriptores del sistema.
            - Se libera el archivo:
                - Otros programas pueden usarlo.
                - Se asegura la integridad del archivo.
        
        Que pasa si NO llamamos a fclose?
            Depende... y eso es lo peligroso.
            Posibles consecuencias:
                - El archivo queda incompleto.
                - Los ultimos datos no se escriben.
                - Fugas de recursos.
                - En algunos sistemas:
                    - El archivo puede quedar corrupto.
                    - O no aparecer.
                - En programas chicos "parece funcionar".
                - En programas reales mata su funcionamiento.
        
        Valor de retorno de fclose:
            - int r = fclose(fp);
                - 0 => OK
                - EOF => Error al cerrar
            Ej.:
                - if (fclose(fp) == EOF)
                - {
                -   printf("Error al cerrar el archivo\n");
                - }
                Regla:
                - Cada fopen exitoso debe tener exactamente un fclose.

    Modos de apertura:

    | Modo | Significado                          |
    | -----| ------------------------------------ |
    | "r"  | Leer (debe existir)                  |
    | "w"  | Escribir (borra o crea)              |
    | "a"  | Agregar al final                     |
    | "r+" | Leer y escribir                      |
    | "w+" | Leer y escribir (borra lo existente) |
    | "a+" | Leer y escribir al final             |

    - "w": Borra el archivo si existe.
    - "r": Falla si no existe.

    Escritura de un caracter:
        - fputc
        Sintaxis:
        - int fputc(int c, FILE *fp);
        Que hace?:
        - Escribe un solo caracter en el archivo.
        - Avanza el puntero de archivo.
        - Devuelve:
            - El caracter escrito (como unsigned char)
            - EOF si hay error.
        Ej.:
            - FILE *fp = fopen("salida.txt", "w");
            -
            - if (fp == NULL)
            -   return 1;
            -
            - fputc('H', fp);
            - fputc('o', fp);
            - fputc('l', fp);
            - fputc('a', fp);
            - fputc('\n', fp);
            -
            - fclose(fp);
            Contenido del archivo:
            - Hola
            IMPORTANTE:
                fputc NO escribe inmediatamente al disco.
                - Va al buffer.
                - Se garantiza la escritura real con:
                    - fclose
                    - fflush
    
    Lectura de un caracter:
        - fgetc
        Sintaxis:
        - int fgetc(FILE *fp);
        
        Que hace?:
        - Lee un caracter del archivo.
        - Avanza el puntero.
        - Devuelve:
            - El caracter leido.
            - EOF si:
                - Llega al fin del archivo.
                - Ocurre un error
                Esto es clave:
                    EOF no distingue un error de fin de archivo.
        
        Ej.:
        - int c;
        - FILE *fp = fopen("salida.txt", "r");
        -
        - if (fp == NULL)
        -   return 1;
        - 
        - while ((c = fgetc(fp)) != EOF)
        - {
        -   putchar(c);
        - }
        - 
        - fclose(fp);

        OBSERVACION:
            - fgetc: Devuelve int.
            - EOF: NO es un char.
            - Por eso la variable es int.
    
    Deteccion de fin de archivo:
        - EOF
            - No es un caracter.
            - Es un valor especial (normalmente -1)
        Forma correcta de utilizarlo:
        - while ((c = fgetc(fp)) != EOF)
    
        Para distinguir Fin de archivo vs Error de lectura, 
        utilizamos feof ¿Fin de archivo?.
        Sintaxis:
        - int feof(FILE *fp);
            - Devuelve distinto de 0 solo despues de intentar leer y fallar por EOF.
            - NO se adelanta.
        Forma incorrecta, error clasico:
        - while (!feof(fp)) // MAL
        - {
        -   c = fgetc(fp);
        - }
        feof se usa despues, no para controlar el loop.

        ferror - ¿Error?:
        Sintaxis:
        - int ferror(FILE *fp);
            - Devuelve distinto de 0 si ocurrio un error de I/O (Input/Output)
        
        Patron correcto de lectura robusta:
        Ej.:
        - int c;
        -
        - while ((c = fgetc(fp)) != EOF)
        - {
        -   putchar(c);
        - }
        -
        - if (feof(fp)) // Detecta fin
        - {
        -   printf("\nFin de archivo alcanzado\n");
        - }
        - else if (ferror(fp)) // Detecta error
        - {
        -   printf("\nError de lectura\n");
        - }
        Este es el patron canonico en C.

    Escritura de un string:
        - fputs
        Sintaxis:
        int fputs(const char *str, FILE *fp);

        Que hace?
        - Escribe un string completo en el archivo.
        - NO agrega \n automaticamente.
        - Devuelve:
            - Valor no negativo si tuvo exito.
            - EOF si hubo error.
        Ej.:
        - FILE *fp = fopen("texto.txt", "w");
        -
        - if (fp == NULL)
        -   return 1;
        -
        - fputs("Hola mundo", fp);
        - fputs("\n", fp);
        - fputs("Segunda linea", fp);
        -
        - fclose(fp);
        Contenido del archivo:
        - Hola mundo
        - Segunda linea

        Diferencia clave con puts:
        | Funcion | Destino  | Agrega \n |
        | ------- | -------- | --------- |
        | puts    | stdout   | si        |
        | fputs   | archivo  | no        |

        Lectura de un string:
            -fgets
            Sintaxis:
            - char *fgets(char *str, int n, FILE *fp);

            Que hace?:
            - Lee hasta n-1 caracteres.
            - Se detiene si encuentra:
                - \n
                - EOF
            - Incluye el \n si lo lee.
            - Siempre agrega '\0'
            - Devuelve:
                - str si pudo leer algo.
                - NULL si no pudo (EOF o error)
            Ej.:
            - FILE *fp = fopen("texto.txt", "r");
            -
            - if (fp == NULL)
            -   return 1;
            -
            - char linea[100]; // 99 char + \0
            -
            - while (fgets(linea, sizeof(linea), fp) != NULL)
            - {
            -   printf("%s", linea);
            - }
            - fclose(fp);
            Salida:
            - Hola mundo
            - Segunda linea
            
            IMPORTANTE:
                - Lee como maximo n-1, si n = 100, lee hasta 99 caracteres + \0
                - Evita desbordes (overflow)
                - A diferencia de gets (Que esta prohibida)
                - El \n queda adentro. Ej.:
                    - fgets(linea, 100, fp);
                    Si el archivo tiene:
                    - Hola
                    El buffer queda:
                    - "Hola\n\0"
                    Por eso muchas veces se ve:
                    - linea[strcspn(linea, "\n")] = '\0';
                - NULL = no se leyo nada.
                    No significa solo EOF, puede ser error tambien.
                    Patron correcto:
                    - if (fgets(linea, sizeof(linea), fp) == NULL)
                    - {
                    -   if (feof(fp))
                    -       printf("Fin de archivo\n");
                    -   else
                    -       printf("Error\n");
                    - }
                - Comparacion:
                | Funcion | Nivel(abstraccion)    | Uso                 |
                | ------- | --------------------- | ------------------- |
                | fgetc   | bajo(caracter)        | lectura simple      |
                | fgets   | medio(linea completa) | lectura segura      |
                | fscanf  | alto(formateado)      | lectura con formato |
    
    Escritura con formato:
        - fprintf
        Sintaxis:
        - int fprintf(FILE *fp, const char *formato, ...);

        Que hace?:
            - Escribe texto formateado en un archivo.
            - Devuelve:
                - Cantidad de caracteres escritos.
                - Valor negativo si hay error.
        Ej.:
        - FILE *fp = fopen("datos.txt", "w");
        - if (fp == NULL)
        -   return 1;
        - 
        - int edad = 25;
        - float altura = 1.75;
        -
        - fprintf(fp, "Edad: %d\n", edad);
        - fprintf(fp, "Altura: %.2f\n", altura);
        -
        - fclose(fp);
        Contenido del archivo:
        - Edad: 25
        - Altura: 1.75

        Formatos validos:
        - Los mismos que printf:
            - %d, %f, %s, %c.
            - %lf, para double
            - %u, %ld, etc.
        
    Lectura con formato:
        - fscanf
        Sintaxis:
        - int fscanf(FILE *fp, const char *formato, ...);
        
        Que hace?:
        -Lee datos formateados desde un archivo.
        - Devuelve:
            - Cantidad de elementos leidos correctamente.
            - EOF si no pudo leer nada.
        
        Ej.:
        Archivo person.txt:
        - 25 1.75
        Codigo:
        - FILE *fp = fopen("persona.txt", "r");
        - if (fp == NULL)
        -   return 1;
        -
        - int edad;
        - float altura;
        -
        - fscanf(fp, "%d %f", &edad, &altura);
        -
        - printf("Edad=%d ALtura %.2f\n", edad, altura);
        -
        - fclose(fp);
        Peligros reales de fscanf:
        - No controla limites de strings
            - char nombre[20];
            - fscanf(fp, "%s", nombre); // Peligro si el nombre es largo
            Mejor:
            - fscanf(fp, "%19s", nombre);
        - No detecta bien fin de archivo
            Error tipico:
            - while (!feof(fp))
            - {
            -   fscanf(fp, "%d", &x);
            - }
        
        Patron correcto con fscanf:
        - while (fscanf(fp, "%d", &x) == 1)
        - {
        -   printf("%d\n", x);
        - }
        O con multiples datos:
        - while (fscanf(fp, "%d %f", &a, &b) == 2)
        - {
        -   ...
        - }
        El == cantidad de campos, es clave.

    fscanf vs fgets + sscanf:
    
    | Funcion | Ventaja | Problema        |
    | ------- | ------- | --------------- |
    | fscanf  | directo | fragil          |
    | fgets   | segura  | hay que parsear |

    Por eso en codigo serio se suele hacer:
    - fgets(linea, sizeof(linea), fp);
    - sscanf(linea, "%d %f", &a, &b);
    fgets:
        - Controla cuanto entra.
        - Nunca se pasa del buffer.
        - Sabe exactamente cuando fallo.
    sscanf:
        - Trabaja sobre memoria, no sobre archivo.
        - No avanza el puntero del archivo.
        - Permite validar mejor lo leido.
        Ej.:
            - char linea[100];
            - int a;
            - float b;
            - while (fgets(linea, sizeof(linea), fp))
            - {
            -   if (sscanf(linea, "%d %f", &a, &b) == 2)
            -   {
            -       printf("a=%d b=%.2f\n", a, b);
            -   }
            -   else
            -   {
            -       printf("Linea mal formada\n");
            -   }
            - }
            Esto no se puede hacer limpio con fscanf
    Pero la clasica suele usar fscanf

*/

#include <stdio.h>

int main(void)
{
    /* ---- DECLARACION ---- */
    FILE *fp;

    /* ---- APERTURA Y ESCRITURA DE ARCHIVO fopen fputc ---- */
    fp = fopen("datos.txt", "w");

    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    
     /* ---- ESCRITURA DE CARACTERES fputc ---- */
    fputc('H', fp);
    fputc('o', fp);
    fputc('l', fp);
    fputc('a', fp);
    fputc('\n', fp);

    /* ---- ESCRITURA DE STRING fputs ---- */
    fputs("Linea uno\n", fp);

    /* ---- ESCRITURA DE CON FORMATO fprintf ---- */
    fprintf(fp, "Edad: %d Altura: %.2f\n", 25, 1.75);
    
    fclose(fp); // SIEMPRE cerrar

    /* ---- LECTURA CARACTER A CARACTER ---- */
    fp = fopen("datos.txt", "r");

    if (fp == NULL)
        return 1;
    
    int c;
    printf("Lectura con fgetc:\n");

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    if (feof(fp))
        printf("\n[Fin de archivo detectado]\n");
    else if (ferror(fp))
        printf("\n[Error de lectura]\n");

    fclose(fp); // SIEMPRE cerrar

    /* ---- LECTURA POR LINEAS + PARSEO ---- */
    fp = fopen("datos.txt", "r");

    if (fp == NULL)
        return 1;

    char linea[100];
    int edad;
    float altura;

    printf("\nLectura con fgets + sscanf:\n");

    while(fgets(linea, sizeof(linea), fp) != NULL)
    {
        printf("Linea cruda: %s", linea);

        /* PARSEO SEGURO */
        if (sscanf(linea, "Edad: %d Altura: %f", &edad, &altura) == 2)
        {
            printf("-> Parseado: edad=%d altura=%.2f\n", edad, altura);
        }
    }

    if (feof(fp))
    {
        printf("Fin de archivo\n");
    }
    else if (ferror(fp))
    {
        printf("Error de lectura\n");
    }
    fclose(fp);

    return 0;
}