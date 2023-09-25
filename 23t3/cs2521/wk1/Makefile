CC=clang
CFLAGS=-Wall -Werror

myprog.o: myprog.c

sum: sum.o List.o
sum.o: sum.c List.h

delete: delete.o List.o
delete.o: delete.c List.h

List.o: List.c List.h

clean:
	rm -f *.o sum delete
