#include <stdio.h>

#include "BST.h"


#define NOT_HEIGHT_BALANCED -99


int bstIsHeightBalanced(BST bst) {
    // TODO: Give this a try on your own!
}


int main(int argc, char **argv) {
    BST bst = argvToBST(argc, argv);

    int height = bstIsHeightBalanced(bst);
    if (height != NOT_HEIGHT_BALANCED) {
        printf("The tree has height %d\n", height);
    } else {
        printf("The tree is not height balanced\n");
    }

    freeBST(bst);
    return 0;
}
