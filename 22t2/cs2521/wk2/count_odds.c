#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Counts the odd numbers in the list. */
int count_odds(List l) {
    // Base case: empty list has no odd numbers:
    if (l == NULL) {
        return 0;

    // Recursive case 1: a nonempty list with odd-valued head has 1 more odd
    // number of odd elements than the rest of list after the head has.
    } else if (l->data % 2 == 1) {
        return 1 + count_odds(l->next);

    // Recursive case 2: a nonempty list with even-valued head has the same
    // number of odd elements than the rest of list after the head has.
    } else {
        return count_odds(l->next);
    }
}


int main(int argc, char **argv) {
    List l = read_list(argc, argv);
    printf("Input list: ");
    show_list(l);

    printf("The list has %d odd element(s)\n", count_odds(l));

    free_list(l);
    return EXIT_SUCCESS;
}
