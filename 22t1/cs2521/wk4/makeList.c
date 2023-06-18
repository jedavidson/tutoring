#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node *Node;

struct node {
    int value;
    Node next;
};


Node createNode(int value) {
    // valgrind complains about invalid reads of size 4 and 8, coming from
    // memory allocated in this function here
    // Node n = malloc(sizeof(Node));

    // The problem with how this malloc call is written is that it is allocating
    // memory for just a node struct pointer, and not a node struct itself
    // Typically pointers are 8 bytes, and integers are 4 bytes, so the struct
    // above actually needs 12 bytes of memory, but we're only allocating 8
    // So, updating fields of the struct actually causes us to write to memory
    // beyond the 8 bytes we've been allocated, which is potentially very bad

    // Here is how the malloc should've been written instead
    Node n = malloc(sizeof(struct Node)); // or sizeof(*n)

    assert(n != NULL);

    n->value = value;
    n->next = NULL;
    return n;
}


/**
 * TODO: What is the problem with this seemingly-correct piece of code?
 * HINT: What do you see if you use valgrind?
 */
int main(void) {
    Node n1 = createNode(3);
    n1->next = createNode(1);
    n1->next->next = createNode(4);

    printf(
        "%d -> %d -> %d -> X\n",
        n1->value, n1->next->value, n1->next->next->value
    );

    free(n1->next->next);
    free(n1->next);
    free(n1);
}
