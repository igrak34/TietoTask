CC=gcc
CFLAGS=-I.

DEPS = CStringWrapper.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

wrapper: CStringWrapper.o main.o
	$(CC) -o wrapper CStringWrapper.o main.o