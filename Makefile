CC=gcc
OBJ=bubble_sort

$(OBJ): bubble_sort.c list.o node.o
	$(CC) -o $@ $< list.o node.o

node.o: node.c node.h
	$(CC) -c $<

list.o: list.c list.h
	$(CC) -c $<

clean:
	rm list.o
	rm node.o
	rm bubble_sort
