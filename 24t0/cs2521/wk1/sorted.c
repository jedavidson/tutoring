#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Determines if a linked list is sorted or not. */
bool sorted(List l) {
    // Base case #1: the empty list is sorted
    if (l == NULL) {
        return true;
    }

    // Base case #2: a single-node list is sorted
    else if (l->next == NULL) {
        return true;
    }

    // Base case #3: if the first two nodes are out of order,
    // the list is not sorted
    else if (l->data > l->next->data) {
        return false;
    }

    // Recursive case: the list is sorted if the rest of it past the head is
    // (since if we get to this point, the first two nodes are in order)
    return sorted(l->next);
}

int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("Input list: ");
    show_list(l);

    char *status = sorted(l) ? "sorted" : "not sorted";
    printf("The list is%s\n", status);

    free_list(l);
    return EXIT_SUCCESS;
}
