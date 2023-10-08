#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

/**
 * Returns a count of the number of integers in the array which occur
 * an odd number of times.
 */
int num_odd_occurrences(int arr[], int size) {
    // Idea: use a set to track elements that have been seen an odd
    // number of times so far in the array
    Set odd = new_set();

    for (int i = 0; i < size; i++) {
        // If it's in our set, we've seen it an odd number of times before,
        // and now we've seen it once (i.e. an even number of times so far),
        // so in this case we should evict it from the set
        // Otherwise, we must be seeing this element for the first, third,
        // fifth, etc. time, so we should add it back to the set
        if (set_contains(odd, arr[i])) {
            remove_from_set(odd, arr[i]);
        } else {
            add_to_set(odd, arr[i]);
        }
    }

    // Now we can just count how many elements we have in the set at the end
    int count = set_size(odd);
    free_set(odd);
    return count;
}

/**
 * Returns a count of the number of integers in the array which occur
 * exactly once.
 */
int num_single_occurrences(int arr[], int size) {
    // Idea: like before, we use a set to store the elements we've seen once
    // so far, but we also create another set to hold duplicates
    Set unique = new_set();
    Set duplicated = new_set();

    for (int i = 0; i < size; i++) {
        // When we see an element that already exists in our unique set,
        // we remove it and put it into the duplicate set
        // Otherwise, if it's in neither set, we add it to the unique set
        if (set_contains(unique, arr[i])) {
            remove_from_set(unique, arr[i]);
            add_to_set(duplicated, arr[i]);
        } else if (!set_contains(duplicated, arr[i])) {
            add_to_set(unique, arr[i]);
        }
    }

    // Now we can just count how many elements are left after this process
    int count = set_size(unique);
    free_set(unique);
    free_set(duplicated);
    return count;
}

int main(int argc, char **argv) {
    int *arr = malloc((argc - 1) * sizeof(int));
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    int noo = num_odd_occurrences(arr, argc - 1);
    printf("%d element(s) occur an odd number of times\n", noo);

    int nso = num_single_occurrences(arr, argc - 1);
    printf("%d element(s) occur exactly once\n", nso);

    free(arr);
    return EXIT_SUCCESS;
}
