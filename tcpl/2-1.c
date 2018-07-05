/* Write a program to determine the ranges of char, short, int, and long variables 
 * both signed and unsigned, by printing appropriate values from standard headers 
 * and by direct computation. Harder if you compute them: determine the ranges of
 * the various floating-point types. */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    char mychar = 0;
    for (int i=0; i < 255; ++i)
    {
        printf("%c ", mychar);
        ++mychar;
    }
    printf("\n");

    signed int go_over = 0;
    for (signed int i = 0; i >= 0; ++i)
    {
        ++go_over;
    }
    printf("%d\n", go_over);
}
