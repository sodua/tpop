/* Write a loop equivalent to the for loop above without using && or ||. */

#include <stdio.h>

int main(void)
{
    int i;
    const int lim = 10;
    char c;
    char s[lim];

    for (i = 0; (c = getchar()) != EOF; ++i)
    {
        if (i > lim - 1)
            break;
        if (c == '\n')
        {
            s[i] = c;
            break;
        }
        else
            s[i] = c;
    }
    for (i = 0; i < lim - 2; ++i)
        printf("%c", s[i]);
}
