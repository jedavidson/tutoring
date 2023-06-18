#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


/**
 * Time complexity: O(n^2) - !!!
 * (where n is the length of the string)
 */
void strToLower(char *s) {
    // The problem here is that we recompute the length of the string each time,
    // so checking the loop condition invovles O(n) operations, which is bad
    // A much better solution would store this value in a variable before the
    // loop so that we only compute it once, giving a final complexity of O(n)
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
}


int main(int argc, char **argv) {
    assert(argc > 1);

    int n = atoi(argv[1]);
    char *s = malloc((n + 1) * sizeof(char));
    for (int i = 0; i <= n; i++) {
        s[i] = (i == n) ? '\0' : 'A';
    }

    printf("Converting string of size %d to lowercase... ", n);
    strToLower(s);
    printf("Done!\n");

    free(s);
    return EXIT_SUCCESS;
}
