#include <stdio.h>


typedef struct {
    int a;
    int b;
} Item;


static void printCmpResult(int result, char *i1, char *i2);


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


int main(void) {
    Item i1 = { .a = 1, .b = 2 };

    Item i2 = { .a = 0, .b = 2 }; // i1 > i2
    Item i3 = { .a = 1, .b = 1 }; // i1 > i3
    Item i4 = { .a = 1, .b = 2 }; // i1 == i4
    Item i5 = { .a = 2, .b = 2 }; // i1 < i5
    Item i6 = { .a = 1, .b = 3 }; // i1 < i6

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
