CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

PROG = main
OBJ = main.o fibo.o

$(PROG): $(OBJ)
	$(CC) $(OBJ) -o $(PROG)

main.o: main.c fibo.h
	$(CC) $(CFLAGS) -c main.c

fibo.o: fibo.c fibo.h
	$(CC) $(CFLAGS) -c fibo.c

.PHONY: clean
clean:
	del $(OBJ) $(PROG).exe