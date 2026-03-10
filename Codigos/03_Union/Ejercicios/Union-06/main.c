// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include <stdio.h>
#include <conio.h> // Se usa getche() puede ser reemplazado por getchar() que pertenece al estandar, clrscr() no existe en GCC/MinGW se reemplaza agregando stdlib.h y usando system("cls")
/* Agregado para reemplazar clrscr() */
#include <stdlib.h> // Se usa system("cls")

/* MAX determina el largo maximo del vector */
#define MAX 100

/* Declaracion de estructuras */
struct coupe
{
    char nro_cil;
    int cilind, veloc_max;
    char marchas;
};

struct sedan
{
    char puertas, color[10], familiar;
};

struct cuotas
{
    int cant;
    float val;
};

/* Declaracion union de estructuras */
union clase
{
    struct coupe dat;
    struct sedan dat1;
};

/* Declaracion union que contiene tipo primitivo y estructura */
union fina
{
    float contado;
    struct cuotas pagos;
};

/* Declaracion de estructura que contiene union */
struct autos
{
    char marca[10];
    int modelo;
    char tipo;
    union clase caract;
    char vendido, cont;
    union fina valor;
};

/* Se declaran los prototipos de las funciones */
int ingreso(struct autos stock[], int);
void listado(struct autos stock[], int);

int main(void)
{
    /* Se declaran las variables a utilizar */
    struct autos stock[MAX];
    int i, j = 0;

    /* Impresion del menu de opciones */
    do
    {
        clrscr(); // No existe en GCC/MinGW, reemplazar por system("cls") de stdlib.h
        //system("cls");

        /* Menu principal */
        printf("\n\n\t\t\tMenu principal");
        printf("\n\n1 - Ingreso de datos");
        printf("\n\n2 - Listado de datos");
        printf("\n\n3 - Salir");
        printf("\n\nIngrese una opcion (1 - 3): ");
        
        /* Leer el valor intriducido */
        scanf("%d", &i);
        
        /* Caso 1: llamar a la funcion ingreso con los argumentos vector de estructura stock y la variable entera j y almacenar lo que devuelve en j 
         * Caso 2: llamar a la funcion listado con los argumentos vector de estructura stock y la variable entera j.
         */
        switch(i)
        {
            case 1:
                j = ingreso(stock, j);
                break;
            
            case 2:
                listado(stock, j);
        }
    }
    while(i != 3); // Mientras la variable sea distinta de 3.

    return 0;
}

