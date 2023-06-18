#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int a;
    int b;
} Item;


/** This is the function we wrote in Q7. */
static int itemCmp(Item i1, Item i2) {
    if (i1.a < i2.a) {
        return -1;
    } else if (i1.a == i2.a) {
        if (i1.b < i2.b) {
            return -1;
        } else if (i1.b == i2.b) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}


bool isStableSort(Item *original, Item *sorted, int size) {
    // Q: What's an easy way to check if something is stably sorted?
    // A: Use an existing stable sorting algorithm on the original array,
    //    then compare the output with the sorted array we were given.
    return false;
}


int main(void) {
    Item *original = malloc(6 * sizeof(Item));
    if (original == NULL) {
        exit(EXIT_FAILURE);
    }

    original[0] = (Item) { .a = 2, .b = 1 };
    original[1] = (Item) { .a = 3, .b = 1 };
    original[2] = (Item) { .a = 1, .b = 1 };
    original[3] = (Item) { .a = 4, .b = 1 };
    original[4] = (Item) { .a = 1, .b = 2 };
    original[5] = (Item) { .a = 3, .b = 2 };

    Item *stable = malloc(6 * sizeof(Item));
    if (stable == NULL) {
        exit(EXIT_FAILURE);
    }

    stable[0] = (Item) { .a = 1, .b = 1 };
    stable[1] = (Item) { .a = 1, .b = 2 };
    stable[2] = (Item) { .a = 2, .b = 1 };
    stable[3] = (Item) { .a = 3, .b = 1 };
    stable[4] = (Item) { .a = 3, .b = 2 };
    stable[5] = (Item) { .a = 4, .b = 1 };

    bool result = isStableSort(original, stable, 6);
    printf("%s\n", result ? "Stable" : "Not stable");

    Item *unstable = malloc(6 * sizeof(Item));
    if (unstable == NULL) {
        exit(EXIT_FAILURE);
    }

    // Items with .a = 1, 3 have been reversed in this order
    unstable[0] = (Item) { .a = 1, .b = 2 };
    unstable[1] = (Item) { .a = 1, .b = 1 };
    unstable[2] = (Item) { .a = 2, .b = 1 };
    unstable[3] = (Item) { .a = 3, .b = 2 };
    unstable[4] = (Item) { .a = 3, .b = 1 };
    unstable[5] = (Item) { .a = 4, .b = 1 };

    result = isStableSort(original, unstable, 6);
    printf("%s\n", result ? "Stable" : "Not stable");

    return 0;
}
