CC=gcc-4.7

all: test

test: example
	./example

example: example.c qc.c qc.h
	$(CC) -o example example.c qc.c qc.h -I/usr/include/gc -lgc -Wall

lint:
	splint *.c *.h

clean:
	-rm example
