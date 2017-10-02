#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal;
 * a veritcal orientation is more challenging. */

int main(void)
{
    int c, i, j, nchar;
    int wlen[10];

    nchar = 0;
    for (i = 0; i < 10; i++)
            wlen[i] = 0;

    while ((c = getchar()) != EOF) {
        nchar = 1;
        if (c == ' ' || c == '\n' || c == '\t')
            continue;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\t') {
            ++nchar;
            printf("%d\n", nchar);
        }
        wlen[nchar] += 1;
        for (i = 0; i < 10; ++i) {
            printf("words of length %d: %d\n", i, wlen[i]);
            for (j = 0; j < wlen[i]; ++j)
                printf("|");
            printf("\n");
        }
    }
}
