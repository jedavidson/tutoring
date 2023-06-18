#include <stdio.h>
#include <stdlib.h>

#include "BST.h"


static BST newBSTNode(int value) {
    BST node = malloc(sizeof(*node));
    if (node == NULL) {
        fprintf(stderr, "Could not create BST node\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->left = node->right = NULL;

    return node;
}

static BST insertIntoBST(BST bst, int value) {
    if (bst == NULL) {
        bst = newBSTNode(value);
    } else if (value < bst->value) {
        bst->left = insertIntoBST(bst->left, value);
    } else if (value > bst->value) {
        bst->right = insertIntoBST(bst->right, value);
    }

    return bst;
}


BST argvToBST(int argc, char **argv) {
    BST bst = NULL;
    for (int i = 1; i < argc; i++) {
        bst = insertIntoBST(bst, atoi(argv[i]));
    }

    return bst;
}

void freeBST(BST bst) {
    if (bst != NULL) {
        freeBST(bst->left);
        freeBST(bst->right);
        free(bst);
    }
}
