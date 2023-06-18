/**
 * Notice how I've implemented some of these functions
 * using recursion and not iteration?
 */


#include <stdio.h>
#include <stdlib.h>

#include "List.h"


static Node *newNode(int data) {
    Node *node = malloc(sizeof(*node));
    node->data = data;
    node->next = NULL;
    return node;
}

static List insertIntoList(List list, int data) {
    if (list == NULL) {
        return newNode(data);
    }
    list->next = insertIntoList(list->next, data);
    return list;
}


List readList(int argc, char **argv) {
    List list = NULL;
    for (int i = 1; i < argc; i++) {
        list = insertIntoList(list, atoi(argv[i]));
    }
    return list;
}

void showList(List list) {
    if (list == NULL) {
        printf("X\n");
    } else {
        printf("%d -> ", list->data);
        showList(list->next);
    }
}

void freeList(List list) {
    if (list != NULL) {
        freeList(list->next);
        free(list);
    }
}
