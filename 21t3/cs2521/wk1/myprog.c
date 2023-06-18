#include <stdio.h>


/**
 * What are the values of argc and argv for the invocation
 * ./myprog hello there, 'John Shepherd' > myFile
 */
int main(int argc, char **argv) {
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }

    return 0;
}
