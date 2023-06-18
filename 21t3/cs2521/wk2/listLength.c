#include <stdio.h>

#include "List.h"


/**
 * Computes the length of a linked list.
 */
int listLength(List list) {
    int length = 0;
    Node *curr = list;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

/**
 * The same thing, but using recursion!
 */
int listLengthRec(List list) {
    // Base case: the empty list has length 0.
    if (list == NULL) {
        return 0;
    }

    // Recursive case: we have a node followed by the rest of the list.
    // If we can find out the length of the rest, we can say that the
    // length of the list we're currently looking at is just 1 greater.
    List rest = list->next;
    return 1 + listLengthRec(rest);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    printf(
        "The iterative function says the list has length %d\n",
        listLength(list)
    );

    printf(
        "The recursive function says the list has length %d\n",
        listLengthRec(list)
    );

    freeList(list);
    return 0;
}