/* Funcion para permitir el ingreso de los datos */
int ingreso(struct autos stock[], int j)
{
    /* Declaracion de las variables a utilizar para *
     * realizar el ingreso de los valores de tipo   *
     * "char" con formato numerico y para poder     *
     * ingresar los valores de tipo "float"         */

     int i;
     float f;

     /* Verifica que no se exceda el maximo del vector */
     if (j == MAX)
        return (j);

    /* Comienzo del ingreso de los datos */
    do
    {
        clrscr(); // No existe en GCC/MinGW, reemplazar por system("cls") de stdlib.h
        //system("cls");

        printf("\n\t\t\tINGRESO DE DATOS");
        printf("\n\n\tMarca: ");
        
        fflush(stdin); // Produce comportamiento indefinido, puede ser remplazaodo por las 2 siguientes lineas
        //int basura;
        //while ((basura = getchar()) != '\n' && basura != EOF);

        gets(stock[j].marca); // Eliminado en C11, reemplazar con fgets(), comentar esta linea y descomentar la siguiente
        //fgets(stock[j].marca, sizeof(stock[j].marca), stdin); 
        
        printf("\n\n\tModelo: ");
        scanf("%d", &stock[j].modelo);

        fflush(stdin); // Produce comportamiento indefinido, puede ser remplazaodo por la siguiente linea
        //while ((basura = getchar()) != '\n' && basura != EOF);
        
        printf("\tTipo (C - S): ");

        /* Ingreso de datos selectivo segun el tipo elegido */
        do
        {
            stock[j].tipo = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

            if (stock[j].tipo == 'C' || stock[j].tipo == 'c')
            {
                printf("\n\tNumero de cilindros: ");

                /* Utilizacion de una variable auxiliar para *
                 * ingresar un valor con formato numerico en *
                 * una variable de tipo "char"               */
                scanf("%d", &i); 

                /* Almacenar en struct autos => union clase caract => struct coupe dat => char nro_cil el valor almacenado en la variable entera i */
                stock[j].caract.dat.nro_cil = i;

                printf("\tCilindrada: ");
                scanf("%d", &stock[j].caract.dat.cilind);

                printf("\tVelocidad maxima: ");
                scanf("%d", &stock[j].caract.dat.veloc_max);

                printf("\tCantidad de marchas: ");
                scanf("%d", &i); // Se sobreescribe el valor de la variable entera i

                /* Almacenar en struct autos => union clase caract => struct coupe dat => char marchas el valor almacenado en la variable entera i */
                stock[j].caract.dat.marchas = i;
            }

            if (stock[j].tipo == 'S' || stock[j].tipo == 's')
            {
                printf("\n\tCantidad de puertas: ");
                scanf("%d", &i); // Se sobreescribe el valor de la variable entera i

                /* Almacenar en struct autos => union clase caract => struct sedan dat1 => char puertas el valor almacenado en la variable entera i */
                stock[j].caract.dat1.puertas = i;

                fflush(stdin); // Produce comportamiento indefinido, puede ser remplazaodo por la siguiente linea
                //while ((basura = getchar()) != '\n' && basura != EOF);

                printf("\tColor: ");
                
                gets(stock[j].caract.dat1.color); // Eliminado en C11, reemplazar con fgets(), comentar esta linea y descomentar la siguiente
                //fgets(stock[j].caract.dat1.color, sizeof(stock[j].caract.dat1.color), stdin);

                printf("\tFamiliar (S/N): ");

                stock[j].caract.dat1.familiar = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

                printf("\n");
            }
        
        } /* Mientras que tipo sea uno de los caracartere C, c, S, s el programa seguira */
        while(!(stock[j].tipo != 'C' || stock[j].tipo != 'c' || stock[j].tipo != 'S' || stock[j].tipo != 's')); // Cambiada la logica de !(tipo != caracter || tipo != caracter) a (tipo != caracter && tipo != caracter) para que funcione
        //while(stock[j].tipo != 'C' && stock[j].tipo != 'c' && stock[j].tipo != 'S' && stock[j].tipo != 's');
        
        printf("\tVendido (S/N): ");

        /* Ingreso selectivo de los datos de venta */
        do
        {
            stock[j].vendido = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

            if (stock[j].vendido == 'S' || stock[j].vendido == 's')
            {
                printf("\n\tVenta al contado (S/N): ");
                do
                {
                    stock[j].cont = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

                    if (stock[j].cont == 'S' || stock[j].cont == 's')
                    {
                        printf("\n\tValor: ");

                        /* Utilizacion de una variable auxiliar        *
                         * para permitir el ingreso de una variable    *
                         * de tipo "float" en un vector de estructuras */
                         scanf("%f", &f);

                         /* Almacenar en struct autos => union fina valor => float contado el valor almacenado en la variable float f */
                         stock[j].valor.contado = f;
                    }

                    if (stock[j].cont == 'N' || stock[j].cont == 'n')
                    {
                        printf("\n\tNumero de cuotas: ");
                        scanf("%d", &stock[j].valor.pagos.cant);

                        printf("\tValor de la cuota: ");
                        scanf("%f", &f); // Se sobreescribe el valor de la variable float f

                        /* Almacenar en struct autos => union fina valor => struct cuotas pagos => float val el valor almacenado en la variable float f */
                        stock[j].valor.pagos.val = f;
                    }
                } /* Mientras que cont sea uno de los caracartere S, s, N, n el programa seguira */
                while(!(stock[j].cont != 'S' || stock[j].cont != 's' || stock[j].cont != 'N' || stock[j].cont != 'n')); // Cambiada la logica de !(tipo != caracter || tipo != caracter) a (tipo != caracter && tipo != caracter) para que funcione
                //while(stock[j].cont != 'S' && stock[j].cont != 's' && stock[j].cont != 'N' && stock[j].cont != 'n');
            }
            /* En caso de no haberse producido la venta *
             * Se inicializan las variables a cero      */
            if (stock[j].vendido == 'N' || stock[j].vendido == 'n')
            {
                stock[j].valor.pagos.cant = 0;
                stock[j].valor.pagos.val = 0;
            }
        } /* Mientras que vendido sea uno de los caracartere S, s, N, n el programa seguira */
        while(!(stock[j].vendido != 'S' || stock[j].vendido != 's' || stock[j].vendido != 'N' || stock[j].vendido != 'n')); // Cambiada la logica de !(tipo != caracter || tipo != caracter) a (tipo != caracter && tipo != caracter) para que funcione
        //while(stock[j].vendido != 'S' && stock[j].vendido != 's' && stock[j].vendido != 'N' && stock[j].vendido != 'n');

        printf("\n\tDesea ingresar otro vehiculo (S/N): ");

        i = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER
        j++; // Contador
    }
    /* Se comprueba que no se exceda el largo maximo del vector         *
     * en el caso de que se quieran agregar mas dato que los permitidos */
    while((i == 'S' || i == 's') && j < MAX);

    /* Se retorna el ultimo valor de la posicion maxima de los valores ingresados */

    return (j);
}

