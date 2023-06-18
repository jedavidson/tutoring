/**
 * An interface exposing two linked list types and a common node type,
 * as well as a few helper functions to create a list from the command-line
 * arguments, show a list's contents and free memory belonging to a list.
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
	int          data;
	struct node *next;
} Node;

typedef Node *List;


struct conlist {
    Node *head;
};

typedef struct conlist *ConList;


List    read_list(int, char **);
void    show_list(List);
void    free_list(List);

ConList read_conlist(int, char **);
void    show_conlist(ConList);
void    free_conlist(ConList);


#endif // LIST_H
