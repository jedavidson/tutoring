CC=gcc
CFLAGS=-Wall -Werror

reachable: reachable.o Graph.o Set.o
reachable.o: reachable.c Graph.h Set.h

Graph.o: Graph.c Graph.h
Set.o: Set.c Set.h

clean:
	rm -f *.o reachable
