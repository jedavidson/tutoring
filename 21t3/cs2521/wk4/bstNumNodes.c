#include <stdio.h>

#include "BST.h"


/**
 * Counts the number of nodes in a binary search tree.
 * Time complexity: O(n), since we visit every node.
 * (where n is the number of nodes)
 */
int bstNumNodes(BST bst) {
    // The empty tree has 0 nodes, of course.
    if (bst == NULL) {
        return 0;
    }

    // For non-empty trees though, the number of nodes is going to be
    // one more than the number in each of its subtrees.
    return 1 + bstNumNodes(bst->left) + bstNumNodes(bst->right);
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    printf("The tree has %d node(s)\n", bstNumNodes(bst));

    freeBST(bst);
    return 0;
}
