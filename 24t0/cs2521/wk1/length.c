#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Returns the length of a linked list. */
int length(List l) {
    // TODO: Complete this function!
    return 0;
}

/** Returns the length of a containerised linked list. */
int containerised_length(ConList cl) {
    // TODO: Complete this function!
    return 0;
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
