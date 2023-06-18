#include <stdio.h>


typedef struct {
    int first;
    int second;
} Item;


static void printCmpResult(int, char *, char *);


/**
 * Compares two Items, on the first field first, and then on the second field.
 * Returns -1 if i1 < i2, 0 if i1 == i2, and 1 if i1 > i2.
 */
static int itemCmp(Item i1, Item i2) {
    // TODO: Implement this function
    return 0;
}


int main(void) {
    Item i1 = { .first = 1, .second = 2 };

    Item i2 = { .first = 0, .second = 2 }; // i1 > i2
    Item i3 = { .first = 1, .second = 1 }; // i1 > i3
    Item i4 = { .first = 1, .second = 2 }; // i1 == i4
    Item i5 = { .first = 2, .second = 2 }; // i1 < i5
    Item i6 = { .first = 1, .second = 3 }; // i1 < i6

    printCmpResult(itemCmp(i1, i2), "i1", "i2");
    printCmpResult(itemCmp(i1, i3), "i1", "i3");
    printCmpResult(itemCmp(i1, i4), "i1", "i4");
    printCmpResult(itemCmp(i1, i5), "i1", "i5");
    printCmpResult(itemCmp(i1, i6), "i1", "i6");

    return 0;
}


static void printCmpResult(int result, char *x, char *y) {
    printf("%s is ", x);
    if (result == -1) {
        printf("less than ");
    } else if (result == 0) {
        printf("equal to ");
    } else if (result == 1) {
        printf("greater than ");
    }
    printf("%s\n", y);
}
