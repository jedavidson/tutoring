#include <stdio.h>

#include "BST.h"


/**
 * Counts the number of nodes in a binary search tree.
 *
 * Time complexity: O(n)
 * (where n is the number of nodes)
 */
int bstNumNodes(BST t) {
    // Base case: the empty tree has no nodes
    if (t == NULL) {
        return 0;
    }

    // Recursive case: the number of nodes in the tree is the sum of the
    // number of nodes in its left and right subtree, plus 1 for the root
    return 1 + bstNumNodes(t->left) + bstNumNodes(t->right);
}


int main(int argc, char **argv) {
    BST t = argvToBST(argc, argv);
    printf("The tree has %d node(s)\n", bstNumNodes(t));
    freeBST(t);
    return 0;
}
