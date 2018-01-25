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
	while (still == 1) {
		while ((rem = m % t) != 0) {
			--t;
			++i;
		}
		if (rem == 0) {
			if (n % t == 0) {
				++i;
				still = 0;
				printf("iterations: %d\n", i);
				return t;
			}
			else
				--t;
				++i;
		}
	}
}
