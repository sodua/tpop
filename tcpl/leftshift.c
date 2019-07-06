#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int num;

   if (argc > 1) {
       num = atoi(argv[1]);
       printf("%u\n", 48 | 1 << num);
   }
}
