/**
 * A very hacky implementation of a fixed-size set for storing integer values.
 * An actual set would be implemented differently to this, and more importantly
 * be far less functionally limited. It will do for this question, though, and
 * it also gives us the main advantage we're looking for in a set: no duplicate
 * elements and O(1) access times.
 */

#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set *Set;

/** Constructs a new empty set. */
Set new_set(void);

/** Frees all memory associated with a set. */
void free_set(Set s);

/** Inserts an element into a set. */
void add_to_set(Set s, int elem);

/** Removes an element from the set. */
void remove_from_set(Set s, int elem);

/** Returns true if a set contains a given element, or false otherwise. */
bool set_contains(Set s, int elem);

/** Returns the number of elements in a set. */
int set_size(Set s);

/** Shows a set. */
void show_set(Set s);

#endif // SET_H
