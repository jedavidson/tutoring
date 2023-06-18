#include <stdio.h>

#include "List.h"


/**
 * Counts the number of odd elements in a linked list.
 */
int listCountOdds(List list) {
    // Base case: empty list has no odd elements
    if (list == NULL) {
        return 0;
    }

    // Recursive case: if the head of the current list is odd, then it has
    // 1 more odd number than are in the rest of the list, but if the head
    // is odd, the count in the rest of the list is the same as the whole list
    if (list->data % 2 == 1) {
        return 1 + listCountOdds(list->next);
    } else {
        return listCountOdds(list->next);
    }

    // Alternatively:
    // return (list->data % 2) + listCountOdds(list->next);
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    printf(
        "The list has %d odd elements\n",
        listCountOdds(list)
    );

    freeList(list);
    return 0;
}
