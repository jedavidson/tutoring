#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

#define ABSENT_NODE_LEVEL -1

/**
 * Computes the level of a node with a given value in a binary search tree,
 * or `ABSENT_NODE_LEVEL` if no such node exists.
 *
 * Time complexity: O(h), because we're basically just searching for the value
 * and doing a bit of O(1) math on top of that
 * (where n is the number of nodes, h is the height)
 */
int node_level(BST t, int value) {
    // Base case #1: no values exist in an empty tree, so we should return
    // `ABSENT_NODE_LEVEL`
    if (t == NULL) {
        return ABSENT_NODE_LEVEL;
    }

    // Base case #2: if the root of the current subtree is a match, we return
    // 0 by definition
    // Note that this is saying that the node has level 0 *relative to the
    // subtree we're currently looking at*, but not necessarily level 0 in the
    // whole tree, because the true level will be incrementally computed as the
    // following recursive calls start to unwind after we hit the tree's leaves
    if (t->data == value) {
        return 0;
    }

    // Recursive case: depending on which subtree the value should belong to,
    // the level is just one more than its level relative to that subtree
    // Obviously if there is no such node, we should return `ABSENT_NODE_LEVEL`
    if (t->data > value) {
        int level = node_level(t->left, value);
        if (level == ABSENT_NODE_LEVEL) {
            return ABSENT_NODE_LEVEL;
        } else {
            return 1 + level;
        }
    } else {
        int level = node_level(t->right, value);
        if (level == ABSENT_NODE_LEVEL) {
            return ABSENT_NODE_LEVEL;
        } else {
            return 1 + level;
        }
    }
}

int main(int argc, char **argv) {
    BST t = argv_to_bst(argc, argv);

    int value;
    printf("Enter a value: ");
    scanf("%d", &value);

    printf("The value %d is at level %d in the tree\n", value,
           node_level(t, value));

    free_bst(t);
    return EXIT_SUCCESS;
}