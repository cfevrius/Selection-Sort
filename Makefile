CC=gcc
OBJ=bubble_sort

$(OBJ): bubble_sort.c
	$(CC) -o $@ $^

clean:
	rm bubble_sort
