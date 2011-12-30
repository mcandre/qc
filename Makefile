all: example

example: example.c qc.c qc.h
	gcc -o example example.c qc.c qc.h -I/usr/include/gc -lgc -Wall

clean:
	-rm example
