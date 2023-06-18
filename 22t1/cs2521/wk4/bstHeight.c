#include <stdio.h>

#include "BST.h"


// A preprocessor macro to compute the maximum of two numbers
// Use and introduce macros like this wisely!
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


/**
 * Finds the height of a binary search tree.
 *
 * Time complexity: O(n)
 * (where n is the number of nodes in the tree)
 */
int bstHeight(BST t) {
    // Base case: height of the empty tree is notionally -1
    if (t == NULL) {
        return -1;
    }

    // Recursive case: height of the current tree is simply 1 tallest of its
    // left and right subtrees, plus 1 for the edge taken to get to it
    return 1 + MAX(bstHeight(t->left), bstHeight(t->right));
}


int main(int argc, char **argv) {
    BST t = argvToBST(argc, argv);
    printf("The tree has height %d\n", bstHeight(t));
    freeBST(t);
    return 0;
}
