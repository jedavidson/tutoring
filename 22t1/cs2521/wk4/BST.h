#ifndef BST_H
#define BST_H


typedef struct BSTNode *BST;

struct BSTNode {
	int value;
	BST left;
	BST right;
};


/**
 * Creates a BST out of command-line arguments, assumed to be the
 * level-order traversal of the desired BST.
 */
BST  argvToBST(int, char **);

/** Frees all memory associated with a BST. */
void freeBST(BST);


#endif // BST_H
