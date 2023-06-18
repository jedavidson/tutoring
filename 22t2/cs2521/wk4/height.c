#include <stdio.h>

#include "BST.h"


// A preprocessor macro to compute the maximum of two numbers. It's used pretty
// much identically to a function, but it isn't actually a function.
// Use and introduce macros like this wisely!
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


/**
 * Finds the height of a binary search tree.
 * Time complexity: O(n)
 * (where n is the number of nodes in the tree)
 */
int height(BST t) {
    // Base case: we define the height of the empty tree to be -1.
    // (This is to distinguish it from single-node trees with height 0.)
    if (t == NULL) {
        return -1;
    }

    // Recursive case: the height of the tree is one more than the height of
    // its taller subtree.
    return 1 + MAX(height(t->left), height(t->right));
}


int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has height %d\n", height(t));
    free_bst(t);
    return 0;
}
