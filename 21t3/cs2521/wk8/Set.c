#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Set.h"


#define MIN(a, b)   (((a) < (b)) ? (a) : (b))
#define NONEMPTY(s) ((s)->leastElem <= (s)->cap)


struct set {
    bool *contents;
    int   cap;
    int   leastElem;
};


Set newSet(int cap) {
    Set s = malloc(sizeof(*s));
    s->contents = malloc((cap + 1) * sizeof(bool));
    memset(s->contents, false, cap * sizeof(bool));
    s->cap = cap;
    s->leastElem = cap + 1;

    return s;
}

void freeSet(Set s) {
    if (s != NULL) {
        free(s->contents);
        free(s);
    }
}

void addToSet(Set s, int elem) {
    if (s != NULL && 0 <= elem && elem <= s->cap) {
        s->contents[elem] = true;
        s->leastElem = MIN(s->leastElem, elem);
    } else {
        printf("Couldn't add %d to the set\n", elem);
    }
}

bool setContains(Set s, int elem) {
    return (0 <= elem && elem <= s->cap) && s->contents[elem];
}

void showSetContents(Set s) {
    printf("{");

    if (NONEMPTY(s)) {
        printf("%d", s->leastElem);
        for (int elem = 0; elem <= s->cap; elem++) {
            if (elem != s->leastElem && s->contents[elem]) {
                printf(", %d", elem);
            }
        }
    }

    printf("}\n");
}
