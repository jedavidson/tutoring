CC=gcc
CFLAGS=-Wall -Werror

myprog: myprog.o
myprog.o: myprog.c

listSum: listSum.o List.o
listSum.o: listSum.c List.h

listDelete: listDelete.o List.o
listDelete.o: listDelete.c List.h

List.o: List.c List.h

clean:
	rm -f *.o myprog myFile listSum listDelete
