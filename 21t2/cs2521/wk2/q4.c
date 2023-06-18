#include <stdio.h>
#include <stdlib.h>


/**
 * What's the complexity of this function?
 * A: O(2^n) -- pretty bad!
 */
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

/**
 * This is a faster version of fib. How about its complexity?
 * A: O(n) -- much better.
 *
 * There is an O(log(n)) algorithm too! It's complicated, though,
 * so you'll have to wait until COMP3121/3821 for more.
 */
int fibFaster(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    // Here, we're using
    // - curr as fib(i)
    // - prev as fib(i - 1)
    // - last as fib(i - 2).
    int curr, prev = 1, last = 1;
    for (int i = 3; i <= n; i++) {
        curr = prev + last;
        last = prev;
        prev = curr;
    }

    return curr;
}


int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    printf("fibFaster(%d) = %d\n", n, fibFaster(n));
    return 0;
}
