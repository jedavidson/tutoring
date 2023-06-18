#include <stdio.h>

#include "BST.h"


int bstNumNodes(BST bst) {
    if (bst == NULL) {
        return 0;
    }

    return 1 + bstNumNodes(bst->left) + bstNumNodes(bst->right);
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    printf("The tree has %d node(s)\n", bstNumNodes(bst));

    freeBST(bst);
    return 0;
}
