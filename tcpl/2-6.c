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
   for (unsigned i=a; i<=b; i++) {
       printf("r is %d and i is %d\n", r, i);
       r |= 1 << i;
   }


/* OR: result is 1 if one of either bits is 1, and 0 only when both bits are 0
 * left shift: the most-significant bit is lost and a 0 added at least-significant
 */

   return r;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
	unsigned mask = create_mask(p, p+n);
    printf("mask is %u\n", mask);
    printf("1's compliment of mask is %d\n", ~mask);
    printf("y AND 1's compliment of mask is %d\n", (y & ~mask));
    printf("x AND mask is %d\n", (x & mask));
    return ((y & ~mask) | (x & mask));
    /* AND: result is 1 only if both bits are 1
     * OR: used to turn bits on */
}
