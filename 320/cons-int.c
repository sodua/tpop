#include <stdio.h>
int gcd(int m, int n);
int main(void)
{
    int m = 31415;
    int n = 14142;
    printf("%d\n", gcd(m, n));   
}    

int gcd(int m, int n) {
    int i, t, rem;
    int still = 0;

    t = n;
    rem = m % n;
    while (still = 1) {
        while (rem != 0) {
            rem = n % t;
            --t;
        }
        if (rem == 0) {
            while (n % t != 0) {
                rem = n % t;
                return t;
            }
            else
                --t;
        }
    }
}
