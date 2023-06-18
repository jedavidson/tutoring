#include <stdio.h>

#include "BST.h"


#define NOT_IN_TREE -1


/**
 * Computes the level of a node in a binary search tree.
 * Time complexity: O(log n). Why?
 */
int bstNodeLevel(BST bst, int value) {
    int level = 0;

    // If we hit a NULL tree, then we've been unsuccessful in finding
    // the value, so we return -1.
    if (bst == NULL) {
        return NOT_IN_TREE;

    // If the current node we're looking at is the target value, then
    // its level *relative to the current subtree of interest* is 0.
    // This doesn't mean the level overall will be 0, though!
    } else if (bst->value == value) {
        return 0;

    // If the tree isn't empty and the current node we're looking at isn't
    // the target value, then look in the left and right subtree accordingly.
    } else if (bst->value > value) {
        level = bstNodeLevel(bst->left, value);
    } else /* if (bst->value < value) */ {
        level = bstNodeLevel(bst->right, value);
    }

    // There is the possibility that searching in either of these subtrees
    // for the value is unsuccessful, so we need to explicitly check to see
    // if there was no match, as we need to return -1 in that case.
    if (level == NOT_IN_TREE) {
        return NOT_IN_TREE;
    }

    // Assuming the value was found in a subtree though, clearly its level
    // relative to the current tree is 1 more than its level previously.
    // As the recursion starts to unwind itself, the true level relative
    // to the whole tree will slowly build itself up in this way.
    return 1 + level;
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    int value;
    printf("Enter a value: ");
    scanf("%d", &value);

    printf(
        "The value %d is at level %d in the tree\n",
        value, bstNodeLevel(bst, value)
    );

    freeBST(bst);
    return 0;
}
