CC=gcc
CFLAGS=-Wall -Werror

length: length.o
length.o: length.c

q1: q1.o List.o
q1.o: q1.c List.h

q2: q2.o List.o
q2.o: q2.c List.h

q3: q3.o List.o
q3.o: q3.c List.h

q4: q4.o
q4.o: q4.c

q6: q6.o
q6.o: q6.c

List.o: List.c List.h

clean:
	rm -f *.o length q1 q2 q3 q4 q6
