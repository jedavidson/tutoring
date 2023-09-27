#include <stdio.h>

#include "BST.h"

// A preprocessor macro to compute the maximum of two numbers. It's used pretty
// much identically to a function, but it isn't actually a function.
// Use and introduce macros like this wisely!
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Finds the height of a binary search tree.
 *
 * Time complexity: TODO
 * (where n is the number of nodes in the tree)
 */
int height(BST t) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    printf("The tree has height %d\n", height(t));
    free_bst(t);
    return 0;
}
