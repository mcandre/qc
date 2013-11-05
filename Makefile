CC=clang
FLAGS=-O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith

all: test

test: example
	./example

example: example.c qc.c qc.h
	$(CC) $(FLAGS) -o example example.c qc.c -lgc

lint:
	splint *.c *.h

clean:
	-rm *.exe
	-rm example
