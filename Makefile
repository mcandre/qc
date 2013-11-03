CC=gcc-4.7

all: test

test: example
	./example

example: example.c qc.c qc.h
	$(CC) -O2 -Wall -Wextra -o example example.c qc.c qc.h -lgc

lint:
	splint *.c *.h

clean:
	-rm *.exe
	-rm example
