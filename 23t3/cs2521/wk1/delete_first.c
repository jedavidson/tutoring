#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Deletes the first occurrence of a value from a linked list. */
void delete_first(ConList cl, int value) {
    // TODO: Complete this function!
}

int main(int argc, char **argv) {
    ConList cl = read_conlist(argc, argv);

    int value;
    printf("Value to delete: ");
    scanf("%d", &value);

    delete_first(cl, value);
    printf("List after deleting %d is ", value);
    show_conlist(cl);

    free_conlist(cl);
    return EXIT_SUCCESS;
}
