#include <stdio.h>

#include "BST.h"

/**
 * Counts the number of nodes in a binary search tree.
 *
 * Time complexity: TODO
 * (where n is the number of nodes)
 */
int num_nodes(BST t) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d node(s)\n", num_nodes(t));
    free_bst(t);
    return 0;
}
