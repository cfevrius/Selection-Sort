CC=gcc
CFLAGS=-Wall -std=gnu99
OBJ=bubble_sort

$(OBJ): bubble_sort.c list.o node.o
	$(CC) $(CFLAGS) -o $@ $< list.o node.o

node.o: node.c node.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm list.o
	rm node.o
	rm bubble_sort
