#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node *Node;

struct node {
    char *word;
    Node  next;
};


Node createNode(char *word) {
    Node n = malloc(sizeof(struct node));
    assert(n != NULL);

    // Previously: use the same pointer for every node
    // n->word = word;

    // Now: create a copy of the string in memory with its own pointer
    n->word = strdup(word);

    n->next = NULL;
    return n;
}


/**
 * TODO: What is the problem with this code?
 * HINT: How do pointers work again?
 */
int main(void) {
    // Assume words are no longer than 99 characters (100 - 1, for \0)
    char buffer[100];

    // Every call to createNode gets the same pointer to the buffer array,
    // which is overwritten every time a new word is read in
    // So, we have 2 solutions:
    //   (1) Create 3 separate buffers for each word
    //   (2) Make a copy of the string currently in the buffer in createNode
    // The second solution is a better approach
    scanf("%s", buffer);
    Node n1 = createNode(buffer);
    scanf("%s", buffer);
    n1->next = createNode(buffer);
    scanf("%s", buffer);
    n1->next->next = createNode(buffer);

    printf(
        "\"%s\" -> \"%s\" -> \"%s\" -> X\n",
        n1->word, n1->next->word, n1->next->next->word
    );

    // With the second approach though, each word is now a malloc'd string, so
    // once we're done we should also free the memory to avoid memory leaks
    // Forgetting this step would be something picked up by valgrind!
    free(n1->next->next->word);
    free(n1->next->word);
    free(n1->word);

    free(n1->next->next);
    free(n1->next);
    free(n1);
}
