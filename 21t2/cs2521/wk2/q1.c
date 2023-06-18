#include <stdio.h>

#include "List.h"


int listLength(List list) {
    // First, let's do this the COMP1511 way.
    int length = 0;
    Node *curr = list;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    return length;
}

int listLengthRec(List list) {
    // Base case: an empty list has length 0.
    if (list == NULL) {
        return 0;
    }

    // Recursive case: the length is 1 + (length of the next sublist).
    return 1 + listLengthRec(list->next);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    printf(
        "Iterative says the list has length %d\n",
        listLength(list)
    );
    printf(
        "Recursive says the list has length %d\n",
        listLengthRec(list)
    );

    freeList(list);
    return 0;
}
