#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Determines if there are two numbers in the array which sum to the target
 * value.
 *
 * Time complexity: O(n^2)
 * (where n is the length)
 */
bool two_sum(int *nums, int length, int target) {
    // Outer loop has n iterations
    for (int i = 0; i < length; i++) {
        // For the ith iteration of the outer loop, we have n - i - 1
        // iterations of the inner loop, and each inner iteration is O(1)
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                return true;
            }
        }
    }

    // So in total, we have
    // (0 + 1 + ... + (n - 2) + (n - 1)) * O(1)
    // = O(n^2) * O(1)

    // (Useful fact: 1 + 2 + ... + n = O(n^2))

    return false;
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
