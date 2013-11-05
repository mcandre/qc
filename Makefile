CC=gcc-4.7
FLAGS=-O2 -Wall -Wextra

all: test

test: example
	./example

example: example.c qc.c qc.h
	$(CC) $(FLAGS) -o example example.c qc.c qc.h -lgc

lint:
	splint *.c *.h

clean:
	-rm *.exe
	-rm example
