#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


/** Makes an uppercase string of A's with length n. */
static char *makeString(int n);


/**
 * Time complexity: O(n^2)
 * (where n is the length of the string)
 *
 * Could we do better?
 * A: Yes! We can make it O(n) by extracting the call to strlen
 *    out to a variable before we enter the loop, and then adjust
 *    the loop condition to check the value of i against it.
 *    In the original code, we had to first evaluate strlen(s) each
 *    time we checked the condition. Since the length of the string
 *    is not changing, this is pointlessly increasing complexity.
 */
void strToLower(char *s) {
    /*
    // Original code
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
    */

    // Optimised code
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        s[i] = tolower(s[i]);
    }
}


int main(int argc, char **argv) {
    assert(argc > 1);

    int n = atoi(argv[1]);
    char *s = makeString(n);

    printf("Converting string of size %d to lowercase...\n", n);
    strToLower(s);
    printf("Done!\n");

    free(s);
    return EXIT_SUCCESS;
}


char *makeString(int n) {
    char *s = malloc((n + 1) * sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "Couldn't allocate memory for string");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= n; i++) {
        s[i] = (i == n) ? '\0' : 'A';
    }

    return s;
}
