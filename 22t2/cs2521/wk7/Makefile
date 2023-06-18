CC=gcc
CFLAGS=-Wall -Werror

is_euler_path: is_euler_path.o Graph.o
is_euler_path.o: is_euler_path.c Graph.h

Graph.o: Graph.c Graph.h

clean:
	rm -f *.o is_euler_path
