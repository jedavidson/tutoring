#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/**
 * Counts the number of nodes greater than some value in a binary search tree.
 *
 * Time complexity: O(n), because in the worst case we have to visit each node
 * (where n is the number of nodes, h is the height)
 */
int count_greater(BST t, int value) {
    // Base case: there are no nodes greater in an empty tree
    if (t == NULL) {
        return 0;
    }

    // Recursive case: count the number of nodes greater in the subtrees,
    // and then add 1 to if the current node is also greater
    if (t->data > value) {
        return 1 + count_greater(t->left, value) +
               count_greater(t->right, value);
    } else {
        // Since (node values in t->left) < t->data <= value, we will only find
        // greater values in the right subtree, so we can skip the recursion on
        // the left subtree in this branch to save some work
        return count_greater(t->right, value);
    }
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);

    int value;
    printf("Enter a value: ");
    scanf("%d", &value);

    printf("There are %d node(s) with a value greater than %d\n",
           count_greater(t, value), value);

    free_bst(t);
    return EXIT_SUCCESS;
}
