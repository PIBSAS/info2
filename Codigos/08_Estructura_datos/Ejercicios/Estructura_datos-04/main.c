// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

/* Programa de ejemplo:
 * Sistema basico de facturacion.
 *
 * Se utilizan:
 * - Vectores de estructuras.
 * - Estructuras anidadas.
 * - Paso de estructuras por puntero.
 * - Busqueda secuencial.
 * - Ordenamiento (burbuja y seleccion).
 * - Acumuladores.
 */
#include <stdio.h> // gets() eliminado en C11, reemplazo fgets().
#include <string.h>

/* Estructura que representa un producto */
struct Productos
{
    int Articulo;         // Codigo identificador del producto
    char Descripcion[31]; // Cadena de hasta 30 caracteres + '\0'
    float PrecioUnitario; // Precio del producto
};

/* Estructura que representa un vendedor */
struct Vendedores
{
    int Legajo;                    // Numero interno del empleado
    char Nombre[81], Apellido[81]; // Nombre del vendedor, Cadenas de hasta 80 caracteres + '\0'
    int Numero;                    // Numero identificador para ventas
    float Comision;                // Porcentaje de comision
};

/* Estructura que representa una venta individual */
struct Ventas
{
    int NumeroArticulo, Cantidad; // Codigo del articulo vendido y Cantidad vendida
};

/* Estructura que representa una factura */
struct Facturas
{
    int Numero, CodigoCliente, NumeroVendedor; // Numero de factura, Codigo del cliente, Numero del vendedor
    /* Vector de estructura (estructura anidada on vector interno) */
    struct Ventas venta[10];                   // Hasta 10 articulos por factura
};

/* Estructura que acumula comisiones por vendedor */
struct Comisiones
{
    int Numero;                     // Numero del vendedor
    float Comision, ValorRecaudado; // Porcentaje de comision y Total acumulado de comisiones
};

/* Prototipos de funciones:
 * Todas reciben punteros a estructuras.
 * Cuando se pasa un vector a una funcion,
 * se pasa implicitamente un puntero al primer elemento.
 */
void IngresarProductos(struct Productos *);
void IngresarVendedores(struct Vendedores *);
void Inicializar(struct Productos *, struct Vendedores *, struct Ventas *, struct Comisiones *);
float IngresarVentas(struct Productos *, struct Ventas *, struct Comisiones *, struct Vendedores *);
void OrdenarProductos(struct Ventas *);
void OrdenarVendedores(struct Comisiones *);
void Listados(struct Ventas *, float, struct Comisiones *);
int BuscarArticulo(int, struct Productos *);
int BuscarVendedor(int, struct Vendedores *);

int main(void)
{
    /* Declaracion de vectores de estructuras
     * Memoria reservada automaticamente (stack)
     */
    struct Productos Producto[10];  // Hasta 10 productos
    struct Vendedores Vendedor[50]; // Hasta 50 vendedores
    struct Ventas Venta[10];        // Acumulador por producto
    struct Comisiones Comision[50]; // Acumulador por vendedor

    /* Total general del sistema */
    float TotalFacturado;
    
    /* Carga inicial de datos */
    IngresarProductos(Producto);
    IngresarVendedores(Vendedor);
    
    /* Inicializa acumuladores en cero */
    Inicializar(Producto, Vendedor, Venta, Comision);

    /* Procesa facturas y devuelve total facturado */
    TotalFacturado = IngresarVentas(Producto, Venta, Comision, Vendedor);

    /* Ordenamientos */
    OrdenarProductos(Venta);     // Ordena productos por numero de articulos
    OrdenarVendedores(Comision); // Ordena vendedores por comision recaudada

    /* Listado final */
    Listados(Venta, TotalFacturado, Comision);

    return 0;
}

/* Funcion que carga los datos de los productos */
void IngresarProductos(struct Productos *Prod) // Recibe un puntero al primer elemento del vector de estructuras
{
    /* Variable de control del ciclo*/
    int i;
    
    /* Recorre el vector de productos*/
    for (i = 0; i < 10; i++)
    {
        printf("Articulo ");
        scanf("%d", &Prod[i].Articulo); // Acceso por puntero al elemento i
        
        fflush(stdin); // Limpieza del buffer (no estandar) Reemplazar con:
        //while ((basura = getchar()) != '\n' && basura != EOF);

        printf("Descripcion ");
        gets(Prod[i].Descripcion); // Lectura de cadena (Funcion insegura)
        //fgets(Prod[i].Descripcion, sizeof(Prod[i].Descripcion), stdin);
        printf("Precio Unitario ");
        scanf("%f", &Prod[i].PrecioUnitario); // Lectura del precio
    }
}

