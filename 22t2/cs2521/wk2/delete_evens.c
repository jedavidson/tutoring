#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/**
 * Deletes all of the even elements from the list, returning a pointer
 * to what remains of the original list afterwards.
 */
List delete_evens(List l) {
    // Base case: do nothing with the empty list
    if (l == NULL) {
        return NULL;
    }

    // Recursive case 1: if the head of list is even-valued, then just return
    // the rest of the list with all of the even numbers taken out.
    else if (l->data % 2 == 0) {
        List new_rest = delete_evens(l->next);
        free(l);
        return new_rest;
    }

    // Recursive case 2: if the head of list is odd-valued, then the node after
    // the head should be the head of the rest of the list after removing all
    // of the even numbers from it.
    else {
        List new_rest = delete_evens(l->next);
        l->next = new_rest;
        return l;
    }
}


int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("Input list: ");
    show_list(l);

    List l_after = delete_evens(l);
    printf("List without evens: ");
    show_list(l_after);

    free_list(l_after);
    return 0;
}
