#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

static BST new_bst_node(int data);
static BST insert(BST t, int data);

BST argv_to_bst(int argc, char **argv) {
    BST t = NULL;
    for (int i = 1; i < argc; i++) {
        t = insert(t, atoi(argv[i]));
    }

    return t;
}

void free_bst(BST t) {
    if (t != NULL) {
        free_bst(t->left);
        free_bst(t->right);
        free(t);
    }
}

static BST new_bst_node(int data) {
    BST n = malloc(sizeof(*n));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

static BST insert(BST t, int data) {
    if (t == NULL) {
        t = new_bst_node(data);
    } else if (data < t->data) {
        t->left = insert(t->left, data);
    } else if (data > t->data) {
        t->right = insert(t->right, data);
    }

    return t;
}
