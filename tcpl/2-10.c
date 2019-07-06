/* Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int c;

    if (argc > 1) {
        c = argv[1][0];
        (c > 64 && c < 91) ? printf("%c\n", c + 32) : printf("%c\n", c);
    }
}
