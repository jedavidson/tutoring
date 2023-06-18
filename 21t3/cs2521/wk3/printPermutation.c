#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static void panic(const char *);


/**
 * Prints a permutation of a set of strings specified by the perm array,
 * where perm[i] is the index of the i-th element in the permutation.
 *
 * Time complexity: O(n^2) + O(1) = O(n^2)
 * Space complexity: O(1)
 * (where n is the size of both arrays)
 */
void printPermutation(char **items, int *perm, int n) {
    // Runs O(n) times, O(n) each, so O(n^2) overall
    for (int i = 1; i <= n; i++) {
        // Runs O(n) times, O(1) each run, so O(n) overall
        for (int j = 0; j < n - 1; j++) {
            // O(1)
            if (perm[j] == i) {
                printf("%s ", items[j]);
            }
        }
    }

    // O(1)
    printf("\n");
}

void printPermutationFaster(char **items, int *perm, int n) {
    // TODO: Complete this function!
    // HINT: Would using some extra space help?
    return;
}


int main(int argc, char **argv) {
    int n = argc - 1;
    assert(n > 0);

    int *perm = malloc(n * sizeof(int));
    if (perm == NULL) {
        panic("couldn't allocate memory for permutation array");
    }

    printf("Enter permutation indices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
    }

    printf("The permuted items are ");
    printPermutation(&argv[1], perm, n);

    return EXIT_SUCCESS;
}


static void panic(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}
