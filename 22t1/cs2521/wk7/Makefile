CC=gcc
CFLAGS=-Wall -Werror

isEulerPath: isEulerPath.o Graph.o
isEulerPath.o: isEulerPath.c Graph.h

Graph.o: Graph.c Graph.h

clean:
	rm -f *.o isEulerPath
