/* Write a program to print a histogram of the frequencies of
 * different characters in its input.
 * Note: a-z: 97-122, A-Z: 65-90 */

#include <stdio.h>

int main(void)
{
    int c, i, j, nchar;
    int alpha[123];

    nchar = 0;
    for (i = 0; i < 123; i++)
            alpha[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 65 && c <= 90)
            alpha[c] += 1;
        else if (c >= 97 && c <= 122)
            alpha[c] += 1;
        else
            continue;
    }

    for (i = 65; i <= 122; ++i) {
        if (alpha[i] > 0)
            printf("%c: %d\n", i, alpha[i]);
    }
}
