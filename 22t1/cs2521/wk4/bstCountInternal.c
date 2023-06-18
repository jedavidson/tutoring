#include <stdio.h>

#include "BST.h"


/**
 * Counts the number of internal nodes in a tree. An internal node is one with
 * at least 1 child (i.e. not a leaf node).
 *
 * Time complexity: O(n)
 * (where n is the number of nodes)
 */
int bstCountInternal(BST t) {
    // Base cases: the empty tree and a single-node tree have no internal nodes
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    }

    // Recursive case: same logic as in bstNumNodes
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}


int main(int argc, char **argv) {
    BST t = argvToBST(argc, argv);
    printf("There are %d internal nodes in the tree\n", bstCountInternal(t));
    freeBST(t);
    return 0;
}
