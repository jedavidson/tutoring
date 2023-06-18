#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
 * Prints a permutation of a set of strings specified by the perm array,
 * where perm[i] is the index of the i-th element in the output permutation.
 * For example, if perm[2] = 5, then items[2] should be printed 5th.
 *
 * Time complexity:
 * Space complexity:
 * (where n is the size of both arrays)
 */
void printPermutation(char **items, int *perm, int n) {
    // To decide the i-th word to print, we loop through the perm array
    // and find the index j matching the i-th word in the permutation,
    // i.e. the actual index of that word in the items array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (perm[j] == i) {
                printf("%d. %s\n", i, items[j]);
            }
        }
    }
}

void printPermutationFaster(char **items, int *perm, int n) {
    // TODO: Complete this function
    // HINT: Would using some extra space help?
    return;
}


int main(int argc, char **argv) {
    int n = argc - 1;
    assert(n > 0);

    int *perm = malloc(n * sizeof(int));

    printf("Enter permutation indices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
    }

    printf("The permuted items are\n");
    printPermutation(&argv[1], perm, n);

    return EXIT_SUCCESS;
}
