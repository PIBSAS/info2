# Libreria dinamica:
# .ddl (Windows) / .so (Linux)
# Es codigo compilado que NO se copia dentro del ejecutable, el ejecutable queda mas chico y en tiempo de ejcucion(runtime) el sistema operativo carga la .dll o .so, resuelve los simbolos(funciones), el programa llama a ese codigo externo.
# Se usa cuando varios programas usan la misma libreria, queres actualizar la libreria sin recompilar, queres reducir el ejecutable, estas haciendo APIs, frameworks, plugins.
# No es recomendado para sistemas embebidos, no es portable en un unico .exe, no queres depender del entorno
# Compilar objetos sin linkear, se usa la opcion -fPIC (Position Independent Code) En linux es obligatorio (.fPIC) para librerias dinamicas(.so), en Windows con MinGW no:
# gcc -std=c11 -Wall -Wextra -fPIC -c suma.c
# gcc -std=c11 -Wall -Wextra -fPIC -c resta.c
# Una vez creados los objetos, creamos la libreria dinamica .dll en linux .so:
# gcc -shared -o operaciones.dll suma.o resta.o
# Esto genera:
# operaciones.dll: La libreria real
# liboperaciones.dll.a: import library (la usa el linker) En MinGW no se creo esta pero funciono

# Forma explicita que nos asegure la creacion de liboperaciones.dll.a y operaciones.dll es:
# gcc -shared -o operaciones.dll suma.o resta.o "-Wl,--out-implib,liboperaciones.dll.a"
# En Powershell agregamos "" porque sino lo interpreta como un array
# Compilamos y linkeamos como en libreria estatica:
# gcc main.c -L. -loperaciones -o programa
# Comprobamos con nm:
# nm programa.exe | findstr suma
# veremos:
# 00000001400111f8 I __imp_suma (Nos indica que es externa, esto es lo que buscamos ver)
# 0000000140001750 T suma (Simbolo local generado por MinGW (thunk), no es interesante)

######################################
# Libreria dinamica con Makefile:
######################################

# Declarar variable que indique el compilador y archiver a usar, y sus opciones
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -MMD -MP -fPIC
LDFLAGS = -L.
LDLIBS = -loperaciones
SHAREDFLAGS = -shared
IMPLIBFLAGS = -Wl,--out-implib,$(IMPLIB) # En Makefile no hacen falta escapar las comas con las "" como en PowerShell

# Nombre de la libreria dinamica
DLL = operaciones.dll
IMPLIB = liboperaciones.dll.a

# Objetos de la libreria
LIB_OBJ = suma.o resta.o

# Objeto principal
OBJ = main.o

# Dependencias automaticas
DEP = $(OBJ:.o=.d) $(LIB_OBJ:.o=.d)

# Target principal
programa: $(OBJ) $(DLL)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o programa

# Crear libreria dinamica + import library para el linker. Target:Dependencias
$(DLL): $(LIB_OBJ)
	$(CC) $(SHAREDFLAGS) -o $(DLL) $(LIB_OBJ) $(IMPLIBFLAGS)
	
# Version avanzada para crear libreria dinamica:
# $@ = target (operaciones.dll)
# $^ = dependencias (suma.o resta.o)
#$(DLL): $(LIB_OBJ)
#	$(CC) $(SHAREDFLAGS) -o $@ $^ $(IMPLIBFLAGS)

# Regla generica para objetos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Incluir dependencias si existen, evitando primer error con -
-include $(DEP)

# Limpieza
.PHONY: clean
clean:
	del *.o *.d *.dll *.a programa.exe
