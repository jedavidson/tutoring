/**
 * A basic implementation of a LIFO stack of integers.
 */

#ifndef STACK_H
#define STACK_H

typedef struct stack *Stack;

/** Creates a new empty stack. */
Stack new_stack(void);

/** Pushes a new item onto the stack. */
void push_onto_stack(Stack s, int item);

/** Removes the top item of the stack and returns it. */
int pop_from_stack(Stack s);

/** Returns the number of items on the stack. */
int stack_size(Stack s);

#endif // STACK_H
