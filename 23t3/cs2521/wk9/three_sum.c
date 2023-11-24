#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

/**
 * Returns true if there are three integers in the array which sum to give
 * target and false otherwise.,
 */
bool three_sum(int *nums, int n, int target) {
    // TODO: Complete this function!
    HashTable ht = hashtable_new();
    bool found = false;
    return found;
}

int main(int argc, char **argv) {
    int n = argc - 1;
    int *nums = malloc(n * sizeof(int));
    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }

    int target;
    printf("Enter a target sum: ");
    while (scanf("%d", &target) > 0) {
        char *result = three_sum(nums, n, target) ? "is" : "isn't";
        printf("There %s a three sum for %d\n", result, target);
        printf("Enter a target sum: ");
    }

    free(nums);
    return EXIT_SUCCESS;
}
