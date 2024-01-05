#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/**
 * Counts the odd nodes in a binary search tree.
 *
 * Time complexity: TODO
 * (where n is the number of nodes, h is the height)
 */
int count_odds(BST t) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d odd node(s)\n", count_odds(t));
    free_bst(t);
    return EXIT_SUCCESS;
}
