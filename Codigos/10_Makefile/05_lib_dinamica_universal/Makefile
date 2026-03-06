#############################################################################
# Libreria dinamica con Makefile para Windows y linux deteccion automatica:
#############################################################################

# Declarar variable que indique el compilador y sus opciones
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -MMD -MP -fPIC

# Objetos de la libreria
LIB_OBJ = suma.o resta.o

# Objeto principal
OBJ = main.o

# Dependencias automaticas
DEP = $(OBJ:.o=.d) $(LIB_OBJ:.o=.d)

###################################
# Deteccion del sistema operativo
###################################

ifeq ($(OS), Windows_NT)
	# ------ Windows -------
	SHARED_EXT = dll
	LIB_PREFIX =
	IMPLIB = liboperaciones.dll.a
	SHAREDFLAGS = -shared
	IMPLIBFLAGS = -Wl,--out-implib,$(IMPLIB)
	LDFLAGS = -L.
	LDLIBS = -loperaciones
	RM = del
	EXE = .exe
else
	# ----- Linux ---------
	SHARED_EXT = so
	LIB_PREFIX = lib
	IMPLIB = liboperaciones.a
	SHAREDFLAGS = -shared -fPIC
	IMPLIBFLAGS =
	LDFLAGS = -L. -Wl,-rpath,.
	LDLIBS = -loperaciones
	RM = rm -f
	EXE =
endif

# Nombre final de la libreria
SHARED_LIB = $(LIB_PREFIX)operaciones.$(SHARED_EXT)

# Target principal
programa: $(OBJ) $(SHARED_LIB)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o programa$(EXE)

# Crear libreria dinamica. Target:Dependencias
$(SHARED_LIB): $(LIB_OBJ)
	$(CC) $(SHAREDFLAGS) -o $(SHARED_LIB) $(LIB_OBJ) $(IMPLIBFLAGS)
	
# Version avanzada para crear libreria dinamica:
# $@ = target (operaciones.dll)
# $^ = dependencias (suma.o resta.o)
#$(SHARED_LIB): $(LIB_OBJ)
#	$(CC) $(SHAREDFLAGS) -o $@ $^ $(IMPLIBFLAGS)

# Regla generica para objetos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Incluir dependencias si existen, evitando primer error con -
-include $(DEP)

# Limpieza
.PHONY: clean
clean:
	$(RM) *.o *.d *.so *.dll *.a programa$(EXE)
