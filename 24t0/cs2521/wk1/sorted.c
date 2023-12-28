#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Determines if a linked list is sorted or not. */
bool sorted(List l) {
    // TODO: Complete this function!
    return true;
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
