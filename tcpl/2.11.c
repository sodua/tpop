#include <stdio.h>

int main(void)
{
    int a[1902];
    for (int j = 0; j < 1902; j++)
        a[j] = j;
    int i, n = 1902;
    for (i = 0; i < n; i++)
        printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}
