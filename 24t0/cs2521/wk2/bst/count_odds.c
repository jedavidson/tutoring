#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/**
 * Counts the odd nodes in a binary search tree.
 *
 * Time complexity: O(n), because we have to visit every node
 * (where n is the number of nodes, h is the height)
 */
int count_odds(BST t) {
    // Base case: an empty tree has no odd nodes
    if (t == NULL) {
        return 0;
    }

    // Recursive case: count the number of odd nodes in the subtrees,
    // and then add 1 to that if the current node is odd
    int odds_in_subtrees = count_odds(t->left) + count_odds(t->right);
    if (t->data % 2 == 0) {
        return odds_in_subtrees;
    } else {
        return 1 + odds_in_subtrees;
    }

    // The above recursive case could also be written as
    // return (t->data % 2 != 0) + odds_in_subtrees;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d odd node(s)\n", count_odds(t));
    free_bst(t);
    return EXIT_SUCCESS;
}
