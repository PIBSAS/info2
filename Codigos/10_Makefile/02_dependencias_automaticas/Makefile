# Declaracion de variables, compilador, opciones de compilacion, objetos, dependencias, se agrega -MMD y -MP
# -MMD Genera un archivo .d con las dependencias reales (.c → .h)
# -MP Evita errores si un header se borra
# Cada compilacion genera un archivo .d con las dependencias reales del objeto (.c y .h)
# De esta manera, al agragar nuevos .c o cambiar que archivos forman el programa,
# solo hay que editar OBJ en el Makefile, los .h se detectan automaticamente
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -MMD -MP

OBJ = main.o suma.o resta.o
DEP = $(OBJ:.o=.d) # Lo que hace es .o a .d

# Declaracion del Target programa, indicando los objetos de los que dependen
# Si las dependencias estan cumplidas linkea y genera el ejecutable
programa: $(OBJ)
	$(CC) $(OBJ) -o programa

# Incluir todos los .d si existen, pero no falles si aun no existen, el - evita error la primera vez
-include $(DEP)

# Para cualquier .o, compilado desde su .c correspondiente, $< significa primer prerequisito (%.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Declaracion del target especial .PHONY para borrar objetos, dependencias y ejecutable
.PHONY: clean
clean:
	del *.o *.d programa.exe