#include <stdio.h>

#include "BST.h"

/**
 * Counts the number of nodes greater than some value in a binary search tree.
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

    printf("There are %d node(s) with a value greater than %d\n",
           count_greater(t, value), value);

    free_bst(t);
    return 0;
}
