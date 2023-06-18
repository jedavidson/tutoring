#ifndef LIST_H
#define LIST_H


typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node *List;


List readList(int, char **);
void showList(List);
void freeList(List);


#endif // LIST_H
