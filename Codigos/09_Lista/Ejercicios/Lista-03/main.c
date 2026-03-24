// gcc -std=c11 -Wall -Wextra -pedantic main.c -o main

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> // Se usa toupper()

/* Definicion de nodo de lista simplemente enlazada */
struct Lis
{
  int Dato; /* Valor almacenado en el nodo */
  struct Lis *Sig; /* Puntero al siguiente nodo */
};

/* Prototipos de funciones */
void Ingresa(struct Lis **);
void Lee(struct Lis **);
void Borra(struct Lis **);
void Busca(struct Lis **);
void Contar(struct Lis **);

int main(void)
{
  int Opcion;

  /* Inicializa la lista vacia */
  struct Lis *Inicio = NULL;

  /* Bucle infinito (menu) */
  for(;;)
  {
    system("cls"); /* Limpia la pantalla en Windows, en Linux "clear" */

    /* Menu de opciones */
    printf("1 - Ingresa datos\n");
    printf("2 - Lee datos\n");
    printf("3 - Borrar datos\n");
    printf("4 - Buscar datos\n");
    printf("5 - Contar nodos\n");
    printf("6 - Salir\n\n");
    printf("Ingrese una opcion ( 1 - 5 ) : ");

    /* Lee opcion como caracter */
    Opcion = getchar();

    /* Limpia buffer no estandar */
    fflush(stdin);

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
      Contar(&Inicio);
      break;
    case '6':
      exit(0); // Finaliza programa
    }
  }
  return 0;
}

/* Inserta un nodo en la lista de forma ordenada */
void Ingresa(struct Lis **Principio)
{
  struct Lis *Actual, *Nuevo, *Anterior;

  /* Reserva memoria para un nuevo nodo */
  if (!(Nuevo = (struct Lis *)malloc(sizeof(struct Lis))))
  {
    printf("\n\nNo hay memoria disponible\n");
    system("pause");
    return;
  }

  /* Carga el dato en el nuevo nodo */
  printf("\n\nIngrese el dato : ");
  scanf("%d", &Nuevo->Dato);
  fflush(stdin);

  /* Caso lista vacia */
  if (!*Principio)
  {
    *Principio = Nuevo;
    Nuevo->Sig = NULL;
    return;
  }

  /* Recorre la lista para ubicar posicion ordenada */
  Anterior = *Principio;
  Actual = *Principio;

  while (Actual && (Actual->Dato < Nuevo->Dato))
  {
    Anterior = Actual;
    Actual = Actual->Sig;
  }

  /* Insertar al final */
  if (!Actual)
  {
    Anterior->Sig = Nuevo;
    Nuevo->Sig = NULL;
    return;
  }

  /* Insertar al inicio */
  if (Anterior == Actual)
  {
    *Principio = Nuevo;
    Nuevo->Sig = Anterior;
    return;
  }

  /* Insertar en el medio */
  Anterior->Sig = Nuevo;
  Nuevo->Sig = Actual;
}

/* Recorre y muestra todos los nodos */
void Lee(struct Lis **Principio)
{
  struct Lis *Actual = *Principio;
  while (Actual)
  {
    printf("\nEl dato es : %d\n", Actual->Dato);
    Actual = Actual->Sig;
  }
  system("pause");
}

/* Busca y elimina un nodo por valor */
void Borra(struct Lis **Principio)
{
  struct Lis *Actual, *Anterior;
  int Valor;
  char Opcion;

  printf("\nIngrese el dato a borrar : ");
  scanf("%d", &Valor);
  fflush(stdin);

  Actual = *Principio;
  Anterior = *Principio;

  /* Busca el nodo */
  while (Actual && (Valor != Actual->Dato))
  {
    Anterior = Actual;
    Actual = Actual->Sig;
  }
  /* Si lo encontro */
  if (Actual)
  {
    printf("\nEl dato es : %d\n\n", Actual->Dato);
    printf("\n\nDesea eliminar este dato (S / N) ");

    Opcion = toupper(getchar());
    fflush(stdin);
    
    if (Opcion == 'S')
    {
      /* Si es el primer nodo */
      if (Anterior == Actual)
      {
        *Principio = Actual->Sig;
        free(Actual);
        return;
      }

      /* Nodo intermedio o final */
      Anterior->Sig = Actual->Sig;
      free(Actual);
      return;
    }
    return;
  }

  printf("\nEl dato no ha sido encontrado\n\n");
  system("pause");
}

/* Busca un nodo y muestra su direccion */
void Busca(struct Lis **Principio)
{
  struct Lis *Actual;
  int Valor;

  printf("\nIngrese el dato a buscar : ");
  scanf("%d", &Valor);
  
  Actual = *Principio;
  
  /* Recorre hasta encontrar */
  while (Actual && (Valor != Actual->Dato))
    Actual = Actual->Sig;
  
  if (Actual)
  {
    printf("\nEl dato es : %d\tSu ubicacion es : %p\n\n", Actual->Dato, Actual); // Castear a (void *)Actual
    
    system("pause");
    return;
  }

  printf("\nEl dato no ha sido encontrado\n\n");
  system("pause");
}

/* Cuenta la cantidad de nodos de la lista */
void Contar(struct Lis **Principio)
{
  int Contador = 0;
  struct Lis *Actual;
  Actual = *Principio;

  /* Recorre toda la lista */
  while (Actual)
  {
    Contador++;
    Actual = Actual->Sig;
  }
  
  printf("\n\nLa cantidad de nodos de la lista es : %d\n\n", Contador);
  system("pause");
}