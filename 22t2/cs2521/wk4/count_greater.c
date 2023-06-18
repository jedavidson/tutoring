#include <stdio.h>

#include "BST.h"


/**
 * Counts the number of nodes greater than some value in a binary search tree.
 * Time complexity: O(n) worst case, O(height(t)) best case
 * (where n is the number of nodes)
 */
int count_greater(BST t, int value) {
    // Base case: there is nothing bigger than the value in an empty tree.
    if (t == NULL) {
        return 0;
    }

    // Recursive case 1: if the root of the tree is bigger than the value, then
    // certainly the root node plus everything in the right subtree will be
    // bigger than it, but there might be things bigger in the left subtree too.
    // So we count both and add 1 for the root node.
    if (t->data > value) {
        return 1 + count_greater(t->left, value) + count_greater(t->right, value);
    }

    // Recursive case 2: if the root of the tree is smaller/equal to the value,
    // then the only place where bigger values could be is the right subtree, so
    // we should just count how many of those there are.
    else {
        return count_greater(t->right,value);
    }
}


int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);

    int value;
    printf("Enter a value: ");
    scanf("%d", &value);

    printf(
        "There are %d node(s) with a value greater than %d\n",
        count_greater(t, value), value
    );

    free_bst(t);
    return 0;
}
