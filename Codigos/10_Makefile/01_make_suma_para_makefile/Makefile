CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

OBJ = main.o suma.o

programa: $(OBJ)
	$(CC) $(OBJ) -o programa

main.o: main.c suma.h
	$(CC) $(CFLAGS) -c main.c

suma.o: suma.c suma.h
	$(CC) $(CFLAGS) -c suma.c

.PHONY: clean
clean:
	del *.o programa.exe