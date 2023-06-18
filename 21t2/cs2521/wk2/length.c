#include <stdio.h>


int stringLength(char *s) {
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int stringLengthRec(char *s) {
    if (*s == '\0') {
        return 0;
    } else {
        // The "s + 1" bit gives us the rest of the string minus the
        // first character using some pointer arithmetic.
        // It's equivalent to &s[1], if you'd prefer that way.
        return 1 + stringLengthRec(s + 1);
    }
}


int main(int argc, char **argv) {
    printf(
        "Iterative says \"%s\" has length %d\n",
        argv[1], stringLength(argv[1])
    );
    printf(
        "Recursive says \"%s\" has length %d\n",
        argv[1], stringLengthRec(argv[1])
    );

    return 0;
}
