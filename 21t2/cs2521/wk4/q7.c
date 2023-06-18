#include <stdio.h>

#include "BST.h"


#define NOT_IN_TREE -1


int bstNodeLevel(BST bst, int value) {
    if (bst == NULL) {
        return NOT_IN_TREE;
    } else if (value == bst->value) {
        // We'll say that any root node is at level 0 of the tree.
        // You could say it's level 1 as well, though - up to you.
        return 0;
    }

    int subtreeLevel;
    if (value < bst->value) {
        subtreeLevel = bstNodeLevel(bst->left, value);
    } else {
        subtreeLevel = bstNodeLevel(bst->right, value);
    }

    if (subtreeLevel == NOT_IN_TREE) {
        return NOT_IN_TREE;
    }

    return 1 + subtreeLevel;
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
