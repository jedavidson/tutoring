#include <stdio.h>

#include "List.h"


int listCountOdds(List list) {
    // First, let's do this the COMP1511 way.
    int odds = 0;
    Node *curr = list;
    while (curr != NULL) {
        if (curr->data % 2 == 1) {
            odds++;
        }
        curr = curr->next;
    }

    return odds;
}

int listCountOddsRec(List list) {
    // Base case: an empty list has no odd elements.
    if (list == NULL) {
        return 0;
    }

    // Recursive case(s):
    // (1) the number of odds in a list with an odd head is
    //     1 + (number of odds in the next sublist).
    // (2) the number of odds in a list with an even head is
    //     just (number of odds in the next sublist).
    if (list->data % 2 == 1) {
        return 1 + listCountOddsRec(list->next);
    } else {
        return listCountOddsRec(list->next);
    }

    // Below is a solution using a ternary expression (see tute 1)
    // so that we can collapse the two recursive cases into one.
    // oddness is 1 when list->data is odd, and is 0 otherwise.

    /*
    int oddness = (list->data % 2 == 1) ? 1 : 0;
    return oddness + listCountOddsRec(list->next);
    */
}


int main(int argc, char **argv) {
    List list = readList(argc, argv);
    printf("Input list: ");
    showList(list);

    printf(
        "Iterative says the list has %d odd elements\n",
        listCountOdds(list)
    );
    printf(
        "Recursive says the list has %d odd elements\n",
        listCountOddsRec(list)
    );

    freeList(list);
    return 0;
}