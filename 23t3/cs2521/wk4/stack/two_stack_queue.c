/**
 * A queue implemented using two stacks.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

typedef struct queue {
    Stack s1;
    Stack s2;
} *Queue;

Queue new_queue(void) {
    Queue q = malloc(sizeof(*q));
    q->s1 = new_stack();
    q->s2 = new_stack();
    return q;
}

void free_queue(Queue q) {
    free(q->s1);
    free(q->s2);
    free(q);
}

void enqueue(Queue q, int item) {
    // TODO: Complete this function!
}

int dequeue(Queue q) {
    // TODO: Complete this function!
    return 0;
}

int main(void) {
    Queue q = new_queue();

    for (int i = 1; i <= 5; i++) {
        enqueue(q, i);
    }

    for (int i = 1; i <= 3; i++) {
        assert(dequeue(q) == i);
    }

    enqueue(q, 6);
    for (int i = 4; i <= 6; i++) {
        assert(dequeue(q) == i);
    }

    printf("The queue appears to work properly!\n");

    free_queue(q);
    return EXIT_SUCCESS;
}
