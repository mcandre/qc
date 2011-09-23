qc - A C port of the QuickCheck unit test framework

REQUIREMENTS

 - [BoehmGC](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

EXAMPLE

	$ make
	gcc -o example example.c qc.c qc.h -lgc -Wall
	./example
	+++ OK, passed 100 tests.
	*** Failed!
	506830150
	*** Failed!
	1374187048
	1922575898
	1694164924
	*** Failed!
	'8'
	8