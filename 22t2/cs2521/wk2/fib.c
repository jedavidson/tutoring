#include <stdio.h>
#include <stdlib.h>


/**
 * Computes the nth Fibonacci number, given the initial values F_1 = F_2 = 1.
 * What's wrong with this, though?
 */
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

/**
 * This is a faster version of fib that runs in O(n) time.
 *
 * There is actually an O(log(n)) algorithm too! It's complicated though,
 * so you'll have to wait until you take COMP3121/3821 for more.
 */
int fib_faster(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    // The variable names are a bit confusing, but we really mean
    // curr = F_i, last = F_(i - 1) and lastlast = F_(i - 2).
    int curr, last = 1, lastlast = 1;
    for (int i = 3; i <= n; i++) {
        curr = last + lastlast;
        lastlast = last;
        last = curr;
    }

    return curr;
}


int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    printf("fib_faster(%d) = %d\n", n, fib_faster(n));
    return 0;
}
