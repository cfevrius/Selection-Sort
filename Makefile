CC=gcc
CFLAGS=-Wall -std=gnu99
OBJ=selection_sort

$(OBJ): selection_sort.c list.o node.o
	@echo Linking $@...
	@$(CC) $(CFLAGS) -o $@ $< list.o node.o

node.o: node.c node.h
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c $<

list.o: list.c list.h
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c $<

clean:
	@echo Cleaning...
	@rm list.o
	@rm node.o
	@rm $(OBJ)
