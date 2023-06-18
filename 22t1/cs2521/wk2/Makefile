CC=gcc
CFLAGS=-Wall -Werror

listLength: listLength.o List.o
listLength.o: listLength.c List.h

listCountOdds: listCountOdds.o List.o
listCountOdds.o: listCountOdds.c List.h

listIsSorted: listIsSorted.o List.o
listIsSorted.o: listIsSorted.c List.h

fib: fib.o
fib.o: fib.c

List.o: List.c List.h

clean:
	rm -f *.o listLength listCountOdds listIsSorted fib
