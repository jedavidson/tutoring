#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


/**
 * Determines if a string is a palindrome.
 *
 * Time complexity: O(n)
 * (where n is the length of the string)
 */
bool isPalindrome(char *s) {
    // O(1)
    int left = 0;

    // O(n), because strlen(s) is O(n)
    int right = strlen(s) - 1;

    // Observe that the left and right indices cannot be moved
    // forwards/backwards more than n / 2 times before they cross
    // over, which would break the loop condition. Thus, the loop
    // has O(n) iterations with O(1) work per iteration, i.e. O(n).
    while (left < right) {
        // O(1)
        if (s[left] != s[right]) {
            return false;
        }

        // O(1)
        left++;

        // O(1)
        right--;
    }

    // O(1)
    return true;
}


int main(int argc, char **argv) {
    assert(argc > 1);

    char *status = isPalindrome(argv[1]) ? "is" : "is not";
    printf("%s %s a palindrome", argv[1], status);

    return EXIT_SUCCESS;
}
