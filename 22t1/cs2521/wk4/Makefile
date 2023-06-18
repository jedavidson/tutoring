# Recall: -g adds debugging info to the executable => can use gdb and valgrind
CC=gcc
CFLAGS=-Wall -Werror -g

makeList: makeList.o

strList: strList.o

bstNumNodes: bstNumNodes.o BST.o
bstNumNodes.o: bstNumNodes.c BST.h

bstHeight: bstHeight.o BST.o
bstHeight.o: bstHeight.c BST.h

bstCountInternal: bstCountInternal.o BST.o
bstCountInternal.o: bstCountInternal.c BST.h

BST.o: BST.c BST.h

clean:
	rm -f *.o makeList strList length bstNumNodes bstHeight bstCountInternal
