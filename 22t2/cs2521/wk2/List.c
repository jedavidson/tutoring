/**
 * Notice how I've implemented some of these functions using recursion
 * and not iteration? Are there any disadvantages to this implementation?
 */


#include <stdio.h>
#include <stdlib.h>

#include "List.h"


static Node *new_node(int);
static List  insert(List, int);


List read_list(int argc, char **argv) {
    List list = NULL;
    for (int i = 1; i < argc; i++) {
        list = insert(list, atoi(argv[i]));
    }
    return list;
}

void show_list(List list) {
    if (list == NULL) {
        printf("X\n");
    } else {
        printf("%d -> ", list->data);
        show_list(list->next);
    }
}

void free_list(List list) {
    if (list != NULL) {
        free_list(list->next);
        free(list);
    }
}


static Node *new_node(int data) {
    Node *node = malloc(sizeof(*node));
    node->data = data;
    node->next = NULL;
    return node;
}

static List insert(List list, int data) {
    if (list == NULL) {
        return new_node(data);
    }
    list->next = insert(list->next, data);
    return list;
}
