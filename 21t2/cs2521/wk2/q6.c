#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static int doBinarySearchRec(int a[], int lo, int hi, int value) {
    int mid = (lo + hi) / 2;

    // Base cases?
    // Recursive cases?
}


int binarySearch(int a[], int n, int value) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == value) {
            return mid;
        } else if (value < a[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int binarySearchRec(int a[], int n, int value) {
    // Here, we delegate computation to a helper function.
    // Why can't we just use binarySearchRec though?
    // A: it doesn't let us specify lo and hi in recursive calls.
    return doBinarySearchRec(a, 0, n - 1, value);
}


int main(int argc, char **argv) {
    assert(argc > 0);

    int n = argc - 1;
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = atoi(argv[i + 1]);
    }

    int target;
    printf("Target: ");
    scanf("%d", &target);

    char *status = (binarySearch(a, n, target) != -1)
        ? "found"
        : "did not find";

    char *statusRec = (binarySearchRec(a, n, target) != -1)
        ? "found"
        : "did not find";

    printf("Iterative %s %d in the array\n", status, target);
    printf("Recursive %s %d in the array\n", statusRec, target);

    free(a);
    return 0;
}