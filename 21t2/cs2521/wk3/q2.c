#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


// Represents the nth degree polynomial a[0] + a[1]z + ... + a[n]z^n.
typedef struct polynomial {
    int *a;
    int  degree;
} Polynomial;


/** Evaluates p(x) for an nth degree polynomial p in O(n) time. */
double evalPolynomial(Polynomial p, double x) {
    // A naive solution would be to use the pow function from math.h
    // to calculate x^i in each step of the loop. Be careful, though!
    // pow(x, i) is not an O(1) operation. We saw in week 2's tute that
    // we could implement our own pow in O(log n) time, so overall
    // our algorithm ends up having complexity O(n log n) -- too slow.

    // In order to avoid this and get a true O(n) algorithm, we will
    // compute x^i incrementally as we go along in the loop.
    // Initially, we set a variable to be x^0 = 1 ...
    double power = 1;

    double result = 0;
    for (int i = 0; i <= p.degree; i++) {
        // ... use it in place of pow(x, i) ...
        result += p.a[i] * power;

        // ... and finally multiply it by x each iteration of the loop
        // so that we end up with x^(i+1) for the next multiplication.
        power *= x;
    }

    return result;
}


int main(int argc, char **argv) {
    assert(argc > 1);

    double x;
    sscanf(argv[1], "%lf", &x);

    // This is the polynomial p(z) = 1 - z + z^2 - z^3.
    int coefficients[4] = { 1, -1, 1, -1 };
    Polynomial p = {
        .a = coefficients,
        .degree = 3
    };

    printf("p(%.2lf) = %.2lf\n", x, evalPolynomial(p, x));

    return EXIT_SUCCESS;
}
