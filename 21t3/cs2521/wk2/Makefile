CC=gcc
CFLAGS=-Wall -Werror

listLength: listLength.o List.o
listLength.o: listLength.c List.h

listIsSorted: listIsSorted.o List.o
listIsSorted.o: listIsSorted.c List.h

listDeleteEvens: listDeleteEvens.o List.o
listDeleteEvens.o: listDeleteEvens.c List.h

fib: fib.o
fib.o: fib.c

List.o: List.c List.h

clean:
	rm -f *.o listLength listIsSorted listDeleteEvens fib
