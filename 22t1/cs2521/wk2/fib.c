#include <stdio.h>
#include <stdlib.h>


/**
 * Computes the nth Fibonacci number from the recursive definition, assuming
 * that fib(1) = fib(2) = 1. The algorithm is fine, but what's wrong with the code?
 *
 * A: It repeats calculations unnecessarily, blowing out the execution time.
 */
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

/**
 * This is a faster, iterative version of fib that runs in O(n) time.
 *
 * There is actually an O(log n) algorithm too! It's complicated though, and
 * relies on some maths and techniques covered in COMP3121/3821.
 */
int fibFaster(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    // The variable names are a bit confusing, but we really mean that
    // curr = fib(i), last = fib(i - 1) and lastlast = fib(i - 2)
    int curr, last = 1, lastlast = 1;
    for (int i = 3; i <= n; i++) {
        curr = last + lastlast;

        // Since fib(i + 1) = fib(i) + fib(i - 1), we can just shift the values
        // along to prepare for the next iteration
        lastlast = last;
        last = curr;
    }

    return curr;
}


/**
 * Run using ./main n 0 for the recursive version
 * Run using ./main n 1 for the iterative version
 */
int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int iterative = atoi(argv[2]);

    if (!iterative) {
        printf("fib(%d) = %d\n", n, fib(n));
    } else {
        printf("fibFaster(%d) = %d\n", n, fibFaster(n));
    }

    return 0;
}
