#include <stdio.h>

void swap(int *px, int *py);

int main(int argc, char **argv)
{
    int a = 5;
    int b = 7;
    printf("a is %d.\n", a);
    printf("b is %d.\n", b);

    swap(&a, &b);

    printf("a is now %d.\n", a);
    printf("b is now %d.\n", b);

    return 0;
}

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
