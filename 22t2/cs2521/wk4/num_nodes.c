#include <stdio.h>

#include "BST.h"


/**
 * Counts the number of nodes in a binary search tree.
 * Time complexity: O(n)
 * (where n is the number of nodes)
 */
int num_nodes(BST t) {
    // Base case: the empty tree has no nodes.
    if (t == NULL) {
        return 0;
    }

    // Recursive case: we simply count how many nodes are in the left and right
    // subtrees and add 1 to account for the root node.
    return 1 + num_nodes(t->left) + num_nodes(t->right);
}


int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has %d node(s)\n", num_nodes(t));
    free_bst(t);
    return 0;
}
