#include <stdio.h>
#include <stdlib.h>


// We'll assume a max compact vector size of 1000.
// Exercise: modify the code to remove this assumption!
#define MAX_VEC_ELEMS 1000


// Represents an index-value pair.
typedef struct ivpair {
    int    index;
    double value;
} IVPair;

// A compact form vector is then an array of n index-value pairs.
// We additionally assume the pairs sorted by their index.
typedef struct compactvector {
    int     size;
    IVPair *elements;
} *CompactVector;


/** Creates a new compact vector. */
static CompactVector makeVector(void);

/** Reads a vector into compact form from stdin. */
static CompactVector readVector(void);


/**
 * Adds two compact vectors to form a compact vector.
 *
 * Time complexity:
 * (where m is v1->size, and n is v2->size)
 *
 * What would the implications be for our algorithm's complexity
 * if compact vectors weren't necessarily sorted by their index?
 */
CompactVector add(CompactVector v1, CompactVector v2) {
    // TODO: Give this a try on your own!
    // HINT: First consider what the size of the sum vector is,
    //       then think about how you might add the vector elements.
}


int main(void) {
    // After you've finished entering the values for each vector,
    // you'll need to press Ctrl + D to signal the end of input.
    CompactVector v1 = readVector();
    CompactVector v2 = readVector();

    CompactVector v3 = add(v1, v2);

    printf("v1 + v2 = [ ");
    for (int i = 0; i < v3->size - 1; i++) {
        printf(
            "(%d, %.2lf), ",
            v3->elements[i].index, v3->elements[i].value
        );
    }
    printf(
        "(%d, %.2lf) ]\n",
        v3->elements[v3->size - 1].index,
        v3->elements[v3->size - 1].value
    );

    return EXIT_SUCCESS;
}


static CompactVector makeVector(void) {
    CompactVector v = malloc(sizeof(*v));
    if (v == NULL) {
        fprintf(stderr, "Couldn't allocate memory for vector");
        exit(EXIT_FAILURE);
    }

    v->size = 0;

    v->elements = malloc(MAX_VEC_ELEMS * sizeof(IVPair));
    if (v->elements == NULL) {
        fprintf(stderr, "Couldn't allocate memory for vector elements");
        exit(EXIT_FAILURE);
    }

    return v;
}


static CompactVector readVector(void) {
    CompactVector v = makeVector();

    double value = 0;
    int index = 0;

    printf("Enter vector elements: ");
    while (v->size < MAX_VEC_ELEMS && (scanf("%lf", &value) == 1)) {
        if (value != 0) {
            v->elements[v->size] = (IVPair) {
                .index = index,
                .value = value
            };
            v->size++;
        }
        index++;
    }

    return v;
}
