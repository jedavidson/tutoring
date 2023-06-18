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
 * HINT: In math.h, the function pow(x, y) computes x^y.
 */
double evalPolynomial(Polynomial p, double x) {
    double result = 0;
    int n = p.degree;
    int *coefficients = p.a;

    // Calling pow(x, y) is too expensive - depending on the implementation,
    // it could take up to O(n) time per call. Slowly building up x^n with
    // each loop iteration is much more efficient. Always keep in mind the
    // complexities of any functions your algorithms call!
    int xpower = 1;
    for (int i = 0; i <= n; i++) {
        // Instead of
        // result += coefficients[i] * pow(x, i)

        // ... we prefer this.
        result += coefficients[i] * xpower;
        xpower *= x;
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
