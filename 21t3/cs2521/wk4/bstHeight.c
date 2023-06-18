#include <stdio.h>

#include "BST.h"


// This is a preprocessor macro. It behaves a bit like a function,
// but is actually closer to a #define'd constant! Handy for functions
// that would otherwise just be evaluating and returning an expression,
// but shouldn't be used for anything more complicated than that.
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


/**
 * Finds the height of a binary search tree.
 * Time complexity: O(n), since we visit every node.
 * (where n is the number of nodes in the tree)
 */
int bstHeight(BST bst) {
    // We adopt the convention where empty trees have height -1,
    // since single-node trees have height 0.
    if (bst == NULL) {
        return -1;
    }

    // The height of the tree is going to be one more than the tallest
    // of its two subtrees.
    return 1 + MAX(bstHeight(bst->left), bstHeight(bst->right));
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    printf("The tree has height %d\n", bstHeight(bst));

    freeBST(bst);
    return 0;
}
