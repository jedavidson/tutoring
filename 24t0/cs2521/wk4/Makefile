CC=clang
CFLAGS=-Wall -Werror

reachable: reachable.o Digraph.o Set.o
reachable.o: reachable.c Digraph.h Set.h

Digraph.o: Digraph.c Digraph.h
Set.o: Set.c Set.h

clean:
	rm -f *.o reachable
