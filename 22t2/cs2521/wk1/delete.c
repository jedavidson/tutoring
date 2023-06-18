#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Deletes the first occurrence of a value from a linked list. */
void delete(ConList cl, int value) {
    Node *prev = NULL;
    Node *curr = cl->head;

    // It's important that we do the NULL check first here!
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    // If we didn't find any occurrences of the value, there is nothing to do.
    if (curr == NULL) {
        return;
    }

    Node *next = curr->next;

    // To delete from the start of the list, we just need to update the head
    // pointer in our container.
    if (prev == NULL /* or curr == cl->head, if you want */) {
        cl->head = next;
    }

    // Otherwise, we're somewhere in the middle of the list or at its end.
    // But either way, we do the same thing: just link the previous node to the
    // next one in the list (which will be NULL if we're at the end).
    else {
        prev->next = next;
    }

    // Remember that we have to free the node itself before we go, though!
    free(curr);
}


int main(int argc, char **argv) {
    ConList cl = read_conlist(argc, argv);

    int value;
    printf("Value to delete: ");
    scanf("%d", &value);

    delete(cl, value);
    printf("List after deleting %d is ", value);
    show_conlist(cl);

    free_conlist(cl);
    return EXIT_SUCCESS;
}
