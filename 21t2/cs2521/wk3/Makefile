# See if you can identify what the compile commands being used are
# at each step. Also, try to see if you can find what LDLIBS is
# and why we even need it in this case. (hint: look at q2.c)

CC=gcc
CFLAGS=-Wall -Werror
LDLIBS=-lm

q1: q1.o
q2: q2.o
q3: q3.o
q7: q7.o

*.o: *.c

clean:
	rm -f *.o q1 q2 q3 q7 *.xopp~
