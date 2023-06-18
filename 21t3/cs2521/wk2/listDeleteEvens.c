#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/**
 * Deletes all of the even elements from the list, returning a pointer
 * to what remains of the original list afterwards.
 */
List listDeleteEvens(List list) {
    // Base case: the empty list doesn't contain any evens.
    if (list == NULL) {
        return list;
    }

    // We have access to the rest of the list that comes after the head
    // of the current list we have (i.e. the "list" in the argument).
    List rest = list->next;

    // Recursive case: the head of the list is a node with an even number.
    // This node should be deleted, and then afterwards we can just return
    // what remains of the rest of the list after also removing all of the
    // even numbers from that.
    if (list->data % 2 == 0) {
        free(list);
        return listDeleteEvens(rest);

    // Recursive case: the head of the list is a node with an odd number.
    // We handle this similarly to the previous case, except that we don't
    // delete the current node. What comes after might've changed though!
    } else {
        list->next = listDeleteEvens(list->next);
        return list;
    }
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    List listAfter = listDeleteEvens(list);
    printf("List without evens: ");
    showList(listAfter);

    freeList(list);
    return 0;
}
