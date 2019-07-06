#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int num;

   if (argc > 1) {
       num = atoi(argv[1]);
       printf("%d\n", num % 10);
   }
}
