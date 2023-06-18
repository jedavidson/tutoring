#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/**
 * Deletes the first occurrence of a value from a linked list.
 */
void listDelete(ConList cl, int value) {
    // If we are deleting a node after the head, we'll need to keep track
    // of the node that came before it to properly re-link it.
    Node *prev = NULL;
    Node *curr = cl->head;
    while (curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }

    // At this point, we know that we're either at the end of the list
    // or we're at the first node that contains the value we're after.
    if (curr != NULL) {
        if (curr == cl->head) {
            cl->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}


int main(int argc, char **argv) {
    ConList cl = readConList(argc, argv);

    int value;
    printf("Value to delete: ");
    scanf("%d", &value);

    listDelete(cl, value);
    printf("List after deleting %d is ", value);
    showConList(cl);

    return EXIT_SUCCESS;
}
