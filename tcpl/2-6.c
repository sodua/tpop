/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */
#include <stdio.h>

int main(void)
{
    int n = 1111;
    n = n & 1000;
    printf("%d\n", n);

}
