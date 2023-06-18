/**
 * Try running gcc -E preprocessor.c and see what happens.
 * Don't worry if some of the lines before the main function
 * don't make much sense -- focus instead on what happens inside main
 * after we run this command.
 */


#include <stdio.h>


#define W 2521
#define X W * 2
#define Y W + 2
#define Z X * Y


#define FOO(x) (x == x)


int main(void) {
    int var = W + X + Y + Z;
    if (FOO(var == 123)) {
        ;
    }
    return 0;
}
