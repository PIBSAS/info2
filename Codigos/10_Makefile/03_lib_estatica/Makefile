# Una libreria estatica es un archivo .a que contiene uno o mas objetos, como un .zip
# Para crear una libreria estatica, usamos el binario ar (archiver) con las opciones rcs (replace/add, create si no existe, s indice de simbolos):
# ar rcs liboperaciones.a suma.o resta.o
# Llamamos al archiver le pasamos las opciones, el nombre de la libreria con la palabra lib antes del nombre, la extension .a y los objetos que se incluiran en la libreria
# Pero para tener esos objetos, debemos compilar sin linkear usando gcc:
# gcc -std=c11 -Wall -Wextra -c suma.c La cual creara suma.o
# gcc -std=c11 -Wall -Wextra -c resta.c La cual creara resta.o
# Ahora si podemo crear la libreria estatica con archiver.
# Tras tener la libreria estatica, la cual hara nuestro ejecutable de mayor tamaño, e incluira solo lo que nuestro main use de la libreria, haciendolo autonomo.
# Compilaremmos y linkearemos nuestro ejecutable, indicando el path donde se encuentra la libreria con la opcion -LPath donde Path en este caso sera . ya que la libreria se encuentra en el
# mismo directorio que el sourcecode, y la opcion -lNombre nombre de la libreria -l(library) pero pasamos el nombre sin la palabra lib:
# gcc main.c -L. -loperaciones -o programa
# Si main solo usa la funcion suma de la libreria (contiene suma y resta), entonces solo agregara el código de la funcion suma al ejecutable generado
# Ventajas:
# Ejecutable rápido, no hay lookup dinamico, ideal para sistemas embebidos, no depende del sistema, muy simple conceptualmente, el main no se altera, Separación clara entre interfaz (.h) e implementación (.a)
# Desventajas:
# Ejecutable más grande que usando librerias dinamicas, aunque solo incluye los simbolos realmente usados. Si la libreria cambia se recompila todo, codigo duplicado en multiples programas

# Opciones de archiver:
# Listar contenido: ar t libNOMBRE.a
# Extraer archivos: ar x libNOMBRE.a
# Agregar o reemplazar archivos: ar r libNOMBRE.a
# Crear la libreria si no exite: ar c libNOMBRE.a
# Generar indice de simbolos: ar s libNOMBRE.a

# nm es una herramienta que lista los simbolos del ejecutable:
# .o, .a, .exe
# Un simbolo es; una funcion; una variable global; algo que el linker puede resolver.
# Ejecutemos en la terminal y observemos la salida:
# nm suma.o
# nm liboperaciones.a
# nm programa.exe
# Un simbolo puede estar:
# Definido: T, t, D, B
# Indefinido: U lo debe resolver el linker

######################################
# Libreria estatica con Makefile:
######################################

# Declarar variable que indique el compilador y archiver a usar, y sus opciones
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -MMD -MP
LDFLAGS = -L.
LDLIBS = -loperaciones
AR = ar
ARFLAGS = rcs

# Nombre de la libreria estatica
LIB = liboperaciones.a

# Objetos de la libreria
LIB_OBJ = suma.o resta.o

# Objeto principal
OBJ = main.o

# Dependencias automaticas
DEP = $(OBJ:.o=.d) $(LIB_OBJ:.o=.d)

# Target principal
programa: $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o programa

# Crear libreria estatica Target:Dependencias
$(LIB): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJ)
	
# Version avanzada para crear libreria estatica:
# $@ = target (liboperaciones.a)
# $^ = dependencias (suma.o resta.o)
#$(LIB): $(LIB_OBJ)
#	$(AR) $(ARFLAGS) $@ $^

# Regla generica para objetos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Incluir dependencias si existen, evitando primer error con -
-include $(DEP)

# Limpieza
.PHONY: clean
clean:
	del *.o *.d *.a programa.exe