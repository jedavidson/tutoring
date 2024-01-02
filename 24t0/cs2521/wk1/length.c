#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Returns the length of a linked list. */
int length(List l) {
    // Base case: an empty list has length 0
    if (l == NULL) {
        return 0;
    }

    // Recursive case: the length of the list is at least 1,
    // plus however long the rest of the list past the head is
    return 1 + length(l->next);
}

/** Returns the length of a containerised linked list. */
int containerised_length(ConList cl) {
    // We just take the head pointer out of the box,
    // and then call the function we previously wrote which
    // can do actual recursion (since it's a Node *)
    return length(cl->head);
}

int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("The list has length %d\n", length(l));
    free_list(l);

    ConList cl = read_conlist(argc, argv);
    printf("The containerised list has length %d\n", containerised_length(cl));
    free_conlist(cl);

    return EXIT_SUCCESS;
}
