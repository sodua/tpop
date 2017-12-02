/* Write a program to copy its input to its output, replacing each
 * tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
 * and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == ' ')
            printf("SPACE");
        else if (c == '\n')
            printf("\\n\n");
        else if (c == '\0')
            printf("\\0");
        else
            putchar(c);
    }
}
