/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
    int x = 220;
    printf("%d\n", setbits(x, 4, 3, 2));

}

unsigned setbits(unsigned x, int p, int n, int y)
{
    return (x >> (p+1-n)) & (~0 << n);
}
