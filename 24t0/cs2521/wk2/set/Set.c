/**
 * Fair warning to anyone reading the actual implementation of this set: this
 * is not an example to follow! To make the implementation easy, I've made the
 * super limiting assumption that only the numbers {0, 1, ..., 100} are stored.
 * I've also ignored cases where the set may be NULL.
 *
 * The week 3 lectures do things in a more sensible way, but just aren't as
 * efficient as this implementation. The proper data structure for this job is
 * something called a hash table, which will come later in the course.
 */

#include <stdlib.h>

#include "Set.h"

#define MIN_ELEM 0
#define MAX_ELEM 100
#define VALID_ELEM(e) (((0 <= (e)) && ((e) <= MAX_ELEM)))

struct set {
    bool *exists;
    int cardinality;
};

Set new_set(void) {
    Set s = malloc(sizeof(*s));
    s->exists = calloc(MAX_ELEM + 1, sizeof(bool));
    return s;
}

void free_set(Set s) {
    free(s->exists);
    free(s);
}

void add_to_set(Set s, int elem) {
    if (VALID_ELEM(elem)) {
        s->cardinality += !s->exists[elem];
        s->exists[elem] = true;
    }
}

void remove_from_set(Set s, int elem) {
    if (VALID_ELEM(elem)) {
        s->cardinality -= s->exists[elem];
        s->exists[elem] = false;
    }
}

bool set_contains(Set s, int elem) {
    if (!VALID_ELEM(elem)) {
        return false;
    }

    return s->exists[elem];
}

int set_size(Set s) {
    return s->cardinality;
}
