/**
 * An interface exposing a simple binary search tree type,
 * but only the functions relevant for the week 4 tutorial.
 */

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
BST argv_to_bst(int argc, char **argv);

/** Frees all memory associated with a BST. */
void free_bst(BST t);

#endif // BST_H
