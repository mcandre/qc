qc - A C port of the QuickCheck unit test framework

REQUIREMENTS

 - [BoehmGC](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

EXAMPLE

	$ make
	gcc -o example example.c qc.c qc.h -lgc -Wall
	./example
	Random bool: 1
	Random int: 1958514439
	Random char: q
	Random string: l/@