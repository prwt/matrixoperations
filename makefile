CC=gcc
CFLAGS=-g -Wall -W -Werror -std=gnu99
prgr: matrix.o 
	$(CC) $(CFLAGS) -o matrix.c
     
matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c 
