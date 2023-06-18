#include <stdio.h>
#include <stdlib.h>

#include "List.h"


static void  panic(const char *);
static Node *newNode(int);


List readList(int argc, char **argv) {
    List l = NULL;
    Node *curr = NULL;
    for (int i = 1; i < argc; i++) {
        Node *n = newNode(atoi(argv[i]));
        if (l == NULL) {
            l = n;
        } else {
            curr->next = n;
        }

        curr = n;
    }

    return l;
}

void showList(List l) {
    if (l != NULL) {
        for (Node *curr = l; curr != NULL; curr = curr->next) {
            printf("%d -> ", curr->value);
        }
    }

    printf("X\n");
}

void freeList(List l) {
    Node *curr = l;
    while (curr != NULL) {
        Node *temp = curr->next;
        free(curr);
        curr = temp;
    }
}


ConList readConList(int argc, char **argv) {
    ConList cl = malloc(sizeof(*cl));
    if (cl == NULL) {
        panic("couldn't allocate memory for ConList");
    }

    cl->head = readList(argc, argv);
    return cl;
}

void showConList(ConList cl) {
    List l = cl->head;
    showList(l);
}

void freeConList(ConList cl) {
    freeList(cl->head);
    free(cl);
}


static void panic(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

static Node *newNode(int value) {
    Node *n = malloc(sizeof(*n));
    if (n == NULL) {
        panic("couldn't allocate memory for Node");
    }

    n->value = value;
    n->next = NULL;
    return n;
}
