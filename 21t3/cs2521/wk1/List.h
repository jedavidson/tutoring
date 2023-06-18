/**
 * An interface exposing two linked list types and a common node type,
 * as well as a few helper functions.
 *
 * List is a plain linked list which is represented as a pointer to the head,
 * which is to say that lists themselves are indistinguishable from nodes.
 *
 * ConList is a containerised linked list structure that contains a pointer
 * to a plain linked list as described previously. In this way, there is an
 * actual difference in the representation of the list and its nodes.
 */


#ifndef LIST_H
#define LIST_H


typedef struct node {
	int          value;
	struct node *next;
} Node;

typedef Node *List;


struct conlist {
    Node *head;
};

typedef struct conlist *ConList;


List    readList(int argc, char **argv);
void    showList(List l);
void    freeList(List l);

ConList readConList(int argc, char **argv);
void    showConList(ConList cl);
void    freeConList(ConList cl);


#endif // LIST_H
