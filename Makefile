all: example

example: example.c qc.c qc.h
	gcc -o example example.c qc.c qc.h
	./example

clean:
	-rm example