#include <stdio.h>

/* rudimentary calculator */
int main(void)
{
    double sum, atof(char[]);
    char line[BUFSIZ];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, BUFSIZ) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