/* Carga los datos de los vendedores */
void IngresarVendedores(struct Vendedores *Vend) // Recibe un puntero al primer elemento del vector de estructuras
{
    /* Variable de control del ciclo */
    int i;

    /* Recorre el vector de vendedores */
    for (i = 0; i < 50; i++)
    {
        printf("Legajo ");
        scanf("%d", &Vend[i].Legajo); // Acceso por puntero al elemento i, Carga legajo

        fflush(stdin); // Limpieza del buffer (no estandar) Reemplazar con:
        //int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);
        
        printf("Nombre y Apellido ");
        gets(Vend[i].Nombre); // Lectura de cadena, Carga de Nombre y Apellido
        gets(Vend[i].Apellido);
        /*
        fgets(Vend[i].Nombre, sizeof(Vend[i].Nombre), stdin);
        fgets(Vend[i].Apellido, sizeof(Vend[i].Apellido),stdin);
        */

        printf("Numero ");
        scanf("%d", &Vend[i].Numero); // Numero identificador

        printf("Comision ");
        scanf("%f", &Vend[i].Comision); // Porcentaje de comision
    }
}

/* Inicializa estructuras acumuladoras 
 * Recibe:
 * - Un puntero al primer elemento del vector de estructuras Productos.
 * - Un puntero al primer elemento del vector de estructuras Vendedores.
 * - Un puntero al primer elemento del vector de estructuras Ventas.
 * - Un puntero al primer elemento del vector de estructuras Comisiones.
 */
void Inicializar(struct Productos *Prod, struct Vendedores *Vend, struct Ventas *Vent, struct Comisiones *Com)
{
    int i;

    /* Inicializa ventas por producto */
    for (i = 0; i < 10; i++)
    {
        Vent[i].NumeroArticulo = Prod[i].Articulo; // Copia numero de articulo
        Vent[i].Cantidad = 0; // Inicializacion del acumulador en cero
    }

    /* Inicializa acumulador de comisiones por vendedor */
    for (i = 0; i < 50; i++)
    {
        Com[i].Numero = Vend[i].Numero;     // Copia numero de vendedor
        Com[i].Comision = Vend[i].Comision; // Copia porcentaje de comision
        Com[i].ValorRecaudado = 0;          // Inicializa acumulador de Valor Recaudado en cero
    }
}

/* Procesa facturas hasta ingresar Numero = 0
 * Recibe:
 * - Un puntero al primer elemento del vector de estructuras Productos.
 * - Un puntero al primer elemento del vector de estructuras Ventas (acumulador por productos).
 * - Un puntero al primer elemento del vector de estructuras Comisiones (acumulador por vendedor).
 * - Un puntero al primer elemento del vector de estructuras Vendedores.
 */
float IngresarVentas(struct Productos *Prod, struct Ventas *Vent, struct Comisiones *Com, struct Vendedores *Vend)
{
    struct Facturas Factura; // Variable local del tipo struct Facturas
    float Total = 0;         // Acumulador total
    int i, Art, Ven;

    printf("Numero ");
    scanf("%d", &Factura.Numero); // Primer numero de factura

    while (Factura.Numero) // Mientras Factura.Numero != 0
    {
        printf("Codigo Cliente ");
        scanf("%d", &Factura.CodigoCliente); // Carga codigo de cliente

        printf("Numero Vendedor ");
        scanf("%d", &Factura.NumeroVendedor); // Carga numero de vendedor

        /* Busqueda del vendedor que realizo la venta */
        Ven = BuscarVendedor(Factura.NumeroVendedor, Vend);

        i = 0;

        printf("Numero Articulo ");
        scanf("%d", &Factura.venta[i].NumeroArticulo); // Carga numero de articulo

        /* Se procesan hasta 10 articulos o hasta ingresar <= 0 */
        while ((Factura.venta[i].NumeroArticulo > 0) && (i < 10))
        {
            printf("Cantidad ");
            scanf("%d", &Factura.venta[i].Cantidad); // Carga la cantidad

            Art = BuscarArticulo(Factura.venta[i].NumeroArticulo, Prod); // Busca el articulo

            /* Si el articulo existe */
            if (Art != -1)
            {
                Vent[Art].Cantidad += Factura.venta[i].Cantidad; // Acumula cantidad vendida

                Total += Factura.venta[i].Cantidad * Prod[Art].PrecioUnitario; // Acumula total facturado
            }
            /* Si el vendedor existe */
            if (Ven != -1)
            {
                Com[Ven].ValorRecaudado += Factura.venta[i].Cantidad * Prod[Art].PrecioUnitario * Com[Ven].Comision; // Acumula comision
            }

            i++; // Avanza al siguiente articulo

            printf("Numero Articulo ");
            scanf("%d", &Factura.venta[i].NumeroArticulo); // Carga el nuevo numero de articulo
        }

        printf("Numero ");
        scanf("%d", &Factura.Numero); // Carga el numero de nueva factura
    }
    return Total; // Devuelve el total facturado
}

