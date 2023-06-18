#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/**
 * Returns the sum of all elements in a linked list.
 */
int listSumWhile(List l) {
    int sum = 0;
    Node *curr = l;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

/**
 * The same function, but using a for loop instead to traverse the list.
 * Generally speaking, while loops are a bit nicer for linked list stuff,
 * as the for loops can quickly get out of hand (i.e. line length).
 */
int listSumFor(List l) {
    int sum = 0;
    for (Node *curr = l; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}


int main(int argc, char **argv) {
    List l = readList(argc, argv);
    printf("List sum (while): %d\n", listSumWhile(l));
    printf("List sum (for): %d\n", listSumFor(l));
    freeList(l);

    return EXIT_SUCCESS;
}
