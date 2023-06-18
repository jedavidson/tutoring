#include <stdio.h>
#include <stdbool.h>

#include "List.h"


bool listIsSortedRec(List list) {
    // Let's try coming up with only the recursive solution.

    // Base cases:
    // (1) an empty list is sorted.
    // (2) a single-element list is sorted.
    // (3) if the head of a list is bigger than the next node,
    //	   then the list is not sorted.
    if (list == NULL) {
        return true;
    } else if (list->next == NULL) {
        return true;
    } else if (list->data > list->next->data) {
        return false;
    }

    // Recursive case: the list is sorted if the next sublist is.
    return listIsSortedRec(list->next);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    char *status = listIsSortedRec(list)
        ? "sorted"
        : "not sorted";
    printf("The list is %s\n", status);

    freeList(list);
    return 0;
}