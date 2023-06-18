#include <stdio.h>

#include "BST.h"


// This is a preprocessor macro. It works a bit like a function,
// except the contents of the macro are expanded in-place whenever you
// use it (see tute 3). Probably best to use these sparingly like this.
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


int bstHeight(BST bst) {
    if (bst == NULL) {
        return 0;
    } else if (bst->left == NULL && bst->right == NULL) {
        return 0;
    }

    int leftHeight = bstHeight(bst->left);
    int rightHeight = bstHeight(bst->right);
    return 1 + MAX(leftHeight, rightHeight);
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    printf("The tree has height %d\n", bstHeight(bst));

    freeBST(bst);
    return 0;
}
