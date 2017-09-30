#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* count lines, words, and characters in input */
int main(void)
{
    int c, state;

    while ((c = getchar()) != EOF) {
        state = IN;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        putchar(c);
    }
}
