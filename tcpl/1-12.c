#include <stdio.h>

/* Write a program that prints its input one word per line. */
int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
            while ((c = getchar()) == ' ' || c == '\n' || c == '\t') {
                continue;
            }
        }
        putchar(c);
    }
}
