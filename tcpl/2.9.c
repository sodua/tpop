/* Returns the (right adjusted) n-bit field of x that begins
 * at position p. We assume that bit position 0 is at the right
 * end and that n and p are sensible positive values.
 * For example, getbits(x,4,3) returns the three bits in
 * positions 4, 3, and 2, right adjusted.
 */

#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

int main(void)
{
    int x = 220;
    printf("%d\n", getbits(x, 4, 3));

}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
