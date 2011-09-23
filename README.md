qc - A C port of the QuickCheck unit test framework

REQUIREMENTS

 - [BoehmGC](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

EXAMPLE

	$ make
	gcc -o example example.c qc.c qc.h -lgc -Wall
	./example
	+++ OK, passed 100 tests.
	*** Failed!
	1814368998
	*** Failed!
	1979445633
	1873578154
	675318317