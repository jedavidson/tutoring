#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// A preprocessor macro to compute the maximum of two numbers. It's used pretty
// much identically to a function, but it isn't actually a function.
// Use and introduce macros like this wisely!
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define NOT_HEIGHT_BALANCED -99

/**
 * Determines whether a binary search tree is height balanced or not. A tree is
 * said to be height balanced if the absolute difference in height between the
 * left and right subtrees of every node is at most 1.
 *
 * Time complexity: TODO
 * (where n is the number of nodes)
 */
bool is_height_balanced(BST t) {
    // TODO: Complete this function!
    return true;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);
    char *is_balanced = is_height_balanced(t) ? "is" : "is not";
    printf("The tree %s height balanced\n", is_balanced);
    free_bst(t);
    return 0;
}
