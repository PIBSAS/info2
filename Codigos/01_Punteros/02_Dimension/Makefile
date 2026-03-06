CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

PROG = dimension
OBJ = main.o

$(PROG): $(OBJ)
	$(CC) $(OBJ) -o $(PROG)

$(OBJ): main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean
clean:
	del $(OBJ) $(PROG).exe