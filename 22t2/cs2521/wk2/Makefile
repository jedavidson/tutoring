CC=gcc
CFLAGS=-Wall -Werror

length: length.o List.o
length.o: length.c List.h

count_odds: count_odds.o List.o
count_odds.o: count_odds.c List.h

is_sorted: is_sorted.o List.o
is_sorted.o: is_sorted.c List.h

delete: delete.o List.o
delete.o: delete.c List.h

delete_evens: delete_evens.o List.o
delete_evens.o: delete_evens.c List.h

fib: fib.o
fib.o: fib.c

pow: pow.o
pow.o: pow.c

List.o: List.c List.h

clean:
	rm -f *.o length count_odds is_sorted delete delete_evens fib pow
