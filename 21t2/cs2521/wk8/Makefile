CC=gcc
CFLAGS=-Wall -Werror

q2: q2.o Graph.o Set.o
q2.o: q2.c Graph.h Set.h

Graph.o: Graph.c Graph.h
Set.o: Set.c Set.h

clean:
	rm -f *.o q2
