/**
 * A very hacky implementation of a fixed-size set for storing
 * integers in the range from 0 to n (inclusive).
 * An actual set would be implemented differently to this, and
 * more importantly be far less functionally limited. It will
 * do for this question, though, and it also gives us the main
 * advantage we're looking for in a set: no duplicate elements
 * and fast (O(1)) access times.
 */


#ifndef SET_H
#define SET_H


#include <stdbool.h>


typedef struct set *Set;


/** Creates a new set with a given capacity. */
Set newSet(int);

/** Frees all memory associated with a set. */
void freeSet(Set);

/** Adds an element to the set. */
void addToSet(Set, int);

/** Checks whether an element is in the set. */
bool setContains(Set, int);

/** Shows the elements that are in the set. */
void showSetContents(Set);


#endif // SET_H
