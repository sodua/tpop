#include <stdio.h>

int main(void)
{
    int p;
    int n = 4;
    int base = 2;

    for(p = 1; n > 0; --n) {
        p = p * base;
        printf("n: %d p: %d base: %d\n", n, p, base);
    }
}
