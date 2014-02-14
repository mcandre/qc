CC=clang
FLAGS=-O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith

BIN=example

all: test

test: $(BIN)
	./$(BIN)

$(BIN): example.c example.h qc.c qc.h
	$(CC) $(FLAGS) -o $(BIN) example.c qc.c -lgc

splint:
	find . -type f -name '*.c' -exec splint {} \;
	find . -type f -name '*.h' -exec splint {} \;

vera++:
	find . -type f -name '*.cpp' -exec vera++ -s {} \;
	find . -type f -name '*.c' -exec vera++ -s {} \;
	find . -type f -name '*.h' -exec vera++ -s {} \;

lint: splint vera++

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes ./$(BIN)

clean:
	-rm *.exe
	-rm $(BIN)
