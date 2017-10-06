/* Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal;
 * a veritcal orientation is more challenging. */
#include <stdio.h>

int main(void)
{
    int c, i, j, nchar;
    int wlen[30];

    nchar = 0;
    for (i = 0; i < 30; i++)
            wlen[i] = 0;

    while ((c = getchar()) != EOF) {
        nchar = 1;
        if (c == ' ' || c == '\n' || c == '\t')
            continue;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\t')
            ++nchar;
        wlen[nchar] += 1;
    }
    
    for (i = 1; i < 30; ++i) {
        printf("%2d:", i);
        for (j = 0; j < wlen[i]; ++j)
            printf("|");
        printf("\n");
    }
}
