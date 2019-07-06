/* bitcount: count 1 bits in x */
#include <stdio.h>
int bitcount(unsigned x);

int main(void)
{
    unsigned d = 211;
    printf("%d is the number of 1 bits\n", bitcount(d));
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x!= 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
