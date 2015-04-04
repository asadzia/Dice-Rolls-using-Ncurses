CC=gcc

CFLAGS=-Wall

DD=-lncurses


OBJ = 3.1.c

make: $(OBJ)
	   $(CC) $(CFLAGS) -o test $(OBJ) $(DD)

clean:
	rm -f test *.o


