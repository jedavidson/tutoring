#ifndef LIST_H
#define LIST_H


typedef struct node {
    int          data;
    struct node *next;
} Node;

typedef Node *List;


List read_list(int, char **);
void show_list(List);
void free_list(List);


#endif // LIST_H
