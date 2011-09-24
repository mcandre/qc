all: example

example: example.c qc.c qc.h
	gcc -o example example.c qc.c qc.h -lgc -Wall

clean:
	-rm example