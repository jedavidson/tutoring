#include <stdlib.h>

/** Q2 */

void stackInt(void) {
	int a = 5;
}

void heapInt(void) {
	int *a = malloc(sizeof(int));
	*a = 5;
}

/** Q3 */

struct node {
	int value;
	struct node *next;
};

void allocNode(void) {
    struct node n;
	n.value = 42;
	n.next = NULL;
}

// Q4
void allocArray(void) {
    int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}
}
