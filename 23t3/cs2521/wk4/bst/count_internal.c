#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/**
 * Counts the internal nodes in a binary search tree, i.e. nodes having at
 * least 1 child node.
 *
 * Time complexity: TODO
 * (where n is the number of nodes, h is the height)
 */
int count_internal(BST t) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d internal node(s)\n", count_internal(t));
    free_bst(t);
    return EXIT_SUCCESS;
}
