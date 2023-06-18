CC=gcc
CFLAGS=-Wall -Werror

itemCmp: itemCmp.o
itemCmp.o: itemCmp.c

listSelectionSort: listSelectionSort.o List.o
listSelectionSort.o: listSelectionSort.c List.h

List.o: List.c List.h

clean:
	rm -f *.o itemCmp listSelectionSort
