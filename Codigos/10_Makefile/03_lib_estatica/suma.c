#include "suma.h"

/* Variable global definida (inicializada) solo para que se vea en el comando nm la salida D */
int contador = 0;

int suma(int a, int b)
{
    contador++; 
    return a+b;
}