/* Ordenamiento tipo burbuja por NumeroArticulo */
void OrdenarProductos(struct Ventas *Vent) // Recibe un puntero al primer elemento del vector de estructuras Ventas.
{
    /* Variables de control para los bucles */
    int i, j;
    struct Ventas Venta; // Variable auxiliar para intercambio

    /* Primer bucle:
     * Controla la cantidad de pasadas del algoritmo burbuja.
     * En cada pasada se va 'acomodando' un elemento en su posicion correcta.
     * Recorre desde la primera hasta la ultima posicion del vector.
     */
    for (i = 0; i < 10; i++)
    {
        /* Segundo bucle:
         * Recorre el vector desde el final hacia la posicion i.
         * Compara elementos adyacentes para ordenarlos.
         * Comienza desde el ultimo elemento (indice 9).
         */
        for (j = 9; j >= i; j--)
        {
            /* Compara el numeroArticulo del elemento anterior con el actual.
             * Si el anterior es mayor, estan en orden incorrecto.
             */
            if (Vent[j - 1].NumeroArticulo > Vent[j].NumeroArticulo)
            {
                /* Se realiza el intercambio completo de estructuras */
                Venta = Vent[j - 1];   // Guarda temporalmente el elemento anterior,
                Vent[j - 1] = Vent[j]; // Copia el elemento actual en la posicion anterior.
                Vent[j] = Venta;       // Coloca el elemento guardado en la posicion actual.
            }
        }
    }
}

/* Ordenamiento por seleccion segun ValorRecaudado */
void OrdenarVendedores(struct Comisiones *Com) // Recibe un puntero al primer elemento del vector de estructuras
{
    /* i controla la posicion actual,
     * j recorre el resto,
     * pos guarda la posicion del minimo.
     */
    int i, j, pos;

    /* Variable auxiliar para guardar el menor elemento encontrado */
    struct Comisiones min;

    /* Recorre todo el vector.
     * i indica la posicion donde se colocara el menor elemento restante 
     */
    for (i = 0; i < 50; ++i)
    {
        pos = i;      // Se asume inicialmente que el menor es el actual.
        min = Com[i]; // Se guarda como minimo provisional el elemento actual.

        /* Se busca en el resto del vector un elemento menor.
         * j Recorre desde la posicion siguiente hasta el final.
         */
        for (j = i + 1; j < 50; ++j)
        {
            /* Compara el ValorRecaudado del elemento actual con el minimo provisional.
            */
            if (Com[j].ValorRecaudado < min.ValorRecaudado)
            {
                pos = j;      // Actualiza la posicion del nuevo minimo encontrado
                min = Com[j]; // Actualiza el valor minimo encontrado
            }
            /* Intercambio:
             * Se coloca en la posicion pos el elemento que estaba en i.
             */
            Com[pos] = Com[i];

            /* Se coloca en la posicion i el minimo encontrado */
            Com[i] = min;
        }
    }
}

/* Listado final de resultados 
 * Recibe:
 * - Un puntero al primer elemento del vector de estructuras Ventas.
 * - El total general facturado (float).
 * - Un puntero al primer elemento del vector de esctructuras Comisiones.
 */
void Listados(struct Ventas *Vent, float Tot, struct Comisiones *Com)
{
    /* Variable de control para recorrer los vectores */
    int i;

    /* Titulo del listado de ventas por producto */
    printf("\n\nArticulo\tCantidad");

    /* Recorre el vector de ventas (10 productos) */
    for (i = 0; i < 10; i++)
    {
        /* Imprime el numero de articulo y la cantidad total vendida acumulada */
        printf("\n%d\t%d", Vent[i].NumeroArticulo, Vent[i].Cantidad);
    }

    /* Muestra el total general facturado */
    printf("\n\nTotal Recaudado %f", Tot);

    /* Titulo del listado de comisiones por vendedor */
    printf("\n\nNumero Vendedor\tCantidad de Comision");

    /* Recorre el vector de comisiones por vendedor */
    for (i = 0; i < 50; i++)
    {
        /* Imprime el numero del vendedor y el total de comision acumulada */
        printf("\n%d\t%f", Com[i].Numero, Com[i].ValorRecaudado);
    }
}

/* Busqueda secuencial de articulo */
int BuscarArticulo(int Art, struct Productos *Prod) // Recibe un entero y un puntero al primer elemento del vector de estructuras
{
    /* Comienza buscando desde la primera posicion del vector */
    int i = 0;

    /* Recorre el vector mientras:
     * 1) No se haya llegado al final (i < 10).
     * 2) El articulo actual sea distinto al buscado.
     */
    while((i < 10) && (Prod[i].Articulo != Art))
    {
        i++; // Avanza a la siguiente posicion
    }

    /* Si salio del bucle porque llego al final sin encontrarlo */
    if (i >= 10)
    {
        i = -1; // Se asigna -1 para indicar 'No encontrado'
    }

    /* Devuelve la posicion si lo encontro, o -1 si no existe. */
    return i;
}

/* Busqueda secuencial de vendedor */
int BuscarVendedor(int Num, struct Vendedores *Vend) // Recibe un entero y un puntero al primer elemento del vector de estructuras
{
    /* Comienza desde la primera posicion del vector */
    int i = 0;

    /* Recorre el vector mientras:
     * 1) No se haya llegado al final (i < 50).
     * 2) El numero del vendedor sea distinto al buscado.
     */
    while ((i < 50) && (Vend[i].Numero != Num))
    {
        i++; // Avanza a la siguiente posicion
    }

    if (i >= 50)
    {
        i = -1; // Se asigna -1 para indicar 'No encontrado'

    }

    /* Devuelve la posicion si lo encontro, o -1 si no existe. */
    return i;
}