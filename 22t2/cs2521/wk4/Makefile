CC=gcc
CFLAGS=-Wall -Werror

num_nodes: num_nodes.o BST.o
num_nodes.o: num_nodes.c BST.h

count_odds: count_odds.o BST.o
count_odds.o: count_odds.c BST.h

height: height.o BST.o
height.o: height.c BST.h

count_internal: count_internal.o BST.o
count_internal.o: count_internal.c BST.h

node_level: node_level.o BST.o
node_level.o: node_level.c BST.h

count_greater: count_greater.o BST.o
count_greater.o: count_greater.c BST.h

is_height_balanced: is_height_balanced.o BST.o
is_height_balanced.o: is_height_balanced.c BST.h

BST.o: BST.c BST.h

clean:
	rm -f *.o num_nodes count_odds height count_internal node_level count_greater is_height_balanced
