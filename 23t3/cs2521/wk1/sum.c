#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Returns the sum of all elements in a linked list. */
int sum(List l) {
    int sum = 0;

    /*
    // In COMP1511, we would use a `while` loop like so:
    Node *curr = l;
    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
    }
    */

    // ... but we can also use `for` loops:
    for (Node *curr = l; curr != NULL; curr = curr->next) {
        sum += curr->data;
    }

    return sum;
}


int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("List sum: %d\n", sum(l));
    free_list(l);
    return EXIT_SUCCESS;
}