/* Funcion que permite la visualizacion de los datos */
void listado(struct autos stock[], int i)
{
    /* Declaracion de las variables a utilizar en la funcion */
    int j, k;

    /* Lazo para poder realizar la visualizacion de los datos *
     * dentro del rango ingresado                             */
     for (j = 0; j < i; j++)
     {
        clrscr(); // No existe en GCC/MinGW, reemplazar por system("cls") de stdlib.h
        //system("cls");

        /* Mostrar marca, modelo y tipo */
        printf("\n\n\tMarca: %s", stock[j].marca);
        printf("\tModelo: %d", stock[j].modelo);
        printf("\tTipo: %c\n", stock[j].tipo);

        /* Listado selectivo segun el tipo */
        if (stock[j].tipo == 'C' || stock[j].tipo == 'c')
        {
            /* Mostrar numero de cilidros, cilindrada, velocidad maxima, cantidad de marchas para tipo Coupe */
            printf("\n\tNumero de cilindros: %d", stock[j].caract.dat.nro_cil);
            printf("\n\tCilindrada: %d", stock[j].caract.dat.cilind);
            printf("\n\tVelocidad máxima : %d",stock[j].caract.dat.veloc_max);
			printf("\n\tCantidad de marchas : %d",stock[j].caract.dat.marchas);
        }

        if(stock[j].tipo=='S'||stock[j].tipo=='s')
        {
            /* Mostrar cantidad de puertas, color, familiar para tipo Sedan */
            printf("\n\tCantidad de puertas : %d",stock[j].caract.dat1.puertas);
			printf("\n\tColor : %s",stock[j].caract.dat1.color);
			printf("\n\tFamiliar : %c",stock[j].caract.dat1.familiar);
        }

        /* Mostrar vendido */
        printf("\n\n\tVendido : %c",stock[j].vendido);

        /* Listado selectivo de los datos de venta */
        if (stock[j].vendido == 'S' || stock[j].vendido == 's')
        {
            if (stock[j].cont == 'S' || stock[j].cont == 's')
            {
                printf("\n\tValor : %.2f", stock[j].valor.contado); // Mostrar valor de contado
            }

            if (stock[j].cont == 'N' || stock[j].cont == 'n')
            {
                printf("\n\tNumero de cuotas : %d", stock[j].valor.pagos.cant); // Mostrar numero de cuotas
				printf("\tValor de la cuota : %.2f", stock[j].valor.pagos.val); // Mostrar valor de cada cuota
            }
        }

        printf("\n\n\t\tDesea listar otro vehículo (S/N) ");
		
        k = getche(); // Puede ser reemplazada con getchar() pero requiere ENTER

        /* Seleccion que permite seguir visualizando o no      *
         * los datos del vector segun la eleccion del operador */
        if (k == 'N' || k == 'n')
        {
            return;
        }
     }

}
