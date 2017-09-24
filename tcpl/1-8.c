#include <stdio.h>

int main(void)
{
    int c, blank, tab, nl;

    blank = 0;
    tab = 0;
    nl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blank;
        if (c == '\t')
            ++tab;
        if (c == '\n')
            ++nl;
    }

    printf("blanks: %d, tabs: %d, newlines: %d\n", blank, tab, nl);
}
