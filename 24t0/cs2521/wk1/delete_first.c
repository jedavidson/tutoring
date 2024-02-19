#include <stdio.h>
#include <stdlib.h>

#include "List.h"

/** Deletes the first occurrence of a value from a linked list. */
List delete_first(List l, int value) {
    // Base case #1: there's nothing to delete from an empty list
    if (l == NULL) {
        return NULL;
    }

    // Base case #2: the head of the list is the value to delete,
    // and the new head of the list is the node after the head
    else if (l->data == value) {
        List rest = l->next;
        free(l);
        return rest;
    }

    // Recursive case: the node to delete is possibly in the rest
    // of the list past the head, so do any deletion from it and
    // make sure the head points to whatever the head of the rest
    // of the list happens to be afterwards
    l->next = delete_first(l->next, value);
    return l;
}

/** Deletes the first occurrence of a value from a containerised linked list. */
void containerised_delete_first(ConList cl, int value) {
    // Like with the length example, we just defer the actual work to
    // the recursive function we wrote earlier, and update the head pointer
    // after it's done
    cl->head = delete_first(cl->head, value);

    // The main advantage of this linked list representation is that this
    // function doesn't have to return a pointer (note how it returns void!),
    // whereas the helper function/version using the node representation does
    // This is just convenient and less error-prone (e.g. now if we also want
    // to compute a value to return alongside modifying the list, we can
    // without resorting to uglier solutions like "out-parameters"/pointers to
    // values to store the extra return values in, returning structs, ...)
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