#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

/**
 * Returns a count of the number of integers in the array which occur
 * an odd number of times.
 */
int num_odd_occurrences(int arr[], int size) {
    // TODO: Complete this function!
    return 0;
}

int main(int argc, char **argv) {
    int *arr = malloc((argc - 1) * sizeof(int));
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    int noo = num_odd_occurrences(arr, argc - 1);
    printf("%d element(s) occur an odd number of times\n", noo);

    free(arr);
    return EXIT_SUCCESS;
}
