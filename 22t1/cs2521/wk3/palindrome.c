#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


/**
 * Determines if a string is a palindrome.
 *
 * Time complexity: O(n) + O(n) + O(1) = O(n)
 * (where n is the length of the string)
 */
bool isPalindrome(char *s) {
    // Taking the length of a string in C is an O(n) operation, but in other
    // languages it could be O(1), e.g. Python or Java
    int n = strlen(s);

    // There are n = O(n) iterations of the loop, and the per-iteration cost
    // is O(1), so overall the loop involves O(n) * O(1) = O(n) operations
    for (int i = 0; i < n; i++) {
        // This conditional statement is composed of primitive operations,
        // and so it has complexity O(1)
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }

    // Returning a fixed value is a primitive operation, i.e. O(1)
    return true;
}


int main(int argc, char **argv) {
    assert(argc > 1);

    char *status = isPalindrome(argv[1]) ? "is" : "is not";
    printf("%s %s a palindrome", argv[1], status);

    return EXIT_SUCCESS;
}
