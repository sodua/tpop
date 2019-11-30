#include <stdio.h>

void printd(int n);

int main(void)
{
    printd(-154);
    printf("\n");
}

/* printd:  print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        printf("-- %d --", n);
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
