CFLAGS=-c -g -Wall -Werror
CC=gcc

all: asciilogo

asciilogo: main.o turtle.o screen.o
	$(CC) -o asciilogo main.o turtle.o screen.o

clean:
	rm -f *.o asciilogo

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<