#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// Maximum line size. Each time we read a line in from a file, we assume
// that it will always fit in a buffer/array of this size.
#define MAXLINE 512


/**
 * Merges two sorted files into one bigger sorted file, writing the
 * contents to the file pointed to by mergedfp.
 */
void mergeFiles(FILE *fp1, FILE *fp2, FILE *mergedfp) {
    char buf1[MAXLINE];
    char buf2[MAXLINE];

    fgets(buf1, MAXLINE, fp1);
    fgets(buf2, MAXLINE, fp2);
    while (!feof(fp1) && !feof(fp2)) {
        if (strcmp(buf1, buf2) <= 0) {
            fputs(buf1, mergedfp);
            fgets(buf1, MAXLINE, fp1);
        } else {
            fputs(buf2, mergedfp);
            fgets(buf2, MAXLINE, fp2);
        }
    }

    while (!feof(fp1)) {
        fputs(buf1, mergedfp);
        fgets(buf1, MAXLINE, fp1);
    }

    while (!feof(fp2)) {
        fputs(buf2, mergedfp);
        fgets(buf2, MAXLINE, fp2);
    }
}


int main(int argc, char **argv) {
	assert(argc > 2);

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Invalid input file(s).\n");
		return EXIT_FAILURE;
    }

    FILE *mergedfp = fopen("merged.txt", "w+");
    if (mergedfp == NULL) {
        fprintf(stderr, "Cannot open merged.txt");
        fclose(fp1);
        fclose(fp2);
        return EXIT_FAILURE;
    }

    mergeFiles(fp1, fp2, mergedfp);

    fclose(fp1);
    fclose(fp2);
    fclose(mergedfp);

    return EXIT_SUCCESS;
}
