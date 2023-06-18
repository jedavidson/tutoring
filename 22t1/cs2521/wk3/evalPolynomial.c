#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


// Represents the nth degree polynomial a[0] + a[1]z + ... + a[n]z^n.
typedef struct polynomial {
    int *a;
    int  degree;
} Polynomial;


/**
 * Evaluates p(x) for an nth degree polynomial p in O(n) time.
 */
double evalPolynomial(Polynomial p, double x) {
    // Field access and variable assignments are O(1)
    int n = p.degree;
    double result = 0;
    double y = 1; // = x^0, initially

    // There are n + 1 = O(n) iterations, but the per-iteration cost is
    //   * O(log(n)), if you use math.h's pow function to compute x^i from
    //     scratch, and assuming it uses the implementation from week 2's tute
    //   * O(1), if you progressively build up x^i as you go
    // So depending on which approach you use, you either get O(n log(n)) or O(n)
    // as the complexity for the entire loop, and thus the algorithm
    for (int i = 0; i <= n; i++) {
        // O(log(n)) solution that recomputes x^i from scratch each time
        // result += p.a[i] * pow(x, i);

        // O(1) solution, assuming that y = x^i at the start of each iteration
        // To maintain this assumption for the next iteration, multiply y by x
        // at the end so that y = x^(i + 1)
        result += p.a[i] * y;
        y *= x;
    }

    // Returning a precomputed value is O(1)
    return result;
}


int main(int argc, char **argv) {
    assert(argc > 1);

    double x;
    sscanf(argv[1], "%lf", &x);

    // For example, this is the polynomial p(z) = 1 - z + z^2 - z^3
    int coefficients[4] = { 1, -1, 1, -1 };
    Polynomial p = {
        .a = coefficients,
        .degree = 3
    };

    printf("p(%.2lf) = %.2lf\n", x, evalPolynomial(p, x));

    return EXIT_SUCCESS;
}
