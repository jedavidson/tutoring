#include <stdio.h>
#include <stdlib.h>

#include "List.h"


static Node *new_node(int);


List read_list(int argc, char **argv) {
    List l = NULL;
    Node *curr = NULL;
    for (int i = 1; i < argc; i++) {
        Node *n = new_node(atoi(argv[i]));
        if (l == NULL) {
            l = n;
        } else {
            curr->next = n;
        }
        curr = n;
    }

    return l;
}

void show_list(List l) {
    if (l != NULL) {
        for (Node *curr = l; curr != NULL; curr = curr->next) {
            printf("%d -> ", curr->data);
        }
    }
    printf("X\n");
}

void free_list(List l) {
    Node *curr = l;
    while (curr != NULL) {
        Node *temp = curr->next;
        free(curr);
        curr = temp;
    }
}


ConList read_conlist(int argc, char **argv) {
    ConList cl = malloc(sizeof(*cl));
    if (cl == NULL) {
        fprintf(stderr, "Allocation of conlist failed.\n");
        exit(EXIT_FAILURE);
    }

    cl->head = read_list(argc, argv);
    return cl;
}

void show_conlist(ConList cl) {
    List l = cl->head;
    show_list(l);
}

void free_conlist(ConList cl) {
    free_list(cl->head);
    free(cl);
}


static Node *new_node(int data) {
    Node *n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "Allocation of node failed.\n");
        exit(EXIT_FAILURE);
    }

    n->data = data;
    n->next = NULL;
    return n;
}
