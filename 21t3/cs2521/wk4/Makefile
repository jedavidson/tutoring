CC=gcc
CFLAGS=-Wall -Werror

bstNumNodes: bstNumNodes.o BST.o
bstNumNodes.o: bstNumNodes.c BST.h

bstHeight: bstHeight.o BST.o
bstHeight.o: bstHeight.c BST.h

bstNodeLevel: bstNodeLevel.o BST.o
bstNodeLevel.o: bstNodeLevel.c BST.h

BST.o: BST.c BST.h

clean:
	rm -f *.o length bstNumNodes bstHeight bstNodeLevel
