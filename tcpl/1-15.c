/* Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion. */
#include <stdio.h>

int getcelsius(int fahr, int upper);

int main(void)
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = getcelsius(fahr, upper);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int getcelsius(int fahr, int upper)
{
    int celsius = 0;

    celsius = 5 * (fahr-32) / 9;
    return celsius;
}
