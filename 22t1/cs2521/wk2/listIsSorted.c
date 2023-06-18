#include <stdio.h>
#include <stdbool.h>

#include "List.h"


/**
 * Determines if a linked list is sorted or not.
 */
bool listIsSorted(List list) {
    // Base case #1: the empty list is sorted
    if (list == NULL) {
        return true;
    }

    // Base case #2: a single element list is sorted
    if (list->next == NULL) {
        return true;
    }

    // Recursive case: the current list is sorted if and only if
    // * the head is less than/equal to the next element
    // * the rest of the list after the head is sorted
    return (list->data <= list->next->data) && listIsSorted(list->next);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    char *status = listIsSorted(list) ? "sorted" : "not sorted";
    printf("The list is %s\n", status);

    freeList(list);
    return 0;
}
