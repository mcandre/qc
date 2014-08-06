CC=clang
FLAGS=-O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith

BIN=bin/example

all: test

test: $(BIN)
	$(BIN)

$(BIN): example.c example.h qc.c qc.h
	mkdir -p bin/
	$(CC) $(FLAGS) -o $(BIN) example.c qc.c -lgc

cppcheck:
	cppcheck --quiet --enable=all --suppressions $$HOME/suppressions.cfg .

splint:
	find . -type f -name '*.[ch]' -exec splint {} \;

vera++:
	find . -type f -name '*.cpp' -o -name '*.[ch]' -exec vera++ -s {} \;

lint: cppcheck splint vera++

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes ./$(BIN)

clean:
	-rm -rf bin/
