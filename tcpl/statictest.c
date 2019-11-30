#include <stdio.h>

int myfunc(int num);

int main(void)
{
    int val;
    val = myfunc(25);
    val = myfunc(25);
    val = myfunc(25);
    printf("%d\n", val);
}

int myfunc(int num)
{
    static int keep = 0;
    keep += num;
    return keep;
}
