#include <stdio.h>

#include "List.h"


/**
 * Computes the length of a linked list recursively.
 */
int listLengthRec(List list) {
    // Base case: the empty list has length 0
    if (list == NULL) {
        return 0;
    }

    // Recursive case: the length of a nonempty list is 1 + whatever the
    // length of the rest of the list after the head is
    return 1 + listLengthRec(list->next);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    printf(
        "The recursive function says the list has length %d\n",
        listLengthRec(list)
    );

    freeList(list);
    return 0;
}
