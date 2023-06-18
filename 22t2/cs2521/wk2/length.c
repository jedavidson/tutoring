#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Computes the length of a linked list. */
int length(List list) {
    // Base case: length of the empty list is 0.
    if (list == NULL) {
        return 0;
    }

    // Recursive case: the length of a nonempty list is 1 + length of rest of
    // the list after the head.
    return 1 + length(list->next);
}


int main(int argc, char **argv) {
    List list = read_list(argc, argv);
    printf("Input list: ");
    show_list(list);

    printf("The list has length %d\n", length(list));

    free_list(list);
    return EXIT_SUCCESS;
}
