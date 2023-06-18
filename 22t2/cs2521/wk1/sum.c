#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Returns the sum of all elements in a linked list. */
int sum(List l) {
    int sum = 0;

    // Quick exercise: write this as a for loop.
    Node *head = l;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }

    return sum;
}

int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("List sum: %d\n", sum(l));
    free_list(l);
    return EXIT_SUCCESS;
}
