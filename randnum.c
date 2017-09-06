#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i;
    for(i = 0; i < 100; i++)
        printf("%d\n", rand());
}
