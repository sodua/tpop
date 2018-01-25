#include <stdio.h>
int gcd(int m, int n);
int main(void)
{
    int m = 31415;
    int n = 14142;
    int i;
    for (i = 0; i < 1000; ++i)
        printf("%d\n", gcd(m, n));   
}    

int gcd(int m, int n) {
    int i = 0;
	int t, rem;
    int still = 1;

    t = n;
	while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
        ++i;
	}
    if (n == 0) {
        printf("iterations: %d\n", i);
        return m;
    }
}
