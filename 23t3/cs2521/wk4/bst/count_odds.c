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
    if (t->data % 2 == 1) {
        return 1 + count_odds(t->left) + count_odds(t->right);
    } else {
        return count_odds(t->left) + count_odds(t->right);
    }

    // The above recursive case could also be written as
    // return (t->data % 2 == 1) + count_odds(t->left) + count_odds(t->right);
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d odd node(s)\n", count_odds(t));
    free_bst(t);
    return EXIT_SUCCESS;
}
