#include <stdio.h>

#include "BST.h"

#define NOT_IN_TREE -1

/**
 * Computes the level of a node with a given value in a binary search tree,
 * or `NOT_IN_TREE` if no such node exists.
 *
 * Time complexity: TODO
 * (where n is the number of nodes)
 */
int count_greater(BST t, int value) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);

    int value;
    printf("Enter a value: ");
    scanf("%d", &value);

    printf("The value %d is at level %d in the tree\n", value,
           count_greater(t, value));

    free_bst(t);
    return 0;
}
