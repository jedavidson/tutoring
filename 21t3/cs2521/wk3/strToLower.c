#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


static char *makeString(int);


/**
 * Time complexity: O(n^2) !!!
 * (where n is the length of the string)
 */
void strToLower(char *s) {
    // Can make it much faster by extracting out the strlen call to a
    // variable before entering the loop so that it's only evaluated once.
    for (int i = 0; i < strlen(s); i++) {
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


static char *makeString(int n) {
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
