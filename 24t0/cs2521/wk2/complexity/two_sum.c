#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Determines if there are two numbers in the array which sum to the target
 * value.
 *
 * Time complexity:
 * (where n is the length)
 */
bool two_sum(int *nums, int length, int target) {
    // TODO: Complete this function!
    return true;
}

int main(int argc, char **argv) {
    int n = argc - 1;
    int *nums = malloc(n * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Couldn't allocate memory for an array\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }

    int target;
    printf("Enter a target sum: ");
    while (scanf("%d", &target) > 0) {
        char *result = two_sum(nums, n, target) ? "is" : "isn't";
        printf("There %s a two sum for %d\n", result, target);
        printf("Enter a target sum: ");
    }

    free(nums);
    return EXIT_SUCCESS;
}
