#include <stdio.h>
#include <stdlib.h>

#include "List.h"


/** Finds and returns a pointer to the smallest node in the given list. */
static Node *findMinNode(List);

/** Swap the data fields of two nodes. */
static void swapData(Node *, Node *);


/** Sorts a linked list using selection sort. */
void listSelectionSort(List l) {
    for (Node *curr = l; curr->next != NULL; curr = curr->next) {
        // Find the smallest node in the list starting from curr
        Node *min = findMinNode(curr);

        // The smallest node logically belongs where the current node is, so we
        // can just swap their data fields to effectively "swap" the values in
        // the same way as we do for the regular array selection sort
        swapData(min, curr);
    }
}


int main(int argc, char **argv) {
    List l = readList(argc, argv);

    listSelectionSort(l);
    printf("Sorted list: ");
    showList(l);

    return EXIT_SUCCESS;
}


static Node *findMinNode(List l) {
    Node *min = l;
    for (Node *curr = l; curr != NULL; curr = curr->next) {
        if (curr->data < min->data) {
            min = curr;
        }
    }

    return min;
}

static void swapData(Node *n1, Node *n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}
