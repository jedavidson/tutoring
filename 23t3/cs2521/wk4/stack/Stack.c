#include <assert.h>
#include <stdlib.h>

#include "Stack.h"

typedef struct item {
    int item;
    struct item *next;
} *Item;

static Item new_stack_item(int item) {
    Item i = malloc(sizeof(*i));
    i->item = item;
    i->next = NULL;
    return i;
}

struct stack {
    struct item *top;
    int size;
};

Stack new_stack(void) {
    Stack s = malloc(sizeof(*s));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push_onto_stack(Stack s, int item) {
    Item old_top = s->top;
    s->top = new_stack_item(item);
    s->top->next = old_top;
    s->size++;
}

int pop_from_stack(Stack s) {
    assert(s->size > 0);

    Item top = s->top;
    int top_item = top->item;

    s->top = s->top->next;
    free(top);
    s->size--;

    return top_item;
}

int stack_size(Stack s) {
    return s->size;
}
