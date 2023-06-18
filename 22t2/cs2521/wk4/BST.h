#ifndef BST_H
#define BST_H


struct BSTNode {
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};

typedef struct BSTNode *BST;

/**
 * Creates a BST out of command-line arguments, assumed to be the
 * level-order traversal of the desired BST.
 */
BST  argv_to_bst(int, char **);

/** Frees all memory associated with a BST. */
void free_bst(BST);


#endif // BST_H
