# Asi indicamos el compilador a utilizar
CC = gcc

# Asi indicamos los flags que usaremos en la compilacion
CFLAGS = -std=c11 -Wall -Wextra -pedantic

# Asi indicamos los targets por defecto (los nombres de los ejecutables .exe)
all: standard ejemplo

# Programa 1
standard: standard.c
	$(CC) $(CFLAGS) standard.c -o standard

# Programa 2
ejemplo: ejemplo_porque_usar_c11_y_no_c23.c
	$(CC) $(CFLAGS) ejemplo_porque_usar_c11_y_no_c23.c -o ejemplo

# Asi indicamos que se va a borrar al realizar make clean
clean:
	del standard.exe ejemplo.exe