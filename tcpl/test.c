#include <stdio.h>
#include <math.h>

double sqrt(double);

int main(void)
{
    int n = 36;
    printf("%f\n", sqrt(n));
    int j = sqrt(n);
    printf("%d\n", j);
}
