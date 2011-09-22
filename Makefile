all: example

example: example.c qc.c qc.h
	gcc -o example example.c qc.c qc.h -lgc
	./example

clean:
	-rm example