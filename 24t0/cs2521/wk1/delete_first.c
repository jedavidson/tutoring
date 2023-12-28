#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Deletes the first occurrence of a value from a linked list. */
List delete_first(List l, int value) {
    // TODO: Complete this function!
    return NULL;
}

int main(int argc, char **argv) {
    List l = read_list(argc, argv);

    int value;
    printf("Value to delete: ");
    scanf("%d", &value);

    l = delete_first(l, value);
    printf("List after deleting %d is ", value);
    show_list(l);

    free_list(l);
    return EXIT_SUCCESS;
}