CC=gcc
CFLAGS=-Wall -Werror

myprog: myprog.o
myprog.o: myprog.c

sum: sum.o List.o
sum.o: sum.c List.h

delete: delete.o List.o
delete.o: delete.c List.h

List.o: List.c List.h

clean:
	rm -f *.o myprog myFile sum delete
