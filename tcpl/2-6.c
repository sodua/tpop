/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
    int x = 202;
    int y = 211;
    printf("%d\n", setbits(x, 4, 3, y));

}

unsigned create_mask(unsigned a, unsigned b)
{
   unsigned r = 0;
   for (unsigned i=a; i<=b; i++)
       r |= 1 << i;

   return r;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
	unsigned mask = create_mask(p, p+n);
    return ((y & ~mask) | (x & mask));
}
